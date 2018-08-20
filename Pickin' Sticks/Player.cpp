//
//  Player.cpp
//  Pickin' Sticks
//
//  Created by Rory O'Connor on 8/19/18.
//  Copyright © 2018 Rory O'Connor. All rights reserved.
//

#include "Player.hpp"

Player::Player() {
    x = 50;
    y = 50;
    sprite = NULL;
}


Player::Player(const char* filename) {
    x = 50;
    y = 50;
    sprite = al_load_bitmap(filename);
}


void Player::handleMovement(ALLEGRO_KEYBOARD_STATE keystate) {
    if (al_key_down(&keystate, ALLEGRO_KEY_RIGHT)) {
        x += 1;
    }
    if (al_key_down(&keystate, ALLEGRO_KEY_LEFT)) {
        x -= 1;
    }
    if (al_key_down(&keystate, ALLEGRO_KEY_UP)) {
        y -= 1;
    }
    if (al_key_down(&keystate, ALLEGRO_KEY_DOWN)) {
        y+= 1; 
    }
}


void Player::drawToScreen() {
    al_draw_bitmap(sprite, x, y, 0); 
}


Player::~Player() {
    if (sprite != NULL) {
        al_destroy_bitmap(sprite); 
    }
}
