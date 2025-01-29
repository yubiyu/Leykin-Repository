#include "partyview.h"

Frame* PartyView::viewportFrame;
Frame* PartyView::optionsFrame;
Frame* PartyView::optionsButtonsFrame;

void PartyView::Initialize()
{
    viewportFrame = new Frame;
    viewportFrame->Initialize(FrameIndex::PARTYVIEW_VIEWPORT_X, FrameIndex::PARTYVIEW_VIEWPORT_Y, FrameIndex::PARTYVIEW_VIEWPORT_W, FrameIndex::PARTYVIEW_VIEWPORT_H, false);

    optionsFrame = new Frame;
    optionsFrame->Initialize(FrameIndex::PARTYVIEW_OPTIONS_X, FrameIndex::PARTYVIEW_OPTIONS_Y, FrameIndex::PARTYVIEW_OPTIONS_W, FrameIndex::PARTYVIEW_OPTIONS_H, false);

    optionsButtonsFrame = new Frame();
    optionsButtonsFrame->Initialize(FrameIndex::PARTYVIEW_OPTIONS_BUTTONS_X, FrameIndex::PARTYVIEW_OPTIONS_BUTTONS_Y, FrameIndex::PARTYVIEW_OPTIONS_BUTTONS_W, FrameIndex::PARTYVIEW_OPTIONS_BUTTONS_H, true);
    optionsButtonsFrame->AddButton(ButtonIndex::BT_WORLDVIEW);
    optionsButtonsFrame->AddButton(ButtonIndex::BT_CARGOVIEW);
    optionsButtonsFrame->AddButton(ButtonIndex::BT_CRAFTINGVIEW);
    optionsButtonsFrame->AddButton(ButtonIndex::BT_JOURNALVIEW);
    optionsButtonsFrame->AddButton(ButtonIndex::BT_LEYNETVIEW);
}

void PartyView::Uninitialize()
{
    delete viewportFrame;
    delete optionsFrame;
    delete optionsButtonsFrame;

}

void PartyView::Drawing()
{
    al_draw_text(FONTDEF_PARTYVIEW_HEADER, COLKEY_TEXT_HEADER, 0,0, ALLEGRO_ALIGN_LEFT, "Caravan Overview");

    int cardIndex = 0;
    for(std::vector<Being*>::iterator it = Caravan::pcCaravan->members.begin(); it != Caravan::pcCaravan->members.end(); ++it)
    {
        float cardDrawX = CARDS_ORIGIN_X;
        float cardDrawY = CARDS_ORIGIN_Y + CARD_HEIGHT*cardIndex;

        al_draw_rounded_rectangle(cardDrawX, cardDrawY, cardDrawX+CARD_WIDTH, cardDrawY+CARD_HEIGHT, 2.0, 2.0, al_map_rgb(0,0,0), 4.0);

        (*it)->DrawActivity(cardDrawX + PORTRAIT_X, cardDrawY + PORTRAIT_Y);

        Hax::string_al_draw_text(FONTDEF_PARTYVIEW_VALUE, COLKEY_TEXT_VALUE, cardDrawX+BIOGRAPHICAL_X, cardDrawX+NAME_TEXT_Y, ALLEGRO_ALIGN_LEFT, (*it)->GetName());
        Hax::string_al_draw_text(FONTDEF_PARTYVIEW_VALUE, COLKEY_TEXT_VALUE, cardDrawY+BIOGRAPHICAL_X, cardDrawY+ANCESTRY_AND_ROLE_TEXT_Y, ALLEGRO_ALIGN_LEFT,
                                 AncestryIndex::ancestryNames.at((*it)->GetAncestry()) + " " + RoleIndex::roleNames.at((*it)->GetRole()));

        for(size_t i = 0; i < AttributeIndex::NUM_ATTRIBUTES; i++)
        {
            Hax::DrawPlaceholder32(cardDrawX + ATTRIBUTES_ICONS_X + i*ATTRIBUTES_ICONS_X_SEPARATION, cardDrawY + ATTRIBUTES_Y);
            Hax::string_al_draw_text(FONTDEF_PARTYVIEW_VALUE, COLKEY_TEXT_VALUE, cardDrawX+ATTRIBUTES_VALUES_X + i*ATTRIBUTES_VALUES_X_SEPARATION, cardDrawY + ATTRIBUTES_Y,
                                     ALLEGRO_ALIGN_LEFT, (*it)->attributesString[i]);


            for(size_t j = 0; j < 4; /*EquipmentIndex::NUM_SLOTS;*/ j++)
            {
                float equipmentDrawX = EQUIPMENT_X + EQUIPMENT_X_SEPARATION*(j%EQUIPMENT_COLS);
                float equipmentDrawY = EQUIPMENT_Y + EQUIPMENT_Y_SEPARATION*(j/EQUIPMENT_COLS);

                Hax::DrawPlaceholder32(cardDrawX+equipmentDrawX, cardDrawY+equipmentDrawY);
            }
        }

        cardIndex ++;
    }

    optionsFrame->Drawing();
    optionsButtonsFrame->Drawing();
}

void PartyView::Input()
{
    if(Mouse::mouseButtonHoldTicks[Mouse::MOUSE_LEFT] == 1)
    {
        if(optionsButtonsFrame->CheckWithinFrame(Mouse::displayXPosition, Mouse::displayYPosition, 0, 0))
            MouseLeftOnOptionsButtonsFrame();
    }


    if(Keyboard::keyHoldTicks[Keyboard::KEY_ESC] == 1)
    {
        Scene::ChangeScene(Scene::SCENE_WORLDVIEW);
    }
}

void PartyView::Logic()
{


}

void PartyView::MouseLeftOnOptionsButtonsFrame()
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
        case ButtonIndex::BT_WORLDVIEW:
            //std::cout << "Unimplemented - Local " << std::endl;
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
