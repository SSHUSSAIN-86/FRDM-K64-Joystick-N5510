/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Joystick.h"
#include "N5110.h"
#include <cstdio>


// Blinking rate in milliseconds
#define BLINKING_RATE     500ms



int main()
{
    PinName PTC9;
    PinName PTC10;
    PinName PTC7;
    PinName PTC2;
    PinName PTC1;
    PinName PTC11;

    PinName PTB10;
    PinName PTB11;
    PinName PTC16;

    N5110 lcd(PTC9,PTC0,PTC7,PTD2,PTD1,PTC11);
    //Initialisation
    lcd.init();

    //Clearing the screen buffer
    lcd.clear();

    //Printing strings and chars
    lcd.printString("Hello,World!",0,0);
    lcd.printChar('X',5,3);

    //Setting and clearing pixels
    lcd.setPixel(2,5);

    
    Joystick joystick(PTB10,PTB11,PTC16);
    joystick.init();

    if(joystick.button_pressed()){
        printf("Button Pressed\n");
    }

    Vector2D coord = joystick.get_coord();
    printf("Coord = %f,%f\n", coord.x,coord.y);       

    

    

    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);

    

    while (true) {
       

        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
    }
}
