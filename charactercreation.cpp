#include "charactercreation.h"

int CharacterCreation::creationPhase;

PC* CharacterCreation::creation;

int CharacterCreation::appearanceSelection;

int CharacterCreation::creationMode;

void CharacterCreation::Initialize()
{
    creation = new PC();

    RandomizeAll();

    creationPhase = PHASE_SUMMARY;
    creationMode = 0;


    /*
    for(int i = 0; i < 25; i++)
    {
        std::string exampleName = NameIndex::Generate();
        std::cout << exampleName << std::endl;
    }
    */
}

void CharacterCreation::Uninitialize()
{
    delete creation;
}

void CharacterCreation::LogicSwitchboard()
{
    switch(creationPhase)
    {
    case PHASE_ANCESTRY:
        AncestryLogic();
        break;
    case PHASE_CLASS_PRESET:

        break;
    case PHASE_ATTRIBUTES:

        break;
    case PHASE_SKILLS:

        break;
    case PHASE_FEATS:

        break;
    case PHASE_NAME:

        break;

    case PHASE_SUMMARY:
        SummaryLogic();
        break;
    }
}

void CharacterCreation::AncestryLogic()
{

}

void CharacterCreation::SummaryLogic()
{
    creation->ProgressAnimation();
}

void CharacterCreation::InputSwitchboard()
{
    switch(creationPhase)
    {
    case PHASE_ANCESTRY:
        AncestryInput();
        break;
    case PHASE_CLASS_PRESET:

        break;
    case PHASE_ATTRIBUTES:

        break;
    case PHASE_SKILLS:

        break;
    case PHASE_FEATS:

        break;
    case PHASE_NAME:

        break;

    case PHASE_SUMMARY:
        SummaryInput();
        break;
    }
}

void CharacterCreation::AncestryInput()
{
    if(Keyboard::keyHoldTicks[Keyboard::KEY_UP] == 1)
    {

    }
    if(Keyboard::keyHoldTicks[Keyboard::KEY_DOWN] == 1)
    {

    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_LEFT] == 1)
    {

    }
    if(Keyboard::keyHoldTicks[Keyboard::KEY_RIGHT] == 1)
    {

    }
}

void CharacterCreation::SummaryInput()
{
    if(Keyboard::keyHoldTicks[Keyboard::KEY_R] == 1)
    {
        RandomizeAll();
    }

    else if(Keyboard::keyHoldTicks[Keyboard::KEY_ENTER] == 1)
    {
        Scene::ChangeScene(Scene::SCENE_OVERWORLD);
    }
}

void CharacterCreation::DrawingSwitchboard()
{
    switch(creationPhase)
    {
    case PHASE_ANCESTRY:
        AncestryDrawing();
        break;
    case PHASE_CLASS_PRESET:

        break;
    case PHASE_ATTRIBUTES:

        break;
    case PHASE_SKILLS:

        break;
    case PHASE_FEATS:

        break;
    case PHASE_NAME:

        break;

    case PHASE_SUMMARY:
        SummaryDrawing();
        break;
    }
}

void CharacterCreation::AncestryDrawing()
{
    for(size_t i = 0; i < AncestryIndex::NUM_ANCESTRIES; i++)
    {
        Hax::string_al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_VALUE, ANCESTRY_SELECTION_TEXT_X, ANCESTRY_SELECTION_TEXT_Y + i*ANCESTRY_SELECTION_TEXT_SPACING, 0, AncestryIndex::ancestryNames.at(i));
    }

}

