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

#import <grumble/io/FileManager.hpp>
#import <grumble/io/FileHandler.hpp>
#import <grumble/ui/View.hpp>
#import <grumble/base/Object.hpp>
#import <grumble/ui/ScreenHandler.hpp>
#import <grumble/render/SpriteManager.hpp>

#import "BlueprintManager.hpp"
#import "BoardDataModel.hpp"
#import "BoardView.hpp"

class Game : public grumble::Object {
    
public:
    Game(const grumble::ScreenHandler& screenHandler, grumble::FileHandler* fileHandler, grumble::SpriteHandler* spriteHandler);
    ~Game();
    
    void update(const float& dt);
    void render();
    
private:
    const grumble::ScreenHandler &_screenHandler;
    const grumble::SpriteManager _spriteManager;
    const grumble::FileManager _fileManager;
    BlueprintManager _blueprintManager;
    
    grumble::View _mainView;
    BoardDataModel _boardDataModel;
};

#endif /* Game_hpp */
