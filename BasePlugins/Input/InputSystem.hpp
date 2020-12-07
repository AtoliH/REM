//
//  InputSystem.hpp
//  Input
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef InputSystem_hpp
#define InputSystem_hpp

#include <memory>
#include "IPlugin.hpp"
#include "InputObject.hpp"
#include "InputScene.hpp"

class InputSystem: public IPlugin {
public:
    ~InputSystem() override;
    
    std::shared_ptr<IScene> createScene() const override;
};

#endif /* InputSystem_hpp */
