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
class NewObservable {
    T value;
    std::function<void(T)> notifyCallback;
    
public:
    constexpr NewObservable(): value(T()) {
        
    }
    
    constexpr NewObservable(T init): value(init) {
        
    }
    
    constexpr operator T() const {
        return value;
    }
    
    NewObservable& operator=(NewObservable arg) noexcept {
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

enum Observable {
    X,
    Y
};

typedef std::variant<int> ObservableType;

#endif /* Observable_h */
