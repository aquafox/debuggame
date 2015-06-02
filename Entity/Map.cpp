#include "Map.h"
#include "../Game.h"
#include <iostream>

using namespace std;
using namespace Engine;

Map::Map(string tmxfile)
{
    // Load tmx file
    TmxMapPtr tmx(new Tmx::Map);
    tmx->ParseFile(tmxfile);

    // Error checking.
    if (tmx->HasError())
        cerr << "Map " << tmxfile << " error:" << endl << tmx->GetErrorCode() << ":" << tmx->GetErrorText() << endl;

    m_dimensions = Ness::Sizei(tmx->GetWidth(),tmx->GetHeight());
    m_tilesize = Ness::Sizei(tmx->GetTileWidth(),tmx->GetTileHeight());


}

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
