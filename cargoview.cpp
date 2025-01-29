#include "cargoview.h"

Frame* CargoView::viewportFrame;
Frame* CargoView::itemGridFrame;
Frame* CargoView::itemReadoutFrame;
Frame* CargoView::optionsFrame;
Frame* CargoView::optionsButtonsFrame;

bool CargoView::hasItemCellSelected;
size_t CargoView::selectedItemCellCol;
size_t CargoView::selectedItemCellRow;
size_t CargoView::selectedItemCellIndex;

void CargoView::Initialize()
{
    viewportFrame = new Frame;
    viewportFrame->Initialize(FrameIndex::CARGOVIEW_VIEWPORT_X, FrameIndex::CARGOVIEW_VIEWPORT_Y,
                              FrameIndex::CARGOVIEW_VIEWPORT_W, FrameIndex::CARGOVIEW_VIEWPORT_H, false);

    optionsFrame = new Frame;
    optionsFrame->Initialize(FrameIndex::CARGOVIEW_OPTIONS_X, FrameIndex::CARGOVIEW_OPTIONS_Y,
                             FrameIndex::CARGOVIEW_OPTIONS_W, FrameIndex::CARGOVIEW_OPTIONS_H, false);

    itemGridFrame = new Frame;
    itemGridFrame->Initialize(FrameIndex::CARGOVIEW_VIEWPORT_X + ITEM_GRID_ORIGIN_X, FrameIndex::CARGOVIEW_VIEWPORT_Y + ITEM_GRID_ORIGIN_Y,
                               ITEM_GRID_WIDTH, ITEM_GRID_HEIGHT, false);

    itemReadoutFrame = new Frame;
    itemReadoutFrame->Initialize(FrameIndex::CARGOVIEW_VIEWPORT_X + ITEM_READOUT_ORIGIN_X, FrameIndex::CARGOVIEW_VIEWPORT_Y + ITEM_READOUT_ORIGIN_Y,
                                 ITEM_READOUT_WIDTH, ITEM_READOUT_HEIGHT, false);

    optionsButtonsFrame = new Frame();
    optionsButtonsFrame->Initialize(FrameIndex::CARGOVIEW_OPTIONS_BUTTONS_X, FrameIndex::CARGOVIEW_OPTIONS_BUTTONS_Y,
                                    FrameIndex::CARGOVIEW_OPTIONS_BUTTONS_W, FrameIndex::CARGOVIEW_OPTIONS_BUTTONS_H, true);
    optionsButtonsFrame->AddButton(ButtonIndex::BT_WORLDVIEW);
    optionsButtonsFrame->AddButton(ButtonIndex::BT_PARTYVIEW);
    optionsButtonsFrame->AddButton(ButtonIndex::BT_CRAFTINGVIEW);
    optionsButtonsFrame->AddButton(ButtonIndex::BT_JOURNALVIEW);
    optionsButtonsFrame->AddButton(ButtonIndex::BT_LEYNETVIEW);

    hasItemCellSelected = false;
    selectedItemCellCol = 0;
    selectedItemCellRow = 0;
    selectedItemCellIndex = 0;
}

void CargoView::Uninitialize()
{
    delete viewportFrame;
    delete itemGridFrame;
    delete itemReadoutFrame;
    delete optionsFrame;
    delete optionsButtonsFrame;
}

void CargoView::Logic()
{

}

void CargoView::Drawing()
{
    // Draw grid perimeter
    al_draw_rectangle(ITEM_GRID_ORIGIN_X, ITEM_GRID_ORIGIN_Y,
                      ITEM_GRID_ORIGIN_X+ITEM_CELLS_X_SEPARATION*ITEM_GRID_COLS, ITEM_GRID_ORIGIN_Y+ITEM_CELLS_Y_SEPARATION*ITEM_GRID_ROWS,
                      al_map_rgb(0,0,0), 2);
    // Draw grid vertical lines
    for(size_t col = 1; col < ITEM_GRID_COLS; col++)
    {
        float drawX = ITEM_GRID_ORIGIN_X + ITEM_CELLS_X_SEPARATION*col;
        al_draw_line(drawX, ITEM_GRID_ORIGIN_Y,
                     drawX, ITEM_GRID_ORIGIN_Y+ITEM_GRID_ROWS*ITEM_CELLS_Y_SEPARATION,
                    al_map_rgb(0,0,0), 2);
    }
    // Draw grid horizontal lines
    for(size_t row = 1; row < ITEM_GRID_ROWS; row++)
    {
        float drawY = ITEM_GRID_ORIGIN_Y + ITEM_CELLS_Y_SEPARATION*row;
        al_draw_line(ITEM_GRID_ORIGIN_X, drawY,
                     ITEM_GRID_ORIGIN_X+ITEM_CELLS_X_SEPARATION*ITEM_GRID_COLS, drawY,
                     al_map_rgb(0,0,0), 2);
    }

    size_t index = 0;
    for(std::map<int, int>::iterator it = Caravan::pcCaravan->inventory.cargo.begin(); it != Caravan::pcCaravan->inventory.cargo.end(); ++it)
    {
        size_t col = index%ITEM_GRID_COLS;
        size_t row = index/ITEM_GRID_COLS;
        float drawX = ITEM_GRID_ORIGIN_X + ITEM_CELLS_X_SEPARATION*col;
        float drawY = ITEM_GRID_ORIGIN_Y + ITEM_CELLS_Y_SEPARATION*row;

        al_draw_scaled_bitmap(Image::cargoSub[(*it).first],
                              0, 0,
                              Tile::WIDTH, Tile::HEIGHT,
                              drawX, drawY,
                              Tile::WIDTH*2, Tile::HEIGHT*2, 0);

        Hax::string_al_draw_text(Font::monogram32, al_map_rgb(0,0,0), drawX+STACK_QUANTITY_TEXT_X, drawY+STACK_QUANTITY_TEXT_Y, ALLEGRO_ALIGN_RIGHT, std::to_string((*it).second));

        index ++;
    }

    // Draw readout perimeter
    al_draw_rectangle(ITEM_READOUT_ORIGIN_X, ITEM_READOUT_ORIGIN_Y,
                      ITEM_READOUT_ORIGIN_X + ITEM_READOUT_WIDTH, ITEM_READOUT_ORIGIN_Y + ITEM_READOUT_HEIGHT,
                      al_map_rgb(0,0,0), 2);

    if(hasItemCellSelected)
    {
            std::map<int, int>::iterator it = Caravan::pcCaravan->inventory.cargo.begin();
            std::advance(it, selectedItemCellIndex);

            Hax::string_al_draw_text(Font::monogram32, al_map_rgb(0,0,0),
                                     ITEM_READOUT_ORIGIN_X+ITEM_READOUT_TEXT_X, ITEM_READOUT_ORIGIN_Y+ITEM_READOUT_NAME_Y,
                                     ALLEGRO_ALIGN_LEFT, InventoryIndex::itemNames.at((*it).first));


            Hax::string_al_draw_multiline_text(Font::monogram32, al_map_rgb(0,0,0),
                                               ITEM_READOUT_ORIGIN_X+ITEM_READOUT_TEXT_X, ITEM_READOUT_ORIGIN_Y+ITEM_READOUT_ENCYCLOPEDIA_Y,
                                               ITEM_READOUT_TEXT_WIDTH, Tile::HEIGHT,
                                               ALLEGRO_ALIGN_LEFT, Encyclopedia::entries.at(Encyclopedia::CATEGORIES_CARGO).at((*it).first));
    }

    optionsFrame->Drawing();
    optionsButtonsFrame->Drawing();
}

