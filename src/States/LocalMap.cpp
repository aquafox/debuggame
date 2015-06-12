#include "../Game.h"
#include "LocalMap.h"
#include "../Entity/Character.h"

using namespace Engine;
using namespace std;

void LocalMapState::on_start()
{
    // Set the initial scene
    m_scene = Game::instance().renderer()->create_scene();
    m_zscene = m_scene->create_znode();

    m_map = create_map();
    // Map gMap("resources/maps/map.tmx");
    m_map->on_start(shared_from_this());
    
    auto charlie = create_character();
    charlie->on_start(shared_from_this());
    m_chars.push_back(charlie);
}

void LocalMapState::update()
{
    m_scene->render();
}

void LocalMapState::on_exit()
{
    // Delete characters
    for (auto it = m_chars.begin(); it != m_chars.end(); it++)
    {
        (*it).reset();
    }
    
    m_map.reset();
}