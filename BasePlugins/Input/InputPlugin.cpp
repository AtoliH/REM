//
//  InputPlugin.cpp
//  Input
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//


#include <iostream>
#include "InputPlugin.hpp"
#include "InputPluginPriv.hpp"
#include "InputSystem.hpp"

#include "InputPlugin.hpp"

PLUGIN RP_initPlugin(PluginManager &pluginManager) {
    pluginManager.registerPlugin(std::make_shared<InputSystem>());
}
