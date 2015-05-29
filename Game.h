#pragma once

#include "States/State.h"

#include "NessEngine/NessEngine.h"
#include <vector>
#include <string>

using namespace std;

namespace Engine
{
    class Game
    {
        Ness::Renderer              g_renderer;
        vector<StatePtr>            m_statestack;

    public:
        Game();
        ~Game();
        bool                        init();
        void                        update();
        void                        push_state(StatePtr state);
        void                        pop_state();
        Ness::Renderer*             renderer();
    };
}



