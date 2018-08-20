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

class Player {
   
public:
    // constructors //
    Player();
    Player(const char* filename);
    ~Player();
    
    // methods //
    void drawToScreen();
    void handleMovement(ALLEGRO_KEYBOARD_STATE keystate); 
    
    
    // properties
    int x;
    int y;
    ALLEGRO_BITMAP* sprite;
    
};


#endif /* Player_hpp */
