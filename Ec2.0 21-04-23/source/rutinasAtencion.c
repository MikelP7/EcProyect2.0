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
int seg3;
int segbalon;
int yflecha;
int pj;

void RutAtencionTeclado()
{
	if (ESTADO == INTRO){

		if(TeclaPulsada()==START){
			ESTADO=MENU;

			consoleClear();

			BorrarBalon1(1, 80, 130);
			BorrarBalon1(2, 120, 130);
			BorrarBalon1(3, 160, 130);

			BorrarBalon2(1, 80, 130);
			BorrarBalon2(2, 120, 130);
			BorrarBalon2(3, 160, 130);
		}
	}

	if (ESTADO == PAUSA){

		if(TeclaPulsada()==B){
			ESTADO=JUEGO;

		}
	}

	if (ESTADO == MENU){

		if(TeclaPulsada()==A && yflecha==60){
			pj=1;
			ESTADO=SELECCION;
		}

		else if(TeclaPulsada()==A && yflecha!=60){
			ESTADO=JUEGO;
		}

		if (TeclaPulsada()==R){
			ESTADO=INFO;
		}
	}

	if(ESTADO == SELECCION){

		if(TeclaPulsada()==R && pj<3){
			pj++;
			consoleClear();
		}

	    if(TeclaPulsada()==L && pj>1){
			pj--;
			consoleClear();
		}

		if(TeclaPulsada()==B){
			ESTADO = MENU;
		}
	}

	if (ESTADO == INFO){
		if(TeclaPulsada()==B){
			ESTADO=MENU;
		}
	}

}

void RutAtencionTempo()
{
	static int tick = 0;
	static int tick3 = 0;
	static int seg = 0;
	static int segtick3 = 0;

	if (ESTADO != HELP)
	{
		tick++;
		tick3++;

		if (tick == 5)
		{
			seg++;
			//iprintf("\x1b[3;2HSegundos=%d", seg);
			tick = 0;

			if (ESTADO == INTRO)
			{
				seg3++;
				if (seg3 == 3)
				{
					seg3 = 0;

					//iprintf("\x1b[12;4H[Press 'START' to play]");
				}

				segbalon++;

				if(segbalon==1){
					MostrarBalon1(1, 80, 130);
					MostrarBalon1(2, 120, 130);
					MostrarBalon1(3, 160, 130);
					//iprintf("\x1b[12;4H[Press 'START' to play]");
				}

				if(segbalon==2){
					BorrarBalon1(1, 80, 130);
					BorrarBalon1(2, 120, 130);
					BorrarBalon1(3, 160, 130);
					//iprintf("\x1b[12;4H[Press         to play]");

					MostrarBalon2(1, 80, 130);
					MostrarBalon2(2, 120, 130);
					MostrarBalon2(3, 160, 130);
					segbalon=0;
				}
			}


		}

		if(tick3==3){
			
			segtick3++;
			tick3=0;

			if(ESTADO == INTRO){

				if(segtick3==1){
					iprintf("\x1b[12;4H[Press 'START' to play]");
				}

				if(segtick3==2){
					iprintf("\x1b[12;4H[Press         to play]");
					segtick3=0;
				}
			}
		}
		


	}
}

void EstablecerVectorInt()
{
	// A COMPLETAR
	irqSet(IRQ_KEYS, RutAtencionTeclado);
	irqSet(IRQ_TIMER0, RutAtencionTempo);
}
