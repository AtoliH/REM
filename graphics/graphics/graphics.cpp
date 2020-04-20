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

extern "C" void openGUI();

extern "C" IPlugin* create_handle() {
    return new graphics;
}

extern "C" void destroy_handle(IPlugin* handle) {
    delete static_cast<graphics*>(handle);
}

void graphics::createScene() {
    openGUI();
}

void graphics::destroyScene() {
}
