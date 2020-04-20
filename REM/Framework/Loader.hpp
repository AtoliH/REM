//
//  Loader.hpp
//  REM
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef Loader_hpp
#define Loader_hpp


#include <type_traits>
#include <tuple>
#include "PlatformManager.hpp"


class Loader {
public:
    class PluginLoader {
        PlatformManager * platformManager;
        
    public:
        PluginLoader(PlatformManager * platformManager);
        
        template <class GPlugin, class ...GPlugins>
        std::tuple<std::shared_ptr<GPlugin>, std::shared_ptr<GPlugins>...> loadPlugins() {
            // TODO: Static assert
            
            auto plugin = std::make_tuple(platformManager->loadPlugin<GPlugin>());
            
            if constexpr(sizeof...(GPlugins) > 0)
                return std::tuple_cat(plugin, loadPlugins<GPlugins...>());
            else
                return plugin;
        }
    };

private:
    PluginLoader pluginLoader;
    
public:
    Loader(PlatformManager * platformManager);
    
    template <class GRScene>
    void load() {
        // TODO: Static assert
        
        GRScene::loadPlugins(pluginLoader);
    }

};

#endif /* Loader_hpp */
