/* Bibliotecas para el movimiento de motores a pasos */
#include "app_StepperMotors.h"


/* Declaración del movimiento de los motores */
/* Declaración de los puertos */
DigitalOut Step_X(Step_PIN_X);
DigitalOut Step_Y1(Step_PIN_Y1);
DigitalOut Step_Y2(Step_PIN_Y2);

/* Declaracion de las salidas digitales de */
/* la direccion de los motores */
DigitalOut Direction_X(Direction_PIN_X);
DigitalOut Direction_Y1(Direction_PIN_Y1);
DigitalOut Direction_Y2(Direction_PIN_Y2);

/* Contador del Encoder */
DigitalIn EncoderX1(Encoder1_Y_PIN);
DigitalIn EncoderX2(Encoder2_Y_PIN);

/* Conexion serial al PC */
Serial com(USBTX, USBRX,115200);

/* Habilita los motores a pasos */
/* Un estado de 0 los habilita, un estado de 1 los desabilita */
DigitalOut Enable(Enable_PIN);

/* Resetea el driver de los motores */
/* Un estado de 0 los habilita, un estado de 1 los desabilita */
DigitalOut Reset(Reset_PIN);

/* Indicadores del movimiento */
DigitalOut Rojo(LED1);
DigitalOut Verde(LED2);


/* Variables globales */
enum S_Endstop{
    NORMAL,
    PARO,
    REINICIO
};

int Contador_distancia_X = 0, Contador_distancia_Y = 0;
    

/*Declaración de las funciones */

void app_StepperMotorInitialState(void)
{
    Enable = true;
    Reset = true;
}

int app_Encoder(void)
{
    /* Contador de posicion del encoder */
    volatile uint8_t Contador = 0u;
    if((EncoderX1 == true) && (EncoderX2 == false))
    {
        Contador = Contador + 1;
    }
    else if((EncoderX1 == false) && (EncoderX2 == true))
    {
        Contador = Contador - 1;
    }
    return Contador;
}

void app_Distance(char Eje, uint8_t Distancia,uint8_t Direccion,uint8_t Tiempo)
{
    /* Curva de calibracion de los milimetros a pulsos */
    uint16_t Pulsos[1];
    volatile uint8_t i;
    if(i > 2)
    {
        i = 0;
    }
    else
    {
        Pulsos[i] = (3.3*Distancia)-0.0000000000000227373675443232;
    }
    switch(Eje)
    {
        case 'X' | 'x':
        {
            switch (Alarma)
            {
                case NORMAL:
                {
                    if ((Contador_distancia_Y == Pulsos[0]) && (Contador_distancia_X == Pulsos[1]))
                    { 
                        /* Desabilito el driver */
                        Enable.write(1);
                        /* Mando el driver a reset */
                        Reset.write(0);   
                    }
                    else if(Contador_distancia_X < Pulsos[i])
                    {
                        
                        /* Habilito el driver */
                        Enable.write(0);
                        /* Reset desactivado */
                        Reset.write(1);
                        /*Coloca el sentido de giro del motor */
                        Direction_X = Direccion;
                        /* Envio un bit */
                        Step_X.write(1);
                        Rojo.write(false);
                        /*Seleciona la frecuencia de movimiento */
                        /* Frecuencia de 500Hz */
                        wait_ms(Tiempo);
                        Step_X.write(0);
                        Rojo.write(true);
                        wait_ms(Tiempo);
                        Contador_distancia_X = Contador_distancia_X + 1;
                        com.printf("Pulsos %d Contador %d",Distancia,Contador_distancia_X);
                        i = i + 1;
                    }
                }
                break;
                case PARO:
                {
                    Alarma = PARO;
                    Tiempo = 0;
                    /* Desabilito el driver */
                    Enable.write(1);
                    /* Mando el driver a reset */
                    Reset.write(0); 
                }
                break;
                case REINICIO:
                {
                    /* Mando el driver a reset */
                    Reset.write(0); 
                }
                default:
                break;
            }
        }
        break;
        case 'Y' | 'y':
        {
             switch (Alarma)
            {
                case NORMAL:
                {
                    if ((Contador_distancia_Y == Pulsos[0]) && (Contador_distancia_X == Pulsos[1]))
                    { 
                        /* Desabilito el driver */
                        Enable.write(1);
                        /* Mando el driver a reset */
                        Reset.write(0);   
                    }
                    else if(Contador_distancia_Y < Pulsos[i])
                    {
                        
                        /* Habilito el driver */
                        Enable.write(0);
                        /* Reset desactivado */
                        Reset.write(1);
                        /*Coloca el sentido de giro del motor */
                        Direction_Y1 = Direccion;
                        Direction_Y2 = Direccion;
                        /* Envio un bit */
                        Step_Y1.write(1);
                        Step_Y2.write(1);
                        Verde.write(false);
                        /*Seleciona la frecuencia de movimiento */
                        /* Frecuencia de 500Hz */
                        wait_ms(Tiempo);
                        Step_Y1.write(0);
                        Step_Y2.write(0);
                        Verde.write(true);
                        wait_ms(Tiempo);
                        Contador_distancia_Y = Contador_distancia_Y + 1;
                        com.printf("Pulsos %d Contador %d",Distancia,Contador_distancia_Y);
                        i = i + 1;
                    }
                }
                break;
                case PARO:
                {
                    Alarma = PARO;
                    /* Desabilito el driver */
                    Enable.write(1);
                    /* Mando el driver a reset */
                    Reset.write(0); 
                    Tiempo = 0;
                }
                break;
                case REINICIO:
                {
                    /* Mando el driver a reset */
                    Reset.write(0); 
                }
                break;
                default:
                {}  
            } 
        }
        break;
        default:
        {}
    }
    
}
