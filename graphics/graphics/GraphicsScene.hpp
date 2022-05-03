//
//  GraphicsScene.hpp
//  graphics
//
//  Created by Fire937 on 9/11/21.
//  Copyright © 2021 Red Ember Mist. All rights reserved.
//

#ifndef GraphicsScene_hpp
#define GraphicsScene_hpp

#include "IScene.hpp"

class GraphicsScene: public IScene {
    
public:
    std::shared_ptr<ITask> getTask() const;
    
    std::shared_ptr<IObject> createObject(StateManager * stateManager) const;
};

#endif /* GraphicsScene_hpp */
