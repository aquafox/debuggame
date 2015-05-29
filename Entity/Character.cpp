#include "../NessEngine/NessEngine.h"
#include "Character.h"
#include <string>

using namespace std;
using namespace Engine;

Character::Character()
{
    m_type = "char";
}

void Character::add_character(Game *current_game)
{
//    m_scene = current_game->get_zscene();
    m_sprite = (*m_scene)->create_animated_sprite(m_spritesheet);
    m_sprite->set_source_from_sprite_sheet(Ness::Pointi(0,0),Ness::Sizei(3,4));
    m_sprite->set_blend_mode(Ness::BLEND_MODE_BLEND);
    //m_sprite->set_scale(1.0f);
    m_sprite->set_position(Ness::Point(100, 100));
    m_sprite->set_anchor(Ness::Point::HALF);

}

void Character::set_spritesheet(string sheet_file)
{
    m_spritesheet = sheet_file;
}

Character::~Character()
{

}
