#include "archive.h"

//std::string Archive::returnToTitleString;

int Archive::currentCategory;
int Archive::currentSection;


void Archive::Logic()
{

}

void Archive::Input()
{
    if(Keyboard::keyHoldTicks[Keyboard::KEY_ESC] == 1 || Keyboard::keyHoldTicks[Keyboard::KEY_ENTER] == 1)
    {
        Scene::ChangeScene(Scene::SCENE_TITLE);
    }
}

void Archive::Drawing()
{


    /*
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT,
                             Archive::RETURN_TO_TITLE_TEXT_X, Archive::RETURN_TO_TITLE_TEXT_Y,
                             ALLEGRO_ALIGN_CENTER, Archive::returnToTitleString);
    */


    /*

    for(int i = 0; i < Encyclopedia::NUM_CATEGORIES; i++)
    {
        Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT, CATEGORIES_TABS_X + i*CATEGORIES_TABS_COL_SPACING, CATEGORIES_TABS_Y, ALLEGRO_ALIGN_LEFT, Encyclopedia::categoryTitles.at(i) );
    }

    for(size_t i = 0; i < Encyclopedia::entries.at(currentCategory).size() + 1; i++)
    {
        ///Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT, SECTION_FRAME_X, SECTION_FRAME_Y + i*SECTION_FRAME_ROW_SPACING, ALLEGRO_ALIGN_LEFT, Encyclopedia::entryTitles.at(currentCategory).at(i));
    }


    Hax::string_al_draw_multiline_text(Font::monogram32, COLKEY_TEXT, ENTRY_BUBBLE_X, ENTRY_BUBBLE_Y,
                                       ENTRY_BUBBLE_WIDTH, Font::TEXT_HEIGHT_48,
                                       ALLEGRO_ALIGN_LEFT, Encyclopedia::entries.at(currentCategory).at(currentSection));

    */

}
