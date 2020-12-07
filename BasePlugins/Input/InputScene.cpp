//
//  InputScene.cpp
//  Input
//
//  Created by Fire937 on 4/24/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "InputScene.hpp"
#include "InputObject.hpp"


std::shared_ptr<ITask> InputScene::getTask() const {
    return std::make_shared<InputTask>();
}


std::shared_ptr<IObject> InputScene::createObject(StateManager * stateManager) const {
    return std::make_shared<InputObject>(stateManager);
}
