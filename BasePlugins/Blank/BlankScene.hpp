//
//  BlankScene.hpp
//  Blank
//
//  Created by Fire937 on 4/22/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#ifndef BlankScene_hpp
#define BlankScene_hpp

#include "IBlankSystem.hpp"
#include "IScene.hpp"
#include "BlankTask.hpp"

class BlankScene: public IScene {
public:
    std::shared_ptr<ITask> getTask() const;
    
    std::shared_ptr<IObject> createObject(StateManager * stateManager) const;
};

#endif /* BlankScene_hpp */
