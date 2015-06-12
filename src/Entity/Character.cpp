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

#include "Character.h"

using namespace std;
using namespace Engine;

Character::Character()
{
    m_type = "character";
}

/*void Character::add_character()
{
    m_scene = state->znode();
    m_sprite = m_scene->create_animated_sprite(m_spritesheet);
    m_sprite->set_source_from_sprite_sheet(Ness::Pointi(0,0),Ness::Sizei(3,4));
    m_sprite->set_blend_mode(Ness::BLEND_MODE_BLEND);
    //m_sprite->set_scale(1.0f);
    m_sprite->set_position(Ness::Point(100, 100));
    m_sprite->set_anchor(Ness::Point::HALF);
    state.reset();
}*/


void Character::update() {}

void Character::on_start(const StatePtr& state)
{
    m_spritesheet = "resources/gfx/chars/char001.png";
//    add_character(); //Not sure about this function
    m_scene = state->znode();
    m_sprite = m_scene->create_animated_sprite(m_spritesheet);
    m_sprite->set_source_from_sprite_sheet(Ness::Pointi(0,0),Ness::Sizei(3,4));
    m_sprite->set_blend_mode(Ness::BLEND_MODE_BLEND);
    //m_sprite->set_scale(1.0f);
    m_sprite->set_position(Ness::Point(100, 100));
    m_sprite->set_anchor(Ness::Point::HALF);
}

void Character::on_exit()
{
    m_scene.reset();
    m_sprite.reset();
}

CharPtr Engine::create_character()
{
    auto creation = make_shared<Character>();
    return creation;
}