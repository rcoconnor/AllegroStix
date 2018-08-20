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
    screenWidth = 500;
    screenHeight = 500;
    
}

Systems::Systems(int width, int height) {
    
    screenWidth = width;
    screenHeight = height;
    display = NULL;
    queue = NULL; 

}

void Systems::setup() {
    
    al_init();
    al_init_image_addon(); 
    display = al_create_display(screenWidth, screenHeight);
    queue = al_create_event_queue();
    al_install_keyboard();
    
    
    // register event sources
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());
    //al_register_event_source(queue, al_get_mouse_event_source()); 
    
}


int Systems::getScreenWidth() {
    
    return screenWidth;

}


int Systems::getScreenHeight() {

    return screenHeight;
    
}



// Destructor //
Systems::~Systems() {
    
    al_uninstall_keyboard();
    al_destroy_display(display);
    al_destroy_event_queue(queue); 

}
