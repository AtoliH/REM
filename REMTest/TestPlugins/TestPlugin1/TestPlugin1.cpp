//
//  TestPlugin1.cpp
//  TestPlugin1
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//


#include <iostream>
#include "TestPlugin1.hpp"
#include "TestPlugin1Priv.hpp"
#include "TestSystem1.hpp"


extern "C" PLUGIN_API void RP_initPlugin(const RP_PlatformInfo * info, void * platformManager) {
    {
        RP_PluginClassInfo testClass1 = {
            {1, 0, 0},
            TestSystem11::create,
            TestSystem11::destroy
        };
        info->registerClass(&testClass1, platformManager);
    }
    
    /*{
        RP_PluginClassInfo testClass2 = {
            {2, 0, 0},
            TestSystem12::create,
            TestSystem12::destroy
        };
        
        
        info->registerClass(&testClass2, platformManager);
    }*/
}
