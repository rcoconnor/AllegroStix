//
//  Target.hpp
//  Pickin' Sticks
//
//  Created by Rory O'Connor on 8/20/18.
//  Copyright © 2018 Rory O'Connor. All rights reserved.
//

#ifndef Target_hpp
#define Target_hpp

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Systems.hpp"

class Target {
   
public:
    Target(const char* filename, Systems* systemPtr);
    ~Target(); 
    int getX();
    int getY();
    void drawStick(ALLEGRO_DISPLAY* displayPtr);
    void createRanPos(); 
    ALLEGRO_BITMAP* sprite;
    box* colBoxPtr; 
    
private:
    int x;
    int y;
    int height;
    int width; 
    
};

#endif /* Target_hpp */
