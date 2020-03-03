//
//  ChangeController.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef ChangeController_hpp
#define ChangeController_hpp

#include <map>
#include <vector>
#include <queue>

#include "Observer.hpp"
#include "Subject.hpp"

class ChangeController : public Observer {
    std::map<unsigned long, std::vector<std::unique_ptr<Observer>> > connection; // All the subjects the observers are listening to
    std::queue<std::shared_ptr<Subject>> changes;
    
public:
    ChangeController();
    
    void connect(Observer &observer, Subject &subject); // Register an observer to a subject so that it can listen to the subject's changes
    void disconnect(Observer &observer, Subject &subject); // Deregister...
    virtual void update(std::shared_ptr<Subject> subject) override;
    
    void distributeChanges();
    
};

#endif /* ChangeController_hpp */
