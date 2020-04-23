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


class Observer: public std::enable_shared_from_this<Observer> {
public:
    template <typename S, typename T>
    void observe(VarType<S, T> varType, std::weak_ptr<Subject> subject, T &listener, StateManager &stateManager) const {
        std::function<bool(T)> callback = [self = weak_from_this(), &listener](T newValue) {
            if (!self.lock())
                return false;
            listener = newValue;
            return true;
        };
        stateManager.connect(subject, varType, callback);
    }
};

#endif /* Observer_hpp */
