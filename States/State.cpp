#include "State.h"
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

    // Create a background
    create_image("resources/gfx/bg.png",this);
    MapPtr gMap(new Map);
    // Map gMap("resources/maps/map.tmx");
    StatePtr thisone(this);
    gMap->on_start(thisone);
    Game::instance().add_map(gMap);




}


void create_image(string img_file, IGameState* gamestate)
{
    Ness::SpritePtr image = gamestate->znode()->create_sprite(img_file);
    gamestate->add_sprite(image);
}

void LocalMapState::update()
{
    m_scene->render();
}

void LocalMapState::on_exit() {}
