#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

//#include <iostream> // debug only
#include <cmath> // abs

#include <allegro5/allegro5.h>

#include "tile.h"
#include "frameindex.h"

/// Note: The camera should try to follow tiles, not follow actors

struct Camera
{
    static ALLEGRO_BITMAP* cameraBuffer;

    static constexpr float SCALE_MIN = 1.0;
    static constexpr float SCALE_MAX = 2.0;

    static ALLEGRO_TRANSFORM identityTransform; // identity transform
    static ALLEGRO_TRANSFORM zoomTransform;

    static float zoomScale;
    static float zoomTranslateX;
    static float zoomTranslateY;

    static bool worldviewCameraMousePanningDisabled;
    static float mouseTransformedX;
    static float mouseTransformedY;

    static bool atDestination;
    static bool approachingDestination;
    static int xCell, yCell;
    static constexpr float MIN_X_POSITION = 0;
    static constexpr float MAX_X_POSITION = 100*Tile::WIDTH;
    static constexpr float MIN_Y_POSITION = 0;
    static constexpr float MAX_Y_POSITION = 100*Tile::HEIGHT;
    static float xPosition, yPosition;
    static float xDestination, yDestination;
    static constexpr float X_SENSITIVITY = 16;
    static constexpr float Y_SENSITIVITY = 16;

    static void Initialize();
    static void Uninitialize();
    static void SetPosition(float x, float y);
    static void SetCell(int x, int y);
    static void SetDestination(float x, float y);
    static void SetDestinationCell(int x, int y);

    static void Logic();

    static void ApproachDestinationLinear(float change);
    static void ApproachDestinationFractional(float change);
    static void WarpToDestination();
};

#endif // CAMERA_H_INCLUDED
