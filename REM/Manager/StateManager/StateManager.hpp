//
//  StateManager.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef ChangeController_hpp
#define ChangeController_hpp

#include <map>
#include <vector>
#include <queue>

#include "Observer.hpp"
#include "Observable.h"

class Subject;
class Observer;

class StateManager {
    struct UpdateInfo {
        Subject *subject;
        Observable observable;
        ObservableType value;
    };
    
    StateManager();
    ~StateManager();
    
    std::map<Subject*, std::vector<Observer*> > connections; // All the observables the observers are listening to
    std::queue<UpdateInfo> updates;

public:
    static StateManager &instance() {
        static StateManager s;
        return s;
    }
    
    void connect(Observer &observer, Subject &subject); // Register an observer to a subject so that it can listen to the subject's changes
    void disconnect(Observer &observer, Subject &subject); // Deregister...
    
    void update(Subject &subject, Observable observable, ObservableType value);
    
    void distributeUpdates();
};

#endif /* ChangeController_hpp */
