//
//  PluginManager.hpp
//  REM
//
//  Created by Fire937 on 4/15/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef PluginManager_hpp
#define PluginManager_hpp

#include <iostream>

#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <typeindex>
#include "DynamicLibrary.hpp"
#include "Plugin.h"
#include "IPlugin.hpp"


class PluginManager {
    typedef std::vector<std::shared_ptr<IPlugin> > PluginVector;
    typedef std::unordered_map<std::type_index, std::shared_ptr<IPlugin> > PluginMap;
    typedef std::map<std::string, std::shared_ptr<DynamicLibrary> > DynamicLibraryMap;
    
    DynamicLibraryMap dynamicLibraryMap;
    PluginVector plugins;
    PluginMap pluginsIndexed;
    RP_PlatformInfo platformInfo;

public:
    PluginManager();
    
    void load(const std::string &path);
    int registerClass(const RP_PluginClassInfo * pluginInfo);
    
    template <class T>
    std::shared_ptr<T> fetchPlugin() {
        try {
            return std::static_pointer_cast<T>(pluginsIndexed.at(std::type_index(typeid(T))));
        }
        catch (std::out_of_range) {
            auto it = std::find_if(plugins.begin(), plugins.end(), [](std::shared_ptr<IPlugin> plugin) {
                return dynamic_cast<T*>(plugin.get()) != nullptr;
            });
            
            if (it != plugins.end()) {
                pluginsIndexed[std::type_index(typeid(T))] = *it;
                return std::static_pointer_cast<T>(*it);
            }
        }
        
        throw std::runtime_error("No loaded plugin matches the requirement (" + std::string(typeid(T).name()) + ")");
    }
};

#endif /* PluginManager_hpp */
