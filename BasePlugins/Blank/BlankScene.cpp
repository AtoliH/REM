//
//  BlankScene.cpp
//  Blank
//
//  Created by Fire937 on 4/24/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "BlankScene.hpp"
#include "BlankObject.hpp"


std::shared_ptr<ITask> BlankScene::getTask() const {
    return std::make_shared<BlankTask>();
}


std::shared_ptr<IObject> BlankScene::createObject(StateManager * stateManager) const {
    return std::make_shared<BlankObject>(stateManager);
}
