#pragma once

#include <string>
#include <map>

#include "tile.h"

struct ButtonIndex
{
    static constexpr float BUTTON_WIDTH_STANDARD = Tile::WIDTH*4;
    static constexpr float BUTTON_HEIGHT_STANDARD = Tile::HEIGHT;

    enum enumButtonIDs
    {
        BT_WORLDVIEW = 0,
        BT_LOCALVIEW = 1,
        BT_PARTYVIEW = 2,
        BT_CARGOVIEW = 3,
        BT_CRAFTINGVIEW = 4,
        BT_JOURNALVIEW = 5,
        BT_LEYNETVIEW = 6
    };

    static inline const std::map<size_t, std::string>buttonNames
    {
        {BT_WORLDVIEW, "World"},
        {BT_LOCALVIEW, "Local"},
        {BT_PARTYVIEW, "Party"},
        {BT_CARGOVIEW, "Cargo"},
        {BT_CRAFTINGVIEW, "Crafting"},
        {BT_JOURNALVIEW, "Journal"},
        {BT_LEYNETVIEW, "Leynet"}
    };

};
