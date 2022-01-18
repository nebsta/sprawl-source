//
//  Game.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 12/12/2021.
//  Copyright © 2021 The Caffeinated Coder. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

#import <grumble/ui/View.hpp>
#import <grumble/base/Object.hpp>
#import <grumble/ui/ScreenHandler.hpp>
#import <grumble/render/SpriteManager.hpp>

#import "BlueprintManager.hpp"
#import "BoardDataModel.hpp"
#import "BoardView.hpp"

class Game : public Object {
    
public:
    Game(const ScreenHandler& screenHandler);
    ~Game();
    
    void update(const float& dt);
    void render();
    
private:
    const ScreenHandler &_screenHandler;
    const SpriteManager _spriteManager;
    BlueprintManager _blueprintManager;
    
    View _mainView;
    BoardDataModel _boardDataModel;
};

#endif /* Game_hpp */
