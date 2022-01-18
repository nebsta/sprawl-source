//
//  BoardLayerView.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 30/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef BoardLayerView_hpp
#define BoardLayerView_hpp

#import "CellView.hpp"

#import "grumble/render/SpriteManager.hpp"
#import "grumble/base/Object.hpp"
#import "grumble/ui/View.hpp"

class BoardLayerView : public grumble::View {
public:
    BoardLayerView(const glm::vec2& size, const grumble::SpriteManager& spriteManager);
    ~BoardLayerView();
    
    void addCell(const CellDataModel& cell);
    void removeCell(const CellDataModel& cell);
    
private:
    const grumble::SpriteManager& _spriteManager;
};

#endif /* BoardLayerView_hpp */
