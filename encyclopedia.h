#ifndef ENCYCLOPEDIAINDEX_H_INCLUDED
#define ENCYCLOPEDIAINDEX_H_INCLUDED

#include <map>
#include <string>

#include "ancestryindex.h"
#include "roleindex.h"
//#include "sovereigntyindex.h"
#include "placeindex.h"
#include "inventoryindex.h"

struct Encyclopedia
{
    enum enumEncyclopediaCategories
    {
        CATEGORIES_ANCESTRIES = 0,
        CATEGORIES_ROLES = 1,
        CATEGORIES_FACTIONS = 2,
        CATEGORIES_PLACES = 3,
        CATEGORIES_CARGO = 4,
        CATEGORIES_MISC = 5
    };
    static const int CATEGORIES_MARKER_FIRST = CATEGORIES_ANCESTRIES;
    static const int CATEGORIES_MARKER_LAST = CATEGORIES_MISC;
    static const int NUM_CATEGORIES = 6;
    inline static const std::map<int, std::string>categoryTitles =
    {
        {CATEGORIES_ANCESTRIES, "Leykin"},
        {CATEGORIES_ROLES, "Roles"},
        {CATEGORIES_FACTIONS, "Factions"},
        {CATEGORIES_PLACES, "Places"},
        {CATEGORIES_CARGO, "Cargo"},
        {CATEGORIES_MISC, "Misc"}
    };

    static std::map<int, std::map<int, std::string>>entryTitles;

    static std::map<int, std::map<int, std::string>>entries;

    static inline const std::map<int, std::string>encyclopediaFactionLore =
    {
        {SOV_NULL, "This area is not recognized as soverign territory."},
        {SOV_VERUS,"The Republic of Verus is symbolically overseen by a parliament of academics responsible for updating the 'Annual Consensus of Philosophy'. This monolithic, self-contradictory text is a survey of national ideals as voted upon by citizens, and serves as a means for individuals to compare the strength of personal beliefs against the norm. The Consensus regularly conflates moral and physical principles as a matter of style, acknowledging that all understanding can be suborned to the preservation of the Republic's incredibly diverse society. Because the Consensus acts as a standard for discourse, citizens can involve themselves in civic life simply by airing their opinions, the most agreeable of which will invariably become reflected in national writ."},
        {SOV_SHARUMNIR, "Sharumnir Assembly represents the secular leadership of its territories. Its laws are few and succinct, concerned with minimums that every citizen is expected to surpass. Though rarely called for, Sharumnir's justice widely engages community support for the counsel and reconciliation of offenders to victims. /// Sharmunir's religious mission is led by the Apostles, chosen messengers who travel between Yeti communities at home and abroad to deliver sermons of encouragement. The Apostles have no formal powers, but are revered as exemplary practitioners of The Creed."},
        {SOV_XENIA, "Xenia is a desert kingdom occupying the domains of the lost technological civilization Makhia, from whom the present-day Makhii claim descent. Power is exercised through the Four Corners, magi-mechanical thrones that greatly extended their occupants' lifespan. Because the thrones select capable leaders and reject them "},
        {SOV_THOUSAND_ISLES,"The Convocation of The Thousand Isles was originally an economic alliance between the Beyu island states of Reach, Karune and Yulmer, before the advent of tethercraft made "}
    };

    static void ApplyStringConfigurations()
    {
        entries =
        {
            //{CATEGORIES_ANCESTRIES, encyclopediaAncestryLore},
            //{CATEGORIES_ANCESTRIES, leykinLore},
            {CATEGORIES_FACTIONS, encyclopediaFactionLore}
        };


        for(size_t i = AncestryIndex::ANCESTRY_MARKER_FIRST; i <= AncestryIndex::ANCESTRY_MARKER_LAST; i++)
        {
            std::string section = "ancestry " + std::to_string(i);
            entryTitles[CATEGORIES_ANCESTRIES][i] = AncestryIndex::ancestryNames.at(i);
            entries[CATEGORIES_ANCESTRIES][i] = Configuration::ReturnString(Configuration::ancestryCfg, section.c_str(), "lore");
        }

        for(size_t i = RoleIndex::ROLE_MARKER_FIRST; i <= RoleIndex::ROLE_MARKER_LAST; i++)
        {
            std::string section = "role " + std::to_string(i);
            entryTitles[CATEGORIES_ROLES][i] = RoleIndex::roleNames.at(i);
            entries[CATEGORIES_ROLES][i] = Configuration::ReturnString(Configuration::roleCfg, section.c_str(), "lore");
        }


        for(size_t i = InventoryIndex::IT_MARKER_FIRST; i <= InventoryIndex::IT_MARKER_LAST; i++)
        {
            std::string section = "cargo " + std::to_string(i);
            entryTitles[CATEGORIES_CARGO][i] = InventoryIndex::itemNames.at(i);
            entries[CATEGORIES_CARGO][i] = Configuration::ReturnString(Configuration::cargoCfg, section.c_str(), "lore");
        }

        for(size_t i = PlaceIndex::PL_MARKER_FIRST; i <= PlaceIndex::PL_MARKER_LAST; i++)
        {
            std::string section = "place " + std::to_string(i);
            entryTitles[CATEGORIES_PLACES][i] = PlaceIndex::placeNames.at(i);
            entries[CATEGORIES_PLACES][i] = Configuration::ReturnString(Configuration::placeCfg, section.c_str(), "lore");
        }
    }
};

#endif // ENCYCLOPEDIAINDEX_H_INCLUDED
