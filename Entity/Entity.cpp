#include "Entity.h"
#include "../NessEngine/NessEngine.h"

using namespace Engine;

unsigned int    bEntity::get_gid()
{
    return m_gid;
}

string          bEntity::get_type()
{
    return m_type;
}
string          bEntity::get_id()
{
    return m_id;
}
