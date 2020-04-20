//
//  TestSystem11.hpp
//  TestPlugin1
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef TestSystem11_hpp
#define TestSystem11_hpp

#include "ITestSystem.hpp"

class TestSystem11: public ITestSystem1 {
public:
    virtual ~TestSystem11() override {
        
    }
    
    virtual IScene * createScene() override {
        return NULL;
        
    }
    
    virtual void destroyScene(IScene * scene) override {
        
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
    
    virtual IScene * createScene() override {
        return NULL;
        
    }
    
    virtual void destroyScene(IScene * scene) override {
        
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
