//
//  DynamicLibrary.cpp
//  REM
//
//  Created by Fire937 on 4/15/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include "DynamicLibrary.hpp"

#include <dlfcn.h>

DynamicLibrary::DynamicLibrary(const std::string &path) {
    handle = dlopen(path.c_str(), RTLD_NOW);
    
    if (handle == NULL) {
        std::string errorString = std::string(dlerror());
        throw std::runtime_error("Could not load dylib (" + errorString + ").");
    }
}

void *DynamicLibrary::getSymbol(const std::string &name) {
    void *symbol = dlsym(handle, name.c_str());
    
    if (symbol == NULL) {
        std::string errorString = std::string(dlerror());
        throw std::runtime_error("Could not load symbol '" + name + "' (" + errorString + ").");
    }
    
    return symbol;
}

DynamicLibrary::~DynamicLibrary() {
    dlclose(handle);
}
