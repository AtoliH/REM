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
    ~TestSystem11() override {
        
    }
    
    std::shared_ptr<IScene> createScene() const override {
        return std::static_pointer_cast<IScene>(std::make_shared<TestScene1>());
    }
    
    std::string test() override {
        return "string from 11";
    }
};

#endif /* TestSystem11_hpp */
