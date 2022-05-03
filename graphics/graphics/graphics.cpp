//
//  graphics.cpp
//  graphics
//
//  Created by Fire937 on 1/12/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include <iostream>

#include "graphics.hpp"
#include "graphicsPriv.hpp"

#include "GraphicsScene.hpp"

extern "C" void openGUI();

extern "C" IPlugin* create_handle() {
    return new graphics;
}

extern "C" void destroy_handle(IPlugin* handle) {
    delete static_cast<graphics*>(handle);
}

std::shared_ptr<IScene> graphics::createScene() const {
    openGUI();
    return std::make_shared<GraphicsScene>();
}

graphics::~graphics() {
    
}
