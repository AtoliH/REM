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
    constexpr auto extractPluginsFetchFunction(const Scene<Plugins...>&) -> pluginFetchFunction<F, Plugins...>;

    template<typename Scene>
    constexpr auto fetchPluginScenes() {
        constexpr auto f = [](const auto &plugin){
            return plugin->createScene();
        };
        return decltype(extractPluginsFetchFunction<decltype(f)>(std::declval<Scene>()))::value(*platformManager, f);
    }
    
public:
    Loader(PlatformManager * platformManager);
    
    template <class Scene>
    std::shared_ptr<Scene> loadScene(StateManager * stateManager) {
        return std::make_shared<Scene>(stateManager, fetchPluginScenes<Scene>());
    }
};

#endif /* Loader_hpp */
