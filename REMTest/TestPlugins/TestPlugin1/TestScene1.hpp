//
//  TestScene1.hpp
//  TestPlugin1
//
//  Created by Fire937 on 4/22/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef TestScene1_hpp
#define TestScene1_hpp

#include "ITestSystem.hpp"
#include "IScene.hpp"
#include "TestTask1.hpp"

class TestScene1: public IScene {
public:
    ITask * getTask() const override {
        return nullptr;
    }
    
    std::shared_ptr<IObject> createObject(StateManager * stateManager) override {
        return std::make_shared<TestObject1>(stateManager);
    }
};

#endif /* TestScene1_hpp */
