#ifndef FEATINDEX_H_INCLUDED
#define FEATINDEX_H_INCLUDED

#include <map>

struct FeatIndex
{
    enum enumAncestryFeats
    {
        AN_FEAT_VERIT_INQUISITIVE,

        AN_FEAT_YETI_WARM_FUR,
        AN_FEAT_YETI_HOSPITALITY,

        AN_FEAT_MAKHI_DESERT_ADAPTATION,
        AN_FEAT_MAKHI_ANCIENT_LINEAGE,

        AN_FEAT_BEYU_DISEASE_RESISTANCE,
        AN_FEAT_BEYU_POISON_TOLERANCE,

        AN_FEAT_MESERA_POWER_PLANT,

        AN_FEAT_ORDON_CARAPACE,
        AN_FEAT_ORDON_DARKVISION,

        AN_FEAT_HAPHAE_FARSIGHT,
        AN_FEAT_HAPHAE_LIGHTNESS
    };

    inline static const std::map<unsigned,std::string>ancestryFeatNames
    {
        {AN_FEAT_VERIT_INQUISITIVE, "Inquisitive"},

        {AN_FEAT_YETI_WARM_FUR, "Warm Fur"},
        {AN_FEAT_YETI_HOSPITALITY, "Hospitality"},

        {AN_FEAT_MAKHI_DESERT_ADAPTATION, "Desert Adaptation"},
        {AN_FEAT_MAKHI_ANCIENT_LINEAGE, "Ancient Lineage"},

        {AN_FEAT_BEYU_DISEASE_RESISTANCE, "Disease Resistant"},
        {AN_FEAT_BEYU_POISON_TOLERANCE, "Poison Tolerance"},

        {AN_FEAT_MESERA_POWER_PLANT, "Power Plant"},

        {AN_FEAT_ORDON_CARAPACE, "Carapace"},
        {AN_FEAT_ORDON_DARKVISION, "Darkvision"},

        {AN_FEAT_HAPHAE_FARSIGHT, "Farsight"},
        {AN_FEAT_HAPHAE_LIGHTNESS, "Lightness"}
    };

    enum enumRoleFeats
    {
        ROLE_FEAT_CARAVANEER_COZY_CAMP,

        ROLE_FEAT_MESSENGER_HASTE,

        ROLE_FEAT_PILGRIM_GUIDANCE,

        ROLE_FEAT_EXILE_WASTEWALKER,

        ROLE_FEAT_BANDIT_INTIMIDATION,

        ROLE_FEAT_WARRIOR_RESOLUTE,

        ROLE_FEAT_HUNTER_PREPARATION,

        ROLE_FEAT_APOSTLE_GREATER_PURPOSE,

        ROLE_FEAT_MERCHANT_APPRAISAL,

        ROLE_FEAT_HEALER_PREVENTATIVE_MEASURES,

        ROLE_FEAT_MINSTREL_SECRET_CHORD,

        ROLE_FEAT_DANCER_GRACE
    };

    inline static const std::map<unsigned, std::string>roleFeatNames
    {
        {ROLE_FEAT_CARAVANEER_COZY_CAMP, "Cozy Camp"},
        {ROLE_FEAT_MESSENGER_HASTE, "Haste"},
        {ROLE_FEAT_PILGRIM_GUIDANCE, "Guidance"},
        {ROLE_FEAT_EXILE_WASTEWALKER, "Wastewalker"},
        {ROLE_FEAT_BANDIT_INTIMIDATION, "Intimidation"},
        {ROLE_FEAT_WARRIOR_RESOLUTE, "Resolute"},
        {ROLE_FEAT_HUNTER_PREPARATION, "Preparation"},
        {ROLE_FEAT_APOSTLE_GREATER_PURPOSE, "Greater Purpose"},
        {ROLE_FEAT_MERCHANT_APPRAISAL, "Appraisal"},
        {ROLE_FEAT_HEALER_PREVENTATIVE_MEASURES, "Preventative Measures"},
        {ROLE_FEAT_MINSTREL_SECRET_CHORD, "Secret Chord"},
        {ROLE_FEAT_DANCER_GRACE, "Grace"}
    };

};

#endif // FEATINDEX_H_INCLUDED
