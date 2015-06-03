#include "Map.h"
#include "../Game.h"
#include <iostream>

using namespace std;
using namespace Engine;

Map::Map(string tmxfile)
{
    m_type="map";
    // Load tmx file
    TmxMapPtr tmxmap(new Tmx::Map);
    m_tmx = tmxmap;
    m_tmx->ParseFile(tmxfile);

    // Error checking.
    if (m_tmx->HasError())
        cerr << "Map " << m_gid << ":" << tmxfile << " error:" << endl << m_tmx->GetErrorCode() << ":" << m_tmx->GetErrorText() << endl;

    m_dimensions = Ness::Sizei(m_tmx->GetWidth(),m_tmx->GetHeight());
    m_tilesize = Ness::Sizei(m_tmx->GetTileWidth(),m_tmx->GetTileHeight());

    const Tmx::Tileset* tileset = m_tmx->GetTileset(0);
    m_spritesheet = tileset->GetImage()->GetSource();
    m_sheetgrid = Ness::Pointi(tileset->GetImage()->GetWidth()/m_tmx->GetTileWidth(),tileset->GetImage()->GetHeight()/m_tmx->GetTileHeight());



}

void Map::on_start(StatePtr state)
{
    m_state = state;
    Ness::Renderer* renderer = Game::instance().renderer();
    Ness::IsoTileMapPtr map(new IsoTileMap(renderer, m_spritesheet, m_dimensions, m_tilesize));
    m_state->znode()->add(map);
    map->set_all_tiles_type(Ness::Pointi(0, 0), m_sheetgrid);

    //const Tmx::TileLayer *layer = m_tmx->GetTileLayer(0);

}

void Map::on_exit()
{

}

void Map::update()
{

}


Map::Map(){m_type="map";}
