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
int touch;

void juego()
{	
	//definiciones de variables
	//int i=9;
	//int tecla=0;;

	ESTADO=INTRO;
	yflecha=60;
	pj=1;

	//******************************************************************************//

    // LLAMADAS A REALIZAR:
	// Configurar el teclado.

	//int APorInt = 0x4001;
	//ConfigurarTeclado(APorInt);

	int ABPorInt = 0x4003;
	ConfigurarTeclado(ABPorInt);

	int StartPorInt = 0x4008;
	ConfigurarTeclado(StartPorInt);

	//int UpDownPorInt = 0x4080;
	//ConfigurarTeclado(UpDownPorInt);

	int LRPorInt = 0x4300;
	ConfigurarTeclado(LRPorInt);

	// Configurar el temporizador.
	int Latch=39321;
	int Conf_Tempo=0x0002;
	ConfigurarTemporizador(Latch, Conf_Tempo);

	// Establecer las rutinas de atención a interrupciones
	EstablecerVectorInt();

	// Habilitar las interrupciones del teclado.
	HabilitarIntTeclado();

	// Habilitar las interrupciones del temporizador.
	PonerEnMarchaTempo();
	HabilitarIntTempo();

	// Habilitar interrupciones.
	HabilitarInterrupciones();

	//******************************************************************************//

	


	while(1)
	{	


	//***********************************INTRO***************************************//
	if (ESTADO == INTRO){
		visualizarIntro2();
	}
	//******************************************************************************//



	//***********************************PAUSA**************************************//
	if (ESTADO == PAUSA){
		visualizarPausa();
	}
	//******************************************************************************//



	//************************************MENU**************************************//
	if (ESTADO == MENU){
		
		consoleClear();
		visualizarMenu();
		MostrarFlecha(1,65,yflecha);
		BorrarAxel(2,111,75);
		BorrarAxelBlack(4,61,75);
		BorrarXavier(7,111,75);
		BorrarXavierBlack(5,111,75);
		BorrarShawn(8,161,75);
		BorrarShawnBlack(6,161,75);
		MostrarInfo(3,235,5);

		if (TeclaPulsada()==ABAJO){
			yflecha=yflecha+35;
		}

		if(TeclaPulsada()==ABAJO && yflecha>95){
			yflecha=yflecha-35;
		}

		if (TeclaPulsada()==ARRIBA){
			yflecha=yflecha-35;
		}

		if(TeclaPulsada()==ARRIBA && yflecha<55){
			yflecha=yflecha+35;
		}
	}
	//******************************************************************************//



	//**********************************JUEGO***************************************//
	if (ESTADO == JUEGO) {
		visualizarCampo();
		BorrarAxel(2,111,75);
		BorrarAxelBlack(4,61,75);
		BorrarXavier(7,111,75);
		BorrarXavierBlack(5,111,75);
		BorrarShawn(8,161,75);
		BorrarShawnBlack(6,161,75);
		
	}
	//******************************************************************************//



	//**********************************SELEC***************************************//
	if (ESTADO == SELECCION) {
		visualizarSeleccion();
		BorrarFlecha(1, 65, yflecha);
		BorrarInfo(3,235,5);
		
		if(pj == 1){
			MostrarAxel(2,61,75);
			BorrarShawn(8,161,75);
			MostrarXavierBlack(5,111,75);
			MostrarShawnBlack(6,161,75);
			BorrarAxelBlack(4,61,75);
			BorrarXavier(7,111,75);
			iprintf("\x1b[5;4HPJ: %d", pj);
			iprintf("\x1b[8;4HName: Axel Blaze   ");
			iprintf("\x1b[10;4HAge:  17");
			iprintf("\x1b[12;4HTeam: Raimon   ");
		}

		if(pj == 2){
			MostrarXavier(7,111,75);
			BorrarShawn(8,161,75);
			BorrarAxel(2,111,75);
			MostrarShawnBlack(6,161,75);
			BorrarXavierBlack(5,111,75);
			MostrarAxelBlack(4,61,75);
			iprintf("\x1b[5;4HPJ: %d", pj);
			iprintf("\x1b[8;4HName: Xavier Foster   ");
			iprintf("\x1b[10;4HAge:  18");
			iprintf("\x1b[12;4HTeam: Genesis   ");
			
		}

		if(pj == 3){
			BorrarShawnBlack(6,161,75);
			MostrarShawn(8,161,75);
			MostrarAxelBlack(4,61,75);
			MostrarXavierBlack(5,111,75);
			BorrarAxel(2,111,75);
			BorrarXavier(7,111,75);
			iprintf("\x1b[5;4HPJ: %d", pj);
			iprintf("\x1b[8;4HName: Shawn Frost   ");
			iprintf("\x1b[10;4HAge:  17");
			iprintf("\x1b[12;4HTeam: Alpine   ");
		}

	}
	//******************************************************************************//




	//**********************************INFO***************************************//
	if (ESTADO == INFO) {
		visualizarInfo();
		BorrarFlecha(1,65,yflecha);
		BorrarInfo(3,235,5);
		
	}
	//******************************************************************************//



	}
	
}



