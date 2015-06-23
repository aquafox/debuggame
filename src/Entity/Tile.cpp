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

#include "Tile.h"
#include "Map.h"

using namespace Engine;
using namespace std;

Tile::Tile(const MapPtr& map, const Ness::Pointi& grid_position)
{
    m_map = map;
    m_grid_position = grid_position;
    m_sprite = map->tilemap()->get_sprite(m_grid_position);
}

void Tile::on_start(const StatePtr& state)
{
}

void Tile::update() {}
void Tile::on_exit() {}

void Tile::change_sprite_to(const Ness::Pointi& sheet_position)
{
    m_sheet_position = sheet_position;
    if (m_sprite)
    {
        if (auto map = m_map.lock())
            m_sprite->set_source_from_sprite_sheet(sheet_position,map->sheet_grid());
        else
            error("Can't change sprite because no map has been assigned yet.");
    }
    else
    {
        error("Can't change sprite because no sprite has been assigned yet.");
    }
}

TilePtr Engine::create_tile(const MapPtr& map, const Ness::Pointi& grid_position)
{
    auto creation = make_shared<Tile>(map,grid_position);
    return creation;
}