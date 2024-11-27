#include "overworld.h"

void Overworld::Initialize()
{
    LockOn::Initialize();
    BubbleView::Initialize();
    Calendar::Initialize(12,17,2,2024);

    for(unsigned i = PlaceIndex::PL_MARKER_FIRST; i <= PlaceIndex::PL_MARKER_LAST; i++)
        Place::places[i] = new Place(i);

    for(unsigned i = ROAD_MARKER_FIRST; i <= ROAD_MARKER_LAST; i++)
    {
        Road::roads[i] = new Road(i);

        Road* r = Road::roads[i];

        WorldGraph::AddRoadToBaseGraph(r->endpointA, r->endpointB, r->length);

        Place::places[r->endpointA]->connections.push_back(r);
        Place::places[r->endpointB]->connections.push_back(r);

    }

    for(std::map<int, Place*>::iterator it = Place::places.begin(); it != Place::places.end(); ++it)
    {
        ((*it).second)->GenerateCitizenCaravans();
    }

    Palette::currentClearColour = Palette::COL_JADE_3;

    Audio::OverworldBeginParallelBackgroundAudio();
}

void Overworld::Uninitialize()
{
    for(std::vector<Being*>::iterator it = Being::people.begin(); it != Being::people.end();)
    {
        delete *it;
        *it = nullptr;
        it = Being::people.erase(it);
    }

    for(std::vector<Caravan*>::iterator it = Caravan::caravans.begin(); it != Caravan::caravans.end();)
    {
        delete *it;
        *it = nullptr;
        it = Caravan::caravans.erase(it);
    }

    for(std::map<int,Place*>::iterator it = Place::places.begin(); it != Place::places.end(); ++it)
        delete it->second;
    Place::places.clear();

    for(std::map<int, Road*>::iterator it = Road::roads.begin(); it != Road::roads.end(); ++it)
        delete it->second;
    Road::roads.clear();

}

void Overworld::Logic()
{
    ProgressWorld();
    UpdateUI();
    Camera::Logic();
}

