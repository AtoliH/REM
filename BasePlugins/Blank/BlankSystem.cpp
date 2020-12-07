//
//  BlankSystem.cpp
//  Blank
//
//  Created by Fire937 on 4/24/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "BlankSystem.hpp"


BlankSystem::~BlankSystem() {
    
}

std::shared_ptr<IScene> BlankSystem::createScene() const {
    return std::static_pointer_cast<IScene>(std::make_shared<BlankScene>());
}
