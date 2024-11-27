#include "palette.h"

ALLEGRO_COLOR Palette::COL_GB[4];

//ALLEGRO_COLOR Palette::COL_NYX8[8];
//ALLEGRO_COLOR Palette::COL_OIL6[6];

ALLEGRO_COLOR Palette::COL_ORTHOS_GREEN[4];
ALLEGRO_COLOR Palette::COL_ORTHOS_BLUE[4];
ALLEGRO_COLOR Palette::COL_ORTHOS_BLACK;
ALLEGRO_COLOR Palette::COL_ORTHOS_WHITE;

//ALLEGRO_COLOR Palette::COL_NYX8[8];
//ALLEGRO_COLOR Palette::COL_OIL6[6];

ALLEGRO_COLOR Palette::COL_EARTHEN_0;
ALLEGRO_COLOR Palette::COL_EARTHEN_1;
ALLEGRO_COLOR Palette::COL_EARTHEN_2;
ALLEGRO_COLOR Palette::COL_EARTHEN_3;
ALLEGRO_COLOR Palette::COL_EARTHEN_4;

ALLEGRO_COLOR Palette::COL_STEEL_0;
ALLEGRO_COLOR Palette::COL_STEEL_1;
ALLEGRO_COLOR Palette::COL_STEEL_2;
ALLEGRO_COLOR Palette::COL_STEEL_3;
ALLEGRO_COLOR Palette::COL_STEEL_4;

ALLEGRO_COLOR Palette::COL_RUST_0;
ALLEGRO_COLOR Palette::COL_RUST_1;
ALLEGRO_COLOR Palette::COL_RUST_2;
ALLEGRO_COLOR Palette::COL_RUST_3;

ALLEGRO_COLOR Palette::COL_FLAME_0;
ALLEGRO_COLOR Palette::COL_FLAME_1;
ALLEGRO_COLOR Palette::COL_FLAME_2;
ALLEGRO_COLOR Palette::COL_FLAME_3;
ALLEGRO_COLOR Palette::COL_FLAME_4;

ALLEGRO_COLOR Palette::COL_CARAMEL_0;
ALLEGRO_COLOR Palette::COL_CARAMEL_1;
ALLEGRO_COLOR Palette::COL_CARAMEL_2;
ALLEGRO_COLOR Palette::COL_CARAMEL_3;
ALLEGRO_COLOR Palette::COL_CARAMEL_4;

ALLEGRO_COLOR Palette::COL_ELECTRIC_0;
ALLEGRO_COLOR Palette::COL_ELECTRIC_1;
ALLEGRO_COLOR Palette::COL_ELECTRIC_2;
ALLEGRO_COLOR Palette::COL_ELECTRIC_3;
ALLEGRO_COLOR Palette::COL_ELECTRIC_4;

ALLEGRO_COLOR Palette::COL_JADE_0;
ALLEGRO_COLOR Palette::COL_JADE_1;
ALLEGRO_COLOR Palette::COL_JADE_2;
ALLEGRO_COLOR Palette::COL_JADE_3;
ALLEGRO_COLOR Palette::COL_JADE_4;

ALLEGRO_COLOR Palette::COL_WIND_0;
ALLEGRO_COLOR Palette::COL_WIND_1;
ALLEGRO_COLOR Palette::COL_WIND_2;
ALLEGRO_COLOR Palette::COL_WIND_3;
ALLEGRO_COLOR Palette::COL_WIND_4;

ALLEGRO_COLOR Palette::COL_AZURE_0;
ALLEGRO_COLOR Palette::COL_AZURE_1;
ALLEGRO_COLOR Palette::COL_AZURE_2;
ALLEGRO_COLOR Palette::COL_AZURE_3;
ALLEGRO_COLOR Palette::COL_AZURE_4;

ALLEGRO_COLOR Palette::COL_OCEAN_0;
ALLEGRO_COLOR Palette::COL_OCEAN_1;
ALLEGRO_COLOR Palette::COL_OCEAN_2;
ALLEGRO_COLOR Palette::COL_OCEAN_3;
ALLEGRO_COLOR Palette::COL_OCEAN_4;

ALLEGRO_COLOR Palette::COL_VIOLET_0;
ALLEGRO_COLOR Palette::COL_VIOLET_1;
ALLEGRO_COLOR Palette::COL_VIOLET_2;
ALLEGRO_COLOR Palette::COL_VIOLET_3;
ALLEGRO_COLOR Palette::COL_VIOLET_4;

