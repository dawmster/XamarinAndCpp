/*
 *  MyCppLibPriv.hpp
 *  MyCppLib
 *
 *  Created by Mikołaj Dawidowski on 24.05.2017.
 *  Copyright © 2017 Abc. All rights reserved.
 *
 */
#ifndef MyCppLib_Priv
#define MyCppLib_Priv

/* The classes below are not exported */
#pragma GCC visibility push(hidden)



class MyCppLibPriv
{
    public:
    void HelloWorldPriv(const char *);

};

class MyCppLib
{
public:
    void HelloWorld(const char *);
};


#pragma GCC visibility pop

#endif
