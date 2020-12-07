//
//  InputTask.hpp
//  Input
//
//  Created by Fire937 on 4/22/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef InputTask_hpp
#define InputTask_hpp


#include <iostream>
#include "ITask.hpp"

class InputTask: public ITask {
    
public:
    void execute() const override;
};

#endif /* InputTask_hpp */
