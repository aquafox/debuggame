#pragma once

#include "Entity.h"
#include <string>
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
        State                       m_state;
        string                      c_first_name;
        string                      c_middle_name;
        string                      c_last_name;
        float                       c_walkspeed;
    public:
        Character();
        ~Character();
        void                        add_character(Game &game, StatePtr state);
        void                        set_spritesheet(string sheet_file);
        void                        update();
    };
}