void Overworld::Input()
{
    if(Mouse::mousewheelInput[Mouse::MOUSEWHEEL_UP])
    {
        if(Camera::zoomScale < Camera::SCALE_MAX)
        {
            Camera::zoomScale += 0.1;

            Camera::zoomTranslateX -= Display::WIDTH*0.05; // Ten 0.05s = 0.5
            Camera::zoomTranslateY -= Display::HEIGHT*0.05;

            //std::cout << "zoom scale " << Camera::zoomScale << " (" << Camera::zoomScale*100 << "%)" << std::endl;
        }

        al_set_mouse_z(0);
    }
    else if(Mouse::mousewheelInput[Mouse::MOUSEWHEEL_DOWN])
    {
        if(Camera::zoomScale > Camera::SCALE_MIN)
        {
            Camera::zoomScale -= 0.1;

            Camera::zoomTranslateX += Display::WIDTH*0.05; // Ten 0.05s = 0.5
            Camera::zoomTranslateY += Display::HEIGHT*0.05;

            //std::cout << "zoom scale " << Camera::zoomScale << " (" << Camera::zoomScale*100 << "%)" << std::endl;
        }

        al_set_mouse_z(0);
    }
    else if(Mouse::mouseInput[Mouse::MOUSE_MIDDLE])
    {
        Camera::zoomScale = 1;
        Camera::zoomTranslateX = 0;
        Camera::zoomTranslateY = 0;
    }

    if(Mouse::mouseButtonHoldTicks[Mouse::MOUSE_LEFT] == 1)
    {
        BubbleView::CloseEncyclopediaBubble();
        BubbleView::CloseBeingStatusBubble();

        bool mouseLeftOnNoCaravanBubbles = false;
        bool mouseLeftOnNoPlaceBubbles = false;

        if(BubbleView::currentCaravan != nullptr)
        {
            if(!MouseLeftOnCaravanCrewBubble())
                if(!MouseLeftOnCaravanInventoryBubble())
                    if(!MouseLeftOnCaravanTradeRecordsBubble())
                        if(!MouseLeftOnCaravanPathfindingBubble())
                            mouseLeftOnNoCaravanBubbles = true;
        }
        else // BubbleView::currentCaravan == nullptr
            mouseLeftOnNoCaravanBubbles = true;

        if(BubbleView::currentPlace != nullptr)
        {
            if(!MouseLeftOnPlacePopulationBubble())
                if(!MouseLeftOnPlaceCaravanseraiBubble())
                    if(!MouseLeftOnPlaceSurplusBubble())
                        if(!MouseLeftOnPlaceDeficitBubble())
                            if(!MouseLeftOnPlaceMarketBubble())
                                if(!MouseLeftOnPlaceIndustriesBubble())
                                    mouseLeftOnNoPlaceBubbles = true;
        }
        else // BubbleView::currentPlace = nullptr
            mouseLeftOnNoPlaceBubbles = true;

        if(mouseLeftOnNoCaravanBubbles && mouseLeftOnNoPlaceBubbles)
        {
            Camera::mouseTransformedX = Mouse::displayXPosition;
            Camera::mouseTransformedY = Mouse::displayYPosition;
            al_invert_transform(&Camera::zoomTransform); // Don't need to invert a second time, by the way. On redraw, cameraZoom will be reset to identity_transform anyway
            al_transform_coordinates(&Camera::zoomTransform,&Camera::mouseTransformedX,&Camera::mouseTransformedY);
            SetCameraCenterDestination(Camera::xPosition + Camera::mouseTransformedX,
                                       Camera::yPosition + Camera::mouseTransformedY);
        }

        //Event::mouseInput[Event::MOUSE_LEFT] = false;
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_ESC] == 1)
    {
        // Priority: 1) Close enyclopedia. 2) Close being status bubble. 3) Close caravan/place bubbles + unlock camera.

        if(BubbleView::encyclopediaBubbleOpen)
        {
            BubbleView::CloseEncyclopediaBubble();
            std::cout << "Closing encyclopedia bubble" << std::endl;
        }
        else // ! EncyclopediaBubbleOpen
        {
            if(BubbleView::BubbleView::beingStatusBubbleOpen)
            {
                BubbleView::CloseBeingStatusBubble();
                std::cout << "Closing being status bubble" << std::endl;
            }
            else // ! BubbleView::beingStatusBubbleOpen
            {
                if(BubbleView::currentCaravan != nullptr || BubbleView::currentPlace != nullptr) // either caravan/place bubbles are open
                {
                    BubbleView::currentCaravan = nullptr;
                    BubbleView::currentPlace = nullptr;
                    std::cout << "Closing caravan/place bubbles" << std::endl;
                }

                UnlockCamera();
                std::cout << "unlocking camera" << std::endl;
            }
        }
        //Event::keyInput[Event::KEY_ESC] = false;

        ///Scene::ChangeScene(Scene::SCENE_TITLE);
    }

    /// Camera panning
    if(!LockOn::isLockedOn)
    {
        if(!Camera::overworldCameraMousePanningDisabled)
        {
            if(Mouse::displayXPosition < 2*Tile::WIDTH)
                Camera::xPosition -= Camera::X_SENSITIVITY;
            if(Mouse::displayXPosition > Display::WIDTH - 2*Tile::WIDTH)
                Camera::xPosition += Camera::X_SENSITIVITY;
            if(Mouse::displayYPosition < 2*Tile::HEIGHT)
                Camera::yPosition -= Camera::Y_SENSITIVITY;
            if(Mouse::displayYPosition > Display::HEIGHT - 2*Tile::HEIGHT)
                Camera::yPosition += Camera::Y_SENSITIVITY;
        }
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_SPACE] == 1)
    {
        // Reestablishes bubbles of locked place/caravan, in case they have been closed (nullptr'd).
        if(LockOn::IsLockedOnPlace)
            BubbleView::currentPlace = LockOn::whichPlace;
        else if(LockOn::isLockedOnCaravan)
        {
            BubbleView::currentCaravan = LockOn::whichCaravan;
            if(BubbleView::currentCaravan->atPlace)
                BubbleView::currentPlace = BubbleView::currentCaravan->whichPlace;
        }
    }
}

