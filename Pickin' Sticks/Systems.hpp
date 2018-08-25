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
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
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
    void drawMenu();
    void mainMenu();
    void displayGameOver();
    void gameOver(); 
    ALLEGRO_BITMAP* loadBitmapAtSize(const char* filename, int w, int h);
    
    ALLEGRO_DISPLAY* display;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_FONT* font;
    ALLEGRO_FONT* largeFont; 
    ALLEGRO_TIMER* timer; 
    
    
private:
    int screenWidth;
    int screenHeight;
    
};

struct box {
    int x;
    int y;
    int width;
    int height;
};

#endif /* Systems_hpp */
