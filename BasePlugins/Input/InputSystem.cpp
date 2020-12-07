//
//  InputSystem.cpp
//  Input
//
//  Created by Fire937 on 4/24/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "InputSystem.hpp"


InputSystem::~InputSystem() {
    
}

std::shared_ptr<IScene> InputSystem::createScene() const {
    return std::static_pointer_cast<IScene>(std::make_shared<InputScene>());
}
