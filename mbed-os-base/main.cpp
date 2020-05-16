/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"
#include "Librerias.h"

/* Comunicacion serial */
Serial pc(USBTX, USBRX,115200);

/*Variables globales */
int Velocidad;
char Eje;
float Distancia;
float Feedrate = 0u;
// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    100

int main()
{
    app_StepperMotorInitialState();
    while (true) {
        pc.printf("$: \n");
        pc.scanf("%d",&Velocidad);
        pc.scanf("%s",&Eje);
        //Feedrate = app_FeedrateConversions(Velocidad);
        app_StepperMotorTask(Eje, Derecha, Distancia, Velocidad);
        thread_sleep_for(BLINKING_RATE_MS);
    }
}
