//
//  BoardInputView.hpp
//  sprawl
//
//  Created by Benjamin Wallis on 28/02/2016.
//  Copyright © 2016 The Caffeinated Coder. All rights reserved.
//

#ifndef BoardInputView_hpp
#define BoardInputView_hpp

#include <grumble/ui/View.hpp>

class BoardInputListener {
public:
    virtual void onLeftInput() = 0;
    virtual void onRightInput() = 0;
    virtual void onDownInput() = 0;
};

class BoardInputView : public grumble::View {
public:
    BoardInputView();
    ~BoardInputView();
    
    void setBoardInputListener(BoardInputListener *listener);
    
private:
    
    BoardInputListener *_listener;
};

#endif /* BoardInputView_hpp */
