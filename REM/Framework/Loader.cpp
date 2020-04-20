//
//  Loader.cpp
//  REM
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "Loader.hpp"

Loader::Loader(PlatformManager * platformManager): pluginLoader(platformManager) {
    
}

Loader::PluginLoader::PluginLoader(PlatformManager * platformManager): platformManager(platformManager) {
    
}
