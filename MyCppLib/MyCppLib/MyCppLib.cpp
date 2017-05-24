/*
 *  MyCppLib.cpp
 *  MyCppLib
 *
 *  Created by Mikołaj Dawidowski on 24.05.2017.
 *  Copyright © 2017 Abc. All rights reserved.
 *
 */

#include <iostream>
#include "MyCppLib.hpp"
#include "MyCppLibPriv.hpp"

void MyCppLib::HelloWorld(const char * s)
{
    MyCppLibPriv *theObj = new MyCppLibPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void MyCppLibPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};


int my_C_Function() {
    return 9999;
}
