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


class Subject: public std::enable_shared_from_this<Subject> {
public:
    virtual ~Subject();
    
    template <typename S, typename T>
    void expose(const VarType<S, T> &varType, Observable<T> &observable, StateManager &stateManager) const {
        observable.bind([this, &stateManager, &varType](T newValue) {
            stateManager.update(this->weak_from_this(), varType, newValue);
        });
    }
};

#endif /* Subject_hpp */
