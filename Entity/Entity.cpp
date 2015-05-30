#include "Entity.h"
#include "../NessEngine/NessEngine.h"

using namespace Engine;

unsigned int    IEntity::get_gid()
{
    return m_gid;
}

string          IEntity::get_type()
{
    return m_type;
}
string          IEntity::get_id()
{
    return m_id;
}
