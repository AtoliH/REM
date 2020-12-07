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
#include "utils.h"
#include <iostream>


/**
 * Universal object that can communicate with managers.
 */
template <class... Systems>
class RObject: public IRObject {
    std::vector<std::shared_ptr<IObject> > objects;

public:
    RObject(detail::tupleOf<sizeof...(Systems), std::shared_ptr<IObject> > objects): IRObject() {
        this->objects = std::apply([](auto&&... elems) {
            std::vector<std::shared_ptr<IObject>> objects;
            objects.reserve(sizeof...(elems));
            (objects.push_back(elems), ...);
            return objects;
        }, objects);
    }
};


#endif /* UObject_hpp */
