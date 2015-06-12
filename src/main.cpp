#include <iostream>
#include <string>
#include "NessEngine/NessEngine.h"

#include "Game.h"
#include "Entity/Entity.h"
#include "Entity/Character.h"
#include "States/LocalMap.h"

using namespace std;

int main(int argc, char** argv)
{
    //Graphics engine init
    Ness::init();
    //Game init
    Engine::Game::instance().init();
    
    auto localmap = make_shared<Engine::LocalMapState>();
    localmap->on_start();
    Engine::Game::instance().push_state(localmap);

    Ness::Utils::EventsPoller EventsPoller;
    Ness::Utils::ApplicationEvents app;
    EventsPoller.add_handler(app);

    while( !app.got_quit() )
    {
        EventsPoller.poll_events();
        Engine::Game::instance().update();
    }

    return 0;
}
