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

class Target {
   
public:
    Target(const char* filename);
    ~Target(); 
    int getX();
    int getY();
    void drawStick();
    void createRanPos(); 
    ALLEGRO_BITMAP* sprite; 
    
private:
    int x;
    int y;
    
};

#endif /* Target_hpp */
