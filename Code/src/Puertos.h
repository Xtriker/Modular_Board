/* Definicion de los puertos */
/* Finales de carrera opticos se usan entradas digitales */

#define Endstop_X1              PTC0
#define Endstop_X2              PTC1
#define Endstop_Y1              PTC2
#define Endstop_Y2              PTC3


/* Defincon de los puertos de salida del Driver X */

#define Step_PIN_X              PTD0         
#define Direction_PIN_X         PTC16

/* Definicion de los puertos de salida del Driver Y1 */

#define Step_PIN_Y1             PTD5
#define Direction_PIN_Y1        PTC13

/*Definicion de los puertos de salida del Driver Y2 */

#define Step_PIN_Y2             PTA13
#define Direction_PIN_Y2        PTC12

/* Habilita los drivers de los motores */

#define Enable_PIN              PTD7

/* Pin de reset para los drivers de los motores */

#define Reset_PIN               PTD6

/* Pines para el encoder */

#define Encoder1_Y_PIN          PTB8
#define Encoder2_Y_PIN          PTB9