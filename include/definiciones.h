/*-------------------------------------
definiciones.h
-------------------------------------*/
#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estandar de C
#include <stdlib.h>		//librería estandar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos


#define IME		(*(vuint32*)0x04000208) //Interrupt Master Enable -- Habilitar-deshabilitar todas las interrupciones
#define IE		(*(vuint32*)0x04000210) //Interrupt Enable -- Habilitar-deshabilitar las interrupciones de forma individual
#define IF		(*(vuint32*)0x04000214) //Interrupt Flag -- Registro de solicitud de interrupción

// funciones para el tratamiento general de las interrupciones
#define HabilitarInterrupciones() IME=1 //Habilitar todas las interrupciones
#define DeshabilitarInterrrupciones() IME=0 //Deshabilitar todas las interrupciones

//registros del teclado
#define TECLAS_DAT	(*(vu16*)0x4000130) //registro de datos
#define TECLAS_CNT	(*(vu16*)0x4000132) //registro de control

//registros del temporizador Timer0
#define TIMER0_CNT   (*(vuint16*)0x04000102) //registro de control
#define TIMER0_DAT    (*(vuint16*)0x04000100) //registro de datos



//Acceso a los registros de la pantalla táctil
extern touchPosition PANT_DAT;

// Nombres asignados a las teclas para facilitar la comprensión de nuestro código

#define A				0 
#define B				1
#define SELECT			2 
#define START			3
#define DERECHA			4 
#define IZQUIERDA		5
#define ARRIBA			6 
#define ABAJO			7
#define R				8 
#define L				9



//Nombres asignados a los estados

#define INICIO      0
#define SELECCION   1
#define TIROS       2
#define FINAL       3
#define PAUSA       4

//Tiros o Paradas

#define TARRIBA      0
#define TABAJO       1
#define TCENTRO      2
#define TIZQUIERDA   3 
#define TDERECHA     4

//PJs

#define Personaje 0
#define Personaje 1
#define Personaje 2
#define Personaje 3
#define Personaje 4

//Porteros

#define Portero 0
#define Portero 1
#define Portero 2

extern int ESTADO;
extern int PJ;
extern int Port;
extern int Direccion;
extern int Parada;
extern int ntiros;
extern int Goles;
extern int Paradas;

