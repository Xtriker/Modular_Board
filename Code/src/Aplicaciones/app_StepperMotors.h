#include "mbed.h"
#include "Puertos.h"
#include "app_Endstops.h"

/* Definiciones */
/* Direcion de desplazamiento del motor a pasos */
#define Derecha (uint8_t)1
#define Izquierda (uint8_t)0

/* Funciones externas */

extern void app_StepperMotorInitialState(void);
extern void app_Distance(char Eje, uint8_t Distancia, uint8_t Direccion,uint8_t Tiempo);

/* Variables externas */
extern uint8_t Alarma;


