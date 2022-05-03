//
//  GraphicsScene.cpp
//  graphics
//
//  Created by Fire937 on 9/11/21.
//  Copyright © 2021 Red Ember Mist. All rights reserved.
//

#include "GraphicsScene.hpp"

#include "GraphicsTask.hpp"
#include "GraphicsObject.hpp"

std::shared_ptr<ITask> GraphicsScene::getTask() const {
    return std::make_shared<GraphicsTask>();
}

std::shared_ptr<IObject> GraphicsScene::createObject(StateManager * stateManager) const {
    return std::make_shared<GraphicsObject>(stateManager);
}
