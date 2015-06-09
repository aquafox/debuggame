#include "Game.h"
#include "NessEngine/NessEngine.h"
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
    // Reset map
    m_map.reset();
    for(auto it = m_statestack.begin(); it != m_statestack.end(); it++)
    {
        it->reset();
    }
}

void Game::push_state(const StatePtr& state)
{
    m_statestack.push_back(state);
}


void Game::add_map(const MapPtr& map)
{
    m_map = map;
}

const MapPtr& create_map(string tmxfile = "")
{
    MapPtr m;
    if (tmxfile == "")
        m = make_shared<Map>();
    else
        m = make_shared<Map>(tmxfile);
    return m;

}