void CargoView::Input()
{
    if(Mouse::mouseButtonHoldTicks[Mouse::MOUSE_LEFT] == 1)
    {
        if(viewportFrame->CheckWithinFrame(Mouse::displayXPosition, Mouse::displayYPosition, 0,0))
        {
            if(itemGridFrame->CheckWithinFrame(Mouse::displayXPosition, Mouse::displayYPosition, 0,0))
                MouseLeftOnItemGridFrame();
        }
        else if(optionsButtonsFrame->CheckWithinFrame(Mouse::displayXPosition, Mouse::displayYPosition, 0, 0))
            MouseLeftOnOptionsButtonsFrame();
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_ESC] == 1)
    {
        Scene::ChangeScene(Scene::SCENE_WORLDVIEW);
    }

}

void CargoView::MouseLeftOnItemGridFrame()
{
    std::cout << "Mouse left on itemGridFrame." << std::endl;

    float clickX = Mouse::displayXPosition - itemGridFrame->GetXPosition();
    float clickY = Mouse::displayYPosition - itemGridFrame->GetYPosition();
    selectedItemCellCol = clickX / ITEM_CELLS_X_SEPARATION;
    selectedItemCellRow = clickY / ITEM_CELLS_Y_SEPARATION;
    selectedItemCellIndex = selectedItemCellRow * ITEM_GRID_COLS + selectedItemCellCol;

    if(selectedItemCellIndex < Caravan::pcCaravan->inventory.cargo.size() )
        hasItemCellSelected = true;
    else
        hasItemCellSelected = false;

    std::cout << "Col: " << selectedItemCellCol << " Row: " << selectedItemCellRow << " Index: " << selectedItemCellIndex << std::endl;


}

void CargoView::MouseLeftOnOptionsButtonsFrame()
{
    std::cout << "Mouse left on optionsButtonsFrame." << std::endl;
    bool buttonClicked = false;
    int buttonIdentity;
    for(std::vector<Button*>::iterator it = optionsButtonsFrame->GetButtons().begin(); it != optionsButtonsFrame->GetButtons().end(); ++it)
    {
        if((*it)->CheckWithinButton(Mouse::displayXPosition,
                                    Mouse::displayYPosition,
                                    0, 0))
        {
            std::cout << "Button clicked." << std::endl;
            buttonClicked = true;
            buttonIdentity = (*it)->GetIdentity();
            break;
        }
    }

    if(buttonClicked)
    {
        switch(buttonIdentity)
        {
        case ButtonIndex::BT_LOCALVIEW:
            std::cout << "Unimplemented - Local " << std::endl;
            break;

        case ButtonIndex::BT_WORLDVIEW:
            Scene::ChangeScene(Scene::SCENE_WORLDVIEW);
            break;

        case ButtonIndex::BT_PARTYVIEW:
            Scene::ChangeScene(Scene::SCENE_PARTYVIEW);
            break;

        case ButtonIndex::BT_CARGOVIEW:
            Scene::ChangeScene(Scene::SCENE_CARGOVIEW);
            break;

        case ButtonIndex::BT_JOURNALVIEW:
            std::cout << "Unimplemented - Journal " << std::endl;
            break;

        case ButtonIndex::BT_CRAFTINGVIEW:
            std::cout << "Unimplemented - Crafting " << std::endl;
            break;

        case ButtonIndex::BT_LEYNETVIEW:
            std::cout << "Unimplemented - Leynet " << std::endl;
            break;
        }
    }
}
