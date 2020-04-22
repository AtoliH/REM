//
//  LoaderTest.cpp
//  REMTest
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Loader.hpp"
#include "RScene.hpp"
#include "RObject.hpp"
#include "ITestSystem.hpp"


class MockRObject: public RObject<ITestSystem1, ITestSystem2> {
public:
    MockRObject(const Loader &loader): RObject<ITestSystem1, ITestSystem2>(loader) {
        
    }
};

class MockRScene: public RScene<ITestSystem1> {
public:
    MockRScene(Loader * loader): RScene<ITestSystem1>(loader) {
        addObject<MockRObject>();
    }
};


TEST(TestLoader, TestLoadScene) {
    PluginManager pluginManager;
    PlatformManager platformManager(&pluginManager);
    platformManager.load("libTestPlugin1.dylib");

    Loader loader(&platformManager);
    
    MockRScene scene(&loader);
}
