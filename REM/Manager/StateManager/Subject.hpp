//
//  Subject.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef Subject_hpp
#define Subject_hpp

#include <vector>
#include "Observable.h"
#include "StateManager.hpp"
#include "VarType.h"


class Subject: std::enable_shared_from_this<Subject> {
    bool observed;
    
public:    
    virtual ~Subject();
    
protected:
    void notify(Observable observable, ObservableType value) {
        // stateManager->update(*this, observable, value);
    }
    
    void setObserved(bool observed);
    
    template <typename S, typename T>
    void expose(const VarType<S, T> &varType, NewObservable<T> &observable, StateManager &stateManager) {
        observable.bind([this, &stateManager, &varType](T newValue) {
            stateManager.update(this->weak_from_this(), varType, newValue);
        });
    }
};

#endif /* Subject_hpp */
