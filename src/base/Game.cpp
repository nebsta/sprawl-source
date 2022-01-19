//
//  Game.cpp
//  sprawl
//
//  Created by Benjamin Wallis on 12/12/2021.
//  Copyright © 2021 The Caffeinated Coder. All rights reserved.
//

#include "Game.hpp"

Game::Game(const grumble::ScreenHandler& screenHandler, grumble::FileHandler* fileHandler, grumble::SpriteHandler* spriteHandler) :
_mainView(VECTOR_EMPTY,glm::vec2(screenHandler.screenWidth(),screenHandler.screenHeight())),
_spriteManager(spriteHandler),
_screenHandler(screenHandler),
_fileManager(fileHandler),
_blueprintManager(_fileManager) {
    
    _mainView.renderer()->setTint(COLOR_RED);
    
//    BoardView *_boardView = new BoardView(_boardDataModel, spriteLoader);
//    _mainView.addChild(_boardView);
//
//    BlueprintDataModel blueprint = _blueprintManager.getRandomBlueprint();
//    _boardDataModel.addBlueprint(blueprint);
}

Game::~Game() {
    
}

void Game::update(const float& dt) {
    _mainView.update(dt);
}

void Game::render() {
    _mainView.render();
}
