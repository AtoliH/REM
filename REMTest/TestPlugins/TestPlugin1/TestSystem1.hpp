//
//  TestSystem11.hpp
//  TestPlugin1
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef TestSystem11_hpp
#define TestSystem11_hpp

#include <memory>
#include "TestObject1.hpp"
#include "TestScene1.hpp"

class TestSystem11: public ITestSystem1 {
public:
    virtual ~TestSystem11() override {
        
    }
    
    virtual std::shared_ptr<IScene> createScene() override {
        return std::static_pointer_cast<IScene>(std::make_shared<TestScene1>());
    }
    
    virtual std::shared_ptr<IObject> createObject() override {
        return std::static_pointer_cast<IObject>(std::make_shared<TestObject1>());
    }
    
    virtual std::string test() override {
        return "string from 11";
    }
    
    static IPlugin * create() {
        return new TestSystem11();
    }
    
    static void destroy(IPlugin * plugin) {
        delete plugin;
    }
};

class TestSystem12: public ITestSystem1 {
public:
    virtual ~TestSystem12() override {
        
    }
    
    virtual std::shared_ptr<IScene> createScene() override {
        return NULL;
        
    }
    
    virtual std::shared_ptr<IObject> createObject() override {
        return nullptr;
    }
    
    virtual std::string test() override {
        return "string from 12";
    }
    
    static IPlugin * create() {
        return new TestSystem12();
    }
    
    static void destroy(IPlugin * plugin) {
        delete plugin;
    }
};

#endif /* TestSystem11_hpp */
