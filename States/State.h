#pragma once

#include "../NessEngine/NessEngine.h"
#include "../Game.h"

#include <memory>

using namespace std;

namespace Engine
{
    // Abstract base class for game states.
    // States are to be added to the stack Game::m_statestack.
    class IGameState
    {
    protected:
        Game                       *m_game;
        Ness::ScenePtr              m_scene;
        Ness::ZNodePtr              m_zscene;
        vector<Ness::SpritePtr>     m_sprites;
    public:
        // Called during Game::update()
        virtual void                update() = 0;
        // Called during Game::push_state()
        virtual void                on_start(Game* current_game) = 0;
        // Called during Game::pop_state()
        virtual void                on_exit() = 0;

        // Just in case this needs to be more complicated
        Ness::ZNodePtr              znode() { return m_zscene; };
        void                        add_sprite(Ness::SpritePtr sprite) {m_sprites.push_back(sprite);}
    };

    class MainMenuState : public IGameState
    {
    public:
        void                        update();
        void                        on_start(Game* current_game);
        void                        on_exit();
    };

    class LoadState : public IGameState
    {
        void                        update();
        void                        on_start(Game* current_game);
        void                        on_exit();
    };
    class SaveState : public IGameState
    {
        void                        update();
        void                        on_start(Game* current_game);
        void                        on_exit();
    };

    class LocalMapState : public IGameState
    {
        // Provide the loading and saving processes access.
        friend class LoadState;
        friend class SaveState;

        void                        update();
        void                        on_start(Game* current_game);
        void                        on_exit();
    };

    // Make code look cleaner
    typedef shared_ptr<IGameState> StatePtr;
}

void create_image(string img_file, Engine::IGameState* gamestate);
