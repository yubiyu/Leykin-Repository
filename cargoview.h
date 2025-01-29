#pragma once

#include "keyboard.h"
#include "mouse.h"

#include "image.h"

#include "scene.h"
#include "frame.h"

#include "caravan.h"

struct CargoView
{
    static Frame* viewportFrame;
    static Frame* itemGridFrame;
    static Frame* itemReadoutFrame;
    static Frame* optionsFrame;
    static Frame* optionsButtonsFrame;

/// Item Grid Begin
    static constexpr float ITEM_GRID_ORIGIN_X = Tile::WIDTH*4;
    static constexpr float ITEM_GRID_ORIGIN_Y = Tile::HEIGHT*4;

    static const size_t ITEM_GRID_COLS = 5;
    static const size_t ITEM_GRID_ROWS = 6;

    static const int STACK_QUANTITY_TEXT_X = 64; // Relative to the top left of an individual cell.
    static const int STACK_QUANTITY_TEXT_Y = 64;

    static constexpr float ITEM_CELLS_X_SEPARATION = Tile::WIDTH*2 + Tile::WIDTH;
    static constexpr float ITEM_CELLS_Y_SEPARATION = Tile::HEIGHT*2 + Tile::HEIGHT;

    static constexpr float ITEM_GRID_WIDTH = ITEM_GRID_COLS*ITEM_CELLS_X_SEPARATION;
    static constexpr float ITEM_GRID_HEIGHT = ITEM_GRID_ROWS*ITEM_CELLS_Y_SEPARATION;

/// Item Grid End
/// Item Readout Begin
    static constexpr float ITEM_READOUT_ORIGIN_X = Tile::WIDTH*22;
    static constexpr float ITEM_READOUT_ORIGIN_Y = ITEM_GRID_ORIGIN_Y;
    static constexpr float ITEM_READOUT_WIDTH = Tile::WIDTH*12;
    static constexpr float ITEM_READOUT_HEIGHT = Tile::HEIGHT*18;

    static const int ITEM_READOUT_TEXT_X = Tile::WIDTH*1; // Relative to origin.
    static const int ITEM_READOUT_TEXT_WIDTH = ITEM_READOUT_WIDTH - ITEM_READOUT_TEXT_X*2;
    static const int ITEM_READOUT_NAME_Y = Tile::HEIGHT*0;
    static const int ITEM_READOUT_VALUE_Y = Tile::HEIGHT*1;
    static const int ITEM_READOUT_WEIGHT_Y = Tile::HEIGHT*2;
    static const int ITEM_READOUT_ENCYCLOPEDIA_Y = Tile::HEIGHT*4;

    static bool hasItemCellSelected;
    static size_t selectedItemCellCol;
    static size_t selectedItemCellRow;
    static size_t selectedItemCellIndex;
/// Item Readout End


    static void Initialize();
    static void Uninitialize();

    static void Logic();
    static void Input();
    static void Drawing();

    static void MouseLeftOnItemGridFrame();
    static void MouseLeftOnOptionsButtonsFrame();

};
