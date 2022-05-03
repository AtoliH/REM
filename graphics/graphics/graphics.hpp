//
//  graphics.hpp
//  graphics
//
//  Created by Fire937 on 1/12/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef graphics_
#define graphics_

/* The classes below are exported */
#pragma GCC visibility push(default)

#include "IPlugin.hpp"

class graphics: public IPlugin {
    
public:
    virtual std::shared_ptr<IScene> createScene() const;
    virtual ~graphics();
};

#pragma GCC visibility pop
#endif