void Overworld::Drawing()
{
    al_set_target_bitmap(Camera::cameraBuffer);
    al_clear_to_color(Palette::currentClearColour);

    al_identity_transform(&Camera::zoomTransform);
    al_scale_transform(&Camera::zoomTransform,Camera::zoomScale,Camera::zoomScale);
    al_translate_transform(&Camera::zoomTransform,Camera::zoomTranslateX,Camera::zoomTranslateY);
    al_use_transform(&Camera::zoomTransform);

    DrawGridUnderlay();
    DrawGridCameraCrosshair();

    for(unsigned i = 0; i < Place::places.size(); i++)
        Place::places[i]->DrawSpriteOnOverworld();

    for(unsigned i = 0; i < Road::roads.size(); i++)
        Road::roads[i]->DrawSegmentsOnOverworld();

    for(unsigned i = 0; i < Caravan::caravans.size(); i++)
        Caravan::caravans[i]->DrawSpriteOnOverworld();

    for(std::map<int, Place*>::iterator it = Place::places.begin(); it != Place::places.end(); ++it)
        (*it).second->DrawFlyingTexts();

    al_use_transform(&Camera::identityTransform); /// UI overlay elements are unaffected by camera position.

    if(BubbleView::beingStatusBubbleOpen)
        BubbleView::DrawBeingStatusBubble(BubbleView::currentBeing);

    if(BubbleView::currentCaravan != nullptr)
    {
        BubbleView::DrawCaravanCrewBubble(BubbleView::currentCaravan);
        //BubbleView::DrawCaravanTravelViewBubble(BubbleView::currentCaravan);
        BubbleView::DrawCaravanInventoryBubble(BubbleView::currentCaravan);
        BubbleView::DrawCaravanTradeRecordsBubble(BubbleView::currentCaravan);
        BubbleView::DrawCaravanPathfindingBubble(BubbleView::currentCaravan);
    }
    if(BubbleView::currentPlace != nullptr)
    {
        BubbleView::DrawPlacePopulationBubble(BubbleView::currentPlace);
        BubbleView::DrawPlaceCaravanseraiBubble(BubbleView::currentPlace);
        BubbleView::DrawPlaceSurplusBubble(BubbleView::currentPlace);
        BubbleView::DrawPlaceDeficitBubble(BubbleView::currentPlace);
        BubbleView::DrawPlaceMarketBubble(BubbleView::currentPlace);
        BubbleView::DrawPlaceIndustriesBubble(BubbleView::currentPlace);
    }

    if(BubbleView::encyclopediaBubbleOpen)
        BubbleView::DrawEncyclopediaBubble();

    Calendar::DrawCalendar();
    DrawGridText(Mouse::displayXPosition, Mouse::displayYPosition);

    al_set_target_bitmap(al_get_backbuffer(Display::display));
    al_clear_to_color(Palette::currentClearColour);
    al_draw_bitmap(Camera::cameraBuffer, Arena::X_POSITION, Arena::Y_POSITION, 0);

}

void Overworld::ProgressWorld()
{
    Calendar::AdvanceHourFrame();
    Calendar::UpdateCalendarText();

    for(std::map<int,Place*>::iterator it = Place::places.begin(); it != Place::places.end(); ++it)
    {
        ((*it).second)->ProgressFlyingTexts();
        ((*it).second)->ProgressPlaceIndustriesBubbleProgressBars();

        if(Calendar::hourChangeTick)
        {
            ((*it).second)->ProgressProduction();

            ((*it).second)->ProgressMaintainenceConsumption();
            ((*it).second)->UpdateSurplusesDescending();
            ((*it).second)->UpdateDeficitsDescending();
        }

        if(Calendar::dayChangeTick)
        {
            //((*it).second)->UpdateEconomyData();
        }

    }

    /*
    for(std::map<int,Road*>::iterator it = Road::roads.begin(); it != Road::roads.end(); ++it)
    {

    }
    */

    for(std::vector<Being*>::iterator it = Being::people.begin(); it != Being::people.end(); ++it)
    {
        (*it)->Progress();
    }

    for(std::vector<Caravan*>::iterator it = Caravan::caravans.begin(); it != Caravan::caravans.end(); ++it)
    {
        (*it)->OverworldLogic();
    }
}

