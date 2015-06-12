#include "State.h"
#include "../Entity/Map.h"
#include "../Game.h"

using namespace Engine;
using namespace std;

void IGameState::update() {}
void IGameState::on_start() {}
void IGameState::on_exit() {}

void LocalMapState::on_start()
{
    // Set the initial scene
    m_scene = Game::instance().renderer()->create_scene();
    m_zscene = m_scene->create_znode();

    auto gMap = make_map();
    // Map gMap("resources/maps/map.tmx");
//    gMap->on_start(StatePtr(this));
//    Game::instance().add_map(gMap);
}

void LocalMapState::update()
{
    m_scene->render();
}

void LocalMapState::on_exit() {}
