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
#include "IRScene.hpp"
#include "ITestSystem.hpp"


class MockRScene: public IRScene<ITestSystem1, ITestSystem1, ITestSystem1, ITestSystem1> {
public:
};


TEST(TestLoader, TestLoadScene) {
    auto pluginManager = std::make_shared<PluginManager>();
    auto platformManager = std::make_shared<PlatformManager>(pluginManager.get());
    platformManager->load("libTestPlugin1.dylib");
        
    Loader loader(platformManager.get());
    loader.load<MockRScene>();
}
