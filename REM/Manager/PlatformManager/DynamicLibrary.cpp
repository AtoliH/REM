//
//  DynamicLibrary.cpp
//  REM
//
//  Created by Fire937 on 4/15/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "DynamicLibrary.hpp"


DynamicLibrary::DynamicLibrary(const std::string &path) {
    
#ifdef _WIN32
    handle = LoadLibrary(TEXT(path.c_str()));
#else
    handle = dlopen(path.c_str(), RTLD_NOW);
#endif
    
    if (handle == NULL) {
#ifdef _WIN32
        std::string errorString = std::string(GetLastError());
#else
        std::string errorString = std::string(dlerror());
#endif
        throw std::runtime_error("Could not load dynamic library : " + errorString + ".");
    }
}

void *DynamicLibrary::getSymbol(const std::string &name) {
#ifdef _WIN32
    void * symbol = GetProcAddress(handle, name.c_str());
#else
    void * symbol = dlsym(handle, name.c_str());
#endif
    
    if (symbol == NULL) {
        std::string errorString = std::string(dlerror());
        throw std::runtime_error("Could not load symbol '" + name + "': " + errorString + ".");
    }
    
    return symbol;
}

DynamicLibrary::~DynamicLibrary() {
#ifdef _WIN32
    FreeLibrary(handle);
#else
    dlclose(handle);
#endif
}
