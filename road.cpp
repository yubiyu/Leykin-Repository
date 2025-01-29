#include "road.h"

std::map<int, Road*> Road::roads;

Road::Road(int id)
{
    identity = id;
    selfPointer = this;

    name = roadNames.at(identity);

    SetGeography(roadGeographies.at(identity));
    SetSovereignty(roadSovereignties.at(identity));


    switch(identity)
    {
    case ROAD_ERICENNES_CHORAS:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_CHORAS;
        SetWaypoint(0, Tile::WIDTH*71.5, Tile::HEIGHT*69.5);
        SetWaypoint(1, Tile::WIDTH*74,   Tile::HEIGHT*68);
        SetWaypoint(2, Tile::WIDTH*74,   Tile::HEIGHT*63.5);
        break;

    case ROAD_ERICENNES_KETH_KETHER:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_KETH_KETHER;
        SetWaypoint(0, Tile::WIDTH*68.5, Tile::HEIGHT*70.5);
        SetWaypoint(1, Tile::WIDTH*63.5, Tile::HEIGHT*70.5);
        SetWaypoint(2, Tile::WIDTH*63.5, Tile::HEIGHT*74);
        break;

    case ROAD_ERICENNES_KETH_ENTWEIR:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_KETH_ENTWEIR;
        SetWaypoint(0, Tile::WIDTH*68.5, Tile::HEIGHT*69.5);
        SetWaypoint(1, Tile::WIDTH*66,   Tile::HEIGHT*67);
        SetWaypoint(2, Tile::WIDTH*60.5, Tile::HEIGHT*67);
        break;

    case ROAD_ERICENNES_ROSKANEL:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_ROSKANEL;
        SetWaypoint(0, Tile::WIDTH*71.5, Tile::HEIGHT*70.5);
        SetWaypoint(1, Tile::WIDTH*73.5, Tile::HEIGHT*72.5);
        SetWaypoint(2, Tile::WIDTH*76,   Tile::HEIGHT*72.5);
        break;

    case ROAD_WATERWAY_ERICENNES_COLDLAKE:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_COLDLAKE;
        SetWaypoint(0, Tile::WIDTH*70, Tile::HEIGHT*68.5);
        SetWaypoint(1, Tile::WIDTH*70, Tile::HEIGHT*67);
        SetWaypoint(2, Tile::WIDTH*66, Tile::HEIGHT*63);
        SetWaypoint(3, Tile::WIDTH*66, Tile::HEIGHT*61.5);
        break;

    case ROAD_WATERWAY_ERICENNES_VEINS:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_VEINS;
        SetWaypoint(0, Tile::WIDTH*70, Tile::HEIGHT*71.5);
        SetWaypoint(1, Tile::WIDTH*70, Tile::HEIGHT*73);
        SetWaypoint(2, Tile::WIDTH*66, Tile::HEIGHT*77);
        SetWaypoint(3, Tile::WIDTH*66, Tile::HEIGHT*81.5);
        break;

    case ROAD_CHORAS_COLDLAKE:
        endpointA = PlaceIndex::PL_CHORAS;
        endpointB = PlaceIndex::PL_COLDLAKE;
        SetWaypoint(0, Tile::WIDTH*72.5, Tile::HEIGHT*61.5);
        SetWaypoint(1, Tile::WIDTH*70.5, Tile::HEIGHT*60);
        SetWaypoint(2, Tile::WIDTH*67.5, Tile::HEIGHT*60);
        break;

    case ROAD_CHORAS_RAMSHORN:
        endpointA = PlaceIndex::PL_CHORAS;
        endpointB = PlaceIndex::PL_RAMSHORN;
        SetWaypoint(0, Tile::WIDTH*75.5, Tile::HEIGHT*62);
        SetWaypoint(1, Tile::WIDTH*79.5, Tile::HEIGHT*62);
        SetWaypoint(2, Tile::WIDTH*81,   Tile::HEIGHT*60.5);
        break;

    case ROAD_CHORAS_HOLLYHEAD:
        endpointA = PlaceIndex::PL_CHORAS;
        endpointB = PlaceIndex::PL_HOLLYHEAD;
        SetWaypoint(0, Tile::WIDTH*74, Tile::HEIGHT*60.5);
        SetWaypoint(1, Tile::WIDTH*74, Tile::HEIGHT*59);
        SetWaypoint(2, Tile::WIDTH*75, Tile::HEIGHT*58);
        SetWaypoint(3, Tile::WIDTH*75, Tile::HEIGHT*56.5);
        break;

    case ROAD_KETH_KETHER_KETH_ENTWEIR:
        endpointA = PlaceIndex::PL_KETH_KETHER;
        endpointB = PlaceIndex::PL_KETH_ENTWEIR;
        SetWaypoint(0, Tile::WIDTH*62, Tile::HEIGHT*72.5);
        SetWaypoint(1, Tile::WIDTH*59, Tile::HEIGHT*72.5);
        SetWaypoint(2, Tile::WIDTH*59, Tile::HEIGHT*68.5);
        break;

    case ROAD_KETH_KETHER_VIELLEICHT:
        endpointA = PlaceIndex::PL_KETH_KETHER;
        endpointB = PlaceIndex::PL_VIELLEICHT;
        SetWaypoint(0, Tile::WIDTH*60.5, Tile::HEIGHT*74);
        SetWaypoint(1, Tile::WIDTH*56,   Tile::HEIGHT*74);
        SetWaypoint(2, Tile::WIDTH*52.5, Tile::HEIGHT*77.5);
        break;

    case ROAD_KETH_KETHER_QUELLUDE:
        endpointA = PlaceIndex::PL_KETH_KETHER;
        endpointB = PlaceIndex::PL_QUELLUDE;
        SetWaypoint(0, Tile::WIDTH*62,   Tile::HEIGHT*75.5);
        SetWaypoint(1, Tile::WIDTH*62,   Tile::HEIGHT*78);
        SetWaypoint(2, Tile::WIDTH*57.5, Tile::HEIGHT*82);
        break;

    case ROAD_KETH_ENTWEIR_AMBLEFORTH:
        endpointA = PlaceIndex::PL_KETH_ENTWEIR;
        endpointB = PlaceIndex::PL_AMBLEFORTH;
        SetWaypoint(0, Tile::WIDTH*57.5, Tile::HEIGHT*67);
        SetWaypoint(1, Tile::WIDTH*55,   Tile::HEIGHT*67);
        SetWaypoint(2, Tile::WIDTH*54,   Tile::HEIGHT*65.5);
        break;

    case ROAD_VIELLEICHT_QUELLUDE:
        endpointA = PlaceIndex::PL_VIELLEICHT;
        endpointB = PlaceIndex::PL_QUELLUDE;
        SetWaypoint(0, Tile::WIDTH*52.5, Tile::HEIGHT*78.5);
        SetWaypoint(1, Tile::WIDTH*52.5, Tile::HEIGHT*82);
        SetWaypoint(2, Tile::WIDTH*54.5, Tile::HEIGHT*82);
        break;

    case ROAD_WATERWAY_VIELLEICHT_REACH:
        endpointA = PlaceIndex::PL_VIELLEICHT;
        endpointB = PlaceIndex::PL_REACH;
        SetWaypoint(0, Tile::WIDTH*49.5, Tile::HEIGHT*78.5);
        SetWaypoint(1, Tile::WIDTH*39.5, Tile::HEIGHT*79.5);
        break;

    case ROAD_WATERWAY_VIELLEICHT_KARUNE:
        endpointA = PlaceIndex::PL_VIELLEICHT;
        endpointB = PlaceIndex::PL_KARUNE;
        SetWaypoint(0, Tile::WIDTH*50.5, Tile::HEIGHT*76.5);
        SetWaypoint(1, Tile::WIDTH*41.5, Tile::HEIGHT*61.5);
        break;

    case ROAD_WATERWAY_VIELLEICHT_HATHSERA:
        endpointA = PlaceIndex::PL_VIELLEICHT;
        endpointB = PlaceIndex::PL_HATHSERA;
        SetWaypoint(0, Tile::WIDTH*50.5, Tile::HEIGHT*79.5);
        SetWaypoint(1, Tile::WIDTH*46.5, Tile::HEIGHT*91.5);
        break;

    case ROAD_AMBLEFORTH_OBSERVIA:
        endpointA = PlaceIndex::PL_AMBLEFORTH;
        endpointB = PlaceIndex::PL_OBSERVIA;
        SetWaypoint(0, Tile::WIDTH*54,   Tile::HEIGHT*62.5);
        SetWaypoint(1, Tile::WIDTH*59.5, Tile::HEIGHT*62.5);
        SetWaypoint(2, Tile::WIDTH*59.5, Tile::HEIGHT*56.5);
        break;

    case ROAD_ROSKANEL_ROSELLA:
        endpointA = PlaceIndex::PL_ROSKANEL;
        endpointB = PlaceIndex::PL_ROSELLA;
        SetWaypoint(0, Tile::WIDTH*76,   Tile::HEIGHT*75.5);
        SetWaypoint(1, Tile::WIDTH*76,   Tile::HEIGHT*78.5);
        SetWaypoint(2, Tile::WIDTH*77.5, Tile::HEIGHT*78.5);
        break;

    case ROAD_ROSKANEL_YHANE:
        endpointA = PlaceIndex::PL_ROSKANEL;
        endpointB = PlaceIndex::PL_YHANE;
        SetWaypoint(0, Tile::WIDTH*74.5, Tile::HEIGHT*74);
        SetWaypoint(1, Tile::WIDTH*74.5, Tile::HEIGHT*77.5);
        SetWaypoint(2, Tile::WIDTH*72.5, Tile::HEIGHT*79.5);
        SetWaypoint(3, Tile::WIDTH*71.5, Tile::HEIGHT*79.5);
        break;

    case ROAD_OBSERVIA_COLDLAKE:
        endpointA = PlaceIndex::PL_OBSERVIA;
        endpointB = PlaceIndex::PL_COLDLAKE;
        SetWaypoint(0, Tile::WIDTH*61,   Tile::HEIGHT*56.5);
        SetWaypoint(1, Tile::WIDTH*61,   Tile::HEIGHT*60);
        SetWaypoint(2, Tile::WIDTH*64.5, Tile::HEIGHT*60);
        break;

    case ROAD_OBSERVIA_UMBERDELL:
        endpointA = PlaceIndex::PL_OBSERVIA;
        endpointB = PlaceIndex::PL_UMBERDELL;
        SetWaypoint(0, Tile::WIDTH*59.5, Tile::HEIGHT*55);
        SetWaypoint(1, Tile::WIDTH*57,   Tile::HEIGHT*55);
        SetWaypoint(2, Tile::WIDTH*57,   Tile::HEIGHT*53);
        SetWaypoint(3, Tile::WIDTH*65.5, Tile::HEIGHT*53);
        break;

    case ROAD_RAMSHORN_JASPER:
        endpointA = PlaceIndex::PL_RAMSHORN;
        endpointB = PlaceIndex::PL_JASPER;
        SetWaypoint(0, Tile::WIDTH*81,   Tile::HEIGHT*57.5);
        SetWaypoint(1, Tile::WIDTH*81,   Tile::HEIGHT*54);
        SetWaypoint(2, Tile::WIDTH*83,   Tile::HEIGHT*52);
        SetWaypoint(3, Tile::WIDTH*84.5, Tile::HEIGHT*52);
        break;

    case ROAD_HOLLYHEAD_RUMNIR:
        endpointA = PlaceIndex::PL_HOLLYHEAD;
        endpointB = PlaceIndex::PL_RUMNIR;
        SetWaypoint(0, Tile::WIDTH*75, Tile::HEIGHT*53.5);
        SetWaypoint(1, Tile::WIDTH*75, Tile::HEIGHT*51);
        SetWaypoint(2, Tile::WIDTH*71, Tile::HEIGHT*48.5);
        SetWaypoint(3, Tile::WIDTH*71, Tile::HEIGHT*45.5);
        break;

    case ROAD_RUMNIR_HEWNHEIM:
        endpointA = PlaceIndex::PL_RUMNIR;
        endpointB = PlaceIndex::PL_HEWNHEIM;
        SetWaypoint(0, Tile::WIDTH*69.5, Tile::HEIGHT*43.5);
        SetWaypoint(1, Tile::WIDTH*67.5, Tile::HEIGHT*41.5);
        SetWaypoint(2, Tile::WIDTH*60.5, Tile::HEIGHT*41.5);
        break;

    case ROAD_RUMNIR_ARTAS_ROCK:
        endpointA = PlaceIndex::PL_RUMNIR;
        endpointB = PlaceIndex::PL_ARTAS_ROCK;
        SetWaypoint(0, Tile::WIDTH*70.5, Tile::HEIGHT*42.5);
        SetWaypoint(1, Tile::WIDTH*69,   Tile::HEIGHT*41);
        SetWaypoint(2, Tile::WIDTH*69,   Tile::HEIGHT*35.5);
        break;

    case ROAD_HEWNHEIM_VERSE:
        endpointA = PlaceIndex::PL_HEWNHEIM;
        endpointB = PlaceIndex::PL_VERSE;
        SetWaypoint(0, Tile::WIDTH*58.5, Tile::HEIGHT*39.5);
        SetWaypoint(1, Tile::WIDTH*58.5, Tile::HEIGHT*37);
        SetWaypoint(2, Tile::WIDTH*62.5, Tile::HEIGHT*32.5);
        SetWaypoint(3, Tile::WIDTH*62.5, Tile::HEIGHT*29.5);
        break;

    case ROAD_WATERWAY_HEWNHEIM_YULMER:
        endpointA = PlaceIndex::PL_HEWNHEIM;
        endpointB = PlaceIndex::PL_YULMER;
        SetWaypoint(0, Tile::WIDTH*57.5, Tile::HEIGHT*41.5);
        SetWaypoint(1, Tile::WIDTH*47.5, Tile::HEIGHT*43.5);
        break;

    case ROAD_ARTAS_ROCK_VERSE:
        endpointA = PlaceIndex::PL_ARTAS_ROCK;
        endpointB = PlaceIndex::PL_VERSE;
        SetWaypoint(0, Tile::WIDTH*69,   Tile::HEIGHT*32.5);
        SetWaypoint(1, Tile::WIDTH*63.5, Tile::HEIGHT*32.5);
        SetWaypoint(2, Tile::WIDTH*63.5, Tile::HEIGHT*29.5);
        break;

    case ROAD_YHANE_VEINS:
        endpointA = PlaceIndex::PL_YHANE;
        endpointB = PlaceIndex::PL_VEINS;
        SetWaypoint(0, Tile::WIDTH*69.5, Tile::HEIGHT*81.5);
        SetWaypoint(1, Tile::WIDTH*69.5, Tile::HEIGHT*83.5);
        SetWaypoint(2, Tile::WIDTH*67.5, Tile::HEIGHT*83.5);
        break;

    case ROAD_YHANE_VORDOZAAL:
        endpointA = PlaceIndex::PL_YHANE;
        endpointB = PlaceIndex::PL_VORDOZAAL;
        SetWaypoint(0, Tile::WIDTH*71.5, Tile::HEIGHT*80.5);
        SetWaypoint(1, Tile::WIDTH*71.5, Tile::HEIGHT*82.5);
        SetWaypoint(2, Tile::WIDTH*76.5, Tile::HEIGHT*82.5);
        break;

    case ROAD_YHANE_QALAIZ:
        endpointA = PlaceIndex::PL_YHANE;
        endpointB = PlaceIndex::PL_QALAIZ;
        SetWaypoint(0, Tile::WIDTH*70.5, Tile::HEIGHT*81.5);
        SetWaypoint(1, Tile::WIDTH*70.5, Tile::HEIGHT*86.5);
        SetWaypoint(2, Tile::WIDTH*72.5, Tile::HEIGHT*89.5);
        break;

    case ROAD_WATERWAY_VEINS_QUMANTH:
        endpointA = PlaceIndex::PL_VEINS;
        endpointB = PlaceIndex::PL_QUMANTH;
        SetWaypoint(0, Tile::WIDTH*66, Tile::HEIGHT*84.5);
        SetWaypoint(1, Tile::WIDTH*66, Tile::HEIGHT*87);
        SetWaypoint(2, Tile::WIDTH*65, Tile::HEIGHT*88);
        SetWaypoint(3, Tile::WIDTH*65, Tile::HEIGHT*93.5);
        break;

    case ROAD_QALAIZ_TOBANDJAN:
        endpointA = PlaceIndex::PL_QALAIZ;
        endpointB = PlaceIndex::PL_TOBANDJAN;
        SetWaypoint(0, Tile::WIDTH*75.5, Tile::HEIGHT*90.5);
        SetWaypoint(1, Tile::WIDTH*75.5, Tile::HEIGHT*95.5);
        SetWaypoint(2, Tile::WIDTH*73.5, Tile::HEIGHT*97.5);
        break;

    case ROAD_QALAIZ_QUMANTH:
        endpointA = PlaceIndex::PL_QALAIZ;
        endpointB = PlaceIndex::PL_QUMANTH;
        SetWaypoint(0, Tile::WIDTH*74.5, Tile::HEIGHT*92.5);
        SetWaypoint(1, Tile::WIDTH*74.5, Tile::HEIGHT*94.5);
        SetWaypoint(2, Tile::WIDTH*73.5, Tile::HEIGHT*95.5);
        SetWaypoint(3, Tile::WIDTH*66.5, Tile::HEIGHT*95.5);
        break;

    case ROAD_QALAIZ_XENIA:
        endpointA = PlaceIndex::PL_QALAIZ;
        endpointB = PlaceIndex::PL_XENIA;
        SetWaypoint(0, Tile::WIDTH*74.5, Tile::HEIGHT*89.5);
        SetWaypoint(1, Tile::WIDTH*78.5, Tile::HEIGHT*89.5);
        SetWaypoint(2, Tile::WIDTH*80.5, Tile::HEIGHT*91.5);
        SetWaypoint(3, Tile::WIDTH*80.5, Tile::HEIGHT*95.5);
        break;

    case ROAD_WATERWAY_QUMANTH_HATHSERA:
        endpointA = PlaceIndex::PL_QUMANTH;
        endpointB = PlaceIndex::PL_HATHSERA;
        SetWaypoint(0, Tile::WIDTH*63.5, Tile::HEIGHT*95.5);
        SetWaypoint(1, Tile::WIDTH*46.5, Tile::HEIGHT*92.5);
        break;

    case ROAD_WATERWAY_REACH_KARUNE:
        endpointA = PlaceIndex::PL_REACH;
        endpointB = PlaceIndex::PL_KARUNE;
        SetWaypoint(0, Tile::WIDTH*37.5, Tile::HEIGHT*78.5);
        SetWaypoint(1, Tile::WIDTH*39.5, Tile::HEIGHT*62.5);
        break;

    case ROAD_WATERWAY_REACH_HATHSERA:
        endpointA = PlaceIndex::PL_REACH;
        endpointB = PlaceIndex::PL_HATHSERA;
        SetWaypoint(0, Tile::WIDTH*37.5, Tile::HEIGHT*81.5);
        SetWaypoint(1, Tile::WIDTH*43.5, Tile::HEIGHT*91.5);
        break;

    case ROAD_WATERWAY_KARUNE_YULMER:
        endpointA = PlaceIndex::PL_KARUNE;
        endpointB = PlaceIndex::PL_YULMER;
        SetWaypoint(0, Tile::WIDTH*40.5, Tile::HEIGHT*59.5);
        SetWaypoint(1, Tile::WIDTH*45.5, Tile::HEIGHT*45.5);
        break;
    }

    /*
    switch(identity)
    {
    case ROAD_ERICENNES_CHORAS:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_CHORAS;
        SetWaypoint(0, Tile::WIDTH*715, Tile::HEIGHT*695);
        SetWaypoint(1, Tile::WIDTH*740, Tile::HEIGHT*680);
        SetWaypoint(2, Tile::WIDTH*740, Tile::HEIGHT*635);
        break;

    case ROAD_ERICENNES_KETH_KETHER:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_KETH_KETHER;
        SetWaypoint(0, Tile::WIDTH*685, Tile::HEIGHT*705);
        SetWaypoint(1, Tile::WIDTH*635, Tile::HEIGHT*705);
        SetWaypoint(2, Tile::WIDTH*635, Tile::HEIGHT*740);
        break;

    case ROAD_ERICENNES_KETH_ENTWEIR:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_KETH_ENTWEIR;
        SetWaypoint(0, Tile::WIDTH*685, Tile::HEIGHT*695);
        SetWaypoint(1, Tile::WIDTH*660, Tile::HEIGHT*670);
        SetWaypoint(2, Tile::WIDTH*605, Tile::HEIGHT*670);
        break;

    case ROAD_ERICENNES_ROSKANEL:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_ROSKANEL;
        SetWaypoint(0, Tile::WIDTH*715, Tile::HEIGHT*705);
        SetWaypoint(1, Tile::WIDTH*735, Tile::HEIGHT*725);
        SetWaypoint(2, Tile::WIDTH*760, Tile::HEIGHT*725);
        break;

    case ROAD_WATERWAY_ERICENNES_COLDLAKE:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_COLDLAKE;
        SetWaypoint(0, Tile::WIDTH*700, Tile::HEIGHT*685);
        SetWaypoint(1, Tile::WIDTH*700, Tile::HEIGHT*670);
        SetWaypoint(2, Tile::WIDTH*660, Tile::HEIGHT*630);
        SetWaypoint(3, Tile::WIDTH*660, Tile::HEIGHT*615);
        break;

    case ROAD_WATERWAY_ERICENNES_VEINS:
        endpointA = PlaceIndex::PL_ERICENNES;
        endpointB = PlaceIndex::PL_VEINS;
        SetWaypoint(0, Tile::WIDTH*700, Tile::HEIGHT*715);
        SetWaypoint(1, Tile::WIDTH*700, Tile::HEIGHT*730);
        SetWaypoint(2, Tile::WIDTH*660, Tile::HEIGHT*770);
        SetWaypoint(3, Tile::WIDTH*660, Tile::HEIGHT*815);
        break;

    case ROAD_CHORAS_COLDLAKE:
        endpointA = PlaceIndex::PL_CHORAS;
        endpointB = PlaceIndex::PL_COLDLAKE;
        SetWaypoint(0, Tile::WIDTH*725, Tile::HEIGHT*615);
        SetWaypoint(1, Tile::WIDTH*705, Tile::HEIGHT*600);
        SetWaypoint(2, Tile::WIDTH*675, Tile::HEIGHT*600);
        break;

    case ROAD_CHORAS_RAMSHORN:
        endpointA = PlaceIndex::PL_CHORAS;
        endpointB = PlaceIndex::PL_RAMSHORN;
        SetWaypoint(0, Tile::WIDTH*755, Tile::HEIGHT*620);
        SetWaypoint(1, Tile::WIDTH*795, Tile::HEIGHT*620);
        SetWaypoint(2, Tile::WIDTH*810, Tile::HEIGHT*605);
        break;

    case ROAD_CHORAS_HOLLYHEAD:
        endpointA = PlaceIndex::PL_CHORAS;
        endpointB = PlaceIndex::PL_HOLLYHEAD;
        SetWaypoint(0, Tile::WIDTH*740, Tile::HEIGHT*605);
        SetWaypoint(1, Tile::WIDTH*740, Tile::HEIGHT*590);
        SetWaypoint(2, Tile::WIDTH*750, Tile::HEIGHT*580);
        SetWaypoint(3, Tile::WIDTH*750, Tile::HEIGHT*565);
        break;

    case ROAD_KETH_KETHER_KETH_ENTWEIR:
        endpointA = PlaceIndex::PL_KETH_KETHER;
        endpointB = PlaceIndex::PL_KETH_ENTWEIR;
        SetWaypoint(0, Tile::WIDTH*620, Tile::HEIGHT*725);
        SetWaypoint(1, Tile::WIDTH*590, Tile::HEIGHT*725);
        SetWaypoint(2, Tile::WIDTH*590, Tile::HEIGHT*685);
        break;

    case ROAD_KETH_KETHER_VIELLEICHT:
        endpointA = PlaceIndex::PL_KETH_KETHER;
        endpointB = PlaceIndex::PL_VIELLEICHT;
        SetWaypoint(0, Tile::WIDTH*605, Tile::HEIGHT*740);
        SetWaypoint(1, Tile::WIDTH*560, Tile::HEIGHT*740);
        SetWaypoint(2, Tile::WIDTH*525, Tile::HEIGHT*775);
        break;

    case ROAD_KETH_KETHER_QUELLUDE:
        endpointA = PlaceIndex::PL_KETH_KETHER;
        endpointB = PlaceIndex::PL_QUELLUDE;
        SetWaypoint(0, Tile::WIDTH*620,   Tile::HEIGHT*755);
        SetWaypoint(1, Tile::WIDTH*620,   Tile::HEIGHT*780);
        SetWaypoint(2, Tile::WIDTH*575, Tile::HEIGHT*820);
        break;

    case ROAD_KETH_ENTWEIR_AMBLEFORTH:
        endpointA = PlaceIndex::PL_KETH_ENTWEIR;
        endpointB = PlaceIndex::PL_AMBLEFORTH;
        SetWaypoint(0, Tile::WIDTH*575, Tile::HEIGHT*670);
        SetWaypoint(1, Tile::WIDTH*550, Tile::HEIGHT*670);
        SetWaypoint(2, Tile::WIDTH*540, Tile::HEIGHT*655);
        break;

    case ROAD_VIELLEICHT_QUELLUDE:
        endpointA = PlaceIndex::PL_VIELLEICHT;
        endpointB = PlaceIndex::PL_QUELLUDE;
        SetWaypoint(0, Tile::WIDTH*525, Tile::HEIGHT*785);
        SetWaypoint(1, Tile::WIDTH*525, Tile::HEIGHT*820);
        SetWaypoint(2, Tile::WIDTH*545, Tile::HEIGHT*820);
        break;

    case ROAD_WATERWAY_VIELLEICHT_REACH:
        endpointA = PlaceIndex::PL_VIELLEICHT;
        endpointB = PlaceIndex::PL_REACH;
        SetWaypoint(0, Tile::WIDTH*495, Tile::HEIGHT*785);
        SetWaypoint(1, Tile::WIDTH*395, Tile::HEIGHT*795);
        break;

    case ROAD_WATERWAY_VIELLEICHT_KARUNE:
        endpointA = PlaceIndex::PL_VIELLEICHT;
        endpointB = PlaceIndex::PL_KARUNE;
        SetWaypoint(0, Tile::WIDTH*505, Tile::HEIGHT*765);
        SetWaypoint(1, Tile::WIDTH*415, Tile::HEIGHT*615);
        break;

    case ROAD_WATERWAY_VIELLEICHT_HATHSERA:
        endpointA = PlaceIndex::PL_VIELLEICHT;
        endpointB = PlaceIndex::PL_HATHSERA;
        SetWaypoint(0, Tile::WIDTH*505, Tile::HEIGHT*795);
        SetWaypoint(1, Tile::WIDTH*465, Tile::HEIGHT*915);
        break;

    case ROAD_AMBLEFORTH_OBSERVIA:
        endpointA = PlaceIndex::PL_AMBLEFORTH;
        endpointB = PlaceIndex::PL_OBSERVIA;
        SetWaypoint(0, Tile::WIDTH*540, Tile::HEIGHT*625);
        SetWaypoint(1, Tile::WIDTH*595, Tile::HEIGHT*625);
        SetWaypoint(2, Tile::WIDTH*595, Tile::HEIGHT*565);
        break;

    case ROAD_ROSKANEL_ROSELLA:
        endpointA = PlaceIndex::PL_ROSKANEL;
        endpointB = PlaceIndex::PL_ROSELLA;
        SetWaypoint(0, Tile::WIDTH*760, Tile::HEIGHT*755);
        SetWaypoint(1, Tile::WIDTH*760, Tile::HEIGHT*785);
        SetWaypoint(2, Tile::WIDTH*775, Tile::HEIGHT*785);
        break;

    case ROAD_ROSKANEL_YHANE:
        endpointA = PlaceIndex::PL_ROSKANEL;
        endpointB = PlaceIndex::PL_YHANE;
        SetWaypoint(0, Tile::WIDTH*745, Tile::HEIGHT*740);
        SetWaypoint(1, Tile::WIDTH*745, Tile::HEIGHT*775);
        SetWaypoint(2, Tile::WIDTH*725, Tile::HEIGHT*795);
        SetWaypoint(3, Tile::WIDTH*715, Tile::HEIGHT*795);
        break;

    case ROAD_OBSERVIA_COLDLAKE:
        endpointA = PlaceIndex::PL_OBSERVIA;
        endpointB = PlaceIndex::PL_COLDLAKE;
        SetWaypoint(0, Tile::WIDTH*610,   Tile::HEIGHT*565);
        SetWaypoint(1, Tile::WIDTH*610,   Tile::HEIGHT*600);
        SetWaypoint(2, Tile::WIDTH*645, Tile::HEIGHT*600);
        break;

    case ROAD_OBSERVIA_UMBERDELL:
        endpointA = PlaceIndex::PL_OBSERVIA;
        endpointB = PlaceIndex::PL_UMBERDELL;
        SetWaypoint(0, Tile::WIDTH*595, Tile::HEIGHT*550);
        SetWaypoint(1, Tile::WIDTH*570,   Tile::HEIGHT*550);
        SetWaypoint(2, Tile::WIDTH*570,   Tile::HEIGHT*530);
        SetWaypoint(3, Tile::WIDTH*655, Tile::HEIGHT*530);
        break;

    case ROAD_RAMSHORN_JASPER:
        endpointA = PlaceIndex::PL_RAMSHORN;
        endpointB = PlaceIndex::PL_JASPER;
        SetWaypoint(0, Tile::WIDTH*810,   Tile::HEIGHT*575);
        SetWaypoint(1, Tile::WIDTH*810,   Tile::HEIGHT*540);
        SetWaypoint(2, Tile::WIDTH*830,   Tile::HEIGHT*520);
        SetWaypoint(3, Tile::WIDTH*845, Tile::HEIGHT*520);
        break;

    case ROAD_HOLLYHEAD_RUMNIR:
        endpointA = PlaceIndex::PL_HOLLYHEAD;
        endpointB = PlaceIndex::PL_RUMNIR;
        SetWaypoint(0, Tile::WIDTH*750, Tile::HEIGHT*535);
        SetWaypoint(1, Tile::WIDTH*750, Tile::HEIGHT*510);
        SetWaypoint(2, Tile::WIDTH*710, Tile::HEIGHT*485);
        SetWaypoint(3, Tile::WIDTH*710, Tile::HEIGHT*455);
        break;

    case ROAD_RUMNIR_HEWNHEIM:
        endpointA = PlaceIndex::PL_RUMNIR;
        endpointB = PlaceIndex::PL_HEWNHEIM;
        SetWaypoint(0, Tile::WIDTH*695, Tile::HEIGHT*435);
        SetWaypoint(1, Tile::WIDTH*675, Tile::HEIGHT*415);
        SetWaypoint(2, Tile::WIDTH*605, Tile::HEIGHT*415);
        break;

    case ROAD_RUMNIR_ARTAS_ROCK:
        endpointA = PlaceIndex::PL_RUMNIR;
        endpointB = PlaceIndex::PL_ARTAS_ROCK;
        SetWaypoint(0, Tile::WIDTH*705, Tile::HEIGHT*425);
        SetWaypoint(1, Tile::WIDTH*690, Tile::HEIGHT*410);
        SetWaypoint(2, Tile::WIDTH*690, Tile::HEIGHT*355);
        break;

    case ROAD_HEWNHEIM_VERSE:
        endpointA = PlaceIndex::PL_HEWNHEIM;
        endpointB = PlaceIndex::PL_VERSE;
        SetWaypoint(0, Tile::WIDTH*585, Tile::HEIGHT*395);
        SetWaypoint(1, Tile::WIDTH*585, Tile::HEIGHT*370);
        SetWaypoint(2, Tile::WIDTH*625, Tile::HEIGHT*325);
        SetWaypoint(3, Tile::WIDTH*625, Tile::HEIGHT*295);
        break;

    case ROAD_WATERWAY_HEWNHEIM_YULMER:
        endpointA = PlaceIndex::PL_HEWNHEIM;
        endpointB = PlaceIndex::PL_YULMER;
        SetWaypoint(0, Tile::WIDTH*575, Tile::HEIGHT*415);
        SetWaypoint(1, Tile::WIDTH*475, Tile::HEIGHT*435);
        break;

    case ROAD_ARTAS_ROCK_VERSE:
        endpointA = PlaceIndex::PL_ARTAS_ROCK;
        endpointB = PlaceIndex::PL_VERSE;
        SetWaypoint(0, Tile::WIDTH*690, Tile::HEIGHT*325);
        SetWaypoint(1, Tile::WIDTH*635, Tile::HEIGHT*325);
        SetWaypoint(2, Tile::WIDTH*635, Tile::HEIGHT*295);
        break;

    case ROAD_YHANE_VEINS:
        endpointA = PlaceIndex::PL_YHANE;
        endpointB = PlaceIndex::PL_VEINS;
        SetWaypoint(0, Tile::WIDTH*695, Tile::HEIGHT*815);
        SetWaypoint(1, Tile::WIDTH*695, Tile::HEIGHT*835);
        SetWaypoint(2, Tile::WIDTH*675, Tile::HEIGHT*835);
        break;

    case ROAD_YHANE_VORDOZAAL:
        endpointA = PlaceIndex::PL_YHANE;
        endpointB = PlaceIndex::PL_VORDOZAAL;
        SetWaypoint(0, Tile::WIDTH*715, Tile::HEIGHT*805);
        SetWaypoint(1, Tile::WIDTH*715, Tile::HEIGHT*825);
        SetWaypoint(2, Tile::WIDTH*765, Tile::HEIGHT*825);
        break;

    case ROAD_YHANE_QALAIZ:
        endpointA = PlaceIndex::PL_YHANE;
        endpointB = PlaceIndex::PL_QALAIZ;
        SetWaypoint(0, Tile::WIDTH*705, Tile::HEIGHT*815);
        SetWaypoint(1, Tile::WIDTH*705, Tile::HEIGHT*865);
        SetWaypoint(2, Tile::WIDTH*725, Tile::HEIGHT*895);
        break;

    case ROAD_WATERWAY_VEINS_QUMANTH:
        endpointA = PlaceIndex::PL_VEINS;
        endpointB = PlaceIndex::PL_QUMANTH;
        SetWaypoint(0, Tile::WIDTH*660, Tile::HEIGHT*845);
        SetWaypoint(1, Tile::WIDTH*660, Tile::HEIGHT*870);
        SetWaypoint(2, Tile::WIDTH*650, Tile::HEIGHT*880);
        SetWaypoint(3, Tile::WIDTH*650, Tile::HEIGHT*935);
        break;

    case ROAD_QALAIZ_TOBANDJAN:
        endpointA = PlaceIndex::PL_QALAIZ;
        endpointB = PlaceIndex::PL_TOBANDJAN;
        SetWaypoint(0, Tile::WIDTH*755, Tile::HEIGHT*905);
        SetWaypoint(1, Tile::WIDTH*755, Tile::HEIGHT*955);
        SetWaypoint(2, Tile::WIDTH*735, Tile::HEIGHT*975);
        break;

    case ROAD_QALAIZ_QUMANTH:
        endpointA = PlaceIndex::PL_QALAIZ;
        endpointB = PlaceIndex::PL_QUMANTH;
        SetWaypoint(0, Tile::WIDTH*745, Tile::HEIGHT*925);
        SetWaypoint(1, Tile::WIDTH*745, Tile::HEIGHT*945);
        SetWaypoint(2, Tile::WIDTH*735, Tile::HEIGHT*955);
        SetWaypoint(3, Tile::WIDTH*665, Tile::HEIGHT*955);
        break;

    case ROAD_QALAIZ_XENIA:
        endpointA = PlaceIndex::PL_QALAIZ;
        endpointB = PlaceIndex::PL_XENIA;
        SetWaypoint(0, Tile::WIDTH*745, Tile::HEIGHT*895);
        SetWaypoint(1, Tile::WIDTH*785, Tile::HEIGHT*895);
        SetWaypoint(2, Tile::WIDTH*805, Tile::HEIGHT*915);
        SetWaypoint(3, Tile::WIDTH*805, Tile::HEIGHT*955);
        break;

    case ROAD_WATERWAY_QUMANTH_HATHSERA:
        endpointA = PlaceIndex::PL_QUMANTH;
        endpointB = PlaceIndex::PL_HATHSERA;
        SetWaypoint(0, Tile::WIDTH*635, Tile::HEIGHT*955);
        SetWaypoint(1, Tile::WIDTH*465, Tile::HEIGHT*925);
        break;

    case ROAD_WATERWAY_REACH_KARUNE:
        endpointA = PlaceIndex::PL_REACH;
        endpointB = PlaceIndex::PL_KARUNE;
        SetWaypoint(0, Tile::WIDTH*375, Tile::HEIGHT*785);
        SetWaypoint(1, Tile::WIDTH*395, Tile::HEIGHT*625);
        break;

    case ROAD_WATERWAY_REACH_HATHSERA:
        endpointA = PlaceIndex::PL_REACH;
        endpointB = PlaceIndex::PL_HATHSERA;
        SetWaypoint(0, Tile::WIDTH*375, Tile::HEIGHT*815);
        SetWaypoint(1, Tile::WIDTH*435, Tile::HEIGHT*915);
        break;

    case ROAD_WATERWAY_KARUNE_YULMER:
        endpointA = PlaceIndex::PL_KARUNE;
        endpointB = PlaceIndex::PL_YULMER;
        SetWaypoint(0, Tile::WIDTH*405, Tile::HEIGHT*595);
        SetWaypoint(1, Tile::WIDTH*455, Tile::HEIGHT*455);
        break;
    }
    */

    length = 0;
    for(int i = 0; i < lastWaypoint; ++i)
    {
        float dx = xWaypoints[i+1] - xWaypoints[i];
        float dy = yWaypoints[i+1] - yWaypoints[i];
        length += std::sqrt(dx*dx + dy*dy);
    }
    //std::cout << "Road " << id << " generated with length of " << length << std::endl;
}

