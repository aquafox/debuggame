#include "Map.h"
#include "../Game.h"

using namespace std;
using namespace Engine;

void Map::on_start(StatePtr state)
{
    m_state = state;
    Ness::Renderer* renderer = Game::instance().renderer();
    Ness::IsoTileMapPtr map(new IsoTileMap(renderer, m_spritesheet, m_dimensions, m_tilesize));
    m_state->znode()->add(map);
    map->set_all_tiles_type(Ness::Pointi(0, 0), m_sheetgrid);

}

void Map::on_exit()
{

}

void Map::update()
{

}


Map::Map(){m_type="map";}
