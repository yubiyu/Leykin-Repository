#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

struct Font
{
    static const int TEXT_HEIGHT_8 = 8;
    static const int TEXT_HEIGHT_12 = 12;
    static const int TEXT_HEIGHT_16 = 16;
    static const int TEXT_HEIGHT_32 = 32;
    static const int TEXT_HEIGHT_48 = 48;

    static ALLEGRO_FONT *builtin8;
    static ALLEGRO_FONT *monogram32;

    static void Initialize();
    static void Uninitialize();

    static void LoadResources();
    static void UnloadResources();
};

#endif // FONT_H_INCLUDED
