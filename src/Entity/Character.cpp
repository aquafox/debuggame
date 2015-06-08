#include "../NessEngine/NessEngine.h"
#include "Character.h"
#include <string>

using namespace std;
using namespace Engine;

Character::Character()
{
    m_type = "character";
}

void Character::add_character()
{
    m_scene = m_state->znode();
    m_sprite = m_scene->create_animated_sprite(m_spritesheet);
    m_sprite->set_source_from_sprite_sheet(Ness::Pointi(0,0),Ness::Sizei(3,4));
    m_sprite->set_blend_mode(Ness::BLEND_MODE_BLEND);
    //m_sprite->set_scale(1.0f);
    m_sprite->set_position(Ness::Point(100, 100));
    m_sprite->set_anchor(Ness::Point::HALF);

}


void Character::update() {}

void Character::on_start(const StatePtr& state)
{
    m_spritesheet = "resources/gfx/chars/char001.png";
    m_state = state;
    add_character();
}

void Character::on_exit()
{

}

Character::~Character()
{
    m_state.reset();
    m_scene.reset();
    m_sprite.reset();

}
