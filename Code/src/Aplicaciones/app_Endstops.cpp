#include "app_Endstops.h"

/* Declaración de funciones */
volatile uint8_t Alarma;
/* Declaración de bits de entrada de los finales de carrera */



DigitalIn endX1(Endstop_X1);
DigitalIn endX2(Endstop_X2);
DigitalIn endY1(Endstop_Y1);
DigitalIn endY2(Endstop_Y2);

void app_InEndstops(void)
{
    
    
}
void app_Endstop(void)
{
    
    if((endY1 == false) || (endY2 == false))
    {
        Alarma = 1;
    }
    else if((endX1 == false) || (endX2 == false))
    {
        Alarma = 1;
    }
}