Road::~Road()
{
    xWaypoints.clear();
    yWaypoints.clear();
}

void Road::SetGeography(int whichGeography)
{
    geography = whichGeography;
    switch(whichGeography)
    {
    case GEO_PLAINS:
        drawUnderColour = Palette::COL_JADE_1;
        break;
    case GEO_HILLS:
        drawUnderColour = Palette::COL_EARTHEN_2;
        break;
    case GEO_MOUNTAINS:
        drawUnderColour = Palette::COL_EARTHEN_1;
        break;
    case GEO_ICE_MOUNTAINS:
        drawUnderColour = Palette::COL_STEEL_4;
        break;
    case GEO_FOREST:
        drawUnderColour = Palette::COL_JADE_0;
        break;
    case GEO_RIVER:
        drawUnderColour = Palette::COL_AZURE_1;
        break;
    case GEO_OCEAN:
        drawUnderColour = Palette::COL_OCEAN_2;
        break;
    case GEO_TUNDRA:
        drawUnderColour = Palette::COL_STEEL_3;
        break;
    case GEO_DESERT:
        drawUnderColour = Palette::COL_ELECTRIC_4; //COL_CARAMEL_2;
        break;
    case GEO_RED_MESA:
        drawUnderColour = Palette::COL_RUST_2;
        break;
    case GEO_ASH_WASTE:
        drawUnderColour = Palette::COL_EARTHEN_1;
        break;
    case GEO_CLOUDS:
        drawUnderColour = Palette::COL_WIND_1;
        break;
    case GEO_TRANSIENT_LEY:
        drawUnderColour = Palette::COL_VIOLET_1;
        break;
    }

}

