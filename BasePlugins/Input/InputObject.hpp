//
//  InputObject.hpp
//  Input
//
//  Created by Fire937 on 4/22/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef InputObject1_hpp
#define InputObject1_hpp

#include "IInputSystem.hpp"
#include "IObject.hpp"

class InputObject: public IObject {
public:
    InputObject(StateManager * stateManager);
};

#endif /* InputObject_hpp */