ALLEGRO_COLOR Palette::COL_GUM_0;
ALLEGRO_COLOR Palette::COL_GUM_1;
ALLEGRO_COLOR Palette::COL_GUM_2;
ALLEGRO_COLOR Palette::COL_GUM_3;

ALLEGRO_COLOR Palette::COL_FLESH_0;
ALLEGRO_COLOR Palette::COL_FLESH_1;
ALLEGRO_COLOR Palette::COL_FLESH_2;
ALLEGRO_COLOR Palette::COL_FLESH_3;
ALLEGRO_COLOR Palette::COL_FLESH_4;
ALLEGRO_COLOR Palette::COL_FLESH_5;

ALLEGRO_COLOR Palette::currentClearColour;
ALLEGRO_COLOR Palette::transparentColour;

void Palette::InitializeGB()
{
    COL_GB[0] = al_map_rgb(   8,  24,  32); // Darkest
    COL_GB[1] = al_map_rgb(  52, 104,  86);
    COL_GB[2] = al_map_rgb( 136, 192, 112);
    COL_GB[3] = al_map_rgb( 224, 248, 208); // Lightest

    currentClearColour = COLKEY_BACKGROUND;
    transparentColour = al_map_rgba(0, 0, 0, 0);
}

void Palette::InitializeOrthos()
{
    COL_ORTHOS_BLUE[0] = al_map_rgb( 128, 222, 234); // Lightest blue
    COL_ORTHOS_BLUE[1] = al_map_rgb(  78, 208, 225); // Light blue
    COL_ORTHOS_BLUE[2] = al_map_rgb(   0, 131, 143); // Dark blue
    COL_ORTHOS_BLUE[3] = al_map_rgb(   0,  96, 100); // Darkest blue

    COL_ORTHOS_GREEN[0] = al_map_rgb( 255, 224, 130); // Lighest green
    COL_ORTHOS_GREEN[1] = al_map_rgb( 255, 183,  77); // Light green
    COL_ORTHOS_GREEN[2] = al_map_rgb( 255, 143,   0); // Dark green
    COL_ORTHOS_GREEN[3] = al_map_rgb( 255, 111,   0); // Darkest green
    COL_ORTHOS_BLACK = al_map_rgb( 33,  33,  33);
    COL_ORTHOS_WHITE = al_map_rgb(238, 238, 238);


    currentClearColour = COLKEY_BACKGROUND;
    transparentColour = al_map_rgba(0,0,0,0);
}

