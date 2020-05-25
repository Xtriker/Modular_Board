

#include "Aplicaciones/Librerias.h"


/* Comunicacion serial */
Serial pc(USBTX, USBRX,115200);

/*Variables globales */

// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    100


int main()
{   
    //app_StepperMotorInitialState();   
    pc.printf("Movimiento del motor X");
    while (true) {
        //app_Distance('x',2,Izquierda,(uint8_t)2);
        app_Endstop();
        app_Distance('y',100,Izquierda,(uint8_t)2);
    }
}
