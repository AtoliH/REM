//
//  input.cpp
//  input
//
//  Created by Fire937 on 4/30/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include <iostream>
#include "input.hpp"
#include "inputPriv.hpp"

void input::HelloWorld(const char * s)
{
    inputPriv *theObj = new inputPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void inputPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