void Overworld::UpdateUI()
{
    if(LockOn::isLockedOnCaravan)
    {
        Camera::xPosition = LockOn::whichCaravan->overworldXPosition-Display::WIDTH/2;
        Camera::yPosition = LockOn::whichCaravan->overworldYPosition-Display::HEIGHT/2;
    }
    else // if ! isLockedOnCaravan
    {
        if(Camera::approachingDestination)
        {
            Camera::ApproachDestinationFractional(0.5);
            if(std::abs(Camera::xDestination - Camera::xPosition) <= 4 && std::abs(Camera::yDestination - Camera::yPosition) <= 4)
            {
                Camera::WarpToDestination();
                AttemptCameraLockOn();
            }

        }

    }

    if(BubbleView::currentCaravan != nullptr)
    {
        if(BubbleView::currentCaravan->crewBubbleNeedsUpdate)
            BubbleView::UpdateCaravanCrewBubble(BubbleView::currentCaravan);
        if(BubbleView::currentCaravan->inventoryBubbleNeedsUpdate)
            BubbleView::UpdateCaravanInventoryBubble(BubbleView::currentCaravan);
        if(BubbleView::currentCaravan->tradeRecordsBubbleNeedsUpdate)
            BubbleView::UpdateCaravanTradeRecordsBubble(BubbleView::currentCaravan);
        if(BubbleView::currentCaravan->pathfindingBubbleNeedsUpdate)
            BubbleView::UpdateCaravanPathfindingBubble(BubbleView::currentCaravan);
    }

    if(BubbleView::currentPlace != nullptr)
    {
        if(BubbleView::currentPlace->populationBubbleNeedsUpdate)
            BubbleView::UpdatePlacePopulationBubble(BubbleView::currentPlace);
        if(BubbleView::currentPlace->caravanseraiBubbleNeedsUpdate)
            BubbleView::UpdatePlaceCaravanseraiBubble(BubbleView::currentPlace);
        if(BubbleView::currentPlace->surplusBubbleNeedsUpdate)
            BubbleView::UpdatePlaceSurplusBubble(BubbleView::currentPlace);
        if(BubbleView::currentPlace->deficitBubbleNeedsUpdate)
            BubbleView::UpdatePlaceDeficitBubble(BubbleView::currentPlace);
        if(BubbleView::currentPlace->marketBubbleNeedsUpdate)
            BubbleView::UpdatePlaceMarketBubble(BubbleView::currentPlace);
        if(BubbleView::currentPlace->industriesBubbleNeedsUpdate)
            BubbleView::UpdatePlaceIndustriesBubble(BubbleView::currentPlace);

    }

    Audio::OverworldParallelAudioUpdate();
}


/*
void Overworld::DrawDebugGrid()
{
    for(int x = 0; x <= Arena::WIDTH / Tile::WIDTH; x++) //Columns
    {
        al_draw_line(x*Tile::WIDTH - (int)Camera::xPosition%(int)Tile::HEIGHT,
                     0,
                     x*Tile::WIDTH  - (int)Camera::xPosition%(int)Tile::HEIGHT,
                     Arena::HEIGHT,
                     COLKEY_DEBUG_GRID_UNDERLAY,1);
    }

    for(int y = 0; y <= Arena::HEIGHT / Tile::HEIGHT; y++) //Rows
    {
        al_draw_line(0,
                     y*Tile::WIDTH  - (int)Camera::yPosition%(int)Tile::HEIGHT,
                     Arena::WIDTH,
                     y*Tile::WIDTH  - (int)Camera::yPosition%(int)Tile::HEIGHT,
                     COLKEY_DEBUG_GRID_UNDERLAY,1);
    }
}



void Overworld::DrawDebugGridCameraCrosshair()
{
    al_draw_line(Arena::WIDTH/2, 0, Arena::WIDTH/2, Arena::HEIGHT, COLKEY_CAMERA_CROSSHAIR_LOCKED, 1);
    al_draw_line(0, Arena::HEIGHT/2, Arena::WIDTH, Arena::HEIGHT/2, COLKEY_CAMERA_CROSSHAIR_LOCKED, 1);
}



void Overworld::DrawDebugGridText()//float mouseTransformedX, float mouseTransformedY
{
    int camXPos = Camera::xPosition;
    int camYPos = Camera::yPosition;

    int camXCell = std::round(camXPos/Tile::WIDTH);
    int camYCell = std::round(camYPos/Tile::HEIGHT);

    int zoomPercentage = Camera::zoomScale*100;

    std::string cameraPositionString = "Crosshair position: (" + std::to_string(camXPos) + ", " + std::to_string(camYPos) + ") : ("
                                       + std::to_string(camXCell) + ", " + std::to_string(camYCell) + ") "
                                       + std::to_string(zoomPercentage) + "% zoom";

    Hax::string_al_draw_text(Font::builtin8,COLKEY_CAMERA_CROSSHAIR_LOCKED,0,0,ALLEGRO_ALIGN_LEFT,cameraPositionString);
}
*/

bool Overworld::MouseLeftOnCaravanCrewBubble()
{
    if(Mouse::displayXPosition > BubbleView::caravanCrewBubbleDrawX
            && Mouse::displayXPosition < BubbleView::caravanCrewBubbleDrawX + BubbleView::caravanCrewBubbleWidth
            && Mouse::displayYPosition > BubbleView::caravanCrewBubbleDrawY
            && Mouse::displayYPosition < BubbleView::caravanCrewBubbleDrawY + BubbleView::caravanCrewBubbleHeight)
    {
        int x = Mouse::displayXPosition - BubbleView::caravanCrewBubbleDrawX;
        unsigned index = x/Tile::WIDTH;

        if(index < BubbleView::currentCaravan->members.size())
        {
            LockCameraCaravan(BubbleView::currentCaravan);
            BubbleView::OpenBeingStatusBubble(BubbleView::currentCaravan->members[index]);
        }

        return true;
    }
    else
        return false;
}

