#include "Aplicaciones/Librerias.h"


/* Comunicacion serial */
Serial pc(USBTX, USBRX,115200);

/*Variables globales */

// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    100


int main()
{     
    while (true) {
        app_Endstop();
        wait_us(5);
        app_Distance('x',330,Derecha,(uint8_t)2);
        app_Distance('y',100,Izquierda,(uint8_t)2);
    }
}
