//
//  IRScene.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef UScene_hpp
#define UScene_hpp

#include <vector>
#include "RObject.hpp"
#include "Loader.hpp"


/**
 * Keeps track of the different robjects in a certain scene.
 */
template <class... GSystems>
class IRScene {
    std::vector<std::shared_ptr<RObject>> objects;
    
public:
    static void loadPlugins(Loader::PluginLoader &pluginLoader) {
        auto systems = pluginLoader.loadPlugins<GSystems...>();
    }
};

#endif /* UScene_hpp */
