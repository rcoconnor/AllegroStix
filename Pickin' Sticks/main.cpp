//
//  main.cpp
//  Pickin' Sticks
//
//  Created by Rory O'Connor on 8/16/18.
//  Copyright © 2018 Rory O'Connor. All rights reserved.
//




#include "Systems.hpp"
#include "Player.hpp"
#include "Target.hpp"
#include <string.h>


ALLEGRO_BITMAP* loadBitmapAtSize(const char* fileName, int w, int h);
void loadLevel(ALLEGRO_BITMAP* grassFile, int width, int height);


int main(int argc, char** argv) {
    
    Systems System(500, 500);
    System.setup();
    
    ALLEGRO_BITMAP* grassImage;
    grassImage = loadBitmapAtSize("grass03.png", 50, 50);
    
    Player user("Chimp.bmp");
    Target stick("banana2.png");
    
    ALLEGRO_EVENT event;
    bool running = true;
    while (running == true) {
        
        if (!al_is_event_queue_empty(System.queue)) {
            al_wait_for_event(System.queue, &event);
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                running = false;
            }
        }

        
        // handle keyboard input //;
        ALLEGRO_KEYBOARD_STATE keyState;

        al_get_keyboard_state(&keyState);
        user.handleMovement(keyState); 
        
        // load in the level
        loadLevel(grassImage, System.getScreenWidth(), System.getScreenHeight());
        
        // draw the player to the screen
        user.drawToScreen();
        stick.drawStick(); 
        
        al_flip_display();
    }
    
    
    return 0;
    
}


void loadLevel(ALLEGRO_BITMAP* grassImage, int displayWidth, int displayHeight) {
    
    
    for (int i = 0; i < displayWidth; i += displayWidth / 10) {
        for (int j = 0; j < displayHeight; j+= displayHeight / 10) {
            al_draw_bitmap(grassImage, i, j, 0);
        }
    }
    
}


ALLEGRO_BITMAP* loadBitmapAtSize(const char* fileName, int w, int h) {
    
    /*
     * This function will return a scaled bitmap with
     * width = w and height = h
     */
    
    ALLEGRO_BITMAP* resizedBitmap;
    ALLEGRO_BITMAP* loadedBitmap;
    ALLEGRO_BITMAP* prevTarget;
    
    // create a temporary bitmap of the size we want
    resizedBitmap = al_create_bitmap(w, h);
    if (!resizedBitmap) {
        return NULL;
    }
    
    // load the bitmap at the original size
    loadedBitmap = al_load_bitmap(fileName);
    if (!loadedBitmap) {
        al_destroy_bitmap(resizedBitmap);
        return NULL;
    }
    
    // set the target bitmap to the resized bitmap
    prevTarget = al_get_target_bitmap();
    al_set_target_bitmap(resizedBitmap);
    
    // copy the loaded bitmap to the resized bitmap
    al_draw_scaled_bitmap(loadedBitmap,
                          0, 0,                                 // source origin
                          al_get_bitmap_width(loadedBitmap),    // source width
                          al_get_bitmap_height(loadedBitmap),   // source height
                          0, 0,                                 // target origin
                          w, h,                                 // target dimsensions
                          0                                     // flags
                          );
    
    // restore the previous target and clean up
    al_set_target_bitmap(prevTarget);
    al_destroy_bitmap(loadedBitmap);
    
    return resizedBitmap;
    
}


