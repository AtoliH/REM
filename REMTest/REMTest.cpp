//
//  REMTest.cpp
//  REMTest
//
//  Created by Fire937 on 4/13/20.
//  Copyright © 2020 Red Ember Mist. All rights reserved.
//

#include <gtest/gtest.h>
#include "Game.hpp"

#include <graphics/graphics.hpp>


/*TEST(TestFramework, TestRun) {
    auto app = Game();
    ASSERT_EQ(app.run(), 0);
}*/

class TestGame : public Game {
    
public:
    void init() {
        platformManager.load("libgraphics.dylib");
        
        auto scene = loader.loadScene<RScene<graphics>>(&stateManager);
        
        scheduler.setScene(scene);
    }
};

TEST(TestFramework, TestVisual) {
    auto app = TestGame();
    ASSERT_EQ(app.run(), 0);
}
