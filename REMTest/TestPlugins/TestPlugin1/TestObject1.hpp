//
//  TestObject1.hpp
//  REMTest
//
//  Created by Fire937 on 4/22/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef TestObject1_hpp
#define TestObject1_hpp

#include "ITestSystem.hpp"
#include "IObject.hpp"

class TestObject1: public IObject {
public:
    TestObject1(StateManager * stateManager): IObject(stateManager) {
        
    }
};

#endif /* TestObject1_hpp */
