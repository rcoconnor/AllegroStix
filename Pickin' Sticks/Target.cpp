//
//  Target.cpp
//  Pickin' Sticks
//
//  Created by Rory O'Connor on 8/20/18.
//  Copyright © 2018 Rory O'Connor. All rights reserved.
//

#include "Target.hpp"
#include <cstdlib>



Target::Target(const char* filename, Systems* systemPtr) {
    x = 200;
    y = 140;
    width = 50;
    height = 50;
    sprite = systemPtr->loadBitmapAtSize(filename, width, height);
    colBoxPtr = new box;
    colBoxPtr->x = 200;
    colBoxPtr->y = 140;
    colBoxPtr->width = 50;
    colBoxPtr->height = 50;
    srand(time(NULL));
}


void Target::createRanPos() {
    x = rand() % 500;
    y  = rand() % 500;
    colBoxPtr->x = x;
    colBoxPtr->y = y;
    if (x < 50 || x > 450 || y > 450 || y < 50) {
        createRanPos(); 
    }
}


void Target::drawStick(ALLEGRO_DISPLAY* displayPtr) {
    al_draw_bitmap(sprite, x, y, 0); 
    
}


Target::~Target() {
    al_destroy_bitmap(sprite);
}