bool Overworld::MouseLeftOnCaravanInventoryBubble()
{
    if(Mouse::displayXPosition > BubbleView::caravanInventoryBubbleDrawX
            && Mouse::displayXPosition < BubbleView::caravanInventoryBubbleDrawX + BubbleView::caravanInventoryBubbleWidth
            && Mouse::displayYPosition > BubbleView::caravanInventoryBubbleDrawY
            && Mouse::displayYPosition < BubbleView::caravanInventoryBubbleDrawY + BubbleView::caravanInventoryBubbleHeight)
    {
        int x = Mouse::displayXPosition - BubbleView::caravanInventoryBubbleDrawX;
        int y = Mouse::displayYPosition - BubbleView::caravanInventoryBubbleDrawY;

        int xCell = x/Tile::WIDTH;
        int yCell = y/(Tile::HEIGHT+BubbleView::caravanInventoryBubbleRowSpacing);

        unsigned position = yCell*BubbleView::caravanInventoryBubbleNumCols + xCell;

        if(position < BubbleView::currentCaravan->inventory.cargo.size())
        {
            std::map<int,float>::iterator it = BubbleView::currentCaravan->inventory.cargo.begin();
            std::advance(it, position);

            BubbleView::OpenEncyclopediaBubble(Mouse::displayXPosition, Mouse::displayYPosition, Encyclopedia::CATEGORIES_CARGO, (*it).first);
        }

        return true;
    }
    else
        return false;
}

bool Overworld::MouseLeftOnCaravanTradeRecordsBubble()
{
    if(Mouse::displayXPosition > BubbleView::caravanTradeRecordsBubbleDrawX
            && Mouse::displayXPosition < BubbleView::caravanTradeRecordsBubbleDrawX + BubbleView::caravanTradeRecordsBubbleWidth
            && Mouse::displayYPosition > BubbleView::caravanTradeRecordsBubbleDrawY
            && Mouse::displayYPosition < BubbleView::caravanTradeRecordsBubbleDrawY + BubbleView::caravanTradeRecordsBubbleHeight)
    {
        int x = Mouse::displayXPosition - BubbleView::caravanTradeRecordsBubbleDrawX;
        int y = Mouse::displayYPosition - BubbleView::caravanTradeRecordsBubbleDrawY;

        int xCell = x/Tile::WIDTH;
        int yCell = y/(Tile::HEIGHT+BubbleView::caravanTradeRecordsBubbleRowSpacing);

        int ritRecordRowMin = 0;
        int ritRecordRowMax = 0;
        for(std::vector<TradeRecord*>::reverse_iterator rit = BubbleView::currentCaravan->tradeRecords.rbegin(); rit != BubbleView::currentCaravan->tradeRecords.rend(); ++rit)
        {
            ritRecordRowMax = ritRecordRowMin + (*rit)->numRows-1;
            if(yCell >= ritRecordRowMin && yCell <= ritRecordRowMax)
            {
                if(x < BubbleView::caravanTradeRecordsBubblePlaceNameWidth)
                {
                    Place::places[(*rit)->location]->AllBubblesNeedUpdate();
                    LockCameraPlace(Place::places[(*rit)->location]);

                    BubbleView::OpenEncyclopediaBubble(Display::WIDTH/2 - BubbleView::encyclopediaBubbleWidth/2,
                                                       Display::HEIGHT/2 + 2*Tile::HEIGHT,
                                                       Encyclopedia::CATEGORIES_PLACES, (*rit)->location);
                }
                else // x >= caravanTradeRecordsBubblePlaceNameWidth
                {
                    xCell -= BubbleView::caravanTradeRecordsBubblePlaceNameWidth/Tile::WIDTH;
                    yCell -= ritRecordRowMin;

                    unsigned position = yCell*((*rit)->maxCols) + xCell;
                    if(position < (*rit)->tradeQuantities.size())
                    {
                        std::map<int,int>::iterator it = (*rit)->tradeQuantities.begin();
                        std::advance(it, position);

                        BubbleView::OpenEncyclopediaBubble(Mouse::displayXPosition, Mouse::displayYPosition, Encyclopedia::CATEGORIES_CARGO, (*it).first);
                    }
                }
                break;
            }
            else // yCell not within ritRecordRowMin/Max, i.e. not within the boundary coords of the tradeRecord being inspected
                ritRecordRowMin = ritRecordRowMax+1;
        }

        return true;
    }
    else
        return false;
}

