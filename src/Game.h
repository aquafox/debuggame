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

#include "NessEngine/NessEngine.h"
#include "States/State.h"
#include "Entity/Entity.h"

#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;



namespace Engine
{
    //Singleton class the game
    class Game
    {
        Game();
        Ness::Renderer              g_renderer;
        vector<StatePtr>            m_statestack;

    public:
        static Game&                instance() {static Game instance; return instance;}
        ~Game();
        bool                        init();
        void                        update();
        void                        push_state(const StatePtr& state);
        void                        pop_state();
        Ness::Renderer*             renderer();
        StatePtr                    top_state();
    };
    
    //Entity Types
    class Map;
    typedef shared_ptr<Map> MapPtr;
    class Tile;
    typedef shared_ptr<Tile> TilePtr;
    class Character;
    typedef shared_ptr<Character> CharPtr;
    
    //GameState Types
    class LocalMapState;
}

