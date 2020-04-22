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
#include <iostream>
#include "IRObject.hpp"
#include "Loader.hpp"

#include "ITestSystem.hpp"


/**
 * Keeps track of the different robjects in a certain scene.
 */
template <class... Systems>
class RScene {
    // Will later be passed by DI so probably won't be needed anymore
    Loader * loader;
    std::vector<std::shared_ptr<IRObject>> objects;
    std::vector<std::shared_ptr<IScene>> scenes;
    
public:
    RScene(Loader * loader): loader(loader) {
        scenes = loader->loadScenes<Systems...>();
        
        assert(scenes[0] != nullptr);
        std::cout << "finished loading RScene" << std::endl;
    }

protected:
    template <template <class... ObjectSystems> class O>
    auto f() {
        
    }
    
    template <class O>
    void addObject() {
        // Assert Object only extends scenes the RScene extends as well
        objects.push_back(std::static_pointer_cast<IRObject>(std::make_shared<O>(*loader)));
    }
};

#endif /* UScene_hpp */
