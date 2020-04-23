//
//  utils.h
//  REM
//
//  Created by Fire937 on 4/23/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef utils_h
#define utils_h

namespace detail {
    template <size_t I,typename T>
    struct tupleN{
        template< typename...Args> using type = typename tupleN<I-1, T>::template type<T, Args...>;
    };

    template <typename T>
    struct tupleN<0, T> {
        template<typename...Args> using type = std::tuple<Args...>;
    };
    template <size_t I,typename T>  using tupleOf = typename tupleN<I,T>::template type<>;
}

#endif /* utils_h */
