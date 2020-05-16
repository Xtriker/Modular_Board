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

/* Contador del Encoder */
DigitalIn EncoderX1(Encoder1_Y_PIN);
DigitalIn EncoderX2(Encoder2_Y_PIN);

/* Conexion serial al PC */
Serial com(USBTX, USBRX,115200);
PwmOut Rojo(LED1);
PwmOut Verde(LED2);


/* Habilita los motores a pasos */
/* Un estado de 0 los habilita, un estado de 1 los desabilita */
DigitalOut Enable(Enable_PIN);

/* Resetea el driver de los motores */
/* Un estado de 0 los habilita, un estado de 1 los desabilita */
DigitalOut Reset(Reset_PIN);

/* Variables globales */
uint8_t Alarma = false;


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

void app_StepperMotorInitialState(void)
{
    Rojo = true;
    Verde = true;
    Enable = true;
    Reset = true;
}

void app_VelocidadMotor(int Velocidad_Eje, char Eje)
{
        
        volatile float Feedrate = 0.01*Velocidad_Eje - 0.0000000000000004;
        /*En donde Feedrate es el valor de PWM a colocar en Step */
        switch(Eje)
        {
            case 'X' | 'x':
            {
                if(Velocidad_Eje > 100)
                {
                    /* Desabilita los drivers */
                    Enable.write(true);
                    /* Reinicia el driver */
                    Reset.write(false);
                    com.printf("no permitido %d.",Velocidad_Eje);
                }
                else if(Velocidad_Eje < 10)
                {
                    /* Desabilita los drivers */
                    Enable.write(true);
                    /* Reinicia el driver */
                    Reset.write(false);
                    com.printf("no permitido %d.",Velocidad_Eje);
                }
                else if(Alarma == true)
                {
                    /* Desabilita los drivers */
                    Enable.write(true);
                    /* Reinicia el driver */
                    Reset.write(false);
                    /* Alarma activada */
                    com.printf("Alarma");
                }
                else
                {
                    /* Habilita los drivers */
                    Enable.write(false);
                    /* Desabilita el reset */
                    Reset.write(true);     
                    /* Curva de calibracion */
                    Step_X = Feedrate;
                    Rojo = Feedrate;
                }
            }
            break;
            case 'Y' | 'y':
            {   
                if(Velocidad_Eje > 100)
                {
                    /* Desabilita los drivers */
                    Enable.write(true);
                    /* Reinicia el driver */
                    Reset.write(false);
                    com.printf("no permitido %d.",Velocidad_Eje);
                }
                else if(Velocidad_Eje < 10)
                {
                   /* Desabilita los drivers */
                    Enable.write(true);
                    /* Reinicia el driver */
                    Reset.write(false);
                    com.printf("no permitido %d.",Velocidad_Eje);
                }
                else if(Alarma == true)
                {
                    /* Desabilita los drivers */
                    Enable.write(true);
                    /* Reinicia el driver */
                    Reset.write(false);
                    /* Alarma activada */
                    com.printf("Alarma");
                }
                else 
                {
                      /* Habilita los drivers */
                    Enable.write(false);
                    /* Desabilita el reset */
                    Reset.write(true);     
                    /* Curva de calibracion */
                    Step_Y1 = Feedrate;
                    Step_Y2 = Feedrate;
                    Verde = Feedrate;  
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
            case 'X' | 'x':
            {
                Direction_X = Direccion;
            }
            break;
            case 'Y' | 'y':
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

void app_Distance(char Eje, float Distancia)
{
    switch(Eje)
    {
        case 'X' | 'x':
        {
            if(app_Encoder() == Distancia)
            {
                /* Desabilita los drivers */
                Enable.write(true);
                Step_X = false;
                Rojo = true;
            }
            else
            {
                /* Sigue en ejecucion */
                Enable.write(false);
            }
        }
        break;
        case 'Y' | 'y':
        {
            if(app_Encoder() == Distancia)
            {
                /* Desabilita los drivers */
                Enable.write(true);
                Step_Y1 = false;
                Step_Y2 = false;
                Verde = true;
            }
            else
            {
                /* Sigue en ejecucion */
                Enable.write(false);
            }
        }
    }
    
}

void app_StepperMotorTask(char Eje, uint8_t Direccion,float Distancia,int Velocidad_Eje)
{
    app_VelocidadMotor(Velocidad_Eje, Eje);
    app_Movement(Eje, Direccion);
    app_Distance(Eje, Distancia);
}