#include "Game.h"
#include "States/State.h"
#include "NessEngine/NessEngine.h"
#include <memory>

using namespace std;
using namespace Engine;

bool Game::init()
{
    StatePtr teststate(new LocalMapState);
    teststate->on_start(this);
    m_statestack.push_back(teststate);

    return true; //Successful init

}

Game::Game() :  g_renderer("Debug RPG", Ness::Sizei(800,600))
{
}


Ness::Renderer* Game::renderer()
{
    return &g_renderer;
}

void Game::update()
{

        g_renderer.start_frame();
        // Here be dragons.
        StatePtr topstate = *(m_statestack.end());
        topstate->update();
        g_renderer.end_frame();
}


Game::~Game() {}


