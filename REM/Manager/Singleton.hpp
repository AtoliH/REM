//
//  Singleton.hpp
//  REM
//
//  Created by Fire937 on 5/30/19.
//  Copyright © 2019 Red Ember Mist. All rights reserved.
//

#ifndef Singleton_hpp
#define Singleton_hpp

/**
 * Meyer's singleton.
 */
class Singleton
{
    Singleton();
    ~Singleton();
    
public:
    static Singleton& instance()
    {
        static Singleton s;
        return s;
    }
};

#endif /* Singleton_hpp */
