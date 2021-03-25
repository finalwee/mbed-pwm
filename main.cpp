/*
 * Copyright (c) 2014-2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

// Adjust pin name to your board specification.
// You can use LED1/LED2/LED3/LED4 if any is connected to PWM capable pin,
// or use any PWM capable pin, and see generated signal on logical analyzer.

Ticker changer;

PwmOut ch1(LED1);
PwmOut ch2(LED2);
PwmOut ch3(LED3);

int n;
float PI = 3.14159;

void change() {
    double dc = 0;
    double sin_wave = 0;
    
    n = n+1;
    if(n == 100) n = 0;
    
    sin_wave = 1+sin(2*PI*n/100);
    dc = 2-sin_wave;

    //dc = 0.5 + (n/100);

    ch1.write(dc/1.5);
    ch2.write(dc/2);
    ch3.write(dc/3);
}

int main()
{
    int period = 200;
    n = 0;
    ch1.period_ms(period);      
    ch1.write(0.5); 

    ch2.period_ms(period);
    ch2.write(0.5);

    ch3.period_ms(period);
    ch3.write(0.5);
    
    changer.attach(&change, 20ms);

    while(1){
        //printf("n: %d\n", n);
        //wait_us(10000);
    }
    
}
