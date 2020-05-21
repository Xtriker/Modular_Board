#include "mbed.h"
#include "Puertos.h"

/* Definiciones */
/* Direcion de desplazamiento del motor a pasos */
#define Derecha (uint8_t)1
#define Izquierda (uint8_t)0

/* Funciones externas */

extern void app_VelocidadMotor(int Velocidad_Eje, char Eje);
extern void app_Movement(char Eje, uint8_t Direccion);
extern float app_FeedrateConversions(int Velocidad_Eje);
extern void app_StepperMotorInitialState(void);
extern void app_StepperMotorTask(char Eje, uint8_t Direccion,float Distancia,int Velocidad_Eje);
/* Variables externas */
extern uint8_t Alarma;
