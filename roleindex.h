#pragma once

#include "configuration.h"
#include "attributeindex.h"
#include "featindex.h"
#include "skillindex.h"

struct RoleIndex
{
    enum enumRoles
    {
        ROLE_CARAVANEER = 0, // Safety in close cooperation.
        ROLE_MESSENGER = 1,  // Swiftness is security.
        ROLE_PILGRIM = 2,    // Wandering seekers of enlightenment.
        ROLE_EXILE = 3,      // Survivalists by necessity.
        ROLE_BANDIT = 4,     // The bane of travellers.
        ROLE_WARRIOR = 5,    // The study of arms.
        ROLE_BEASTKIN = 6,     // Specialists at subduing beasts.
        ROLE_APOSTLE = 7,    // Servants of the gods.
        ROLE_MERCHANT = 8,   // Profits by exchange.
        ROLE_HEALER = 9,     // Menders and curers.
        ROLE_MINSTREL = 10,  // The rhythm of life.
        ROLE_DANCER = 11     // The world is a stage.
    };
    static const int ROLE_MARKER_FIRST = ROLE_CARAVANEER;
    static const int ROLE_MARKER_LAST = ROLE_DANCER;
    static const int NUM_ROLES = ROLE_MARKER_LAST+1;

    static std::map<int, std::string>roleNames;

    /*
    inline static const std::map<unsigned,std::string>roleNames
    {
        {ROLE_CARAVANEER, "Caravaneer"},
        {ROLE_MESSENGER, "Messenger"},
        {ROLE_PILGRIM, "Pilgrim"},
        {ROLE_EXILE, "Exile"},
        {ROLE_BANDIT, "Bandit"},
        {ROLE_WARRIOR, "Warrior"},
        {ROLE_BEASTKIN, "Beastkin"},
        {ROLE_APOSTLE, "Apostle"},
        {ROLE_MERCHANT, "Merchant"},
        {ROLE_HEALER, "Healer"},
        {ROLE_MINSTREL, "Minstrel"},
        {ROLE_DANCER, "Dancer"}
    };
    */

    inline static const std::map<int, std::array<int, AttributeIndex::NUM_ATTRIBUTES>>roleAttributeBonus
    {                        //b  m  s
        {ROLE_CARAVANEER,     {2, 3, 5}},
        {ROLE_MESSENGER,      {3, 3, 4}},
        {ROLE_PILGRIM,        {0, 4, 6}},
        {ROLE_EXILE,          {4, 4, 2}},
        {ROLE_BANDIT,         {5, 2, 3}},
        {ROLE_WARRIOR,        {7, 2, 1}},
        {ROLE_BEASTKIN,         {3, 5, 2}},
        {ROLE_APOSTLE,        {0, 1, 9}},
        {ROLE_MERCHANT,       {1, 5, 4}},
        {ROLE_HEALER,         {1, 5, 4}},
        {ROLE_MINSTREL,       {0, 3, 7}},
        {ROLE_DANCER,         {3, 1, 6}}
    };

    inline static const std::map<int, std::map<int, int>> roleFeats
    {
        {ROLE_CARAVANEER,  {{FeatIndex::ROLE_FEAT_CARAVANEER_COZY_CAMP, 1}}},
        {ROLE_MESSENGER,   {{FeatIndex::ROLE_FEAT_MESSENGER_HASTE, 1}}},
        {ROLE_PILGRIM,     {{FeatIndex::ROLE_FEAT_PILGRIM_GUIDANCE, 1}}},
        {ROLE_EXILE,       {{FeatIndex::ROLE_FEAT_EXILE_WASTEWALKER, 1}}},
        {ROLE_BANDIT,      {{FeatIndex::ROLE_FEAT_BANDIT_INTIMIDATION, 1}}},
        {ROLE_WARRIOR,     {{FeatIndex::ROLE_FEAT_WARRIOR_RESOLUTE, 1}}},
        {ROLE_BEASTKIN,      {{FeatIndex::ROLE_FEAT_BEASTKIN_PREPARATION, 1}}},
        {ROLE_APOSTLE,     {{FeatIndex::ROLE_FEAT_APOSTLE_GREATER_PURPOSE, 1}}},
        {ROLE_MERCHANT,    {{FeatIndex::ROLE_FEAT_MERCHANT_APPRAISAL, 1}}},
        {ROLE_HEALER,      {{FeatIndex::ROLE_FEAT_HEALER_PREVENTATIVE_MEASURES, 1}}},
        {ROLE_MINSTREL,    {{FeatIndex::ROLE_FEAT_MINSTREL_SECRET_CHORD, 1}}},
        {ROLE_DANCER,      {{FeatIndex::ROLE_FEAT_DANCER_SENSE_AFFINITY, 1}}}
    };

