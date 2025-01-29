#include "image.h"

//ALLEGRO_BITMAP* Image::genericTitlePng;
//ALLEGRO_BITMAP* Image::genericWorldviewPng;
//ALLEGRO_BITMAP* Image::genericResultsPng;
//ALLEGRO_BITMAP* Image::genericBeingPng;
//ALLEGRO_BITMAP* Image::genericTilePng;

ALLEGRO_BITMAP* Image::titleOptionMarkerPng;
ALLEGRO_BITMAP* Image::settingsVolumeBarPng;
ALLEGRO_BITMAP* Image::settingsVolumeBarEmptyPng;

ALLEGRO_BITMAP* Image::worldviewPlacePng;

ALLEGRO_BITMAP* Image::beingsPng;
ALLEGRO_BITMAP* Image::beingsSub[AncestryIndex::NUM_ANCESTRIES];

ALLEGRO_BITMAP* Image::expertiseIconPng;

ALLEGRO_BITMAP* Image::miniCargoPng;
ALLEGRO_BITMAP* Image::cargoPng;
ALLEGRO_BITMAP* Image::cargoSub[InventoryIndex::NUM_ITEMS];

ALLEGRO_BITMAP* Image::redArrowPng;
ALLEGRO_BITMAP* Image::redTransparentXPng;

void Image::Initialize()
{
    al_init_image_addon();
    al_init_primitives_addon();

    LoadResources();
}

void Image::Uninitialize()
{
    UnloadResources();
    al_shutdown_primitives_addon();
    al_shutdown_image_addon();
}

void Image::LoadResources()
{
    //genericTitlePng = al_load_bitmap("genericTitlePng.png");
    //genericWorldviewPng = al_load_bitmap("genericWorldviewPng.png");
    //genericResultsPng = al_load_bitmap("genericResultsPng.png");
    //genericBeingPng = al_load_bitmap("genericBeingPng.png");
    //genericTilePng = al_load_bitmap("genericTilePng.png");

    titleOptionMarkerPng = al_load_bitmap("titleOptionMarker.png");
    settingsVolumeBarPng = al_load_bitmap("settingsVolumeBar.png");
    settingsVolumeBarEmptyPng = al_load_bitmap("settingsVolumeBarEmpty.png");

    worldviewPlacePng = al_load_bitmap("placeholderWorldviewPlace.png");

    beingsPng = al_load_bitmap("placeholderBeings.png");

    for(size_t i = AncestryIndex::ANCESTRY_MARKER_FIRST; i <= AncestryIndex::ANCESTRY_MARKER_LAST; i++)
    {
        beingsSub[i] = al_create_sub_bitmap(beingsPng,
                                           0,
                                           i*Tile::HEIGHT,
                                           Tile::WIDTH * beingNumWalkFrames * beingNumSpriteVariants.at(i),
                                           Tile::HEIGHT);
    }

    expertiseIconPng = al_load_bitmap("placeholderExpertiseIcon.png");

    miniCargoPng = al_load_bitmap("placeholderMiniCargo.png");
    cargoPng = al_load_bitmap("placeholderCargo.png");
    for(size_t i = InventoryIndex::IT_MARKER_FIRST; i <= InventoryIndex::IT_MARKER_LAST; i++)
    {
        cargoSub[i] = al_create_sub_bitmap(cargoPng,
                                           i*Tile::WIDTH, 0,
                                           Tile::WIDTH, Tile::HEIGHT);
    }

    redArrowPng = al_load_bitmap("placeholderRedArrow.png");
    redTransparentXPng = al_load_bitmap("placeholderRedTransparentX.png");
}

void Image::UnloadResources()
{
    //al_destroy_bitmap(genericTitlePng);
    //al_destroy_bitmap(genericWorldviewPng);
    //al_destroy_bitmap(genericResultsPng);
    //al_destroy_bitmap(genericBeingPng);
    //al_destroy_bitmap(genericTilePng);

    al_destroy_bitmap(titleOptionMarkerPng);
    al_destroy_bitmap(settingsVolumeBarPng);
    al_destroy_bitmap(settingsVolumeBarEmptyPng);

    al_destroy_bitmap(worldviewPlacePng);

    for(size_t i = 0; i <= AncestryIndex::ANCESTRY_MARKER_LAST; i++)
        al_destroy_bitmap(beingsSub[i]);
    al_destroy_bitmap(beingsPng);

    al_destroy_bitmap(expertiseIconPng);

    for(size_t i = 0; i <= InventoryIndex::IT_MARKER_LAST; i++)
        al_destroy_bitmap(cargoSub[i]);
    al_destroy_bitmap(miniCargoPng);
    al_destroy_bitmap(cargoPng);

    al_destroy_bitmap(redArrowPng);
    al_destroy_bitmap(redTransparentXPng);
}

