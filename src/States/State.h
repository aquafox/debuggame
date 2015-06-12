#pragma once

#include "../NessEngine/NessEngine.h"

#include <vector>
#include <memory>

using namespace std;

namespace Engine
{
    // Abstract base class for game states.
    // States are to be added to the stack Game::m_statestack.
    
    //Forward declarations
    class Game;

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
