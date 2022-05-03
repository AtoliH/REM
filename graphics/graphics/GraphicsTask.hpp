//
//  GraphicsTask.hpp
//  graphics
//
//  Created by Fire937 on 9/11/21.
//  Copyright © 2021 Red Ember Mist. All rights reserved.
//

#ifndef GraphicsTask_hpp
#define GraphicsTask_hpp

#include <iostream>
#include "ITask.hpp"

class GraphicsTask: public ITask {
    
public:
    void execute() const override;
};

#endif /* GraphicsTask_hpp */