void CharacterCreation::SummaryDrawing()
{
    creation->DrawActivity(SUMMARY_CREATION_SPRITE_X,SUMMARY_CREATION_SPRITE_Y);

    al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_LABEL, SUMMARY_NAME_LABEL_TEXT_X, SUMMARY_NAME_TEXT_Y, ALLEGRO_ALIGN_RIGHT, "Name");
    Hax::string_al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_VALUE, SUMMARY_NAME_VALUE_TEXT_X, SUMMARY_NAME_TEXT_Y, ALLEGRO_ALIGN_LEFT, creation->GetName());

    al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_LABEL, SUMMARY_ANCESTRY_LABEL_TEXT_X, SUMMARY_ANCESTRY_TEXT_Y, ALLEGRO_ALIGN_RIGHT, "Ancestry");
    Hax::string_al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_VALUE, SUMMARY_ANCESTRY_VALUE_TEXT_X, SUMMARY_ANCESTRY_TEXT_Y, ALLEGRO_ALIGN_LEFT, AncestryIndex::ancestryNames.at(creation->GetAncestry()));

    al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_LABEL, SUMMARY_ROLE_LABEL_TEXT_X, SUMMARY_ROLE_TEXT_Y, ALLEGRO_ALIGN_RIGHT, "Role");
    Hax::string_al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_VALUE, SUMMARY_ROLE_VALUE_TEXT_X, SUMMARY_ROLE_TEXT_Y, ALLEGRO_ALIGN_LEFT, creation->GetRoleString());


    al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_LABEL, SUMMARY_HOMETOWN_LABEL_TEXT_X, SUMMARY_HOMETOWN_TEXT_Y, ALLEGRO_ALIGN_RIGHT, "Home");
    Hax::string_al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_VALUE, SUMMARY_HOMETOWN_VALUE_TEXT_X, SUMMARY_HOMETOWN_TEXT_Y, ALLEGRO_ALIGN_LEFT, PlaceIndex::placeNames.at(creation->GetHometown()));


    al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_HEADER, SUMMARY_ATTRIBUTE_HEADER_TEXT_X, SUMMARY_ATTRIBUTE_HEADER_TEXT_Y, ALLEGRO_ALIGN_LEFT, "Attributes");
    for(size_t i = 0; i < AttributeIndex::NUM_ATTRIBUTES; i++)
    {
        Hax::string_al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_LABEL, SUMMARY_ATTRIBUTE_LABEL_TEXT_X, SUMMARY_ATTRIBUTE_TEXT_Y + i*SUMMARY_ATTRIBUTE_TEXT_SPACING, ALLEGRO_ALIGN_RIGHT, AttributeIndex::attributeNames.at(i));
        Hax::string_al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_VALUE, SUMMARY_ATTRIBUTE_VALUE_TEXT_X, SUMMARY_ATTRIBUTE_TEXT_Y + i*SUMMARY_ATTRIBUTE_TEXT_SPACING, ALLEGRO_ALIGN_LEFT, creation->attributesString[i]);
    }

    al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_HEADER, SUMMARY_FEATS_HEADER_TEXT_X, SUMMARY_FEATS_HEADER_TEXT_Y, ALLEGRO_ALIGN_LEFT, "Feats");

    int featsTextYOffset = 0;
    for(std::map<int,int>::iterator it = creation->ancestryFeats.begin(); it != creation->ancestryFeats.end(); ++it)
    {
        Hax::string_al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_LABEL,
                                 SUMMARY_FEATS_LABEL_TEXT_X, SUMMARY_FEATS_TEXT_Y + featsTextYOffset, ALLEGRO_ALIGN_LEFT,
                                 FeatIndex::ancestryFeatNames.at((*it).first));
        featsTextYOffset += SUMMARY_FEATS_TEXT_SPACING;
    }
    for(std::map<int,int>::iterator it = creation->roleFeats.begin(); it != creation->roleFeats.end(); ++it)
    {
        Hax::string_al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_LABEL,
                                  SUMMARY_FEATS_LABEL_TEXT_X, SUMMARY_FEATS_TEXT_Y + featsTextYOffset, ALLEGRO_ALIGN_LEFT,
                                   FeatIndex::roleFeatNames.at((*it).first));
        featsTextYOffset += SUMMARY_FEATS_TEXT_SPACING;
    }

    al_draw_text(Font::monogram32, COLKEY_TEXT_HEADER, SUMMARY_SKILLS_HEADER_TEXT_X, SUMMARY_SKILLS_HEADER_TEXT_Y, ALLEGRO_ALIGN_LEFT, "Skills");

    int skillsTextYOffset = 0;
    for(std::map<int,int>::iterator it = creation->totalSkills.begin(); it != creation->totalSkills.end(); ++it)
    {
        Hax::string_al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_LABEL,
                                 SUMMARY_SKILLS_LABEL_TEXT_X, SUMMARY_SKILLS_TEXT_Y + skillsTextYOffset, ALLEGRO_ALIGN_RIGHT,
                                 SkillIndex::skillNames.at((*it).first));

        Hax::string_al_draw_text(Font::monogram32, Palette::COLKEY_TEXT_VALUE,
                                 SUMMARY_SKILLS_VALUE_TEXT_X, SUMMARY_SKILLS_TEXT_Y + skillsTextYOffset, ALLEGRO_ALIGN_LEFT,
                                 creation->totalSkillsString[(*it).first]);

        skillsTextYOffset += SUMMARY_SKILLS_TEXT_SPACING;

        if((*it).first == SkillIndex::BODY_SKILLS_MARKER_END || (*it).first == SkillIndex::MIND_SKILLS_MARKER_END /* || (*it).first == SkillIndex::SPIRIT_SKILLS_MARKER_END */)
            skillsTextYOffset += SUMMARY_SKILLS_TEXT_SPACING;// line break
    }


    al_draw_text(Font::monogram32, COLKEY_TEXT_HEADER, Display::WIDTH/2, Display::HEIGHT - 100, 0, "R: Reroll || Enter: Proceed");
}

void CharacterCreation::RandomizeAll()
{
    creation->SetName(NameIndex::Generate());

    int randomAncestry = rand()%AncestryIndex::NUM_ANCESTRIES;
    creation->SetAncestry(randomAncestry);

    int randomRole = rand()%RoleIndex::NUM_ROLES;
    creation->SetRole(randomRole);

    int randomHometown = rand()%PlaceIndex::NUM_PLACES;
    creation->SetHometown(randomHometown);

    for(int i = 0; i < AttributeIndex::NUM_ATTRIBUTES; i++)
    {
        creation->SetAttribute(i, AncestryIndex::ancestryAttributes.at(randomAncestry).at(i) + RoleIndex::roleAttributeBonus.at(randomRole).at(i));
        //std::cout << BeingIndex::beingAttributeNames.at(i) << " " << BeingIndex::beingAncestryAttributes.at(randomAncestry).at(i) << " + "  << BeingIndex::beingRoleAttributeBonus.at(randomRole).at(i) << std::endl;
    }
}
