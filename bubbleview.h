#pragma once

#include <string>

#include <allegro5/allegro_primitives.h>

#include "display.h"

#include "tile.h"

#include "gamemode.h"

#include "encyclopedia.h"

class Place;

#include "being.h"
class Being;

#include "caravan.h"
class Caravan;

struct BubbleView
{
    static Caravan* currentCaravan;
    static Place* currentPlace;
    static Being* currentBeing;

    static bool beingStatusBubbleOpen;
    static bool encyclopediaBubbleOpen;

    static constexpr float bubblePadding = Tile::WIDTH/4;
    static constexpr float bubbleCornerRadius = 8;

    /// Being status bubble
    static constexpr float beingStatusBubbleDrawX = Display::WIDTH*12/40;
    static constexpr float beingStatusBubbleDrawY = Display::HEIGHT*9/30;
    static constexpr float beingStatusBubbleWidth  = Tile::WIDTH*5;
    static constexpr float beingStatusBubbleBiographyPartitionHeight = 0;                                                              // Two text lines: Name, Hometown
    static constexpr float beingStatusBubbleStatsPartitionHeight = beingStatusBubbleBiographyPartitionHeight + Font::TEXT_HEIGHT_12*2; // Three icons + bars: vitality, happiness, purpose
    static constexpr float beingStatusBubbleObjectivesPartitionHeight = beingStatusBubbleStatsPartitionHeight + Tile::HEIGHT*3;        // Three text lines: Objective A, B, C
    static constexpr float beingStatusBubbleHeight = beingStatusBubbleObjectivesPartitionHeight + Font::TEXT_HEIGHT_12*3;

    /// Caravan bubbles
    static inline const std::string caravanCrewBubbleHeader = "Crew:";
    static inline const std::string caravanCrewBubbleEmptyText = "<No Crew>"; // Though this ought not to pop up for more than one tick, since the caravan should disband and delete.
    static constexpr float caravanCrewBubbleDrawX = Display::WIDTH*1/40;
    static constexpr float caravanCrewBubbleDrawY = Display::HEIGHT*1/30;
    static constexpr float caravanCrewBubbleHeight = Tile::HEIGHT;
    static float caravanCrewBubbleWidth;

    static inline const std::string caravanInventoryBubbleHeader = "Cargo:";
    static inline const std::string caravanInventoryBubbleEmptyText = "<No cargo carried>";
    static constexpr float caravanInventoryBubbleDrawX = Display::WIDTH*1/40;
    static constexpr float caravanInventoryBubbleDrawY = Display::HEIGHT*6/30;
    static constexpr float caravanInventoryBubbleRowSpacing = Font::TEXT_HEIGHT_8;
    static constexpr float caravanInventoryBubbleBaseCols = 10;
    static constexpr float caravanInventoryBubbleBaseRows = 1;
    static unsigned caravanInventoryBubbleNumCols;
    static unsigned caravanInventoryBubbleNumRows;
    static float caravanInventoryBubbleWidth, caravanInventoryBubbleHeight;

    static inline const std::string caravanTradeRecordsBubbleHeader = "Trade Records:";
    static inline const std::string caravanTradeRecordsBubbleEmptyText = "<No records>";
    static inline const std::string caravanTradeRecordsBubbleNoTransactionText = "<No transaction>";
    static constexpr float caravanTradeRecordsBubbleDrawX = Display::WIDTH* 1/40;
    static constexpr float caravanTradeRecordsBubbleDrawY = Display::HEIGHT* 11/30;
    static constexpr float caravanTradeRecordsBubbleRowSpacing = Font::TEXT_HEIGHT_8;
    static constexpr unsigned caravanTradeRecordsBubbleBaseRows = 1;
    static constexpr unsigned caravanTradeRecordsBubbleNumIconCols = 7;
    static constexpr float caravanTradeRecordsBubbleWidth = Tile::WIDTH*10;
    static constexpr float caravanTradeRecordsBubblePlaceNameWidth = Tile::WIDTH*3;
    static unsigned caravanTradeRecordsBubbleNumRows;
    static float caravanTradeRecordsBubbleHeight;

