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
#include "Observable.h"

#define MAKE_UPDATE_CALLBACK(member) [this](ObservableType value){ this->member = value; }

class Observer {
    typedef std::function<void(ObservableType)> UpdateCallback;

    std::map<Observable, UpdateCallback> updateCallback;
    
public:
    UpdateCallback getUpdateCallback(Observable observable);

protected:
    void setObservable(Observable observable, UpdateCallback callback);
};

#endif /* Observer_hpp */
