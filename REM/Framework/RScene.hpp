//
//  RScene.hpp
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
#include "utils.h"


/**
 * Keeps track of the different robjects in a certain scene.
 */
template <class... Systems>
class RScene {
    std::vector<std::shared_ptr<IRObject> > objects;
    std::vector<std::shared_ptr<IScene> > scenes;
    
    StateManager * stateManager;
    
public:
    RScene(StateManager * stateManager, detail::tupleOf<sizeof...(Systems), std::shared_ptr<IScene> >&& scenes): stateManager(stateManager) {
        this->scenes = std::apply([](auto&&... elems) {
            std::vector<std::shared_ptr<IScene>> scenes;
            scenes.reserve(sizeof...(elems));
            (scenes.push_back(elems), ...);
            return scenes;
        }, scenes);
    }
    
    std::vector<ITask *> getTasks() const {
        std::vector<ITask *> tasks;
        std::for_each(scenes.begin(), scenes.end(), [&tasks](const std::shared_ptr<IScene> &scene) {
            tasks.push_back(scene->getTask());
        });
        return tasks;
    }

private:
    template <typename Tp, typename... List>
     struct contains {
         static constexpr bool value {(std::is_same_v<Tp, List> || ...)};
     };
     
     template <typename Tp, typename... List>
     struct systemsAreAvailable {
         static constexpr bool value {contains<Tp, Systems...>::value && systemsAreAvailable<List...>::value};
     };
     
     template <typename Tp>
     struct systemsAreAvailable<Tp> {
         static constexpr bool value {(contains<Tp, Systems...>::value)};
     };
    
    
    template <int N, class Element, class Head, class... Tail>
    constexpr int find() {
        if constexpr (std::is_same<Element, Head>::value)
            return N;
        else
            return find<N + 1, Element, Tail...>();
    }
    
    template <class System>
    std::shared_ptr<IScene> getScene() {
        return scenes[find<0, System, Systems...>()];
    }
    
    template <class... ObjectSystems>
    auto loadObjects() {
        return std::make_tuple((getScene<ObjectSystems>()->createObject(stateManager), ...));
    }

public:
    template <class... ObjectSystems>
    void addObject() {
        static_assert((std::is_base_of<IPlugin, ObjectSystems>::value || ...));
        static_assert(systemsAreAvailable<ObjectSystems...>::value, "An underlying RObject cannot implement Systems that aren't available in the RScene.");
        // static_assert(std::is_base_of<RObject<ObjectSystems...>, O>::value, "The given RObject doesn't implement the right Systems.");
        
        objects.push_back(std::static_pointer_cast<IRObject>(std::make_shared<RObject<ObjectSystems...> >(loadObjects<ObjectSystems...>())));
    }
};

#endif /* UScene_hpp */
