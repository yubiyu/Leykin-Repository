#pragma once

#include <allegro5/allegro5.h>

#define COLKEY_BACKGROUND                                   Palette::COL_CARAMEL_4

#define COLKEY_DEBUG_GRID_UNDERLAY                          Palette::COL_STEEL_0
#define COLKEY_TEXT_HEADER                                  Palette::COL_EARTHEN_0
#define COLKEY_TEXT_LABEL                                   Palette::COL_EARTHEN_1
#define COLKEY_TEXT_VALUE                                   Palette::COL_EARTHEN_2

#define COLKEY_FLYINGTEXT_UP                                Palette::COL_EARTHEN_0
#define COLKEY_FLYINGTEXT_DOWN                              Palette::COL_FLAME_1

#define COLKEY_UI_BUBBLE_BODY                               Palette::COL_STEEL_3
#define COLKEY_UI_BUBBLE_FRAME                              Palette::COL_STEEL_2
#define COLKEY_UI_BUBBLE_TEXT_SURPLUS                       Palette::COL_JADE_1
#define COLKEY_UI_BUBBLE_TEXT_DEFICIT                       Palette::COL_FLAME_1

#define COLKEY_UI_BUBBLE_BEING_STATUS_VITALITY_BODY         Palette::COL_FLESH_1
#define COLKEY_UI_BUBBLE_BEING_STATUS_VITALITY_FRAME        Palette::COL_FLESH_0
#define COLKEY_UI_BUBBLE_BEING_STATUS_HAPPINESS_BODY        Palette::COL_ELECTRIC_4
#define COLKEY_UI_BUBBLE_BEING_STATUS_HAPPINESS_FRAME       Palette::COL_ELECTRIC_3
#define COLKEY_UI_BUBBLE_BEING_STATUS_PURPOSE_BODY          Palette::COL_VIOLET_2
#define COLKEY_UI_BUBBLE_BEING_STATUS_PURPOSE_FRAME         Palette::COL_VIOLET_1

#define COLKEY_UI_BUBBLE_INDUSTRY_PROGRESS_BODY             Palette::COL_STEEL_4
#define COLKEY_UI_BUBBLE_INDUSTRY_PROGRESS_FRAME            Palette::COL_STEEL_2
#define COLKEY_UI_BUBBLE_INDUSTRY_PROGRESS_BODY_DEFICIT     Palette::COL_RUST_2
#define COLKEY_UI_BUBBLE_INDUSTRY_PROGRESS_FRAME_DEFICIT    Palette::COL_RUST_1

#define COLKEY_UI_TRADERECORD_NEGATIVE                      Palette::COL_FLAME_1
#define COLKEY_UI_TRADERECORD_POSITIVE                      Palette::COL_JADE_2

#define COLKEY_CAMERA_CROSSHAIR_FREE                        Palette::COL_OCEAN_3
#define COLKEY_CAMERA_CROSSHAIR_LOCKED                      Palette::COL_FLAME_3

#define COLKEY_MOUSE_CROSSHAIR                              Palette::COL_VIOLET_3

struct Palette
{
    enum enumColourIndexes
    {
        COLOUR_INDEX_BLUE = 0,
        COLOUR_INDEX_GREEN = 1
    };

    static ALLEGRO_COLOR COL_GB[4];

    //static ALLEGRO_COLOR COL_NYX8[8]; // Uses Javier Guerrero's palette "Nyx 8" --- https://lospec.com/palette-list/nyx8
    //static ALLEGRO_COLOR COL_OIL6[6]; // Uses GrafxKid's palette "Oil 6" --- https://lospec.com/palette-list/oil-6

    static ALLEGRO_COLOR COL_ORTHOS_GREEN[4];
    static ALLEGRO_COLOR COL_ORTHOS_BLUE[4];
    static ALLEGRO_COLOR COL_ORTHOS_BLACK;
    static ALLEGRO_COLOR COL_ORTHOS_WHITE;

    static ALLEGRO_COLOR COL_EARTHEN_0;
    static ALLEGRO_COLOR COL_EARTHEN_1;
    static ALLEGRO_COLOR COL_EARTHEN_2;
    static ALLEGRO_COLOR COL_EARTHEN_3;
    static ALLEGRO_COLOR COL_EARTHEN_4;

