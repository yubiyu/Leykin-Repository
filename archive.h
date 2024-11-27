#ifndef ARCHIVE_H_INCLUDED
#define ARCHIVE_H_INCLUDED

#include "display.h"
#include "keyboard.h"

#include "font.h"

#include "scene.h"
#include "encyclopedia.h"

#include "palette.h"
#include "hax.h"

#include <allegro5/allegro_primitives.h>

#include <string>
#include <cmath>

struct Archive
{
    static inline std::string returnToTitleString = "Press [ESC / Enter] to return to title.";

    static const int RETURN_TO_TITLE_TEXT_X = Display::WIDTH/2;
    static const int RETURN_TO_TITLE_TEXT_Y = Display::HEIGHT/2;

    static constexpr float CATEGORIES_TABS_X = Display::WIDTH*4/40;
    static constexpr float CATEGORIES_TABS_Y = Display::HEIGHT*4/25;
    static constexpr float CATEGORIES_TABS_COL_SPACING = Display::WIDTH*4/40;

    static constexpr float SECTION_FRAME_X = CATEGORIES_TABS_X;
    static constexpr float SECTION_FRAME_Y = CATEGORIES_TABS_Y + Display::HEIGHT*2/25;
    static constexpr float SECTION_FRAME_ROW_SPACING = Display::WIDTH*1/40;

    static constexpr float ENTRY_BUBBLE_X = Display::WIDTH*20/40;
    static constexpr float ENTRY_BUBBLE_Y = CATEGORIES_TABS_Y + Display::HEIGHT*2/25;
    static constexpr float ENTRY_BUBBLE_WIDTH  = Display::WIDTH* 18/40;

    static int currentCategory;
    static int currentSection;

    static void Initialize()
    {
        currentCategory = Encyclopedia::CATEGORIES_MARKER_FIRST;
        currentSection = 0;
    }

    static void ChangeCategory(int which_category);
    static void ChangeSection(int which_section);

    static void Logic();
    static void Input();
    static void Drawing();
};

#endif // ARCHIVE_H_INCLUDED