    inline static const std::map<int, std::map<int, int>> roleSkills
    {
        {ROLE_CARAVANEER, {{SkillIndex::SKILL_TRAVEL, 1},
                           {SkillIndex::SKILL_WEIGHT_LIFTING, 1},
                           {SkillIndex::SKILL_BEAST_TONGUE, 1},
                           {SkillIndex::SKILL_LEADERSHIP, 2}}},

        {ROLE_MESSENGER,   {{SkillIndex::SKILL_BREATH, 1},
                            {SkillIndex::SKILL_TRAVEL, 1},
                            {SkillIndex::SKILL_LANGUAGES, 2},
                            {SkillIndex::SKILL_BEAST_TONGUE, 1}}},

        {ROLE_PILGRIM,    {{SkillIndex::SKILL_LANGUAGES, 1},
                           {SkillIndex::SKILL_MEDICINE, 1},
                           {SkillIndex::SKILL_FAITH, 1},
                           {SkillIndex::SKILL_PERCEPTION, 2}}},

        {ROLE_EXILE,      {{SkillIndex::SKILL_TRAVEL, 2},
                           {SkillIndex::SKILL_MEDICINE, 1},
                           {SkillIndex::SKILL_MACHINERY, 1},
                           {SkillIndex::SKILL_PERCEPTION, 1}}},

        {ROLE_BANDIT,     {{SkillIndex::SKILL_WEIGHT_LIFTING, 1},
                           {SkillIndex::SKILL_TACTICS, 2},
                           {SkillIndex::SKILL_NEGOTIATION, 1},
                           {SkillIndex::SKILL_MACHINERY, 1}}},

        {ROLE_WARRIOR,    {{SkillIndex::SKILL_MARKSMANSHIP, 1},
                           {SkillIndex::SKILL_WEIGHT_LIFTING, 2},
                           {SkillIndex::SKILL_TACTICS, 1},
                           {SkillIndex::SKILL_LEADERSHIP, 1}}},

        {ROLE_BEASTKIN,     {{SkillIndex::SKILL_DANCE, 1},
                           {SkillIndex::SKILL_MARKSMANSHIP, 1},
                           {SkillIndex::SKILL_BEAST_TONGUE, 2},
                           {SkillIndex::SKILL_PERCEPTION, 1}}},

        {ROLE_APOSTLE,    {{SkillIndex::SKILL_BREATH, 1},
                           {SkillIndex::SKILL_LANGUAGES, 1},
                           {SkillIndex::SKILL_FAITH, 2},
                           {SkillIndex::SKILL_MUSIC, 1}}},

        {ROLE_MERCHANT,   {{SkillIndex::SKILL_LANGUAGES, 1},
                           {SkillIndex::SKILL_NEGOTIATION, 2},
                           {SkillIndex::SKILL_LEADERSHIP, 1},
                           {SkillIndex::SKILL_PERCEPTION, 1}}},

        {ROLE_HEALER,     {{SkillIndex::SKILL_MEDICINE, 2},
                           {SkillIndex::SKILL_MACHINERY, 1},
                           {SkillIndex::SKILL_BEAST_TONGUE, 1},
                           {SkillIndex::SKILL_FAITH, 1}}},

        {ROLE_MINSTREL,   {{SkillIndex::SKILL_LANGUAGES, 1},
                           {SkillIndex::SKILL_MACHINERY, 1},
                           {SkillIndex::SKILL_FAITH, 1},
                           {SkillIndex::SKILL_MUSIC, 2}}},

        {ROLE_DANCER,     {{SkillIndex::SKILL_DANCE, 2},
                           {SkillIndex::SKILL_MARKSMANSHIP, 1},
                           {SkillIndex::SKILL_NEGOTIATION, 1},
                           {SkillIndex::SKILL_LEADERSHIP, 1}}}

    };

    static void ApplyStringConfigurations()
    {
        for(unsigned i = ROLE_MARKER_FIRST; i <= ROLE_MARKER_LAST; i++)
        {
            std::string section = "role " + std::to_string(i);
            roleNames[i] = Configuration::ReturnString(Configuration::roleCfg, section.c_str(), "name");
        }
    }

};
