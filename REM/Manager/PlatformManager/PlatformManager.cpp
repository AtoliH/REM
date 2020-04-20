//
//  PlatformManager.cpp
//  REM
//
//  Created by Fire937 on 3/8/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include <dlfcn.h>

#include "PlatformManager.hpp"
#include "IPlugin.hpp"

PlatformManager::PlatformManager(PluginManager * pluginManager): pluginManager(pluginManager) {}

void PlatformManager::load(const std::string &path){
       pluginManager->load(path);
   }
