//
//  IObject.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef ObjectInterface_hpp
#define ObjectInterface_hpp


#include "Observer.hpp"
#include "Subject.hpp"
#include "StateManager.hpp"


class IObject {
    std::weak_ptr<Subject> subject;
    std::weak_ptr<Observer> observer;
    
    StateManager * stateManager;

public:
    IObject(StateManager * stateManager);
        
    template <class S, typename T>
    void expose(const VarType<S, T> &varType, Observable<T> &observable) const {
        std::shared_ptr<Subject>(subject)->expose(varType, observable, *stateManager);
    }
    
    template <class S, typename T>
    void observe(VarType<S, T> varType, std::weak_ptr<Subject> subject, T &listener) const {
        std::shared_ptr<Observer>(observer)->observe(varType, subject, listener, *stateManager);
    }
};

template <typename T>
class Object: public IObject {
};


#endif /* ObjectInterface_hpp */
