//
//  Systems.cpp
//  Pickin' Sticks
//
//  Created by Rory O'Connor on 8/18/18.
//  Copyright © 2018 Rory O'Connor. All rights reserved.
//

#include "Systems.hpp"

// constructors //
Systems::Systems() {
    
    display = NULL;
    queue = NULL;
    font = NULL;
    screenWidth = 500;
    screenHeight = 500;
    
}

Systems::Systems(int width, int height) {
    
    screenWidth = width;
    screenHeight = height;
    display = NULL;
    queue = NULL; 
    font = NULL;
    timer = NULL;

}





void Systems::setup() {
    
    al_init();              // initialize allegro
    al_init_image_addon();  // initialize image addon
    al_init_font_addon();   // initialize font addon
    al_init_ttf_addon();    // initialize true type font addons
    
    display = al_create_display(screenWidth, screenHeight);
    queue = al_create_event_queue();
    al_install_keyboard();
    
    timer = al_create_timer(1.0);
    
    font = al_load_ttf_font("times.ttf", 30, 0);
    if (!font) {
        std::cout << "font not initialized" << std::endl;
        exit(1);
    }
    largeFont = al_load_ttf_font("times.ttf", 50, 0);
    
    // register event sources
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_timer_event_source(timer)); 
    //al_register_event_source(queue, al_get_mouse_event_source()); 
    
}


int Systems::getScreenWidth() {
    
    return screenWidth;

}


int Systems::getScreenHeight() {

    return screenHeight;
    
}

void Systems::displayGameOver() {

    al_clear_to_color(al_map_rgb(200, 0, 0));
    al_draw_text(largeFont, al_map_rgb(0, 0, 0), 130, 20, 0, "Game Over");
    al_draw_text(font, al_map_rgb(0, 0, 0), 95, 400, 0, "Press Space to play again");
    al_draw_text(font, al_map_rgb(0, 0, 0), 170, 430, 0, "Or Q to quit");

}


void Systems::gameOver() {
    
    displayGameOver();
    al_flip_display();
    ALLEGRO_EVENT event;
    bool isGameOver = true;
    while (isGameOver == true) {
        if (!al_is_event_queue_empty(queue)) {
            al_wait_for_event(queue, &event);
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                exit(1); 
            }
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
                    isGameOver = false;
                    return;
                } else if (event.keyboard.keycode == ALLEGRO_KEY_Q) {
                    exit(1);
                }
            }
        }
    }
}


void Systems::drawMenu() {
    
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_draw_text(largeFont, al_map_rgb(0, 0, 0), 120, 20, 0, "Pickin' Stix!");
    al_draw_text(font, al_map_rgb(0, 0, 0), 140, 400, 0, "Press space to play");
    al_draw_text(font, al_map_rgb(0, 0, 0), 180, 435, 0, "Or q to quit");
    
}

void Systems::mainMenu() {
    
    al_set_target_backbuffer(display);
    drawMenu();
    al_flip_display();
    
    ALLEGRO_EVENT event; 
    
    bool menu = true;
    while (menu == true) {
        if (!al_is_event_queue_empty(queue)) {
            al_wait_for_event(queue, &event);
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                exit(1);
            }
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
                    menu = false;
                    return;
                }
                if (event.keyboard.keycode == ALLEGRO_KEY_Q) {
                    exit(1); 
                }
            }
        }
    }
}


ALLEGRO_BITMAP* Systems::loadBitmapAtSize(const char* filename, int w, int h) {
    
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
    loadedBitmap = al_load_bitmap(filename);
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



// Destructor //
Systems::~Systems() {
    
    al_uninstall_keyboard();
    al_destroy_display(display);
    al_destroy_event_queue(queue); 

}
