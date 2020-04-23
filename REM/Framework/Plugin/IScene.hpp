//
//  IScene.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef SceneInterface_hpp
#define SceneInterface_hpp

#include <memory>
#include "ITask.hpp"
#include "IObject.hpp"

class IScene{
public:
    virtual std::shared_ptr<IObject> createObject(StateManager * stateManager) = 0;
    
    virtual ITask * getTask() const = 0;
};


template <typename T>
class Scene: public IScene {
    
};

#endif /* SceneInterface_hpp */
