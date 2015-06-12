#pragma once

#include "NessEngine/NessEngine.h"
#include "States/State.h"
#include "Entity/Entity.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;



namespace Engine
{
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
}

