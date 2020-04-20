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
    platformInfo.version = { 1, 0, 0 };
}

void PluginManager::load(const std::string &path) {
    auto library = std::make_shared<DynamicLibrary>(path);
    
    RP_InitFunction init = (RP_InitFunction)library->getSymbol("RP_initPlugin");
    
    platformInfo.registerClass =
    [](const RP_PluginClassInfo *pluginInfo, void *platformManager) {
        PluginManager *self = (PluginManager *)platformManager;
        return self->registerClass(pluginInfo);
    };
    
    init(&platformInfo, this);
    
    dynamicLibraryMap.insert(std::make_pair(path, library));
}

int PluginManager::registerClass(const RP_PluginClassInfo * info) {    
    if (info == NULL) {
        return 1;
    }

    plugins.push_back(std::shared_ptr<IPlugin>(info->create(), info->destroy));
    return 0;
}
