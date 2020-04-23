//
//  StateManager.cpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "StateManager.hpp"
#include "Observer.hpp"


void StateManager::distributeUpdates() { 
    while (!updates.empty()) {
        auto &[subject, varID, newValue] = updates.front();
        
        auto &callbacks = connections[subject][varID];
        std::for_each(callbacks.begin(), callbacks.end(), [&value = newValue](auto updateValue){
            updateValue(value);
        });
        
        updates.pop();
    }
}