void Road::SetSovereignty(int whichSovereignty)
{
    sovereignty = whichSovereignty;

    switch(sovereignty)
    {
    case SOV_NULL:
        drawOverColour = Palette::COL_FLESH_2;
        break;
    case SOV_VERUS:
        drawOverColour = Palette::COL_JADE_2;
        break;
    case SOV_SHARUMNIR:
        drawOverColour = Palette::COL_STEEL_2;
        break;
    case SOV_XENIA:
        drawOverColour = Palette::COL_ELECTRIC_2;
        break;
    case SOV_THOUSAND_ISLES:
        drawOverColour = Palette::COL_AZURE_2;
        break;
    default:
        drawOverColour = Palette::COL_WIND_3;
        break;
    }
}

void Road::DrawSegmentsOnWorldview()
{
    al_draw_filled_circle(xWaypoints[0] - Camera::xPosition,
                          yWaypoints[0] - Camera::yPosition,
                          6, drawUnderColour);

    al_draw_filled_circle(xWaypoints[xWaypoints.rbegin()->first] - Camera::xPosition,
                          yWaypoints[yWaypoints.rbegin()->first] - Camera::yPosition,
                          6, drawUnderColour);

    for(unsigned i = 0; i < xWaypoints.size()-1; i++)
    {
        al_draw_line(xWaypoints[i] - Camera::xPosition,
                     yWaypoints[i] - Camera::yPosition,
                     xWaypoints[i+1] - Camera::xPosition,
                     yWaypoints[i+1] - Camera::yPosition,
                     drawUnderColour, 6);
        al_draw_line(xWaypoints[i] - Camera::xPosition,
                     yWaypoints[i] - Camera::yPosition,
                     xWaypoints[i+1] - Camera::xPosition,
                     yWaypoints[i+1] - Camera::yPosition,
                     drawOverColour, 2);
    }

    al_draw_filled_circle(xWaypoints[0] - Camera::xPosition,
                          yWaypoints[0] - Camera::yPosition,
                          3, drawOverColour);

    al_draw_filled_circle(xWaypoints[xWaypoints.rbegin()->first] - Camera::xPosition,
                          yWaypoints[yWaypoints.rbegin()->first] - Camera::yPosition,
                          3, drawOverColour);
}

void Road::SetWaypoint(unsigned index, int x, int y)
{
    xWaypoints[index] = x;
    yWaypoints[index] = y;

    lastWaypoint = xWaypoints.size()-1;
}

float Road::ReturnSegmentLength(int a, int b)
{
    float x1 = xWaypoints[a];
    float y1 = yWaypoints[a];
    float x2 = xWaypoints[b];
    float y2 = yWaypoints[b];

    return std::hypot(y2-y1,x2-x1);
}
