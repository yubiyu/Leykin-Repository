#include "font.h"

ALLEGRO_FONT* Font::builtin8;
ALLEGRO_FONT* Font::monogram16;
ALLEGRO_FONT* Font::monogram24;
ALLEGRO_FONT* Font::monogram32;

void Font::Initialize()
{
    al_init_font_addon();
    al_init_ttf_addon();
    LoadResources();
}

void Font::Uninitialize()
{
    UnloadResources();
    al_shutdown_ttf_addon();
    al_shutdown_font_addon();
}

void Font::LoadResources()
{
    builtin8 = al_create_builtin_font();
    monogram16 = al_load_font("monogram.ttf", 16, 0);
    monogram24 = al_load_font("monogram.ttf", 24, 0);
    monogram32 = al_load_font("monogram.ttf", 32, 0);
}

void Font::UnloadResources()
{
    al_destroy_font(builtin8);
    al_destroy_font(monogram16);
    al_destroy_font(monogram24);
    al_destroy_font(monogram32);
}
