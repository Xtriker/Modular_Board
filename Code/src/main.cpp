#include "Aplicaciones/Librerias.h"


/* Comunicacion serial */
Serial pc(USBTX, USBRX,115200);

/*Variables globales */

// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    100


int main()
{     
    while (true) {
        //app_Distance('x',2,Izquierda,(uint8_t)2);
        app_Endstop();
        app_Distance('y',330,Derecha,(uint8_t)2);
    }
}
