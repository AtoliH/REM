//
//  PluginManager.cpp
//  REM
//
//  Created by Fire937 on 4/15/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "PluginManager.hpp"
#include "IPlugin.hpp"


PluginManager::PluginManager() {
    
}

void PluginManager::load(const std::string &path) {
    auto library = std::make_shared<DynamicLibrary>(path);
    
    RP_InitFunction init = (RP_InitFunction)library->getSymbol("RP_initPlugin");
    
    init(*this);
    
    dynamicLibraryMap.insert(std::make_pair(path, library));
}

void PluginManager::registerPlugin(std::shared_ptr<IPlugin> plugin) {
    plugins.push_back(plugin);
}