    static inline const std::string caravanPathfindingBubbleHeader = "Pathfinding:";
    static inline const std::string caravanPathfindingBubbleEmptyText = "<None>";
    static constexpr float caravanPathfindingBubbleColSpacing = Tile::WIDTH;
    static constexpr float caravanPathfindingBubbleRowSpacing = Font::TEXT_HEIGHT_8;
    static constexpr float caravanPathfindingBubbleDrawX = Display::WIDTH*1/40;
    static constexpr float caravanPathfindingBubbleDrawY = Display::HEIGHT*22/30;
    static constexpr unsigned caravanPathfindingBubbleBaseCols = 1;
    static constexpr unsigned caravanPathfindingBubbleBaseRows = 1;
    static unsigned caravanPathfindingBubbleNumCols;
    static unsigned caravanPathfindingBubbleNumRows;
    static float caravanPathfindingBubbleWidth, caravanPathfindingBubbleHeight;

    /// Place bubbles
    static inline const std::string placePopulationBubbleHeader = "Population";
    static inline const std::string placePopulationBubbleEmptyText = "<None>";
    static constexpr float placePopulationBubbleDrawX = Display::WIDTH*26/40;
    static constexpr float placePopulationBubbleDrawY = Display::HEIGHT*1/30;
    static constexpr int placePopulationBubbleBaseCols = 1;
    static constexpr float placePopulationBubbleHeight = Tile::HEIGHT;
    static float placePopulationBubbleWidth;
    static unsigned placePopulationBubbleNumCols;


    static inline const std::string placeCaravanseraiHeader = "Caravanserai";
    static inline const std::string placeCaravanseraiEmptyText = "<Empty>";
    static constexpr float placeCaravanseraiDrawX = Display::WIDTH*33/40;
    static constexpr float placeCaravanseraiDrawY = Display::HEIGHT*14/30;
    static constexpr unsigned placeCaravanseraiBaseCols = 6;
    static constexpr unsigned placeCaravanseraiBaseRows = 1;
    static unsigned placeCaravanseraiNumCols;
    static unsigned placeCaravanseraiNumRows;
    static float placeCaravanseraiWidth;
    static float placeCaravanseraiHeight;


    static inline const std::string placeSurplusBubbleHeader = "Surplus";
    static constexpr float placeSurplusBubbleDrawX = Display::WIDTH*33/40;
    static constexpr float placeSurplusBubbleDrawY = Display::HEIGHT* 6/30;
    static constexpr unsigned placeSurplusBubbleBaseCols = 1;
    static constexpr unsigned placeSurplusBubbleBaseRows = 1;
    static constexpr unsigned placeSurplusBubbleMaxRows = 6;
    static unsigned placeSurplusBubbleNumCols, placeSurplusBubbleNumRows;
    static float placeSurplusBubbleWidth, placeSurplusBubbleHeight; // Width extended by Tile::WIDTH*1.5 in UpdateplaceSurplusBubble()


    static inline const std::string placeDeficitBubbleHeader = "Deficit";
    static constexpr float placeDeficitBubbleDrawX = Display::WIDTH*37/40 - Tile::WIDTH/2;
    static constexpr float placeDeficitBubbleDrawY = Display::HEIGHT*6/30;
    static constexpr unsigned placeDeficitBubbleBaseCols = 1;
    static constexpr unsigned placeDeficitBubbleBaseRows = 1;
    static constexpr unsigned placeDeficitBubbleMaxRows = 6;
    static unsigned placeDeficitBubbleNumCols, placeDeficitBubbleNumRows;
    static float placeDeficitBubbleWidth, placeDeficitBubbleHeight; // Width extended by Tile::WIDTH*1.5 in UpdateplaceDeficitBubble()


    static inline const std::string placeMarketBubbleHeader = "Market";
    static inline const std::string placeMarketBubbleEmptyText = "<No inventory>";
    static constexpr float placeMarketBubbleDrawX       = Display::WIDTH*26/40;
    static constexpr float placeMarketBubbleDrawY       = Display::HEIGHT* 6/30;
    static constexpr float placeMarketBubbleRowSpacing  = Font::TEXT_HEIGHT_8;
    static constexpr unsigned placeMarketBubbleBaseCols = 6;
    static constexpr unsigned placeMarketBubbleBaseRows = 1;
    static unsigned placeMarketBubbleNumCols;
    static unsigned placeMarketBubbleNumRows;
    static float placeMarketBubbleWidth;
    static float placeMarketBubbleHeight;

    static inline const std::string placeIndustriesBubbleHeader = "Local industries";
    static inline const std::string placeIndustriesBubbleEmptyText = "<No industries>";
    static constexpr float placeIndustriesBubbleDrawX = Display::WIDTH*26/40;
    static constexpr float placeIndustriesBubbleDrawY = Display::HEIGHT*14/30;
    static constexpr float placeIndustriesBubbleRowSpacing = 4; // Arbitrary gap
    static constexpr float placeIndustriesBubbleWidth = Tile::WIDTH*6; //+ BubbleView::bubblePadding;
    static constexpr float placeIndustriesBubbleProgressBarOffset = 2.5*Tile::WIDTH;
    static constexpr float placeIndustriesBubbleProgressBarWidth = placeIndustriesBubbleWidth - placeIndustriesBubbleProgressBarOffset;
    static float placeIndustriesBubbleHeight;

