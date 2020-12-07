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
 * Decides which systems to execute during each clock cycle.
 * Must make sure each sytem has time to execute in 1 tick.
 */
template <class... Systems>
class Scheduler {
    std::shared_ptr<RScene<Systems...> > scene;
    
public:
    /**
     * TODO: mechanism to make sure scene doesn't remain null
     */
    Scheduler(std::shared_ptr<RScene<Systems...> > scene = nullptr) {
        this->scene = scene;
    }
    
    void setScene(std::shared_ptr<RScene<Systems...> > scene) {
        this->scene = scene;
    }
    
    /**
     * Schedule scene tasks and send them to task manager then wait for them to finish.
     */
    void runTasks() {
        auto tasks = scene->getTasks();
        
        tbb::task_group g;
        std::for_each(tasks.begin(), tasks.end(), [&g](const std::shared_ptr<ITask> &task){
            g.run([&task]() { task->execute(); });
        });
        
        g.wait();
    }
};

#endif /* Scheduler_hpp */
