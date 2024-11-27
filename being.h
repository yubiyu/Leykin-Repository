#ifndef BEING_H_INCLUDED
#define BEING_H_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include <allegro5/allegro_image.h>

#include "beingindex.h"

#include "nameindex.h"
#include "roleindex.h"
#include "placeindex.h"

#include "image.h"
#include "camera.h"

#include "inventory.h"

class Being
{
public:
    static std::vector<Being*>people;

/// State
    bool active;
    int activity;

private:
/// Biography
    std::string name;
    int ancestry;
    int role;
    std::string roleString;
    int hometown;

public:
/// Stats

    int attributes[AttributeIndex::NUM_ATTRIBUTES];
    std::string attributesString[AttributeIndex::NUM_ATTRIBUTES];

    std::map<int,int>ancestryFeats;
    std::map<int,int>roleFeats;

/// Objectives
    //int objectiveA;
    //int objectiveB;
    //int objectiveC;

/// Abilities
    float travelSpeed;

/// Drawing
    bool facingLeft;
    //const int beingSpriteNumVariants = 2; // In total. Not counting from zero.
    int spriteVariant;
    int spriteWidth, spriteHeight;
    int currentFrame, maxFrame;
    int frameDelayCount;     // Meant to iterate from zero.
    int frameDelayThreshold; // Higher value increases time between frame update

    //int portraitRow, portraitCol;

    Inventory inventory;

/// Status Bubble


/// Constructor and destructor
    Being();
    ~Being();

/// State functions
    void SetActive(bool a);
    void SetActivity(int act);
    bool IsActive();
/// Biography functions
    void SetName(std::string n);
    std::string GetName(){return name;}
    void SetAncestry(int a);
    int GetAncestry(){return ancestry;}
    void SetRole(int whichRole);
    int GetRole(){return role;}
    std::string GetRoleString(){return roleString;}
    void SetHometown(int h);
    int GetHometown(){return hometown;}

/// Stats functions
    void SetAttribute(int which_attribute, int value);

/// Progress
    void Progress();

/// Drawing
    void DrawActivity(float x, float y);
    void ProgressAnimation();
};

#endif // BEING_H_INCLUDED

