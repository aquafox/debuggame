#pragma once

#include "NessEngine/NessEngine.h"
#include "States/State.h"
#include <vector>
#include <string>

using namespace std;



namespace Engine
{
    class Game
    {
        Ness::Renderer              g_renderer;
        vector<StatePtr>            m_statestack;
        //Singleton
        static Game*                s_instance;
        Game();

    public:
        static Game*                instance() {if(!s_instance) s_instance = new Game; return s_instance;}
        ~Game();
        bool                        init();
        void                        update();
        void                        push_state(StatePtr state);
        void                        pop_state();
        Ness::Renderer*             renderer();
        StatePtr                    top_state();
    };
}

