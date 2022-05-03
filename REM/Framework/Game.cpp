//
//  Game.cpp
//  REM
//
//  Created by Fire937 on 3/7/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "Game.hpp"
#include "IBlankSystem.hpp"


Game::Game(): platformManager(&pluginManager), loader(&platformManager) {
    
}

int Game::run() {
    
    this->init();
    
    // - Process window messages
    
    // - Scheduler execution:
    // Determine systems to execute
    // Send to task manager
    // Wait for completion
    
    // - Distribute changes
    
    // - Check execution status (run, stop, pause...)
    
    // Temporary run only 1 tick
    scheduler.runTasks();
    
    return 0;
}

