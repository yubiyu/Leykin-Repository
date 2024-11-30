#ifndef SKILLINDEX_H_INCLUDED
#define SKILLINDEX_H_INCLUDED

#include <map>

struct SkillIndex
{
    enum enumBeingSkills
    {
        //Body skills
        SKILL_BREATH = 0,  // Chant longer spells and resist interruption.
        SKILL_DANCE = 1, // Performances improve the morale of Leykin.
        SKILL_MARKSMANSHIP = 2, // Ranged combat effectiveness.
        SKILL_TRAVEL = 3, // Travel effectively, moving quickly over rough terrain, reducing exposure to elements, and using less food.
        SKILL_WEIGHT_LIFTING = 4, // Wear and wield heavier equipment.

        // Mind skills
        SKILL_LANGUAGES = 5, // Ability to read, write and speak. Leykin naturally know the language of their home domain, but this ability declines with distance.
        SKILL_TACTICS = 6, // Melee combat effectiveness.
        SKILL_NEGOTIATION = 7, // Make better deals.
        SKILL_MEDICINE = 8,  // The effectiveness of medicines and treatments.
        SKILL_MACHINERY = 9, // The effectiveness of tool and vehicle repairs.

        // Spirit skills
        SKILL_BEAST_TONGUE = 10, // Ability to communicate with beasts.
        SKILL_FAITH = 11, // Depth of contact with the divine.
        SKILL_LEADERSHIP = 12, // Ability to gain and influence followers.
        SKILL_MUSIC = 13, // Songs improve the morale of Leykin.
        SKILL_PERCEPTION = 14 // Ability to sense hidden things.
    };
    static const size_t SKILLS_MARKER_BEGIN = SKILL_BREATH;
    static const size_t SKILLS_MARKER_END = SKILL_PERCEPTION;
    static const size_t NUM_SKILLS = SKILLS_MARKER_END+1;
    static const size_t BODY_SKILLS_MARKER_BEGIN = SKILL_BREATH;
    static const size_t BODY_SKILLS_MARKER_END = SKILL_WEIGHT_LIFTING;
    static const size_t NUM_BODY_SKILLS = BODY_SKILLS_MARKER_END+1 - BODY_SKILLS_MARKER_BEGIN;
    static const size_t MIND_SKILLS_MARKER_BEGIN = SKILL_LANGUAGES;
    static const size_t MIND_SKILLS_MARKER_END = SKILL_MACHINERY;
    static const size_t NUM_MIND_SKILLS = MIND_SKILLS_MARKER_END+1 - MIND_SKILLS_MARKER_BEGIN;
    static const size_t SPIRIT_SKILLS_MARKER_BEGIN = SKILL_BEAST_TONGUE;
    static const size_t SPIRIT_SKILLS_MARKER_END = SKILL_PERCEPTION;
    static const size_t NUM_SPIRIT_SKILLS = SPIRIT_SKILLS_MARKER_END+1 - SPIRIT_SKILLS_MARKER_BEGIN;

    static inline const std::map<unsigned,std::string>skillNames
    {
        {SKILL_BREATH, "Breath"},
        {SKILL_DANCE, "Dance"},
        {SKILL_MARKSMANSHIP, "Marksmanship"},
        {SKILL_TRAVEL, "Travel"},
        {SKILL_WEIGHT_LIFTING, "Weight Lifting"},

        {SKILL_LANGUAGES, "Languages"},
        {SKILL_TACTICS, "Tactics"},
        {SKILL_NEGOTIATION, "Negotiation"},
        {SKILL_MEDICINE, "Medicine"},
        {SKILL_MACHINERY, "Machinery"},

        {SKILL_BEAST_TONGUE, "Beast Tongue"},
        {SKILL_FAITH, "Faith"},
        {SKILL_LEADERSHIP, "Leadership"},
        {SKILL_MUSIC, "Music"},
        {SKILL_PERCEPTION, "Perception"}
    };

};

#endif // SKILLINDEX_H_INCLUDED
