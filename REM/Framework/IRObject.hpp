//
//  IRObject.hpp
//  REM
//
//  Created by Fire937 on 4/21/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef IRObject_hpp
#define IRObject_hpp

#include "Observer.hpp"
#include "IObject.hpp"

class IRObject: public Subject, Observer {
    std::vector<std::shared_ptr<IObject> > objects;
    
protected:
    void installObjects(std::vector<std::shared_ptr<IObject> > &&fetchedObjects) {
        objects = fetchedObjects;
    }
};

#endif /* IRObject_hpp */
