#include <iostream>
#include <string>
#include "NessEngine/NessEngine.h"

#include "Game.h"
#include "Entity/Entity.h"
#include "Entity/Character.h"
#include "States/State.h"

using namespace std;

int main(int argc, char** argv)
{
    //Must start with this
    Ness::init();

    Engine::Game::instance().init();
    Engine::StatePtr teststate(new Engine::LocalMapState);
    teststate->on_start(Engine::Game::instance());
    Engine::Game::instance().push_state(teststate);
    Engine::Character charlie;
    charlie.on_start(teststate);

    Ness::Utils::EventsPoller EventsPoller;
    Ness::Utils::ApplicationEvents app;
    EventsPoller.add_handler(app);

    while( !app.got_quit() )
    {
        EventsPoller.poll_events();
        Engine::Game::instance().update();
    }
}
