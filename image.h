#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include "tile.h"
#include "ancestryindex.h"
#include "inventoryindex.h"

struct Image
{
    //static ALLEGRO_BITMAP *genericTitlePng;
    //static ALLEGRO_BITMAP *genericWorldviewPng;
    //static ALLEGRO_BITMAP *genericResultsPng;
    //static ALLEGRO_BITMAP *genericBeingPng;
    //static ALLEGRO_BITMAP *genericTilePng;

    static ALLEGRO_BITMAP *titleOptionMarkerPng;
    static ALLEGRO_BITMAP *settingsVolumeBarPng;
    static ALLEGRO_BITMAP *settingsVolumeBarEmptyPng;

    static ALLEGRO_BITMAP *worldviewPlacePng;

    static const unsigned beingNumWalkFrames = 2;
    static const inline std::map<unsigned,unsigned>beingNumSpriteVariants =
    {
        // In total. Not counting from zero.
        {AncestryIndex::ANCESTRY_VERIT, 4},
        {AncestryIndex::ANCESTRY_YETI, 2},
        {AncestryIndex::ANCESTRY_MAKHI, 3},
        {AncestryIndex::ANCESTRY_BEYU, 2},
        {AncestryIndex::ANCESTRY_MESERA, 2},
        {AncestryIndex::ANCESTRY_ORDON, 2},
        {AncestryIndex::ANCESTRY_HAPHAE, 2}
    };

    static ALLEGRO_BITMAP *beingsPng;
    static ALLEGRO_BITMAP *beingsSub[AncestryIndex::NUM_ANCESTRIES];

    static ALLEGRO_BITMAP *expertiseIconPng;

    static ALLEGRO_BITMAP *miniCargoPng;
    static ALLEGRO_BITMAP *cargoPng;
    static ALLEGRO_BITMAP *cargoSub[InventoryIndex::NUM_ITEMS];


    static ALLEGRO_BITMAP *redArrowPng;
    static ALLEGRO_BITMAP *redTransparentXPng;

    static void Initialize();
    static void Uninitialize();

    static void LoadResources();
    static void UnloadResources();
};
