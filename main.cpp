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

    Engine::Game mygame;
    mygame.init();
    Engine::StatePtr teststate(new Engine::LocalMapState);
    teststate->on_start(&mygame);
    mygame.push_state(teststate);
    Engine::Character charlie;
    charlie.set_spritesheet("resources/gfx/chars/char001.png");
    charlie.add_character(&mygame,teststate);

    Ness::Utils::EventsPoller EventsPoller;
    Ness::Utils::ApplicationEvents app;
    EventsPoller.add_handler(app);

    while( !app.got_quit() )
    {
        EventsPoller.poll_events();
        mygame.update();
    }
}
