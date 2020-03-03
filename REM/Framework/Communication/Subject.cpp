//
//  Subject.cpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "Subject.hpp"


void Subject::addListener(Observer &listener) { 
    observers.push_back(std::make_shared<Observer>(listener));
}

void Subject::removeListener(Observer &listener) {
    observers.erase(std::find_if(observers.begin(), observers.end(), [&listener](const std::shared_ptr<Observer> &e){
        return e->getUID() == listener.getUID();
    }));
}
