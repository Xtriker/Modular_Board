
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
    //app_StepperMotorInitialState();   
    pc.printf("Movimiento del motor X");
    while (true) {
        app_Distance('x',140,Izquierda,(uint8_t)500);
    }
}
