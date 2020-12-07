//
//  TestPlugin1.cpp
//  TestPlugin1
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//


#include <iostream>
#include "TestPlugin1.hpp"
#include "TestPlugin1Priv.hpp"
#include "TestSystem1.hpp"

#include "TestPlugin1.hpp"

PLUGIN RP_initPlugin(PluginManager &pluginManager) {
    pluginManager.registerPlugin(std::make_shared<TestSystem11>());
}