    static ALLEGRO_COLOR COL_STEEL_0;
    static ALLEGRO_COLOR COL_STEEL_1;
    static ALLEGRO_COLOR COL_STEEL_2;
    static ALLEGRO_COLOR COL_STEEL_3;
    static ALLEGRO_COLOR COL_STEEL_4;

    static ALLEGRO_COLOR COL_RUST_0;
    static ALLEGRO_COLOR COL_RUST_1;
    static ALLEGRO_COLOR COL_RUST_2;
    static ALLEGRO_COLOR COL_RUST_3;

    static ALLEGRO_COLOR COL_FLAME_0;
    static ALLEGRO_COLOR COL_FLAME_1;
    static ALLEGRO_COLOR COL_FLAME_2;
    static ALLEGRO_COLOR COL_FLAME_3;
    static ALLEGRO_COLOR COL_FLAME_4;

    static ALLEGRO_COLOR COL_CARAMEL_0;
    static ALLEGRO_COLOR COL_CARAMEL_1;
    static ALLEGRO_COLOR COL_CARAMEL_2;
    static ALLEGRO_COLOR COL_CARAMEL_3;
    static ALLEGRO_COLOR COL_CARAMEL_4;

    static ALLEGRO_COLOR COL_ELECTRIC_0;
    static ALLEGRO_COLOR COL_ELECTRIC_1;
    static ALLEGRO_COLOR COL_ELECTRIC_2;
    static ALLEGRO_COLOR COL_ELECTRIC_3;
    static ALLEGRO_COLOR COL_ELECTRIC_4;

    static ALLEGRO_COLOR COL_JADE_0;
    static ALLEGRO_COLOR COL_JADE_1;
    static ALLEGRO_COLOR COL_JADE_2;
    static ALLEGRO_COLOR COL_JADE_3;
    static ALLEGRO_COLOR COL_JADE_4;

    static ALLEGRO_COLOR COL_WIND_0;
    static ALLEGRO_COLOR COL_WIND_1;
    static ALLEGRO_COLOR COL_WIND_2;
    static ALLEGRO_COLOR COL_WIND_3;
    static ALLEGRO_COLOR COL_WIND_4;

    static ALLEGRO_COLOR COL_AZURE_0;
    static ALLEGRO_COLOR COL_AZURE_1;
    static ALLEGRO_COLOR COL_AZURE_2;
    static ALLEGRO_COLOR COL_AZURE_3;
    static ALLEGRO_COLOR COL_AZURE_4;

    static ALLEGRO_COLOR COL_OCEAN_0;
    static ALLEGRO_COLOR COL_OCEAN_1;
    static ALLEGRO_COLOR COL_OCEAN_2;
    static ALLEGRO_COLOR COL_OCEAN_3;
    static ALLEGRO_COLOR COL_OCEAN_4;

    static ALLEGRO_COLOR COL_VIOLET_0;
    static ALLEGRO_COLOR COL_VIOLET_1;
    static ALLEGRO_COLOR COL_VIOLET_2;
    static ALLEGRO_COLOR COL_VIOLET_3;
    static ALLEGRO_COLOR COL_VIOLET_4;

    static ALLEGRO_COLOR COL_GUM_0;
    static ALLEGRO_COLOR COL_GUM_1;
    static ALLEGRO_COLOR COL_GUM_2;
    static ALLEGRO_COLOR COL_GUM_3;

    static ALLEGRO_COLOR COL_FLESH_0;
    static ALLEGRO_COLOR COL_FLESH_1;
    static ALLEGRO_COLOR COL_FLESH_2;
    static ALLEGRO_COLOR COL_FLESH_3;
    static ALLEGRO_COLOR COL_FLESH_4;
    static ALLEGRO_COLOR COL_FLESH_5;


    static ALLEGRO_COLOR currentClearColour;
    static ALLEGRO_COLOR transparentColour;

    static void InitializeGB();
    static void InitializeOrthos();
    static void InitializeBreath();
    //static void InitializeNyx();
    //static void InitializeOil6();
};
