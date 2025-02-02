#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "timer.h"
#include "scene.h"
#include "event.h"
#include "display.h"
#include "filesystem.h"
#include "image.h"
#include "font.h"
#include "audio.h"
#include "keyboard.h"
#include "mouse.h"
#include "palette.h"
#include "hax.h"

#include "title.h"
#include "worldview.h"
#include "partyview.h"
#include "cargoview.h"
#include "settings.h"
#include "archive.h"
#include "charactercreation.h"

#include "configuration.h"
#include "inventoryindex.h"
#include "placeindex.h"
#include "encyclopedia.h"

struct Game
{
    static bool exit;
    static bool redraw;

    static void MainLoop();

    static bool Initialize(char **argv);
    static void Uninitialize();

    static void InputSwitchboard();
    static void LogicSwitchboard();
    static void DrawingSwitchboard();

};

#endif // GAME_H_INCLUDED
