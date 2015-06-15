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

#include "../NessEngine/NessEngine.h"

#include <memory>

using namespace std;

namespace Engine
{
    // Abstract base class for game states.
    // States are to be added to the stack Game::m_statestack.

    class IGameState : public enable_shared_from_this<IGameState>
    {
    protected:
        Ness::ScenePtr              m_scene;
        Ness::ZNodePtr              m_zscene;
    public:
        // Called during Game::update()
        virtual void                update() = 0;
        // Called during Game::push_state()
        virtual void                on_start() = 0;
        // Called during Game::pop_state()
        virtual void                on_exit() = 0;

        // Just in case this needs to be more complicated
        Ness::ZNodePtr              znode() { return m_zscene; };
    };

    class MainMenuState : public IGameState
    {
    public:
        void                        update();
        void                        on_start();
        void                        on_exit();
    };

    class LoadState : public IGameState
    {
    public:
        void                        update();
        void                        on_start();
        void                        on_exit();
    };
    class SaveState : public IGameState
    {
    public:
        void                        update();
        void                        on_start();
        void                        on_exit();
    };

    // Make code look cleaner
    typedef shared_ptr<IGameState> StatePtr;
}
