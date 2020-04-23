//
//  ITestSystem.hpp
//  REMTest
//
//  Created by Fire937 on 4/20/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef ITestSystem_hpp
#define ITestSystem_hpp


#include "IPlugin.hpp"
#include "VarType.h"


class ITestSystem1: public IPlugin {

public:
    struct Var {
        struct Scene {
            static constexpr VarType<ITestSystem1, bool> state;
        };
        
        struct Object {
            static constexpr VarType<ITestSystem1, float> x;
            static constexpr VarType<ITestSystem1, float> y = 1;
            static constexpr VarType<ITestSystem1, float> z = 2;
            
            static constexpr VarType<ITestSystem1, int> i = 3;
        };
    };
};

class ITestSystem2: public IPlugin {

public:
    struct Var {
        static constexpr VarType<ITestSystem1, float> a;
        static constexpr VarType<ITestSystem1, float> b = 1;
        static constexpr VarType<ITestSystem1, float> c = 2;
        
        static constexpr VarType<ITestSystem1, int> i = 3;
    };
};

#endif /* ITestSystem_hpp */
