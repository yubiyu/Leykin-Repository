#pragma once

struct GameMode
{
    enum enumGameModes
    {
        GAME_MODE_STORY, // Story mode from the player perspective.
        GAME_MODE_SIMULATION // Omniscient perspective. NPC caravans only. Click on beings and towns for full information.
    };

    static int mode;

    static bool isOmniscient;

    static void Initialize(int which_mode)
    {
        mode = which_mode;
        isOmniscient = false;

        switch(mode)
        {
        case GAME_MODE_STORY:

            break;

        case GAME_MODE_SIMULATION:
            isOmniscient = true;

            break;
        }

    }
};
