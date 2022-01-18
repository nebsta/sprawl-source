//
//  CellView.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 9/01/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef CellView_hpp
#define CellView_hpp

#include <grumble/ui/ImageView.hpp>
#include <grumble/render/SpriteManager.hpp>

#include "CellDataModel.h"

class CellView : public grumble::View {
    
public:
    CellView(const CellDataModel& model, const grumble::SpriteManager& spriteManager);
    ~CellView();
};

#endif /* CellView_hpp */
