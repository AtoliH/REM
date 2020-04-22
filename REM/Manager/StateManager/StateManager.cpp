//
//  StateManager.cpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "StateManager.hpp"
#include "Observer.hpp"


void StateManager::connect(Observer &observer, Subject &subject) {
    connections[&subject].push_back(&observer);
}

void StateManager::disconnect(Observer &observer, Subject &subject) {
    auto &observers = connections[&subject];
    observers.erase(std::remove(observers.begin(), observers.end(), &observer), observers.end());
    
    if (observers.empty()) {
        connections.erase(&subject);
    }
}

void StateManager::update(Subject &subject, Observable observable, ObservableType value) {
    updates.push({&subject, observable, value});
}

void StateManager::distributeUpdates() { 
    while (!newUpdates.empty()) {
        auto &[subject, varID, newValue] = newUpdates.front();
        
        auto &callbacks = newConnections[subject][varID];
        std::for_each(callbacks.begin(), callbacks.end(), [&value = newValue](auto updateValue){
            updateValue(value);
        });
        
        newUpdates.pop();
    }
}
