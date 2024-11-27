#include "scene.h"

int Scene::scene;
int Scene::inputContext;

void Scene::Initialize()
{
    ChangeScene(SCENE_TITLE);
}

void Scene::ChangeScene(int whichScene)
{
    scene = whichScene;

    switch(scene)
    {
    case SCENE_TITLE:
        ChangeInputContext(INPUT_CONTEXT_TITLE);
        break;

    case SCENE_OVERWORLD:
        ChangeInputContext(INPUT_CONTEXT_OVERWORLD);
        break;

    case SCENE_ARCHIVE:
        ChangeInputContext(INPUT_CONTEXT_ARCHIVE);
        break;

    case SCENE_SETTINGS:
        ChangeInputContext(INPUT_CONTEXT_SETTINGS);
        break;

    case SCENE_CHARACTER_CREATION:
        ChangeInputContext(INPUT_CONTEXT_CHARACTER_CREATION);
        break;
    }
}

void Scene::ChangeInputContext(int whichContext)
{
    inputContext = whichContext;
}
