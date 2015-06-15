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

#pragma once

#include "../Game.h"
#include "Tile.h"
#include "tmxparser/Tmx.h"

using namespace std;

typedef shared_ptr<Tmx::Map> TmxMapPtr;


// IsoTileMap implementation and the pointer definition and stuff
class IsoTileMap : public Ness::TileMap
{
public:
	// constructor (just call the TileMap's ctor and then fix tiles position to be isometric)
	IsoTileMap(Ness::Renderer* renderer, const Ness::String& spriteFile, const Ness::Sizei& mapSize, const Ness::Size& singleTileSize = Ness::Size(36, 36),
			const Ness::Size& tilesDistance = Ness::Size::ZERO, Ness::TCreateTileSprites createSpriteFunction = nullptr) :
	TileMap(renderer, spriteFile, mapSize, singleTileSize, tilesDistance, createSpriteFunction)
	{
		for (int i = 0; i < m_size.x; i++)
		{
			for (int j = 0; j < m_size.y; j++)
			{
				m_sprites_distance.y = m_tile_size.y * 0.45f;
				if (j % 2) m_sprites[i][j]->set_position(m_sprites[i][j]->get_position() - Ness::Point(m_tile_size.x * 0.5f, 0.0f));
				m_sprites[i][j]->set_position(Ness::Point(m_sprites[i][j]->get_position().x, j * m_sprites_distance.y));
				m_sprites[i][j]->set_blend_mode(Ness::BLEND_MODE_BLEND);
			}
		}
		set_tiles_anchor(Ness::Point(0.5f, 1.0f));
	}

protected:
	// override the function to get how many tiles in screen on x axis, adds +2 because we change every second line position
	virtual int get_tiles_in_screen_x()
	{
		return TileMap::get_tiles_in_screen_x() + 1;
	}
};

namespace Ness
{
    typedef shared_ptr<IsoTileMap> IsoTileMapPtr;
}

namespace Engine
{
    /*
    class Tile : public IEntity
    {
        StatePtr                    m_state;
        Ness::ZNodePtr              m_scene;
        Ness::AnimatedSpritePtr     m_sprite;

    };
    */
    class Map : public IEntity
    {
        friend class Tile;
    protected:
        //Members
        Ness::Sizei                 m_dimensions=Ness::Sizei(100,100);
        Ness::Sizei                 m_tilesize=Ness::Sizei(128,75);
        Ness::Pointi                m_sheetgrid=Ness::Pointi(2,4);
        string                      m_spritesheet="resources/gfx/tilemap.png";
        Ness::IsoTileMapPtr         m_tilemap;
        vector<TilePtr>             m_tilelayer[32];
        
        //tmx members
        TmxMapPtr                   m_tmx;
        unsigned int                m_tmx_first_gid;

    public:
        Map();
        ~Map(){on_exit();}
        Map(const string& tmxfile);
        void                        on_start(const StatePtr& state);
        void                        on_exit();
        void                        update();
        
        const Ness::IsoTileMapPtr& tilemap() { return m_tilemap; }

    };

    typedef shared_ptr<Map>      MapPtr;

    MapPtr create_map(const string& tmxfile=string(""));
}

