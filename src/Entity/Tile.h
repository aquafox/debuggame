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
#include "Character.h"

namespace Engine
{
    class Map;
    typedef shared_ptr<Map> MapPtr;
    
    class Tile : public IEntity
    {
    protected:
        //Members
        weak_ptr<Map>       m_map; //Parent
        Ness::SpritePtr     m_sprite; //Sprite
        weak_ptr<Character> m_char; //Character standing on the tile if any
        bool                m_walkable=true; //Can characters walk on this
        Ness::Pointi        m_grid_position=Ness::Pointi(0,0); //Where it is on the iso grid
        Ness::Pointi        m_sheet_position=Ness::Pointi(0,0); //which sprite on sheet it is
        
    public:
        Tile(const MapPtr& map, const Ness::Pointi& grid_position = Ness::Pointi(0,0));
        ~Tile() { on_exit(); }
        
        void on_exit();
        void on_start(const StatePtr& state);
        void update();
    };
    
    //Types
    typedef shared_ptr<Tile> TilePtr;
    
    TilePtr create_tile(const MapPtr& map, const Ness::Pointi& grid_position = Ness::Pointi(0,0));
}