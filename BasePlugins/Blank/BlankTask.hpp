//
//  BlankTask.hpp
//  Blank
//
//  Created by Fire937 on 4/22/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef BlankTask_hpp
#define BlankTask_hpp


#include <iostream>
#include "ITask.hpp"

class BlankTask: public ITask {
    
public:
    void execute() const override;
};

#endif /* BlankTask_hpp */
