#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

struct Scene
{
    enum enumScene
    {
        SCENE_TITLE,
        SCENE_OVERWORLD,
        SCENE_ARCHIVE,
        SCENE_SETTINGS,
        SCENE_CHARACTER_CREATION
    };
    static int scene;

    enum enumInputContext
    {
        INPUT_CONTEXT_TITLE,
        INPUT_CONTEXT_OVERWORLD,
        INPUT_CONTEXT_ARCHIVE,
        INPUT_CONTEXT_SETTINGS,
        INPUT_CONTEXT_CHARACTER_CREATION
    };
    static int inputContext;

    static void Initialize();
    static void ChangeScene(int whichScene);
    static void ChangeInputContext(int whichContext);
};


#endif // SCENE_H_INCLUDED