bool Overworld::MouseLeftOnCaravanPathfindingBubble()
{
    if(Mouse::displayXPosition > BubbleView::caravanPathfindingBubbleDrawX
            && Mouse::displayXPosition < BubbleView::caravanPathfindingBubbleDrawX + BubbleView::caravanPathfindingBubbleWidth
            && Mouse::displayYPosition > BubbleView::caravanPathfindingBubbleDrawY
            && Mouse::displayYPosition < BubbleView::caravanPathfindingBubbleDrawY + BubbleView::caravanPathfindingBubbleHeight - Font::TEXT_HEIGHT_8)
    {
        int x = Mouse::displayXPosition - BubbleView::caravanPathfindingBubbleDrawX;

        int xCell = x/Tile::WIDTH; // The representation of cities is two tiles wide; every third tile is the red arrow and should not be clickable.
        if(xCell %3 != 2)
        {
            unsigned position = xCell/3;
            int placeId = BubbleView::currentCaravan->worldGraph.path[position];

            Place::places[placeId]->AllBubblesNeedUpdate();

            SetCameraCenterDestination(Place::places[placeId]->overworldXPosition,
                                       Place::places[placeId]->overworldYPosition);

            BubbleView::OpenEncyclopediaBubble(Display::WIDTH/2 - BubbleView::encyclopediaBubbleWidth/2,
                                               Display::HEIGHT/2 + 2*Tile::HEIGHT,
                                               Encyclopedia::CATEGORIES_PLACES, placeId);
        }

        return true;
    }
    else
        return false;
}

bool Overworld::MouseLeftOnPlacePopulationBubble()
{
    return false;
}

bool Overworld::MouseLeftOnPlaceCaravanseraiBubble()
{
    if(Mouse::displayXPosition > BubbleView::placeCaravanseraiDrawX
            && Mouse::displayXPosition < BubbleView::placeCaravanseraiDrawX + BubbleView::placeCaravanseraiWidth
            && Mouse::displayYPosition > BubbleView::placeCaravanseraiDrawY
            && Mouse::displayYPosition < BubbleView::placeCaravanseraiDrawY + BubbleView::placeCaravanseraiHeight)
    {
        int x = Mouse::displayXPosition - BubbleView::placeCaravanseraiDrawX;
        int y = Mouse::displayYPosition - BubbleView::placeCaravanseraiDrawY;

        int xCell = x/Tile::WIDTH;
        int yCell = y/Tile::HEIGHT;

        unsigned position = yCell*(BubbleView::placeCaravanseraiNumCols) + xCell;

        if(position < BubbleView::currentPlace->caravanserai.size())
        {
            BubbleView::currentPlace->caravanserai[position]->AllBubblesNeedUpdate();
            BubbleView::currentCaravan = BubbleView::currentPlace->caravanserai[position];
            //LockCameraCaravan(BubbleView::currentPlace->caravanserai[position]); // Already unlocks camera from place
        }

        return true;
    }
    else
        return false;
}

bool Overworld::MouseLeftOnPlaceSurplusBubble()
{
    return false;
}

bool Overworld::MouseLeftOnPlaceDeficitBubble()
{
    return false;
}

bool Overworld::MouseLeftOnPlaceMarketBubble()
{
    if(Mouse::displayXPosition > BubbleView::placeMarketBubbleDrawX
            && Mouse::displayXPosition < BubbleView::placeMarketBubbleDrawX + BubbleView::placeMarketBubbleWidth
            && Mouse::displayYPosition > BubbleView::placeMarketBubbleDrawY
            && Mouse::displayYPosition < BubbleView::placeMarketBubbleDrawY + BubbleView::placeMarketBubbleHeight)
    {
        int x = Mouse::displayXPosition - BubbleView::placeMarketBubbleDrawX;
        int y = Mouse::displayYPosition - BubbleView::placeMarketBubbleDrawY;

        int xCell = x/Tile::WIDTH;
        int yCell = y/(Tile::HEIGHT+BubbleView::placeMarketBubbleRowSpacing);

        unsigned position = yCell*(BubbleView::placeMarketBubbleNumCols) + xCell;

        if(position < BubbleView::currentPlace->market.cargo.size())
        {
            std::map<int,float>::iterator it = BubbleView::currentPlace->market.cargo.begin();
            std::advance(it, position);

            BubbleView::OpenEncyclopediaBubble(Mouse::displayXPosition, Mouse::displayYPosition, Encyclopedia::CATEGORIES_CARGO, (*it).first);
        }

        return true;
    }
    else
        return false;
}

