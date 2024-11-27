#ifndef SKILLINDEX_H_INCLUDED
#define SKILLINDEX_H_INCLUDED

#include <map>

struct skillIndex
{
    enum enumBeingSkills
    {
        SKILL_COLD_ADAPTATION,
        SKILL_HEAT_ADAPTATION,
        SKILL_TRAVEL,
        SKILL_BREATH,
        SKILL_WEIGHT_LIFTING,

        SKILL_LANGUAGES
        SKILL_TACTICS,
        SKILL_NEGOTIATION,
        SKILL_MEDICINE,
        SKILL_MACHINERY,

        SKILL_RIDING,
        SKILL_FAITH,
        SKILL_MUSIC,
        SKILL_DANCE,
        SKILL_PERCEPTION
    };

    inline static const std::map<unsigned,std::string>skillNames
    {

    };

};

#endif // SKILLINDEX_H_INCLUDED
