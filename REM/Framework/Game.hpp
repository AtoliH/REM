//
//  Game.hpp
//  REM
//
//  Created by Fire937 on 3/7/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef REMApp_hpp
#define REMApp_hpp

#include "Scheduler.hpp"

class Game {

protected:
    PluginManager pluginManager;
    
    PlatformManager platformManager;
    
    StateManager stateManager;
    
    Loader loader;
    
    /*
     * TODO: temporary BlankSystem (templatize Game)
     */
    Scheduler<IPlugin> scheduler;
    
public:
    Game();
    
    virtual void init() {};
    
    /**
     * Execute game loop
     */
    int run();
};

#endif /* REMApp_hpp */