bool Overworld::MouseLeftOnPlaceIndustriesBubble()
{
    if(Mouse::displayXPosition > BubbleView::placeIndustriesBubbleDrawX
            && Mouse::displayXPosition < BubbleView::placeIndustriesBubbleDrawX + BubbleView::placeIndustriesBubbleWidth
            && Mouse::displayYPosition > BubbleView::placeIndustriesBubbleDrawY
            && Mouse::displayYPosition < BubbleView::placeIndustriesBubbleDrawY + BubbleView::placeIndustriesBubbleHeight)
    {
        std::cout << "Unimplemented" << std::endl;

        return true;
    }
    else
        return false;
}

void Overworld::SetCameraCenterDestination(float x, float y)
{
    //BubbleView::currentCaravan = nullptr; // Don't nullify this. Needed to peruse pathfinding bubble locations without it closing
    BubbleView::currentPlace = nullptr;

    UnlockCamera();

    Camera::SetDestination(x - Display::WIDTH/2, y - Display::HEIGHT/2);
}

void Overworld::AttemptCameraLockOn()
{
    for(std::map<int,Place*>::iterator it = Place::places.begin(); it != Place::places.end(); ++it)
    {
        float x = (*it).second->overworldXPosition;
        float y = (*it).second->overworldYPosition;
        float w = Place::OVERWORLD_SPRITE_W;
        float h = Place::OVERWORLD_SPRITE_H;

        if((Camera::xPosition + Display::WIDTH/2) > x - w/2
                && (Camera::xPosition + Display::WIDTH/2) < x + w/2
                && (Camera::yPosition + Display::HEIGHT/2) > y - h/2
                && (Camera::yPosition + Display::HEIGHT/2) < y + h/2)
        {
            LockCameraPlace((*it).second);
            BubbleView::currentPlace = ((*it).second);
            (*it).second->AllBubblesNeedUpdate();

            Camera::xPosition = x - Display::WIDTH/2;
            Camera::yPosition = y - Display::HEIGHT/2;

            BubbleView::OpenEncyclopediaBubble(Display::WIDTH/2 - BubbleView::encyclopediaBubbleWidth/2,
                                               Display::HEIGHT/2 + 2*Tile::HEIGHT,
                                               Encyclopedia::CATEGORIES_PLACES, (*it).first);
            break;
        }
    }

    if(!LockOn::IsLockedOnPlace) // If a Place wasn't locked on to, search for a caravan.
    {
        for(std::vector<Caravan*>::iterator it = Caravan::caravans.begin(); it != Caravan::caravans.end(); ++it)
        {
            float x = (*it)->overworldXPosition;
            float y = (*it)->overworldYPosition;
            float w = (*it)->caravanLeader->spriteWidth;
            float h = (*it)->caravanLeader->spriteHeight;

            if((Camera::xPosition + Display::WIDTH/2) > x - w/2
                    && (Camera::xPosition + Display::WIDTH/2) < x + w/2
                    && (Camera::yPosition + Display::HEIGHT/2) > y - h/2
                    && (Camera::yPosition + Display::HEIGHT/2) < y + h/2)
            {
                LockCameraCaravan(*it);
                BubbleView::currentCaravan = (*it);
                break;
            }
        }
    }
}


void Overworld::LockCameraPlace(Place *whichPlace)
{
    UnlockCameraCaravan();

    LockOn::whichPlace = whichPlace;
    LockOn::IsLockedOnPlace = true;
    LockOn::isLockedOn = true;

    BubbleView::currentPlace = whichPlace;

    Audio::OverworldSwapParallelBackgroundAudioToPlace();
}

void Overworld::LockCameraCaravan(Caravan *whichCaravan)
{
    UnlockCameraPlace();

    LockOn::whichCaravan = whichCaravan;
    LockOn::isLockedOnCaravan = true;
    LockOn::isLockedOn = true;

    BubbleView::currentCaravan = whichCaravan;

    Audio::OverworldSwapParallelBackgroundAudioToField();
}

void Overworld::UnlockCameraCaravan()
{
    LockOn::whichCaravan = nullptr;
    LockOn::isLockedOnCaravan = false;
}

void Overworld::UnlockCameraPlace()
{
    LockOn::whichPlace = nullptr;
    LockOn::IsLockedOnPlace = false;
}

void Overworld::UnlockCamera()
{
    UnlockCameraPlace();
    UnlockCameraCaravan();
    LockOn::isLockedOn = false;
}

