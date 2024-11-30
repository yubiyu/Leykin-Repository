#ifndef ANCESTRYINDEX_H_INCLUDED
#define ANCESTRYINDEX_H_INCLUDED

#include <map>

#include "attributeindex.h"
#include "featindex.h"
#include "skillindex.h"

struct AncestryIndex
{
    enum enumAncestries
    {
        ANCESTRY_GENERAL = -4,

        ANCESTRY_VERIT = 0,   // Hares of Verus
        ANCESTRY_YETI = 1,    // Greathares of Rumnir
        ANCESTRY_MAKHI = 2,   // Felines of Xenia
        ANCESTRY_BEYU = 3,    // Anglerfish of the thousand isles
        ANCESTRY_MESERA = 4,  // Plants of Hathsera
        ANCESTRY_ORDON = 5,   // Salamanders of Ordozaal
        ANCESTRY_HAPHAE = 6   // Avians of Haphaedee

    };
    static const int ANCESTRY_MARKER_FIRST = ANCESTRY_VERIT;
    static const int ANCESTRY_MARKER_LAST = ANCESTRY_HAPHAE;
    static const int NUM_ANCESTRIES = ANCESTRY_MARKER_LAST+1;

    inline static const std::map<unsigned,std::string>ancestryNames
    {
        {ANCESTRY_GENERAL, "Leykin"},

        {ANCESTRY_VERIT, "Verit"},
        {ANCESTRY_YETI, "Yeti"},
        {ANCESTRY_MAKHI, "Makhi"},
        {ANCESTRY_BEYU, "Beyu"},
        {ANCESTRY_MESERA, "Mesera"},
        {ANCESTRY_ORDON, "Ordon"},
        {ANCESTRY_HAPHAE, "Haphae"}
    };

    inline static const std::map<int, std::array<int,AttributeIndex::NUM_ATTRIBUTES>>ancestryAttributes
    {                     //b, m, s
        {ANCESTRY_VERIT,  { 5, 6, 4}},
        {ANCESTRY_YETI,   { 8, 3, 4}},
        {ANCESTRY_MAKHI,  { 4, 6, 5}},
        {ANCESTRY_BEYU,   { 6, 4, 5}},
        {ANCESTRY_MESERA, { 3, 3, 9}},
        {ANCESTRY_ORDON,  { 7, 5, 2}},
        {ANCESTRY_HAPHAE, { 4, 8, 3}}
    };

    inline static const std::map<int, std::map<int, int>> ancestryFeats
    {
        {ANCESTRY_VERIT,  {{FeatIndex::AN_FEAT_VERIT_INQUISITIVE, 1}}},

        {ANCESTRY_YETI,   {{FeatIndex::AN_FEAT_YETI_WARM_FUR, 1},
                           {FeatIndex::AN_FEAT_YETI_HOSPITALITY, 1}}},

        {ANCESTRY_MAKHI,  {{FeatIndex::AN_FEAT_MAKHI_DESERT_ADAPTATION, 1},
                           {FeatIndex::AN_FEAT_MAKHI_ANCIENT_LINEAGE, 1}}},

        {ANCESTRY_BEYU,   {{FeatIndex::AN_FEAT_BEYU_DISEASE_RESISTANCE, 1},
                           {FeatIndex::AN_FEAT_BEYU_POISON_TOLERANCE, 1}}},

        {ANCESTRY_MESERA, {{FeatIndex::AN_FEAT_MESERA_POWER_PLANT, 1}}},

        {ANCESTRY_ORDON,  {{FeatIndex::AN_FEAT_ORDON_CARAPACE, 1}}},

        {ANCESTRY_HAPHAE, {{FeatIndex::AN_FEAT_HAPHAE_FARSIGHT, 1},
                           {FeatIndex::AN_FEAT_HAPHAE_LIGHTNESS, 1}}}
    };

    inline static const std::map<int, std::map<int, int>> ancestrySkills
    {
        {ANCESTRY_VERIT, {{SkillIndex::SKILL_TRAVEL, 1},
                          {SkillIndex::SKILL_LANGUAGES, 1},
                          {SkillIndex::SKILL_LEADERSHIP, 1}}},

        {ANCESTRY_YETI,  {{SkillIndex::SKILL_TRAVEL, 1},
                          {SkillIndex::SKILL_WEIGHT_LIFTING, 1},
                          {SkillIndex::SKILL_FAITH, 1}}},

        {ANCESTRY_MAKHI, {{SkillIndex::SKILL_NEGOTIATION, 1},
                          {SkillIndex::SKILL_MACHINERY, 1},
                          {SkillIndex::SKILL_LEADERSHIP, 1}}},

        {ANCESTRY_BEYU,  {{SkillIndex::SKILL_BREATH, 1},
                          {SkillIndex::SKILL_MEDICINE, 1},
                          {SkillIndex::SKILL_MUSIC, 1}}},

        {ANCESTRY_MESERA, {{SkillIndex::SKILL_DANCE, 1},
                           {SkillIndex::SKILL_BEAST_TONGUE, 1},
                           {SkillIndex::SKILL_PERCEPTION, 1}}},

        {ANCESTRY_ORDON, {{SkillIndex::SKILL_WEIGHT_LIFTING, 1},
                          {SkillIndex::SKILL_TACTICS, 1},
                          {SkillIndex::SKILL_MACHINERY, 1}}},

        {ANCESTRY_HAPHAE, {{SkillIndex::SKILL_MARKSMANSHIP, 1},
                           {SkillIndex::SKILL_LANGUAGES, 1},
                           {SkillIndex::SKILL_NEGOTIATION, 1}}},

    };
};

#endif // ANCESTRYINDEX_H_INCLUDED
