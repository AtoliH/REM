//
//  StateManager.cpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "StateManager.hpp"


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
    while (!updates.empty()) {
        auto &info = updates.front();
        
        auto observers = connections[info.subject];

        std::for_each(observers.begin(), observers.end(), [info](Observer *observer){
            try {
                auto callback = (observer->getUpdateCallback(info.observable));
                callback(info.value);
            }
            catch (const std::out_of_range) {
                
            }
        });
        updates.pop();
    }
}
