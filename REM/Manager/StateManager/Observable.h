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


enum Observable {
    X,
    Y
};

typedef std::variant<int> ObservableType;

#endif /* Observable_h */
