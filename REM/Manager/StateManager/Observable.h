//
//  Observable.h
//  REM
//
//  Created by Fire937 on 4/16/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef Observable_h
#define Observable_h

#include <variant>


template <typename T>
class Observable {
    T value;
    std::function<void(T)> notifyCallback;
    
public:
    constexpr Observable(): value(T()) {
        
    }
    
    constexpr Observable(T init): value(init) {
        
    }
    
    constexpr operator T() const {
        return value;
    }
    
    Observable& operator=(Observable arg) noexcept {
        if (value != arg.value) {
            if (notifyCallback)
                notifyCallback(arg.value);
        }
        std::swap(value, arg.value);
        return *this;
    }
    
    void bind(std::function<void(T)> callback) {
        notifyCallback = callback;
    }
};

#endif /* Observable_h */
