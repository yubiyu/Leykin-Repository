#include "game.h"

bool Game::exit;
bool Game::redraw;

void Game::MainLoop()
{
    while(!exit)
    {
        al_wait_for_event(Event::eventQueue, &Event::event);

        if(Event::event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            exit = true;

        if(Event::event.type == ALLEGRO_EVENT_KEY_DOWN)
            Keyboard::InputKeydown();

        if(Event::event.type == ALLEGRO_EVENT_KEY_UP)
            Keyboard::InputKeyup();

        /*
        if(Event::event.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)
        {

        }

        if(Event::event.type == ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY)
        {

        }
        */

        if(Event::event.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            Mouse::InputMouseXY();
            Mouse::InputMousewheel();
        }

        if(Event::event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            Mouse::InputMouseDown();

        if(Event::event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
            Mouse::InputMouseUp();

        if(Event::event.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;

            InputSwitchboard();
            LogicSwitchboard();

            Audio::Logic();

            Mouse::mouseAxesAltered = false;
        }

        if(redraw && al_is_event_queue_empty(Event::eventQueue))
        {
            DrawingSwitchboard();
        }
    }
}

bool Game::Initialize(char **argv)
{
    exit = false;
    redraw = true;

    srand(time(NULL));

    al_install_system(ALLEGRO_VERSION_INT, NULL);
    Display::Initialize();
    Keyboard::Initialize();
    Mouse::Initialize();
    Timer::Initialize();
    Event::Initialize();

    Filesystem::Initialize(argv);
    Filesystem::SetPhysfsFileInterface();
    Image::Initialize();
    Font::Initialize();
    Audio::Initialize();

    Filesystem::SetStandardFileInterface();
    Configuration::LoadStringConfigurations();
    AncestryIndex::ApplyStringConfigurations();
    RoleIndex::ApplyStringConfigurations();
    InventoryIndex::ApplyStringConfigurations();
    PlaceIndex::ApplyStringConfigurations();
    Encyclopedia::ApplyStringConfigurations();
    Configuration::UnloadStringConfigurations();

    Palette::InitializeOrthos();
    Palette::InitializeGB();
    Palette::InitializeBreath();

    GameMode::Initialize(GameMode::GAME_MODE_SIMULATION);
    Scene::Initialize();
    Camera::Initialize();

    // *Might* not want to initialize everything, later.
    Title::Initialize();
    CharacterCreation::Initialize();
    Worldview::Initialize();
    PartyView::Initialize();
    CargoView::Initialize();
    Settings::Initialize();
    Archive::Initialize();

    return true;
}

void Game::Uninitialize()
{
    //CharacterCreation::Uninitialize();
    Worldview::Uninitialize();
    PartyView::Uninitialize();
    CargoView::Uninitialize();

    Camera::Uninitialize();

    Audio::Uninitialize();
    Font::Uninitialize();
    Image::Uninitialize();
    Filesystem::Uninitialize();

    Event::Uninitialize();
    Timer::Uninitialize();
    Mouse::Uninitialize();
    Keyboard::Uninitialize();
    Display::Uninitialize();

    al_uninstall_system();

}


void Game::InputSwitchboard()
{
    Keyboard::InputKeyHold();
    Mouse::InputMouseButtonHold();

    switch(Scene::inputContext)
    {
    case Scene::INPUT_CONTEXT_TITLE:
        Title::Input();
        break;

    case Scene::INPUT_CONTEXT_WORLDVIEW:
        Worldview::Input();
        break;
    case Scene::INPUT_CONTEXT_PARTYVIEW:
        PartyView::Input();
        break;

    case Scene::INPUT_CONTEXT_CARGOVIEW:
        CargoView::Input();
        break;

    case Scene::INPUT_CONTEXT_ARCHIVE:
        Archive::Input();
        break;
    case Scene::INPUT_CONTEXT_SETTINGS:
        Settings::Input();
        break;
    case Scene::INPUT_CONTEXT_CHARACTER_CREATION:
        CharacterCreation::InputSwitchboard();
        break;
    }
}

void Game::LogicSwitchboard()
{
    switch(Scene::scene)
    {
    case Scene::SCENE_TITLE:
        Title::Logic();
        if(Title::exitOptionSelected)
            exit = true;
        break;

    case Scene::SCENE_WORLDVIEW:
        Worldview::Logic();
        break;
    case Scene::SCENE_PARTYVIEW:
        PartyView::Logic();
        break;

    case Scene::SCENE_CARGOVIEW:
        CargoView::Logic();
        break;

    case Scene::SCENE_SETTINGS:
        Settings::Logic();
        break;
    case Scene::SCENE_ARCHIVE:
        Archive::Logic();
        break;

    case Scene::SCENE_CHARACTER_CREATION:
        CharacterCreation::LogicSwitchboard();
    }
}

void Game::DrawingSwitchboard()
{
    Game::redraw = false;
    al_clear_to_color(COLKEY_BACKGROUND);

    switch(Scene::scene)
    {
    case Scene::SCENE_TITLE:
        Title::Drawing();
        break;

    case Scene::SCENE_WORLDVIEW:
        Worldview::Drawing();
        break;
    case Scene::SCENE_PARTYVIEW:
        PartyView::Drawing();
        break;
    case Scene::SCENE_CARGOVIEW:
        CargoView::Drawing();
        break;

    case Scene::SCENE_SETTINGS:
        Settings::Drawing();
        break;
    case Scene::SCENE_ARCHIVE:
        Archive::Drawing();
        break;
    case Scene::SCENE_CHARACTER_CREATION:
        CharacterCreation::DrawingSwitchboard();
        break;
    }

    al_flip_display();
}
