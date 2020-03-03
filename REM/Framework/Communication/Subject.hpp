//
//  Subject.hpp
//  REM
//
//  Created by Fire937 on 3/2/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef Subject_hpp
#define Subject_hpp

#include <vector>

#include "Observer.hpp"
#include "UObject.hpp"

class Subject: public UObject {
    std::vector<std::shared_ptr<Observer>> observers;
    
public:
    void addListener(Observer &listener);
    void removeListener(Observer &listener);
};

#endif /* Subject_hpp */
