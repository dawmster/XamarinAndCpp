/*
 *  MyCppLib.hpp
 *  MyCppLib
 *
 *  Created by Mikołaj Dawidowski on 24.05.2017.
 *  Copyright © 2017 Abc. All rights reserved.
 *
 */

#ifndef MyCppLib_
#define MyCppLib_

/* The classes below are exported */
#pragma GCC visibility push(default)


extern "C" {
    int my_C_Function();
    int my_second_C_Function();

}
#pragma GCC visibility pop

#endif
