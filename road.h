#ifndef ROAD_H_INCLUDED
#define ROAD_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>
#include <map>

#include "palette.h"

#include "camera.h"
#include "roadindex.h"
#include "placeindex.h"

class Road
{
public:
    static std::map<int,Road*>roads;
/// Identity
    int identity;
    Road *selfPointer;

    std::string name;

/// Connections
    int endpointA; // Use the identity of a place.
    int endpointB;

/// Geometry
    float length;
    std::map<int,float>xWaypoints;
    std::map<int,float>yWaypoints;
    int lastWaypoint; // When not reversed.

/// Sovereignty
    int sovereignty;

/// Geography
    int geography;

/// Cosmetic
    ALLEGRO_COLOR drawOverColour;
    ALLEGRO_COLOR drawUnderColour;

/// Constructor
    Road(int id);
    ~Road();

    void SetWaypoint(unsigned index, int x, int y);
    void SetGeography(int whichGeography);
    void SetSovereignty(int whichSovereignty);

    float ReturnSegmentLength(int a, int b);
    void DrawSegmentsOnWorldview();


};

#endif // ROAD_H_INCLUDED
