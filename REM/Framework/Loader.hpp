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
    PlatformManager * platformManager;

    template <class GPlugin, class ...GPlugins>
    std::tuple<std::shared_ptr<GPlugin>, std::shared_ptr<GPlugins>...> fetchPlugins() const {
        // TODO: Static assert
        
        auto plugin = std::make_tuple(platformManager->fetchPlugin<GPlugin>());
        
        if constexpr(sizeof...(GPlugins) > 0)
            return std::tuple_cat(plugin, fetchPlugins<GPlugins...>());
        else
            return plugin;
    }
    
public:
    Loader(PlatformManager * platformManager);
    
    template <class ...Systems>
    auto loadScenes() const {
        // TODO: Static assert
        
        auto systems = fetchPlugins<Systems...>();
        
        return std::apply([](auto&&... elems) {
            std::vector<std::shared_ptr<IScene>> scenes;
            scenes.reserve(sizeof...(elems));
            (scenes.push_back(elems->createScene()), ...);
            return scenes;
        }, systems);
    }
    
    template <class ...Systems>
    auto loadObjects() const {
        auto systems = fetchPlugins<Systems...>();
        
        return std::apply([](auto&&... elems) {
            std::vector<std::shared_ptr<IObject>> objects;
            objects.reserve(sizeof...(elems));
            (objects.push_back(elems->createObject()), ...);
            return objects;
        }, systems);
    }

};

#endif /* Loader_hpp */
