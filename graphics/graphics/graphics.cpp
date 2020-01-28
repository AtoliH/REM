//
//  graphics.cpp
//  graphics
//
//  Created by Fire937 on 1/12/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include <iostream>
#include "graphics.hpp"
#include "graphicsPriv.hpp"

void graphics::HelloWorld(const char * s)
{
    graphicsPriv *theObj = new graphicsPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void graphicsPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

