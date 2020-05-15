/* Bibliotecas para el movimiento de motores a pasos */
#include "app_StepperMotors.h"


/* Declaración del movimiento de los motores */
/* Declaración de los puertos */
PwmOut Step_X(Step_PIN_X);
PwmOut Step_Y1(Step_PIN_Y1);
PwmOut Step_Y2(Step_PIN_Y2);

/* Declaracion de las salidas digitales de */
/* la direccion de los motores */
DigitalOut Direction_X(Direction_PIN_X);
DigitalOut Direction_Y1(Direction_PIN_Y1);
DigitalOut Direction_Y2(Direction_PIN_Y2);

/* Conexion serial al PC */
Serial com(USBTX, USBRX,115200);
PwmOut Rojo(LED1);
PwmOut Azul(LED2);

/* Habilita los motores a pasos */
DigitalOut Enable()


/*Declaración de las funciones */

float app_FeedrateConversions(int Velocidad_Eje)
{
    float Feedrate;
    if((Velocidad_Eje >= 0) && (Velocidad_Eje <= 100))
    {
        Feedrate = 0.1;
    }
    else if((Velocidad_Eje >= 100) && (Velocidad_Eje <= 200))
    {
        Feedrate = 0.2;
    }
    else if((Velocidad_Eje >= 200) && (Velocidad_Eje <= 300))
    {
        Feedrate = 0.3;
    }
    else if((Velocidad_Eje >= 300) && (Velocidad_Eje <= 400))
    {
        Feedrate = 0.4;
    }
    else if((Velocidad_Eje >= 400) && (Velocidad_Eje <= 500))
    {
        Feedrate = 0.5;
    }
    else if((Velocidad_Eje >= 500) && (Velocidad_Eje <= 600))
    {
        Feedrate = 0.6;
    }
    else if((Velocidad_Eje >= 600) && (Velocidad_Eje <= 700))
    {
        Feedrate = 0.7;
    }
    else if((Velocidad_Eje >= 700) && (Velocidad_Eje <= 800))
    {
        Feedrate = 0.8;
    }
    else if((Velocidad_Eje >= 800) && (Velocidad_Eje <= 900))
    {
        Feedrate = 0.9;
    }
    else if((Velocidad_Eje >= 900) && (Velocidad_Eje <= 1000))
    {
        Feedrate = 1;
    }
    return Feedrate;
}

void app_VelocidadMotor(int Velocidad_Eje, char Eje)
{
        Rojo = 0;
        Azul = 0;
        volatile float Feedrate = 0.01*Velocidad_Eje - 0.0000000000000004;
        /*En donde Feedrate es el valor de PWM a colocar en Step */
        switch(Eje)
        {
            case 'X':
            {
                if(Velocidad_Eje > 100)
                {
                    com.printf("no permitido %d.",Velocidad_Eje);
                }
                else if(Velocidad_Eje < 10)
                {
                    com.printf("no permitido %d.",Velocidad_Eje);
                }
                else
                {
                    Step_X = Feedrate;
                    Rojo = Feedrate;
                }
                
                
            }
            break;
            case 'Y':
            {   
                if(Velocidad_Eje > 100)
                {
                    com.printf("no permitido %d.",Velocidad_Eje);
                }
                else if(Velocidad_Eje < 10)
                {
                    com.printf("no permitido %d.",Velocidad_Eje);
                }
                else 
                {
                    Step_Y1 = Feedrate;
                    Step_Y2 = Feedrate;
                    Azul = Feedrate;  
                }
            }
            break;
            default:
            {

            }
        }    
}



void app_Movement(char Eje, uint8_t Direccion)
{
    /*Seleciona el eje al cual quiera cambiar la direccion */
    /*por defecto este valor es un 0 logico */
        switch(Eje)
        {
            case 'X':
            {
                Direction_X = Direccion;
            }
            break;
            case 'Y':
            {
                Direction_Y1 = Direccion;
                Direction_Y2 = Direccion;
            }
            break;
            default:
            {
                
            }
        }
}

