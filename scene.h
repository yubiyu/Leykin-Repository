#pragma once

struct Scene
{
    enum enumScene
    {
        SCENE_TITLE,

        SCENE_WORLDVIEW,
        SCENE_PARTYVIEW,
        SCENE_CARGOVIEW,

        SCENE_ARCHIVE,
        SCENE_SETTINGS,
        SCENE_CHARACTER_CREATION,
    };
    static int scene;

    enum enumInputContext
    {
        INPUT_CONTEXT_TITLE,

        INPUT_CONTEXT_WORLDVIEW,
        INPUT_CONTEXT_PARTYVIEW,
        INPUT_CONTEXT_CARGOVIEW,

        INPUT_CONTEXT_ARCHIVE,
        INPUT_CONTEXT_SETTINGS,
        INPUT_CONTEXT_CHARACTER_CREATION
    };
    static int inputContext;

    static void Initialize();
    static void ChangeScene(int whichScene);
    static void ChangeInputContext(int whichContext);
};
