/*
 * Copyright (c) 2014-2020 Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

// Adjust pin name to your board specification.
// You can use LED1/LED2/LED3/LED4 if any is connected to PWM capable pin,
// or use any PWM capable pin, and see generated signal on logical analyzer.

PwmOut ch1(LED1);
PwmOut ch2(PWM_OUT);
PwmOut ch3(LED3);

int main()
{
    // specify period first
    int period = 50;
    float cycle = 0.5;

    ch1.period_ms(period);      // 4 second period
    ch1.write(cycle);      // 50% duty cycle, relative to period

    ch2.period_ms(period);
    ch2.write(cycle);

    ch3.period_ms(period);
    ch3.write(cycle);

    while(1);
    
}
