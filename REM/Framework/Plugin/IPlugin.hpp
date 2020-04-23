//
//  IPlugin.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef PluginInterface_hpp
#define PluginInterface_hpp

#include "IScene.hpp"
#include "IObject.hpp"
#include <string>


class IPlugin {
    
public:
    virtual std::shared_ptr<IScene> createScene() const = 0;
    virtual ~IPlugin() {}
    
    virtual std::string test() = 0;
};

#endif /* PluginInterface_hpp */
