#pragma once

#include "display.h"
#include "tile.h"

#include "buttonindex.h"

struct FrameIndex
{
    static const int BUTTON_COLS_STANDARD = 3;
    static const int BUTTON_ROWS_STANDARD = 2;
    static constexpr float BUTTON_X_SEPARATION_STANDARD = Tile::WIDTH;
    static constexpr float BUTTON_Y_SEPARATION_STANDARD = Tile::HEIGHT/2;

    static constexpr float WORLDVIEW_VIEWPORT_X = 0;
    static constexpr float WORLDVIEW_VIEWPORT_Y = 0;
    static constexpr float WORLDVIEW_VIEWPORT_W = Display::WIDTH;
    static constexpr float WORLDVIEW_VIEWPORT_H = Display::HEIGHT - Tile::HEIGHT*4;

    static constexpr float WORLDVIEW_OPTIONS_X = 0;
    static constexpr float WORLDVIEW_OPTIONS_Y = Display::HEIGHT - Tile::HEIGHT*4;
    static constexpr float WORLDVIEW_OPTIONS_W = Display::WIDTH;
    static constexpr float WORLDVIEW_OPTIONS_H = Tile::HEIGHT*4;

    static constexpr float WORLDVIEW_OPTIONS_BUTTONS_X = WORLDVIEW_OPTIONS_X + Tile::WIDTH/2;
    static constexpr float WORLDVIEW_OPTIONS_BUTTONS_Y = WORLDVIEW_OPTIONS_Y + Tile::HEIGHT/2;
    static constexpr float WORLDVIEW_OPTIONS_BUTTONS_W = ButtonIndex::BUTTON_WIDTH_STANDARD * 3; // 3 cols
    static constexpr float WORLDVIEW_OPTIONS_BUTTONS_H = ButtonIndex::BUTTON_HEIGHT_STANDARD * 2; // 2 rows



    static constexpr float PARTYVIEW_VIEWPORT_X = 0;
    static constexpr float PARTYVIEW_VIEWPORT_Y = 0;
    static constexpr float PARTYVIEW_VIEWPORT_W = Display::WIDTH;
    static constexpr float PARTYVIEW_VIEWPORT_H = Display::HEIGHT - Tile::HEIGHT*4;

    static constexpr float PARTYVIEW_OPTIONS_X = 0;
    static constexpr float PARTYVIEW_OPTIONS_Y = Display::HEIGHT - Tile::HEIGHT*4;
    static constexpr float PARTYVIEW_OPTIONS_W = Display::WIDTH;
    static constexpr float PARTYVIEW_OPTIONS_H = Tile::HEIGHT*4;

    static constexpr float PARTYVIEW_OPTIONS_BUTTONS_X = PARTYVIEW_OPTIONS_X + Tile::WIDTH/2;
    static constexpr float PARTYVIEW_OPTIONS_BUTTONS_Y = PARTYVIEW_OPTIONS_Y + Tile::HEIGHT/2;
    static constexpr float PARTYVIEW_OPTIONS_BUTTONS_W = ButtonIndex::BUTTON_WIDTH_STANDARD * 3; // 3 cols
    static constexpr float PARTYVIEW_OPTIONS_BUTTONS_H = ButtonIndex::BUTTON_HEIGHT_STANDARD * 2; // 2 rows



    static constexpr float CARGOVIEW_VIEWPORT_X = 0;
    static constexpr float CARGOVIEW_VIEWPORT_Y = 0;
    static constexpr float CARGOVIEW_VIEWPORT_W = Display::WIDTH;
    static constexpr float CARGOVIEW_VIEWPORT_H = Display::HEIGHT - Tile::HEIGHT*4;

    static constexpr float CARGOVIEW_OPTIONS_X = 0;
    static constexpr float CARGOVIEW_OPTIONS_Y = Display::HEIGHT - Tile::HEIGHT*4;
    static constexpr float CARGOVIEW_OPTIONS_W = Display::WIDTH;
    static constexpr float CARGOVIEW_OPTIONS_H = Tile::HEIGHT*4;

    static constexpr float CARGOVIEW_OPTIONS_BUTTONS_X = CARGOVIEW_OPTIONS_X + Tile::WIDTH/2;
    static constexpr float CARGOVIEW_OPTIONS_BUTTONS_Y = CARGOVIEW_OPTIONS_Y + Tile::HEIGHT/2;
    static constexpr float CARGOVIEW_OPTIONS_BUTTONS_W = ButtonIndex::BUTTON_WIDTH_STANDARD * 3; // 3 cols
    static constexpr float CARGOVIEW_OPTIONS_BUTTONS_H = ButtonIndex::BUTTON_HEIGHT_STANDARD * 2; // 2 rows

};
