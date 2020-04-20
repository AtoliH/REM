//
//  Observer.cpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "Observer.hpp"

Observer::UpdateCallback Observer::getUpdateCallback(Observable observable) {
    return updateCallback.at(observable);
}

void Observer::setObservable(Observable observable, Observer::UpdateCallback callback) {
    updateCallback[observable] = callback;
}
