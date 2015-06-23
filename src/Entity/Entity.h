/*
The MIT License (MIT)

Copyright (c) 2015 Qusai Al Shidi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include "../States/State.h"

#include <iostream>
#include <string>
#include <memory>

using namespace std;

namespace Engine
{
    class IEntity : public enable_shared_from_this<IEntity>
    {
    protected:
        unsigned short          m_id;      //Unique GlobalID
        string                  m_type;     //Type of entity eg "character"

        static unsigned short   next_id;

    public:
        IEntity(){next_id++; m_id=next_id;} //Automatically set GlobalID
        virtual ~IEntity(){} //Destructors are defined by inherited
        
        const unsigned int  id() {return m_id;}
        const string        type() {return m_type;}

        virtual void        on_start(const StatePtr& state)=0;
        virtual void        on_exit()=0;
        virtual void        update()=0;
        
        inline void         error(const string& message) { cerr << m_id << ":" << m_type << ":" << "Error:" << message << endl; }
        inline void         warning(const string& message) { cerr << m_id << ":" << m_type << ":" << "Warning:" << message << endl; }
    };
}



