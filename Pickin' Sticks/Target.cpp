//
//  Target.cpp
//  Pickin' Sticks
//
//  Created by Rory O'Connor on 8/20/18.
//  Copyright © 2018 Rory O'Connor. All rights reserved.
//

#include "Target.hpp"


Target::Target(const char* filename) {
    x = 80;
    y = 80;
    sprite = al_load_bitmap(filename);
}


void Target::drawStick() {
    al_draw_bitmap(sprite, x, y, 0); 
}


Target::~Target() {
    al_destroy_bitmap(sprite);
}
