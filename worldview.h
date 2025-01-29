#pragma once

#include <vector>
#include <string>

#include "keyboard.h"
#include "mouse.h"

#include "image.h"
#include "font.h"
#include "audio.h"

#include "tile.h"
#include "camera.h"
#include "palette.h"

#include "gamemode.h"
#include "scene.h"
#include "frame.h"

#include "calendar.h"
#include "place.h"
#include "being.h"
#include "caravan.h"

#include "lockon.h"

#include "hax.h"

struct Worldview
{
    static Frame* viewportFrame;
    static Frame* optionsFrame;
    static Frame* optionsButtonsFrame;

    static void Initialize();
    static void Uninitialize();

    static void Logic();
    static void Input();
    static void Drawing();

    static void ProgressWorld();
    static void UpdateUI();

/// Within viewportFrame
    static bool MouseLeftOnCaravanCrewBubble();
    static bool MouseLeftOnCaravanInventoryBubble();
    static bool MouseLeftOnCaravanTradeRecordsBubble();
    static bool MouseLeftOnCaravanPathfindingBubble();

    static bool MouseLeftOnPlacePopulationBubble();
    static bool MouseLeftOnPlaceCaravanseraiBubble();
    static bool MouseLeftOnPlaceSurplusBubble();
    static bool MouseLeftOnPlaceDeficitBubble();
    static bool MouseLeftOnPlaceMarketBubble();
    static bool MouseLeftOnPlaceIndustriesBubble();

/// Within optionsButtonsFrame
    static void MouseLeftOnOptionsButtonsFrame();

    static void SetCameraCenterDestination(float x, float y);
    static void AttemptCameraLockOn();
    static void LockCameraPlace(Place *whichPlace);
    static void LockCameraCaravan(Caravan *whichCaravan);
    static void UnlockCamera();
    static void UnlockCameraCaravan();
    static void UnlockCameraPlace();

    static void DrawGridUnderlay();
    static void DrawGridCameraCrosshair();
    //static void WorldviewDrawGridMouseCrosshair(float mouseZoomedX, float mouseZoomedY);
    static void DrawGridText(float mouseTransformedX, float mouseTransformedY);


};
