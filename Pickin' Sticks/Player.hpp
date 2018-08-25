//
//  Player.hpp
//  Pickin' Sticks
//
//  Created by Rory O'Connor on 8/19/18.
//  Copyright © 2018 Rory O'Connor. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Systems.hpp"

class Player {
   
public:
    // constructors //
    Player();
    Player(const char* filename, Systems* systemPtr);
    ~Player();
    
    // methods //
    void drawToScreen(ALLEGRO_DISPLAY* display);
    void handleMovement(ALLEGRO_KEYBOARD_STATE keystate);
    void incrementScore();
    void drawScore();
    void deductTime();
    void resetTime();
    void resetScore();
    void resetPos(); 
    
    int getScore();
    int getTime();
    
    box* colBoxPtr; // box collider
    
private:
    // properties
    int x;
    int y;
    int score;
    int time;
    int startX_pos;
    int startY_pos;
    ALLEGRO_BITMAP* sprite;
    
};


#endif /* Player_hpp */
