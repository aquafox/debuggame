#pragma once

#include <string>

using namespace std;

namespace Engine
{
    class bEntity
    {
    protected:
        unsigned int    m_gid;      //Unique game ID
        string          m_id;       //Name of the entity
        string          m_type;     //Type of entity eg "character"

    public:
        unsigned int    get_gid();
        string          get_type();
        string          get_id();
    };
}
