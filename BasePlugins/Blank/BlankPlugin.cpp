//
//  BlankPlugin.cpp
//  Blank
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//


#include <iostream>
#include "BlankPlugin.hpp"
#include "BlankPluginPriv.hpp"
#include "BlankSystem.hpp"

#include "BlankPlugin.hpp"

PLUGIN RP_initPlugin(PluginManager &pluginManager) {
    pluginManager.registerPlugin(std::make_shared<BlankSystem>());
}
