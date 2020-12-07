//
//  InputScene.hpp
//  Input
//
//  Created by Fire937 on 4/22/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef InputScene_hpp
#define InputScene_hpp

#include "IInputSystem.hpp"
#include "IScene.hpp"
#include "InputTask.hpp"

class InputScene: public IScene {
public:
    std::shared_ptr<ITask> getTask() const;
    
    std::shared_ptr<IObject> createObject(StateManager * stateManager) const;
};

#endif /* InputScene_hpp */
