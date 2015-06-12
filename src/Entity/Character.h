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

using namespace std;

namespace Engine
{
    enum State
    {
        STANDING,
        WALKING,
        DYING
    };


    class Character : public IEntity
    {
    protected:
        // Graphics
        Ness::ZNodePtr              m_scene;
        Ness::AnimatedSpritePtr     m_sprite;
        string                      m_spritesheet;
        // Game
        State                       c_state;
        string                      c_first_name;
        string                      c_middle_name;
        string                      c_last_name;
        float                       c_walkspeed;
    public:
        Character();
        ~Character(){on_exit();}
        void                        add_character();
        void                        update();
        void                        on_start(const StatePtr& state);
        void                        on_exit();
    };
    
    typedef shared_ptr<Character> CharPtr;
    
    CharPtr create_character();
}
