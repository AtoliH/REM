//
//  RObject.hpp
//  REM
//
//  Created by Fire937 on 5/30/19.
//  Copyright © 2019 Red Ember Mist. All rights reserved.
//

#ifndef RObject_hpp
#define RObject_hpp

#include "Loader.hpp"
#include "IRObject.hpp"

/**
 * Universal object that can communicate with managers.
 */
template <class... Systems>
class RObject: public IRObject {
public:
    RObject(const Loader &loader) {
        installObjects(loader.loadObjects<Systems...>());
    }
};


#endif /* UObject_hpp */
