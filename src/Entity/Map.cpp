/*
The MIT License (MIT)

Copyright (c) 2015 Qusai Al Shidi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "../Game.h"
#include "Map.h"

#include "../States/State.h"

#include <iostream>
#include <string>

using namespace std;
using namespace Engine;

Map::Map(const string& tmxfile)
{
    m_type="map";
    // Load tmx file
    TmxMapPtr tmx = make_shared<Tmx::Map>();
    m_tmx = tmx;
    m_tmx->ParseFile(tmxfile);

    // Error checking.
    if (m_tmx->HasError())
        cerr << m_gid << ":" << m_type << ":tmx=" << tmxfile << ":" << endl << m_tmx->GetErrorCode() << ":" << m_tmx->GetErrorText() << endl;

    m_dimensions = Ness::Sizei(m_tmx->GetWidth(),m_tmx->GetHeight());
    m_tilesize = Ness::Sizei(m_tmx->GetTileWidth(),m_tmx->GetTileHeight());

    const Tmx::Tileset* tileset = m_tmx->GetTileset(0);
    m_spritesheet = tileset->GetImage()->GetSource();
    cout << "Loading Spritesheet:" << m_spritesheet << endl;
    m_sheetgrid = Ness::Pointi(tileset->GetImage()->GetWidth()/m_tmx->GetTileWidth(),tileset->GetImage()->GetHeight()/m_tmx->GetTileHeight());
}

void Map::on_start(const StatePtr& state)
{
    Ness::Renderer* renderer = Game::instance().renderer();
    m_tilemap = make_shared<IsoTileMap>(renderer, m_spritesheet, m_dimensions, m_tilesize);
    state->znode()->add(m_tilemap);
    m_tilemap->set_all_tiles_type(Ness::Pointi(0, 0), m_sheetgrid);

    //const Tmx::TileLayer *layer = m_tmx->GetTileLayer(0);

}

void Map::on_exit()
{

}

void Map::update()
{

}


Map::Map()
{
    m_type="map";
}

MapPtr Engine::create_map(const string& tmxfile)
{
    MapPtr creation;
    if(tmxfile=="")
        creation = make_shared<Map>();
    else
        creation = make_shared<Map>(tmxfile);
    return creation;
}