void Palette::InitializeBreath()
{
    COL_EARTHEN_0 =  al_map_rgb( 46,  34,  47);
    COL_EARTHEN_1 =  al_map_rgb( 62,  53,  70);
    COL_EARTHEN_2 =  al_map_rgb( 98,  85, 101);
    COL_EARTHEN_3 =  al_map_rgb(150, 108, 108);
    COL_EARTHEN_4 =  al_map_rgb(171, 148, 122);

    COL_STEEL_0 =    al_map_rgb(105,  79,  98);
    COL_STEEL_1 =    al_map_rgb(127, 112, 138);
    COL_STEEL_2 =    al_map_rgb(155, 171, 178);
    COL_STEEL_3 =    al_map_rgb(199, 220, 208);
    COL_STEEL_4 =    al_map_rgb(255, 255, 255);

    COL_RUST_0 =     al_map_rgb(110,  39, 39);
    COL_RUST_1 =     al_map_rgb(179,  56, 49);
    COL_RUST_2 =     al_map_rgb(234,  79, 54);
    COL_RUST_3 =     al_map_rgb(245, 125, 74);

    COL_FLAME_0 =    al_map_rgb(174,  35, 52);
    COL_FLAME_1 =    al_map_rgb(232,  59, 59);
    COL_FLAME_2 =    al_map_rgb(251, 107, 29);
    COL_FLAME_3 =    al_map_rgb(247, 150, 23);
    COL_FLAME_4 =    al_map_rgb(249, 194, 43);

    COL_CARAMEL_0 =  al_map_rgb(122,  48, 69);
    COL_CARAMEL_1 =  al_map_rgb(158,  69, 57);
    COL_CARAMEL_2 =  al_map_rgb(205, 104, 61);
    COL_CARAMEL_3 =  al_map_rgb(230, 144, 78);
    COL_CARAMEL_4 =  al_map_rgb(251, 185, 84);

    COL_ELECTRIC_0 = al_map_rgb(76,   62,  36);
    COL_ELECTRIC_1 = al_map_rgb(103, 102,  51);
    COL_ELECTRIC_2 = al_map_rgb(162, 169,  71);
    COL_ELECTRIC_3 = al_map_rgb(213, 224,  75);
    COL_ELECTRIC_4 = al_map_rgb(251, 255, 134);

    COL_JADE_0 =     al_map_rgb( 22,  90,  76);
    COL_JADE_1 =     al_map_rgb( 35, 144,  99);
    COL_JADE_2 =     al_map_rgb( 30, 188, 115);
    COL_JADE_3 =     al_map_rgb(145, 219, 105);
    COL_JADE_4 =     al_map_rgb(205, 223, 108);

    COL_WIND_0 = al_map_rgb( 49,  54,  56);
    COL_WIND_1 = al_map_rgb( 55,  78,  74);
    COL_WIND_2 = al_map_rgb( 84, 126, 100);
    COL_WIND_3 = al_map_rgb(146, 169, 132);
    COL_WIND_4 = al_map_rgb(178, 186, 144);

    COL_AZURE_0 = al_map_rgb( 11,  94, 101);
    COL_AZURE_1 = al_map_rgb( 11, 138, 143);
    COL_AZURE_2 = al_map_rgb( 14, 175, 155);
    COL_AZURE_3 = al_map_rgb( 48, 225, 185);
    COL_AZURE_4 = al_map_rgb(143, 248, 226);

    COL_OCEAN_0 = al_map_rgb( 50,  51, 83);
    COL_OCEAN_1 = al_map_rgb( 72,  74, 119);
    COL_OCEAN_2 = al_map_rgb( 77, 101, 180);
    COL_OCEAN_3 = al_map_rgb( 77, 155, 230);
    COL_OCEAN_4 = al_map_rgb(143, 211, 255);

    COL_VIOLET_0 = al_map_rgb( 69,  41,  63);
    COL_VIOLET_1 = al_map_rgb(107,  62, 117);
    COL_VIOLET_2 = al_map_rgb(144,  94, 169);
    COL_VIOLET_3 = al_map_rgb(168, 132, 243);
    COL_VIOLET_4 = al_map_rgb(234, 173, 237);

    COL_GUM_0 = al_map_rgb(117,  60,  84);
    COL_GUM_1 = al_map_rgb(162,  75, 111);
    COL_GUM_2 = al_map_rgb(207, 101, 127);
    COL_GUM_3 = al_map_rgb(237, 128, 153);

    COL_FLESH_0 = al_map_rgb(131,  28,  93);
    COL_FLESH_1 = al_map_rgb(195,  36,  84);
    COL_FLESH_2 = al_map_rgb(240,  79, 120);
    COL_FLESH_3 = al_map_rgb(246, 129, 129);
    COL_FLESH_4 = al_map_rgb(252, 167, 144);
    COL_FLESH_5 = al_map_rgb(253, 203, 176);
}

/*
void Palette::InitializeNyx()
{
    COL_NYX8[0] =  al_map_rgb(  8,  20,  30);
    COL_NYX8[1] =  al_map_rgb( 15,  42,  63);
    COL_NYX8[2] =  al_map_rgb( 32,  57,  79);
    COL_NYX8[3] =  al_map_rgb(246, 214, 189);
    COL_NYX8[4] =  al_map_rgb(195, 163, 138);
    COL_NYX8[5] =  al_map_rgb(153, 117, 119);
    COL_NYX8[6] =  al_map_rgb(129,  98, 113);
    COL_NYX8[7] =  al_map_rgb( 78,  73,  95);
}
*/

/*
void Palette::InitializeOil6()
{
    COL_OIL6[0] = al_map_rgb(251, 241, 239); // Bright Space
    COL_OIL6[1] = al_map_rgb(242, 211, 171); // Bright Light
    COL_OIL6[2] = al_map_rgb(198, 159, 165); // Bright Shadow
    COL_OIL6[3] = al_map_rgb(139, 109, 156); // Dark Light
    COL_OIL6[4] = al_map_rgb( 73,  77, 126); // Dark Shadow
    COL_OIL6[5] = al_map_rgb( 39,  39,  68); // Dark Space
}

*/
