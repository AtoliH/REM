//
//  Observer.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp

#include <memory>
#include <map>
#include "Subject.hpp"
#include "StateManager.hpp"
#include "Observable.h"
#include "VarType.h"

#define MAKE_UPDATE_CALLBACK(member) [this](ObservableType value){ this->member = value; }

class Observer: std::enable_shared_from_this<Observer> {
    typedef std::function<void(ObservableType)> UpdateCallback;

    std::map<Observable, UpdateCallback> updateCallback;
    
public:
    UpdateCallback getUpdateCallback(Observable observable);

protected:
    void setObservable(Observable observable, UpdateCallback callback);
    
    template <typename S, typename T>
    void observe(VarType<S, T> varType, std::weak_ptr<Subject> subject, T &listener, StateManager &stateManager) {
        // RObjects are the subjects and observers they act as a mediator between scenes and objects
        // If scene wants to listen to one of its other components or listen to a component of another RObject
        // it has to ask RObjects to ask StateManager to make the link
        std::function<bool(T)> callback = [self = weak_from_this(), &listener](T newValue) {
            // We must make sure the observer wasn't destroyed before trying to update its listener
            if (!self.lock())
                return false;
            listener = newValue;
            return true;
        };
        stateManager.connect(subject, varType, callback);
    }
};

#endif /* Observer_hpp */
