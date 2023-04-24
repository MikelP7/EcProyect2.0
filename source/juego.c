/*---------------------------------------------------------------------------------
Este código se ha desarrollado basándose en el código de dovoto "Simple sprite demo" 
y en otro ejemplo de Jaeden Ameronen
---------------------------------------------------------------------------------*/


#include <nds.h> 		//librería de la nds
#include <stdio.h>		//librería de entrada/salida estándar de C
#include <stdlib.h>		//librería estándar de C para reserva de memoria y conversiones númericas
#include <unistd.h>		//librería para asegurar la compatibilidad entre sistemas operativos

//librerías desarrolladas por nosotros para el proyecto
	
#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"

int tiempo;

void juego()
{	
	
	ESTADO=INICIO;
	

    // LLAMADAS A REALIZAR:

	// Configurar el teclado.
	int APorInt = 0x4001;
	ConfigurarTeclado(APorInt);

	// Configurar el temporizador.
	int Latch=39321;
	int Conf_Tempo=0x0002;
	ConfigurarTemporizador(Latch, Conf_Tempo);

	// Habilitar las interrupciones del teclado.
	HabilitarIntTeclado();

	// Habilitar las interrupciones del temporizador.
	PonerEnMarchaTempo();
	HabilitarIntTempo();

	// Establecer las rutinas de atención a interrupciones
	EstablecerVectorInt();
	



	//******************************************************************************//
	while(1)
	{	

	HabilitarIntTeclado();


		//************INICIO************//
		if (ESTADO == INICIO) {

			// Escribe el Titulo y los creadores del juego en la pantalla de arriba	
			iprintf("\x1b[10;5HInazuma Strickers");						
			iprintf("\x1b[13;5HBy: Iker, Julen y Mikel  ");
		
			visualizarIntro();
		}


		//************SELECCION************//
		if (ESTADO == SELECCION) {

			PJ=0;
			visualizarFondoSeleccion();  // Visualiza el menú de SELECCION
			visualizarPJ(); //Muestra el sprite del personaje en pantalla 
		
			//Explica por pantalla como seleccionar un personaje
			iprintf("\x1b[5;3HElije tu personaje utilizando R y L para ir cambiando o tocando tactilmente las flechas de la pantalla  ");
			iprintf("\x1b[7;3HPulsa START Para seleccionar al personaje ");
		
		}

		//************TIROS************//
		if(ESTADO == TIROS){

			visualizarPersonajeE();
			visualizarPort();
			visualizarCampo();
			visualizarBalon();
			ntiros=0;
			Goles=0;
			Parada=0;
			
			iprintf("\x1b[5;3HElije la direccion del tiro (ARRIBA, ABAJO, IZQUIERDA, DERECHA, CENTRO)");
			iprintf("\x1b[7;3HPulsa A para tirar");

			//Direccion en pantalla
			if(Direccion==TARRIBA){
				iprintf("\x1b[5;15HDireccion seleccionada: ARRIBA");
			} 
			else if(Direccion==TABAJO){
				iprintf("\x1b[5;15HDireccion seleccionada: ABAJO");
			} 
			else if(Direccion==TIZQUIERDA){
				iprintf("\x1b[5;15HDireccion seleccionada: IZQUIERDA");
			} 
			else if(Direccion==TDERECHA){
				iprintf("\x1b[5;15HDireccion seleccionada: DERECHA");
			} 
			else if(Direccion==TCENTRO){
				iprintf("\x1b[5;15HDireccion seleccionada: CENTRO")
			}

			// Va anotando los goles marcados o las paradas ejecutadas
			tiros();
			// Para finalizar la partida si se acaba el tiempo designado o se han hecho todos los tiros
			if(ntiros = 5 || tiempo = 300){
				ESTADO=FINAL;
			}
		}

		//************FINAL************//
		if(ESTADO==FINAL){
			if(Goles>=3){
				VisualizarVictoria();
			}else{
				VisualizarDerrota();
			}
		}

		// Vblank sincroniza los frames
		swiWaitForVBlank();
	}
}