void Overworld::DrawGridUnderlay()
{

    for(int x = 0; x <= Display::WIDTH/Tile::WIDTH; x++) //Columns
    {
        int cxp = Camera::xPosition;
        int tw = Tile::WIDTH;

        al_draw_line(x*Tile::WIDTH - cxp%tw,
                     0,
                     x*Tile::WIDTH - cxp%tw,
                     Display::HEIGHT,
                     COLKEY_DEBUG_GRID_UNDERLAY,1);
    }

    for(int y = 0; y <= Display::HEIGHT/Tile::WIDTH; y++) //Rows
    {
        int cyp = Camera::yPosition;
        int th = Tile::HEIGHT;

        al_draw_line(0,
                     y*Tile::HEIGHT - cyp%th,
                     Display::WIDTH,
                     y*Tile::HEIGHT - cyp%th,
                     COLKEY_DEBUG_GRID_UNDERLAY,1);
    }
}

void Overworld::DrawGridCameraCrosshair()
{
    if(!LockOn::isLockedOn)
    {
        al_draw_line(Display::WIDTH/2,0,Display::WIDTH/2,Display::HEIGHT,COLKEY_CAMERA_CROSSHAIR_FREE,1);
        al_draw_line(0,Display::HEIGHT/2,Display::WIDTH,Display::HEIGHT/2,COLKEY_CAMERA_CROSSHAIR_FREE,1);
    }
    else
    {
        al_draw_line(Display::WIDTH/2,0,Display::WIDTH/2,Display::HEIGHT,COLKEY_CAMERA_CROSSHAIR_LOCKED,1);
        al_draw_line(0,Display::HEIGHT/2,Display::WIDTH,Display::HEIGHT/2,COLKEY_CAMERA_CROSSHAIR_LOCKED,1);
    }
}

/*
void Overworld::DrawGridMouseCrosshair(float mouseDisplayX, float mouseDisplayY)
{
    al_draw_line(mouseDisplayX, 0, mouseDisplayX, Display::HEIGHT, COLKEY_MOUSE_CROSSHAIR,1);
    al_draw_line(0, mouseDisplayY, Display::WIDTH, mouseDisplayY, COLKEY_MOUSE_CROSSHAIR,1);
}
*/

void Overworld::DrawGridText(float mouseTransformedX, float mouseTransformedY)
{
    int cameraCrosshairXPosition = Camera::xPosition+Display::WIDTH/2;
    int cameraCrosshairYPosition = Camera::yPosition+Display::HEIGHT/2;

    int cameraCrosshairXPositionCell = cameraCrosshairXPosition/Tile::WIDTH;
    int cameraCrosshairYPositionCell = cameraCrosshairYPosition/Tile::HEIGHT;

    int mouseCrosshairXPosition = Camera::xPosition+mouseTransformedX;
    int mouseCrosshairYPosition = Camera::yPosition+mouseTransformedY;

    int mouseCrosshairXPositionCell = mouseCrosshairXPosition/Tile::WIDTH;
    int mouseCrosshairYPositionCell = mouseCrosshairYPosition/Tile::HEIGHT;

    int zoomPercentage = Camera::zoomScale*100;

    std::string cameraCrosshairPositionString = "CAMERA: (" + std::to_string(cameraCrosshairXPosition) + ", " + std::to_string(cameraCrosshairYPosition) + ") : ("
            + std::to_string(cameraCrosshairXPositionCell) + ", " + std::to_string(cameraCrosshairYPositionCell) + ") "
            + std::to_string(zoomPercentage) + "%";

    std::string mouseCrosshairPositionString = "MOUSE:  (" + std::to_string(mouseCrosshairXPosition) + ", " + std::to_string(mouseCrosshairYPosition) + ") : ("
            + std::to_string(mouseCrosshairXPositionCell) + ", " + std::to_string(mouseCrosshairYPositionCell) + ") "
            + std::to_string(zoomPercentage) + "%";

    if(!LockOn::isLockedOn)
        Hax::string_al_draw_text(Font::builtin8,COLKEY_CAMERA_CROSSHAIR_FREE,0,0,ALLEGRO_ALIGN_LEFT,cameraCrosshairPositionString);
    else
        Hax::string_al_draw_text(Font::builtin8,COLKEY_CAMERA_CROSSHAIR_LOCKED,0,0,ALLEGRO_ALIGN_LEFT,cameraCrosshairPositionString);

    Hax::string_al_draw_text(Font::builtin8,COLKEY_MOUSE_CROSSHAIR,0,Font::TEXT_HEIGHT_8,ALLEGRO_ALIGN_LEFT,mouseCrosshairPositionString);

}
