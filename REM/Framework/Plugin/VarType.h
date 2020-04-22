//
//  VarType.h
//  REM
//
//  Created by Fire937 on 4/22/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef VarType_h
#define VarType_h

#include <typeindex>

typedef std::tuple<std::size_t, int> VarID;

template <typename S, typename T>
class VarType {
    const int index;
    
public:
    constexpr VarType(): index(0) {
        
    }
    
    constexpr VarType(int value): index(value) {
        
    }
    
    constexpr operator int() const {
        return index;
    }
    
    constexpr operator VarID() const {
        return { std::type_index(typeid(S)).hash_code(), index };
    }
};


template <typename S, typename T, typename U, typename V>
inline bool operator==(const VarType<S, T>& lhs, const VarType<U, V>& rhs){
    if constexpr (std::is_same<S,U>::value && std::is_same<T, V>::value)
        return lhs.index == rhs.index;
    else
        return false;
}
template <typename S, typename T>
inline bool operator!=(const VarType<S, T>& lhs, const VarType<S, T>& rhs){
    return !(lhs == rhs);
}

#endif /* VarType_h */
