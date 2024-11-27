#pragma once

#include "keyboard.h"

#include "beingIndex.h"

#include "font.h"
#include "palette.h"

#include "pc.h"

#include "hax.h"

struct CharacterCreation
{
    enum enumCreationPhase
    {
        PHASE_ANCESTRY = 0, // Ancestry, basic appearance.
        PHASE_CLASS_PRESET = 1, // Determines initial attributes and skills, but both can be freely modified.
        PHASE_ATTRIBUTES = 2, // Manually customize attributes.
        PHASE_SKILLS = 3, // Manually customize skills.
        PHASE_FEATS = 4, // Manually customize feats.
        PHASE_NAME = 5,
        PHASE_SUMMARY = 6 // All of the above.
    };
    static int creationPhase;

    static PC* creation;

    static const int ANCESTRY_SELECTION_TEXT_X = Display::WIDTH*5/40;
    static const int ANCESTRY_SELECTION_TEXT_Y = Display::HEIGHT*5/30;
    static const int ANCESTRY_SELECTION_TEXT_SPACING = Font::TEXT_HEIGHT_32;

    static int appearanceSelection;

    static constexpr float SUMMARY_CREATION_SPRITE_X = Display::WIDTH*5/40;
    static constexpr float SUMMARY_CREATION_SPRITE_Y = Display::HEIGHT*5/30;

    static const int SUMMARY_NAME_LABEL_TEXT_X = Display::WIDTH*5/40;
    static const int SUMMARY_NAME_VALUE_TEXT_X = Display::WIDTH*6/40;
    static const int SUMMARY_NAME_TEXT_Y = Display::HEIGHT*7/30;

    static const int SUMMARY_ANCESTRY_LABEL_TEXT_X = Display::WIDTH*5/40;
    static const int SUMMARY_ANCESTRY_VALUE_TEXT_X = Display::WIDTH*6/40;
    static const int SUMMARY_ANCESTRY_TEXT_Y = Display::HEIGHT*8/30;

    static const int SUMMARY_ROLE_LABEL_TEXT_X = Display::WIDTH*5/40;
    static const int SUMMARY_ROLE_VALUE_TEXT_X = Display::WIDTH*6/40;
    static const int SUMMARY_ROLE_TEXT_Y = Display::HEIGHT*9/30;

    static const int SUMMARY_HOMETOWN_LABEL_TEXT_X = Display::WIDTH*5/40;
    static const int SUMMARY_HOMETOWN_VALUE_TEXT_X = Display::WIDTH*6/40;
    static const int SUMMARY_HOMETOWN_TEXT_Y = Display::HEIGHT*10/30;

    static const int SUMMARY_ATTRIBUTE_HEADER_TEXT_X = Display::WIDTH*1/40;
    static const int SUMMARY_ATTRIBUTE_HEADER_TEXT_Y = Display::HEIGHT*12/30;
    static const int SUMMARY_ATTRIBUTE_LABEL_TEXT_X = Display::WIDTH*5/40; // Align right
    static const int SUMMARY_ATTRIBUTE_VALUE_TEXT_X = Display::WIDTH*6/40; // Align left
    static const int SUMMARY_ATTRIBUTE_TEXT_Y = Display::HEIGHT*13/30;
    static const int SUMMARY_ATTRIBUTE_TEXT_SPACING = Display::HEIGHT*1/30;

    static const int SUMMARY_FEATS_HEADER_TEXT_X = Display::WIDTH*1/40;
    static const int SUMMARY_FEATS_HEADER_TEXT_Y = Display::HEIGHT*17/30;
    static const int SUMMARY_FEATS_LABEL_TEXT_X = Display::WIDTH*3/40;
    //static const int SUMMARY_FEATS_VALUE_TEXT_X = Display::WIDTH*6/40;
    static const int SUMMARY_FEATS_TEXT_Y = Display::HEIGHT*18/30;
    static const int SUMMARY_FEATS_TEXT_SPACING = Display::HEIGHT*1/30;

    static const int SUMMARY_SKILLS_HEADER_TEXT_X = Display::WIDTH*25/40;
    static const int SUMMARY_SKILLS_HEADER_TEXT_Y = Display::HEIGHT*5/30;

    static int creationMode;
    enum enumCreationModes
    {
        CREATION_MODE_QUESTION = 0,
        CREATION_MODE_CHOOSE_PRESET = 1,
        CREATION_MODE_CHOOSE_CUSTOM = 2
    };

    static void Initialize();
    static void Uninitialize();

    static void LogicSwitchboard();
    static void AncestryLogic();
    static void SummaryLogic();

    static void InputSwitchboard();
    static void AncestryInput();
    static void SummaryInput();

    static void DrawingSwitchboard();
    static void AncestryDrawing();
    static void SummaryDrawing();

    static void RandomizeAll();

};
