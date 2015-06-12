#include "Game.h"

#include <memory>

using namespace std;
using namespace Engine;

bool Game::init()
{
    return true; //Successful init

}


Game::Game() : g_renderer("Debug RPG", Ness::Sizei(800,600))
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
        StatePtr topstate = *(m_statestack.end()-1);
        topstate->update();
        g_renderer.end_frame();
}


Game::~Game()
{
    // Kill the game state pointers
    for(auto it = m_statestack.begin(); it != m_statestack.end(); it++)
    {
        it->reset();
    }
}

void Game::push_state(const StatePtr& state)
{
    m_statestack.push_back(state);
}
