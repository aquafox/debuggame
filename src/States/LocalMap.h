#pragma once

#include "../Game.h"
#include "../Entity/Map.h"
#include "../Entity/Character.h"

using namespace std;

namespace Engine
{
    class LocalMapState : public IGameState
    {
        // Provide the loading and saving processes access.
        friend class LoadState;
        friend class SaveState;
        
        // Members
        MapPtr                      m_map;
        vector<CharPtr>             m_chars;                     
        
        public:
        void                        update();
        void                        on_start();
        void                        on_exit();
    };
}