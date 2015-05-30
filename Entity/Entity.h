#pragma once

#include <string>
#include "../States/State.h"

using namespace std;

namespace Engine
{
    class IEntity
    {
    protected:
        unsigned int        m_gid;      //Unique GlobalID
        string              m_id;       //Name of the entity
        string              m_type;     //Type of entity eg "character"

        static unsigned int next_gid;

    public:
        IEntity(){next_gid++; m_gid=next_gid;}
        unsigned int    get_gid() {return m_gid;}
        string          get_type() {return m_type;}
        string          get_id() {return m_id;}

        virtual void    on_start(StatePtr state)=0;
        virtual void    on_exit()=0;
        virtual void    update()=0;
    };
}



