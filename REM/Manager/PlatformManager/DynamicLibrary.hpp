//
//  DynamicLibrary.hpp
//  REM
//
//  Created by Fire937 on 4/15/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef DynamicLibrary_hpp
#define DynamicLibrary_hpp

#ifdef _WIN32
#   include <windows.h>
#else
#   include <dlfcn.h>
#endif

#include <string>

class DynamicLibrary {
#ifdef _WIN32
    HINSTANCE handle;
#else
    void * handle;
#endif
    
public:
    DynamicLibrary(const std::string &path);
    ~DynamicLibrary();
    void * getSymbol(const std::string &name);

private:
    DynamicLibrary();
    DynamicLibrary(void *handle);
    DynamicLibrary(const DynamicLibrary &);
};

#endif /* DynamicLibrary_hpp */
