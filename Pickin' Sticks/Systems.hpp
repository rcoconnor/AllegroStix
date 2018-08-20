//
//  Systems.hpp
//  Pickin' Sticks
//
//  Created by Rory O'Connor on 8/18/18.
//  Copyright © 2018 Rory O'Connor. All rights reserved.
//

#ifndef Systems_hpp
#define Systems_hpp

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>


class Systems {
    
public:
    // constructors //
    Systems();
    Systems(int width, int height); 
    ~Systems();
    void setup();
    int getScreenWidth();
    int getScreenHeight();
    ALLEGRO_BITMAP* loadBitmapAtSize(); 
    
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue; 
    
private:
    int screenWidth;
    int screenHeight;
    
};

#endif /* Systems_hpp */
