//
//  PlatformManager.hpp
//  REM
//
//  Created by Fire937 on 3/8/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef PlatformManager_hpp
#define PlatformManager_hpp

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "PluginManager.hpp"

class PlatformManager {
    PluginManager * pluginManager;
    
public:
    PlatformManager(PluginManager * pluginManager);
    
    void load(const std::string &path);
    
    template <class T>
    std::shared_ptr<T> loadPlugin() {
        // TODO: Static assert
        
        return pluginManager->fetchPlugin<T>();
    }
};

#endif /* PlatformManager_hpp */
