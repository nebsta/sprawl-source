//
//  BoardView.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 3/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef BoardView_hpp
#define BoardView_hpp

#include <vector>

#include <grumble/render/SpriteManager.hpp>
#include <grumble/util/MathConstants.hpp>
#include <grumble/message/MessageManager.hpp>

#include "BoardDataModel.hpp"
#include "BoardLayerView.hpp"

#define BOARDVIEW_DEFAULT_SIZE glm::vec2(300,550)

typedef enum BoardLayer {
    BoardLayer_Blueprint,
    BoardLayer_Blocks
} BoardLayer;

class BoardView : public grumble::View, public BoardDataModelListener {
    
public:
    BoardView(BoardDataModel& model, const grumble::SpriteManager& spriteLoader);
    ~BoardView();
    
    void addCell(const CellDataModel& cell, const BoardLayer& layer);
    void removeCell(const CellDataModel& cell, const BoardLayer& layer);
    
    // BoardDataModelListener
    void onCellAdded(const CellDataModel& cell);
    void onCellRemoved(const GridLocation& location);
    void onBlueprintAdded(const GridLocation& origin, const BlueprintDataModel& blueprint);
    
private:
    std::map<int,BoardLayerView*> _layers;
    
    void buildLayerView(const BoardLayer &layer, const grumble::SpriteManager& spriteLoader);
};

#endif /* BoardView_hpp */
