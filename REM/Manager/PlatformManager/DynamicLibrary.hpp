//
//  DynamicLibrary.hpp
//  REM
//
//  Created by Fire937 on 4/15/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef DynamicLibrary_hpp
#define DynamicLibrary_hpp

#include <string>

class DynamicLibrary {
public:
    DynamicLibrary(const std::string &path);
    ~DynamicLibrary();
    void * getSymbol(const std::string &name);

private:
    DynamicLibrary();
    DynamicLibrary(void *handle);
    DynamicLibrary(const DynamicLibrary &);

    void * handle;
};

#endif /* DynamicLibrary_hpp */
