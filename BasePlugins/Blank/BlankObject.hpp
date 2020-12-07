//
//  BlankObject.hpp
//  Blank
//
//  Created by Fire937 on 4/22/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef BlankObject1_hpp
#define BlankObject1_hpp

#include "IBlankSystem.hpp"
#include "IObject.hpp"

class BlankObject: public IObject {
public:
    BlankObject(StateManager * stateManager);
};

#endif /* BlankObject_hpp */
