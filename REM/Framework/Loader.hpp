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
#include "StateManager.hpp"
#include "IScene.hpp"
#include "utils.h"


class Loader {
    PlatformManager * platformManager;

    template <typename F, class GPlugin, class ...GPlugins>
    static constexpr auto fetchPlugins(PlatformManager &platformManager, F f) {
        // TODO: Static assert
        
        auto result = std::make_tuple(f(platformManager.fetchPlugin<GPlugin>()));
        
        if constexpr(sizeof...(GPlugins) > 0)
            return std::tuple_cat(result, fetchPlugins<F, GPlugins...>(platformManager, f));
        else
            return result;
    }
    
    template <typename F, typename... Plugins>
    struct pluginFetchFunction {
        static constexpr auto value = fetchPlugins<F, Plugins...>;
    };

    template<typename F, template <typename...> typename Scene, typename... Plugins>
    constexpr auto extractPluginsFetchFunctions(const Scene<Plugins...>&) -> pluginFetchFunction<F, Plugins...>;

    template<typename Scene>
    auto fetchPluginScenes() {
        auto f = [](const auto &plugin){
            return plugin->createScene();
        };
        return decltype(extractPluginsFetchFunctions<decltype(f)>(std::declval<Scene>()))::value(*platformManager, f);
    }
    
public:
    Loader(PlatformManager * platformManager);
    
    template <class Scene>
    Scene loadScene(StateManager * stateManager) {
        return Scene(stateManager, fetchPluginScenes<Scene>());
    }
    
    template <class Object>
    Object loadObject() {
        // return Object(fetchPluginObjects<Object>());
    }
    
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
