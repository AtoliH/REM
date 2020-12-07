//
//  BlankSystem.hpp
//  Blank
//
//  Created by Fire937 on 4/19/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef BlankSystem_hpp
#define BlankSystem_hpp

#include <memory>
#include "BlankObject.hpp"
#include "BlankScene.hpp"

class BlankSystem: public IBlankSystem {
public:
    ~BlankSystem() override;
    
    std::shared_ptr<IScene> createScene() const override;
};

#endif /* BlankSystem_hpp */
