//
//  ChangeController.cpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "ChangeController.hpp"


void ChangeController::connect(Observer &observer, Subject &subject) {
    subject.addListener(*this);
    connection[subject.getUID()].push_back(std::make_unique<Observer>(observer));
}

void ChangeController::disconnect(Observer &observer, Subject &subject) {
    auto &observers = connection[subject.getUID()];
    observers.erase(std::find_if(observers.begin(), observers.end(), [&observer](const std::unique_ptr<Observer> &e){
        return e->getUID() == observer.getUID();
    }));
    
    if (observers.empty()) {
        connection.erase(subject.getUID());
        subject.removeListener(*this);
    }
}

void ChangeController::update(std::shared_ptr<Subject> subject) {
    changes.push(subject);
}

void ChangeController::distributeChanges() { 
    while (!changes.empty()) {
        auto subject = std::move(changes.front());
        changes.pop();
        auto &observers = connection[subject->getUID()];

        std::for_each(observers.begin(), observers.end(), [&subject](std::unique_ptr<Observer> &observer){
            observer->update(subject);
        });
    }
}

ChangeController::ChangeController() {}

