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
    score = 0;
    time = 10; 
}


Player::Player(const char* filename, Systems* systemPtr) {
    x = 50;
    y = 50;
    score = 0;
    time = 10;
    sprite = systemPtr->loadBitmapAtSize(filename, 50, 50);
    colBoxPtr = new box; 
    colBoxPtr->x = x;
    colBoxPtr->y = y;
    colBoxPtr->width = 50;
    colBoxPtr->height = 50;
    startX_pos = 250;
    startY_pos = 250;
}


void Player::handleMovement(ALLEGRO_KEYBOARD_STATE keystate) {
    if (al_key_down(&keystate, ALLEGRO_KEY_RIGHT)) {
        x += 1;
        colBoxPtr->x += 1;
    }
    if (al_key_down(&keystate, ALLEGRO_KEY_LEFT)) {
        x -= 1;
        colBoxPtr->x -= 1;
    }
    if (al_key_down(&keystate, ALLEGRO_KEY_UP)) {
        y -= 1;
        colBoxPtr->y -= 1;
    }
    if (al_key_down(&keystate, ALLEGRO_KEY_DOWN)) {
        y+= 1;
        colBoxPtr->y += 1;  
    }
}


void Player::drawToScreen(ALLEGRO_DISPLAY* display) {
    al_set_target_backbuffer(display); 
    al_draw_bitmap(sprite, x, y, 0);
}


void Player::resetScore() {
    score = 0; 
}


void Player::resetTime() {
    time = 10; 
}


void Player::incrementScore() {
    score++;
}


void Player::resetPos() {
    x = startX_pos;
    y = startY_pos;
    colBoxPtr->x = startX_pos;
    colBoxPtr->y = startY_pos; 
}


void Player::deductTime() {
    time = time - 1; 
}


int Player::getScore() {
    return score;
}

int Player::getTime() {
    return time;
}


Player::~Player() {
    if (sprite != NULL) {
        al_destroy_bitmap(sprite); 
    }
}
