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
#include "LocalMap.h"
#include "../Entity/Character.h"
#include "../Entity/Map.h"

using namespace Engine;
using namespace std;

void LocalMapState::on_start()
{
    // Set the initial scene
    m_scene = Game::instance().renderer()->create_scene();
    m_zscene = m_scene->create_znode();

    m_map = create_map();
    // Map gMap("resources/maps/map.tmx");
    m_map->on_start(shared_from_this());
    
    auto charlie = create_character();
    charlie->on_start(shared_from_this());
    m_chars.push_back(charlie);
}

void LocalMapState::update()
{
    m_scene->render();
}

void LocalMapState::on_exit()
{
    // Delete characters
    for (auto it = m_chars.begin(); it != m_chars.end(); it++)
    {
        (*it).reset();
    }
    
    m_map.reset();
}