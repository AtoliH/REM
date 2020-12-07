//
//  ITask.hpp
//  REM
//
//  Created by Fire937 on 3/8/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef TaskInterface_hpp
#define TaskInterface_hpp


class ITask{
public:
    virtual void execute() const = 0;
};

#endif /* TaskInterface_hpp */
