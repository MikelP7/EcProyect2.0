   
/*-------------------------------------
rutinasAtencion.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"


int ESTADO;
int PJ;
int Port;
int Direccion;

int seg3;
int seg4=0;
int puntos=0;

int xDino=20;	//Posicion Dino eje x
int yDino=131;	//Posicion Dino eje y

int xPajaro=255; //Posicion Pajaro eje x
int xCactus=255; //Posicion Cactus eje x
int xCactus2=255;

int yPajaro=120;
int yCactus=131;
int yCactus2=131;

int cambioFondo=0;  // esta variable indica el cambio de fondo


//
	// Habilitar las interrupciones del teclado.

	// Establecer las rutinas de atención a interrupciones
//	EstablecerVectorInt();
//

void RutAtencionTeclado()
{

	// Teclas para pasar a la pantalla de seleccion de personaje
	if (TeclaPulsada()==START && ESTADO==INICIO){
	   	ESTADO = SELECCION;
	}
	// Teclas para avanazar o retroceder a la hora de seleccionar un personaje
	if (TeclaPulsada()==L && ESTADO==SELECCION){
		PJ--;
		if(PJ<0) PJ=4;
		visualizarPersonaje();
	}
	else if (TeclaPulsada()==R && ESTADO==SELECCION){
		PJ++;
		if(PJ>4) PJ=0;
		visualizarPersonaje();
	} 
	else if (TeclaPulsada()==A && ESTADO==SELECCION){//Tecla para confirmar la seleccion
		ESTADO=TIROS;
	}

	//Teclas para seleccionar la direccion del tiro
	if (TeclaPulsada()==ARRIBA && ESTADO==TIROS){
		Direccion=TARRIBA;
	}
	else if (TeclaPulsada()==ABAJO && ESTADO==TIROS){
		Direccion=TABAJO;
	}
	else if (TeclaPulsada()==IZQUIERDA && ESTADO==TIROS){
		Direccion=TIZQUIERDA;
	}
	else if (TeclaPulsada()==DERECHA && ESTADO==TIROS){
		Direccion=TDERECHA;
	}
	else if (TeclaPulsada()==B && ESTADO==TIROS){
		Direccion=TCENTRO;
	}

	//Tecla para tirar
	if (TeclaPulsada()==A && ESTADO==TIROS){
		//Tiro()

	}

	//Menu de Pausa
	if (TeclaPulsada()==START && ESTADO==TIROS){
		ESTADO=PAUSA;
	}

	//Continuar la partida
	if (TeclaPulsada()==A && ESTADO==PAUSA){
		ESTADO=TIROS;
	}
	else if (TeclaPulsada()==B && ESTADO==PAUSA){ //Volver a INICIO
		ESTADOO=INICIO;
	}

	//Volver a inicio o a seleccion de personaje
	if (TeclaPulsada()==A && ESTADO==FINAL){
		ESTADO=SELECCION;
	}
	else if (TeclaPulsada()==B && ESTADO==FINAL){
		ESTADO=INICIO;
	}
}

void tiros(){
	while (ESTADO==TIROS && ntiros<=5)
	{
		srand (time(NULL));
		Parada = rand()%5; 

		if(Direccion==Parada){
			Paradas ++;
			iprintf("\x1b[5;3HParadas: %d" Parada);
			iprintf("\x1b[5;3HGoles: %d" Goles);
		ntiros++;
		}else{
			Goles ++;
			iprintf("\x1b[5;3HParadas: %d" Parada);
			iprintf("\x1b[5;3HGoles: %d" Goles);
			ntiros++;
		}
	}
}




void RutAtencionTempo()
{
	static int tick=0;  	//Tick para las animaciones (para Mostrar/Borrar) de todos los sprites
	static int tickTemp=0;	//Tick para el tiempo (usado para calcular puntuación)




	/* Mediante un timer vamos a manejar todo el flujo y animaciones del juego*/
	if (ESTADO!=TIROS){
		tick++; 
		tickTemp++;

		if ()

	}

	



void EstablecerVectorInt()
{
	irqSet(IRQ_KEYS, RutAtencionTeclado);
	irqSet(IRQ_TIMER0, RutAtencionTempo);
}
