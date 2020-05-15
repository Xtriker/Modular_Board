#include "mbed.h"
#include "Puertos.h"
/* Funciones externas */

extern void app_Endstop(void);

/* Maquina de estados */

typedef enum
{
    NOPRESIONADO,
    PRESIONADO,
}S_Endstop_PN;

typedef enum{
    ESPERA,
    PARO,
    REINICIO
}S_Endstop_EPR;