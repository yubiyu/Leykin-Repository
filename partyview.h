#pragma once

#include "keyboard.h"
#include "mouse.h"

#include "scene.h"
#include "frame.h"

#include "tile.h"

#include "caravan.h"

struct PartyView
{
    static Frame* viewportFrame;
    static Frame* optionsFrame;
    static Frame* optionsButtonsFrame;

    static constexpr float CARDS_ORIGIN_X = Tile::WIDTH*2;
    static constexpr float CARDS_ORIGIN_Y = Tile::HEIGHT*2;

    static constexpr float CARD_WIDTH = Tile::WIDTH*20;
    static constexpr float CARD_HEIGHT = Tile::HEIGHT*7;

    // All coords relative to its card's top left corner
    static constexpr float PORTRAIT_X = Tile::WIDTH*1;
    static constexpr float PORTRAIT_Y = Tile::HEIGHT*1;

    static const int BIOGRAPHICAL_X = Tile::WIDTH*5;
    static const int NAME_TEXT_Y = Tile::HEIGHT*1;
    static const int ANCESTRY_AND_ROLE_TEXT_Y = Tile::HEIGHT*2;
    static const int ATTRIBUTES_Y = Tile::HEIGHT*3;
    static constexpr float ATTRIBUTES_ICONS_X = BIOGRAPHICAL_X;
    static constexpr float ATTRIBUTES_ICONS_X_SEPARATION = Tile::WIDTH*2;
    static const int ATTRIBUTES_VALUES_X = ATTRIBUTES_ICONS_X + Tile::WIDTH*1;
    static constexpr float ATTRIBUTES_VALUES_X_SEPARATION = ATTRIBUTES_ICONS_X_SEPARATION;

    static constexpr float EQUIPMENT_X = Tile::WIDTH*15;
    static constexpr float EQUIPMENT_X_SEPARATION = Tile::WIDTH + Tile::WIDTH*0.5;
    static constexpr float EQUIPMENT_Y = Tile::HEIGHT*1;
    static constexpr float EQUIPMENT_Y_SEPARATION = Tile::HEIGHT + Tile::HEIGHT*0.5;
    static const size_t EQUIPMENT_COLS = 2;
    static const size_t EQUIPMENT_ROWS = 2;

    static void Initialize();
    static void Uninitialize();

    static void Logic();
    static void Input();
    static void Drawing();

    static void MouseLeftOnOptionsButtonsFrame();
};
