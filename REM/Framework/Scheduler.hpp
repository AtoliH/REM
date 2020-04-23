//
//  Scheduler.hpp
//  REM
//
//  Created by Fire937 on 3/7/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef Scheduler_hpp
#define Scheduler_hpp


#include <tbb/task_group.h>
#include "RScene.hpp"

/**
 * Decides witch systems to execute during each clock cycle.
 * Must make sure each sytem has time to execute in 1 tick.
 */
template <class... Systems>
class Scheduler {
    
public:
    Scheduler(const RScene<Systems...> &stage) {
        
    }
              
    
    /**
     * Schedule tasks and send them to task manager.
     */
    void runTasks() {
        
    }
};

#endif /* Scheduler_hpp */
