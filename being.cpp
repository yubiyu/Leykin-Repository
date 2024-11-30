#include "being.h"

std::vector<Being*> Being::people;

Being::Being()
{
    SetActive(true);
    SetActivity(BeingIndex::ACT_WALKING);

    SetName("Default");
    SetAncestry(rand()%AncestryIndex::NUM_ANCESTRIES);
    //std::cout << "ancestry " << ancestry << std::endl;
    SetRole(rand()%RoleIndex::NUM_ROLES);
    //std::cout << "role " << role << std::endl;
    SetHometown(rand()%PlaceIndex::NUM_PLACES);
    //std::cout << "hometown " << hometown << std::endl;
    //std::cout << std::endl;

    for(size_t i = AttributeIndex::ATTRIBUTE_MARKER_FIRST; i < AttributeIndex::NUM_ATTRIBUTES; i++)
    {
        SetAttribute(i, 6);
    }

    ResetSkills();

    travelSpeed = 1.0;

    facingLeft = false;

    //std::cout << "Being created." << std::endl;
}

Being::~Being()
{
    //std::cout << "Being deleted." << std::endl;
}

void Being::SetActive(bool a)
{
    active = a;
}

void Being::SetActivity(int act)
{
    activity = act;
    currentFrame = 0;
    frameDelayCount = 0;
    frameDelayThreshold = 6;

    switch(activity)
    {
    case BeingIndex::ACT_WALKING:
        maxFrame = 1;
        break;
    }
}

void Being::SetName(std::string n)
{
    name = n;
}
void Being::SetAncestry(int a)
{
    ancestry = a;
    spriteWidth = Tile::WIDTH;
    spriteHeight = Tile::HEIGHT;
    spriteVariant = rand()% Image::beingNumSpriteVariants.at(ancestry);

    ancestryFeats.clear();
    ancestryFeats = AncestryIndex::ancestryFeats.at(ancestry);

    ancestrySkills.clear();
    ancestrySkills = AncestryIndex::ancestrySkills.at(ancestry);
    UpdateTotalSkills();
}

void Being::SetRole(int whichRole)
{
    role = whichRole;
    roleString = RoleIndex::roleNames.at(role);

    roleFeats.clear();
    roleFeats = RoleIndex::roleFeats.at(role);

    roleSkills.clear();
    roleSkills = RoleIndex::roleSkills.at(role);
    UpdateTotalSkills();
}

void Being::SetHometown(int h)
{
    hometown = h;
}

void Being::SetAttribute(int which_attribute, int value)
{
    attributes[which_attribute] = value;
    attributesString[which_attribute] = std::to_string(value);
}


bool Being::IsActive()
{
    return active;
}

void Being::Progress()
{
    ProgressAnimation();
}

void Being::DrawActivity(float x, float y)
{
    //if(x > Camera::OVERWORLD_MIN_DRAW_X && x < Camera::OVERWORLD_MAX_DRAW_X
    //        && y > Camera::OVERWORLD_MIN_DRAW_Y && y < Camera::OVERWORLD_MAX_DRAW_Y)
    //{
        int f = 0;
        if(!facingLeft)
            f = ALLEGRO_FLIP_HORIZONTAL;

        if(activity == BeingIndex::ACT_WALKING)
            al_draw_bitmap_region(Image::beingPng[ancestry],
                                  spriteVariant*Image::beingNumWalkFrames*spriteWidth + spriteWidth*currentFrame,
                                  spriteHeight*activity,
                                  spriteWidth,
                                  spriteHeight,
                                  x - (spriteWidth/2),
                                  y - (spriteHeight/2),
                                  f);
    //}
}

void Being::ProgressAnimation()
{
    if(maxFrame > 0)
    {
        frameDelayCount++;
        if(frameDelayCount >= frameDelayThreshold)
        {
            frameDelayCount = 0;
            currentFrame++;
            if(currentFrame > maxFrame)
                currentFrame = 0;
        }
    }
}
