#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define FONTDEF_OVERWORLD_PLACENAME              Font::builtin8

#define FONTDEF_BUBBLEVIEW_HEADER                Font::builtin8
#define FONTDEF_BUBBLEVIEW_LABEL                 Font::builtin8
#define FONTDEF_BUBBLEVIEW_VALUE                 Font::builtin8

#define FONTDEF_CHARACTER_CREATION_HEADER        Font::monogram32
#define FONTDEF_CHARACTER_CREATION_LABEL         Font::monogram32
#define FONTDEF_CHARACTER_CREATION_VALUE         Font::monogram32
#define FONTDEF_CHARACTER_CREATION_DESCRIPTION   Font::monogram24

struct Font
{
    static const int TEXT_HEIGHT_8 = 8;
    static const int TEXT_HEIGHT_12 = 12;
    static const int TEXT_HEIGHT_16 = 16;
    static const int TEXT_HEIGHT_24 = 24;
    static const int TEXT_HEIGHT_32 = 32;
    static const int TEXT_HEIGHT_48 = 48;
    static const int NUM_FONT_SIZES = 4;

    static ALLEGRO_FONT *builtin8;
    static ALLEGRO_FONT *monogram16;
    static ALLEGRO_FONT *monogram24;
    static ALLEGRO_FONT *monogram32;

    static void Initialize();
    static void Uninitialize();

    static void LoadResources();
    static void UnloadResources();
};

#endif // FONT_H_INCLUDED
