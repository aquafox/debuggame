#pragma once

#include "../States/State.h"
#include "../NessEngine/NessEngine.h"
#include "Entity.h"
#include "tmxparser/Tmx.h"
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
        Ness::Sizei                 m_dimensions=Ness::Sizei(100,100);
        Ness::Sizei                 m_tilesize=Ness::Sizei(128,75);
        Ness::Pointi                m_sheetgrid=Ness::Pointi(2,4);
        string                      m_spritesheet="resources/gfx/tilemap.png";
        Ness::IsoTileMapPtr         m_tilemap;
        TmxMapPtr                   m_tmx;

        StatePtr                    m_state;
        Ness::ZNodePtr              m_scene;

    public:
        Map();
        Map(string tmxfile);
        void                        on_start(const StatePtr& state);
        void                        on_exit();
        void                        update();

    };

    typedef shared_ptr<Map>      MapPtr;

    const MapPtr& make_map(const string tmxfile);
}

