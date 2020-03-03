//
//  SceneInterface.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef SceneInterface_hpp
#define SceneInterface_hpp

#include "Observer.hpp"
#include "Subject.hpp"

class SceneInterface: public Observer, Subject {
    
public:
    virtual void createObject() = 0;
    virtual void destroyObject() = 0;
    virtual void getPrimaryTask() = 0;
};

#endif /* SceneInterface_hpp */
