//
//  LoaderTest.cpp
//  REMTest
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include <utility>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Scheduler.hpp"
#include "Loader.hpp"
#include "RScene.hpp"
#include "RObject.hpp"
#include "ITestSystem.hpp"
#include "StateManager.hpp"


/*class MockRObject: public RObject<ITestSystem1> {
public:
    MockRObject(const Loader &loader): RObject<ITestSystem1>(loader) {
        
    }
};*/

class MockRScene: public RScene<ITestSystem1> {
public:
    using RScene<ITestSystem1>::RScene;
};


TEST(TestLoader, TestLoadScene) {
    
}
