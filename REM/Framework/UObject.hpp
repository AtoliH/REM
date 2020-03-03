//
//  UObject.hpp
//  REM
//
//  Created by Fire937 on 5/30/19.
//  Copyright © 2019 Red Ember Mist. All rights reserved.
//

#ifndef UObject_hpp
#define UObject_hpp

#include <memory>

/**
 * Universal object that can merely communicate with managers.
 */
class UObject
{
    unsigned long uid;
    
public:
    unsigned long getUID() const { return uid; };
};


#endif /* UObject_hpp */
