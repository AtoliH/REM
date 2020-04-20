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

class Subject {
    bool observed;

protected:
    Subject();
    
    void notify(Observable observable, ObservableType value) {
        auto &cc = StateManager::instance();
        cc.update(*this, observable, value);
    }
    
    void setObserved(bool observed);
};

#endif /* Subject_hpp */
