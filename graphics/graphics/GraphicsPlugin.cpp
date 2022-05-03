//
//  GraphicsPlugin.cpp
//  graphics
//
//  Created by Fire937 on 9/11/21.
//  Copyright © 2021 Red Ember Mist. All rights reserved.
//

#include "GraphicsPlugin.hpp"
#include "graphics.hpp"

PLUGIN RP_initPlugin(PluginManager &pluginManager) {
    pluginManager.registerPlugin(std::make_shared<graphics>());
}
