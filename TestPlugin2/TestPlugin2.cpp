//
//  TestPlugin2.cpp
//  TestPlugin2
//
//  Created by Fire937 on 4/20/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include <iostream>
#include "TestPlugin2.hpp"
#include "TestPlugin2Priv.hpp"

void TestPlugin2::HelloWorld(const char * s)
{
    TestPlugin2Priv *theObj = new TestPlugin2Priv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void TestPlugin2Priv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