    /// Encyclopedia bubble
    static int encyclopediaCurrentCategory;
    static int encyclopediaCurrentIndex;
    static std::string encyclopediaBubbleEntryName;
    static std::string encyclopediaBubbleEntryText;

    static inline const std::string encyclopediaBubbleHeader = "Encyclopedia";
    static constexpr float encyclopediaBubbleWidth = Tile::WIDTH*8;
    static float encyclopediaBubbleHeight;
    static float encyclopediaBubbleDrawX;
    static float encyclopediaBubbleDrawY;

    static void Initialize()
    {
        currentCaravan = nullptr;
        currentPlace = nullptr;
        currentBeing = nullptr;

        //caravanCrewBubbleHeader = "Crew:";
        //caravanCrewBubbleEmptyText = "<No Crew>";
        //caravanInventoryBubbleHeader = "Cargo:";
        //caravanInventoryBubbleEmptyText = "<No cargo carried>";
        //caravanTradeRecordsBubbleHeader = "Trade Records:";
        //caravanTradeRecordsBubbleEmptyText = "<No records>";
        //caravanTradeRecordsBubbleNoTransactionText = "<No transaction>";
        //caravanPathfindingBubbleHeader = "Pathfinding:";
        //caravanPathfindingBubbleEmptyText = "<No path>";

        //placePopulationBubbleHeader = "Population";
        //placePopulationBubbleEmptyText = "<None>";
        //placeCaravanseraiHeader = "Caravanserai";
        //placeCaravanseraiEmptyText = "<Empty>";
        //placeSurplusBubbleHeader = "Surplus";
        //placeDeficitBubbleHeader = "Deficit";
        //placeMarketBubbleHeader = "Market";
        //placeMarketBubbleEmptyText = "<No inventory>";
        //placeIndustriesBubbleHeader = "Local Industries";
        //placeIndustriesBubbleEmptyText = "<No industries>";

        //encyclopediaBubbleHeader = "Encyclopedia";

        beingStatusBubbleOpen = false;
        encyclopediaBubbleOpen = false;
    }

/// Being status bubble functions
    static void OpenBeingStatusBubble(Being *b);
    static void CloseBeingStatusBubble();
    static void DrawBeingStatusBubble(Being *b);

/// Caravan bubble functions
    static void UpdateCaravanCrewBubble(Caravan *c);
    static void UpdateCaravanInventoryBubble(Caravan *c);
    static void UpdateCaravanTradeRecordsBubble(Caravan *c);
    static void UpdateCaravanPathfindingBubble(Caravan *c);
    static void UpdateAllCaravanBubbles(Caravan *c);

    static void DrawCaravanCrewBubble(Caravan *c);
    // static void Caravan::DrawCaravanTravelViewBubble(Caravan *c);
    static void DrawCaravanInventoryBubble(Caravan *c);
    static void DrawCaravanTradeRecordsBubble(Caravan *c);
    static void DrawCaravanPathfindingBubble(Caravan *c);

/// Place bubble functions
    static void UpdatePlacePopulationBubble(Place *p);
    //static void UpdateCitizensBubble(Place *p);
    static void UpdatePlaceCaravanseraiBubble(Place *p);
    static void UpdatePlaceSurplusBubble(Place *p);
    static void UpdatePlaceDeficitBubble(Place *p);
    static void UpdatePlaceMarketBubble(Place *p);
    static void UpdatePlaceIndustriesBubble(Place *p); // Only called when industrial activity updated

    static void DrawPlacePopulationBubble(Place *p);
    //static void DrawCitizensBubble(Place *p);
    static void DrawPlaceCaravanseraiBubble(Place *p);
    static void DrawPlaceSurplusBubble(Place *p);
    static void DrawPlaceDeficitBubble(Place *p);
    ///void DrawInventoryBubbles();
    static void DrawPlaceMarketBubble(Place *p);
    static void DrawPlaceIndustriesBubble(Place *p);

/// Encyclopedia bubble functions
    static void OpenEncyclopediaBubble(float x, float y, int category, int index);
    static void CloseEncyclopediaBubble();
    static void DrawEncyclopediaBubble();
};

/// Encyclopedia bubble
