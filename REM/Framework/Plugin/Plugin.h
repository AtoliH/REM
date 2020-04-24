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
#include "PlatformManager.hpp"


#ifndef PLUGIN
#   ifdef _WIN32
#       define PLUGIN extern "C" __declspec(dllexport) void
#   else
#       define PLUGIN extern "C" void
#   endif
#endif

PLUGIN RP_initPlugin(PluginManager &pluginManager);

#endif /* Plugin_h */
