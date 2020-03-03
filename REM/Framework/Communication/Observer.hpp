//
//  Observer.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef Observer_hpp
#define Observer_hpp

#include "UObject.hpp"

class Subject;

class Observer: public UObject {
    
public:
    virtual void update(std::shared_ptr<Subject> subject) {};
};

#endif /* Observer_hpp */
