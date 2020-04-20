//
//  Plugin.h
//  REM
//
//  Created by Fire937 on 4/18/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef Plugin_h
#define Plugin_h

#include "IPlugin.hpp"


struct RP_PluginVersion {
    int major;
    int minor;
    int patch;
};

typedef IPlugin * (*RP_CreateFunction)();
typedef void (*RP_DestroyFunction)(IPlugin * plugin);
 
struct RP_PluginClassInfo {
    RP_PluginVersion version;
    RP_CreateFunction create;
    RP_DestroyFunction destroy;
};

typedef int (*RP_RegisterFunction)(const RP_PluginClassInfo * info, void * platformManager);

struct RP_PlatformInfo {
    RP_PluginVersion version;
    RP_RegisterFunction registerClass;
};

typedef void (*RP_InitFunction)(const RP_PlatformInfo *, void * platformManager);

#ifndef PLUGIN_API
    #ifdef WIN32
        #define PLUGIN_API __declspec(dllimport)
    #else
        #define PLUGIN_API
    #endif
#endif

extern "C" PLUGIN_API void RP_initPlugin(const RP_PlatformInfo * info, void * platformManager);

#endif /* Plugin_h */
