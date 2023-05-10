/*---------------------------------------------------------------------------------
Código desarrollado basado en el ejemplo "Simple sprite demo" de dovoto y en otro de Jaeden Amero.
---------------------------------------------------------------------------------*/

#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

#include "sprites.h"
#include "definiciones.h"

u16* gfxrombo;
u16* gfxromboGrande;
u16* gfxbalon1;
u16* gfxbalon2;
u16* gfxflecha;
u16* gfxaxel;
u16* gfxinfo;


/* Reservar memoria para cada sprite que se quiera mostrar en pantalla */
void memoriaReserva()
{
	/* Por cada sprite que se quiera incluir en la pantalla principal hay que hacer algo equivalente a lo que sigue */
	gfxrombo= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxromboGrande=oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfxbalon1=oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxbalon2=oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxflecha=oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxaxel=oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	gfxinfo=oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
}

/* A cada uno de los 256 valores que puede tomar un pixel en la PALETA PRINCIPAL
   se le puede asignar un color. El valor 0 es transparente. Los valores sin definir son negros. 
   MODIFICAR SEGÚN LOS COLORES QUE QUERAIS UTILIZAR EN VUESTROS SPRITES */
void EstablecerPaletaPrincipal() {

	SPRITE_PALETTE[1] = RGB15(31,0,0); 		// los píxeles con valor 1 serán ROJO.
	SPRITE_PALETTE[2] = RGB15(0,0,31); 		// los píxeles con valor 2 serán AMARILLO.
	SPRITE_PALETTE[3] = RGB15(31,31,31); 	// los píxeles con valor 3 serán BLANCO.
	SPRITE_PALETTE[4] = RGB15(0,31,0); 		// los píxeles con valor 4 serán VERDE.
	SPRITE_PALETTE[6] = RGB15(0,0,0); 		// los píxeles con valor 6 serán NEGRO.
	SPRITE_PALETTE[12] = RGB15(31,31,0); 	// los píxeles con valor 6 serán TURQUESA.
	SPRITE_PALETTE[20] = RGB15(0,31,31); 	// los píxeles con valor 6 serán TURQUESA.
	SPRITE_PALETTE[24] = RGB15(10,20,15); 	// los píxeles con valor 6 serán TURQUESA.

}

/* definición de un sprite de 16x16 píxeles para dibujar un rombo */
/* Por la forma que tienen de trabajar los bancos de memoria, la imagen del sprite se divide en bloques de 8x8 píxeles. Los primeros 64 (8x8) píxeles que indicamos
aparecerán en el cuadrante superior izquierdo de la imagen del sprite, los siguientes 64 en el cuadrante superior derecho, los siguientes en el cuadrante inferior izquierdo y los
últimos en el cuadrante inferior derecho */

u8 rombo[256] = 
{
	0,0,0,0,0,0,2,2,
        0,0,0,0,0,2,2,2,	//	0,0,0,0,0,0,2,2, 2,2,0,0,0,0,0,0,
	0,0,0,0,2,2,2,2,
        0,0,0,2,2,2,2,2,	//	0,0,0,0,0,2,2,2, 2,2,2,0,0,0,0,0,
	0,0,2,2,2,2,2,2,
        0,2,2,2,2,2,2,2,	//	0,0,0,0,2,2,2,2, 2,2,2,2,0,0,0,0,
	2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,	//	0,0,0,2,2,2,2,2, 2,2,2,2,2,0,0,0,
 
	2,2,0,0,0,0,0,0,
        2,2,2,0,0,0,0,0,	//	0,0,2,2,2,2,2,2, 2,2,2,2,2,2,0,0,
	2,2,2,2,0,0,0,0,
        2,2,2,2,2,0,0,0,	//	0,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,0,
	2,2,2,2,2,2,0,0,
        2,2,2,2,2,2,2,0,	//	2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,
        2,2,2,2,2,2,2,2,	//	2,2,2,2,2,2,2,2, 2,2,2,2,2,2,2,2,

	1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,	//	1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,
        0,0,1,1,1,1,1,1,	//	1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
	0,0,0,1,1,1,1,1,
        0,0,0,0,1,1,1,1,	//	0,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,0,
	0,0,0,0,0,1,1,1,
        0,0,0,0,0,0,1,1,	//	0,0,1,1,1,1,1,1, 1,1,1,1,1,1,0,0,

	1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,	//	0,0,0,1,1,1,1,1, 1,1,1,1,1,0,0,0,
	1,1,1,1,1,1,1,0,
        1,1,1,1,1,1,0,0,	//	0,0,0,0,1,1,1,1, 1,1,1,1,0,0,0,0,
	1,1,1,1,1,0,0,0,
        1,1,1,1,0,0,0,0,	//	0,0,0,0,0,1,1,1, 1,1,1,0,0,0,0,0,
	1,1,1,0,0,0,0,0,
        1,1,0,0,0,0,0,0,	//	0,0,0,0,0,0,1,1, 1,1,0,0,0,0,0,0,
};

u8 balon1[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,	0	,	0	,	0	,	0	,	6	,	6	,	6	,	6	,	 // 	0	0	0	0	0	0	6	6	6	6	0	0	0	0	0	0
0	,	0	,	6	,	3	,	3	,	3	,	6	,	6	,	0	,	0	,	6	,	6	,	3	,	3	,	3	,	3	,	 // 	0	0	0	0	6	6	6	6	6	6	6	6	0	0	0	0
0	,	6	,	6	,	6	,	3	,	3	,	3	,	3	,	0	,	6	,	6	,	6	,	3	,	3	,	3	,	3	,	 // 	0	0	6	3	3	3	6	6	6	6	3	3	6	0	0	0
6	,	6	,	6	,	6	,	6	,	6	,	3	,	6	,	6	,	6	,	3	,	3	,	3	,	6	,	6	,	6	,	 // 	0	0	6	6	3	3	3	3	6	3	3	3	6	6	0	0
6	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,	6	,	6	,	0	,	0	,	0	,	0	,	 // 	0	6	6	6	3	3	3	3	6	3	3	3	6	6	6	0
6	,	6	,	3	,	3	,	6	,	0	,	0	,	0	,	6	,	3	,	3	,	3	,	6	,	6	,	0	,	0	,	 // 	0	6	6	6	3	3	3	3	6	3	3	3	6	6	6	0
6	,	3	,	3	,	3	,	6	,	6	,	6	,	0	,	6	,	3	,	3	,	3	,	6	,	6	,	6	,	0	,	 // 	6	6	6	6	6	6	3	6	6	6	3	3	6	6	6	6
6	,	6	,	3	,	3	,	6	,	6	,	6	,	6	,	6	,	6	,	6	,	6	,	6	,	3	,	6	,	6	,	 // 	6	6	3	3	3	6	6	6	6	6	6	6	6	3	6	6
6	,	3	,	3	,	3	,	3	,	3	,	6	,	6	,	6	,	3	,	3	,	3	,	3	,	3	,	6	,	6	,	 // 	6	3	3	3	3	3	6	6	6	6	6	3	3	3	3	6
0	,	6	,	3	,	3	,	3	,	3	,	3	,	6	,	0	,	6	,	6	,	6	,	3	,	6	,	6	,	3	,	 // 	6	3	3	3	3	3	6	6	6	6	6	3	3	3	3	6
0	,	0	,	6	,	6	,	6	,	6	,	3	,	3	,	0	,	0	,	0	,	6	,	6	,	6	,	3	,	3	,	 // 	0	6	3	3	3	3	3	6	6	6	3	3	3	3	6	0
0	,	0	,	0	,	0	,	6	,	6	,	6	,	3	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,	 // 	0	6	6	6	3	6	6	3	3	3	6	6	6	6	6	0
6	,	6	,	6	,	3	,	3	,	3	,	3	,	6	,	6	,	6	,	6	,	3	,	3	,	3	,	3	,	6	,	 // 	0	0	6	6	6	6	3	3	3	3	3	6	6	6	0	0
6	,	6	,	3	,	3	,	3	,	3	,	6	,	0	,	3	,	3	,	6	,	6	,	6	,	6	,	6	,	0	,	 // 	0	0	0	6	6	6	3	3	3	3	6	6	6	0	0	0
3	,	3	,	3	,	6	,	6	,	6	,	0	,	0	,	3	,	3	,	6	,	6	,	6	,	0	,	0	,	0	,	 // 	0	0	0	0	6	6	6	3	3	3	6	6	0	0	0	0
3	,	3	,	6	,	6	,	0	,	0	,	0	,	0	,	6	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	 // 	0	0	0	0	0	0	6	6	6	6	0	0	0	0	0	0

};

u8 balon2[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	3	,	3	,	0	,	0	,	0	,	0	,	3	,	3	,	3	,	3	,	 // 	0	0	0	0	0	0	3	3	3	3	0	0	0	0	0	0
0	,	0	,	3	,	6	,	6	,	6	,	3	,	3	,	0	,	0	,	3	,	3	,	6	,	6	,	6	,	6	,	 // 	0	0	0	0	3	3	3	3	3	3	3	3	0	0	0	0
0	,	3	,	3	,	3	,	6	,	6	,	6	,	6	,	0	,	3	,	3	,	3	,	6	,	6	,	6	,	6	,	 // 	0	0	3	6	6	6	3	3	3	3	6	6	3	0	0	0
3	,	3	,	3	,	3	,	3	,	3	,	6	,	3	,	3	,	3	,	6	,	6	,	6	,	3	,	3	,	3	,	 // 	0	0	3	3	6	6	6	6	3	6	6	6	3	3	0	0
3	,	3	,	0	,	0	,	0	,	0	,	0	,	0	,	3	,	3	,	3	,	3	,	0	,	0	,	0	,	0	,	 // 	0	3	3	3	6	6	6	6	3	6	6	6	3	3	3	0
3	,	3	,	6	,	6	,	3	,	0	,	0	,	0	,	3	,	6	,	6	,	6	,	3	,	3	,	0	,	0	,	 // 	0	3	3	3	6	6	6	6	3	6	6	6	3	3	3	0
3	,	6	,	6	,	6	,	3	,	3	,	3	,	0	,	3	,	6	,	6	,	6	,	3	,	3	,	3	,	0	,	 // 	3	3	3	3	3	3	6	3	3	3	6	6	3	3	3	3
3	,	3	,	6	,	6	,	3	,	3	,	3	,	3	,	3	,	3	,	3	,	3	,	3	,	6	,	3	,	3	,	 // 	3	3	6	6	6	3	3	3	3	3	3	3	3	6	3	3
3	,	6	,	6	,	6	,	6	,	6	,	3	,	3	,	3	,	6	,	6	,	6	,	6	,	6	,	3	,	3	,	 // 	3	6	6	6	6	6	3	3	3	3	3	6	6	6	6	3
0	,	3	,	6	,	6	,	6	,	6	,	6	,	3	,	0	,	3	,	3	,	3	,	6	,	3	,	3	,	6	,	 // 	3	6	6	6	6	6	3	3	3	3	3	6	6	6	6	3
0	,	0	,	3	,	3	,	3	,	3	,	6	,	6	,	0	,	0	,	0	,	3	,	3	,	3	,	6	,	6	,	 // 	0	3	6	6	6	6	6	3	3	3	6	6	6	6	6	0
0	,	0	,	0	,	0	,	3	,	3	,	3	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	3	,	3	,	 // 	0	3	3	3	6	3	3	6	6	6	3	3	3	3	3	0
3	,	3	,	3	,	6	,	6	,	6	,	6	,	3	,	3	,	3	,	3	,	6	,	6	,	6	,	6	,	3	,	 // 	0	0	3	3	3	3	6	6	6	6	6	3	3	3	0	0
3	,	3	,	6	,	6	,	6	,	6	,	6	,	0	,	6	,	6	,	3	,	3	,	3	,	3	,	3	,	0	,	 // 	0	0	0	3	3	3	6	6	6	6	3	3	3	0	0	0
6	,	6	,	6	,	3	,	3	,	3	,	0	,	0	,	6	,	6	,	3	,	3	,	3	,	0	,	0	,	0	,	 // 	0	0	0	0	3	3	3	6	6	6	3	3	0	0	0	0
6	,	6	,	3	,	3	,	0	,	0	,	0	,	0	,	3	,	3	,	0	,	0	,	0	,	0	,	0	,	0	,	 // 	0	0	0	0	0	0	3	3	3	3	0	0	0	0	0	0

};

u8 flecha[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,	6	,	0	,	0	,	0	,	0	,	0	,	 // 	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
6	,	1	,	6	,	6	,	0	,	0	,	0	,	0	,	6	,	1	,	1	,	1	,	1	,	6	,	6	,	0	,	 // 	6	6	6	0	0	0	0	0	0	0	0	0	0	0	0	0
6	,	1	,	1	,	1	,	1	,	1	,	1	,	6	,	6	,	1	,	1	,	1	,	1	,	1	,	1	,	1	,	 // 	6	1	6	6	0	0	0	0	0	0	0	0	0	0	0	0
6	,	1	,	1	,	1	,	1	,	1	,	1	,	1	,	6	,	1	,	1	,	1	,	1	,	1	,	1	,	1	,	 // 	6	1	1	1	1	6	6	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 // 	6	1	1	1	1	1	1	6	6	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 // 	6	1	1	1	1	1	1	1	1	6	6	0	0	0	0	0
6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	1	,	6	,	6	,	0	,	0	,	0	,	0	,	0	,	 // 	6	1	1	1	1	1	1	1	1	1	1	6	6	0	0	0
1	,	1	,	1	,	6	,	6	,	0	,	0	,	0	,	1	,	1	,	1	,	1	,	1	,	6	,	6	,	0	,	 // 	6	1	1	1	1	1	1	1	1	1	1	1	1	6	6	0
6	,	1	,	1	,	1	,	1	,	1	,	1	,	1	,	6	,	1	,	1	,	1	,	1	,	1	,	1	,	1	,	 // 	6	1	1	1	1	1	1	1	1	1	1	1	1	1	1	6
6	,	1	,	1	,	1	,	1	,	1	,	1	,	1	,	6	,	1	,	1	,	1	,	1	,	1	,	1	,	1	,	 // 	6	1	1	1	1	1	1	1	1	1	1	1	1	6	6	9
6	,	1	,	1	,	1	,	1	,	1	,	1	,	6	,	6	,	1	,	1	,	1	,	1	,	6	,	6	,	9	,	 // 	6	1	1	1	1	1	1	1	1	1	1	6	6	9	9	0
6	,	1	,	1	,	6	,	6	,	9	,	9	,	0	,	6	,	6	,	6	,	9	,	9	,	0	,	0	,	0	,	 // 	6	1	1	1	1	1	1	1	1	6	6	9	9	0	0	0
1	,	1	,	1	,	1	,	1	,	1	,	1	,	6	,	1	,	1	,	1	,	1	,	1	,	6	,	6	,	9	,	 // 	6	1	1	1	1	1	1	6	6	9	9	0	0	0	0	0
1	,	1	,	1	,	6	,	6	,	9	,	9	,	0	,	1	,	6	,	6	,	9	,	9	,	0	,	0	,	0	,	 // 	6	1	1	1	1	6	6	9	9	0	0	0	0	0	0	0
6	,	9	,	9	,	0	,	0	,	0	,	0	,	0	,	9	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 // 	6	1	1	6	6	9	9	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 // 	6	6	6	9	9	0	0	0	0	0	0	0	0	0	0	0

};

u8 info[256] = 
{
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,	 // 	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0
0	,	0	,	0	,	6	,	6	,	6	,	3	,	3	,	0	,	0	,	0	,	6	,	3	,	3	,	3	,	3	,	 // 	0	0	0	0	0	0	6	6	6	6	0	0	0	0	0	0
0	,	0	,	6	,	3	,	3	,	3	,	3	,	6	,	0	,	6	,	3	,	3	,	3	,	3	,	3	,	6	,	 // 	0	0	0	6	6	6	3	3	3	3	6	6	0	0	0	0
0	,	6	,	3	,	3	,	3	,	3	,	3	,	3	,	0	,	6	,	3	,	3	,	3	,	3	,	3	,	6	,	 // 	0	0	0	6	3	3	3	3	3	3	3	3	6	0	0	0
0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	6	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	 // 	0	0	6	3	3	3	3	6	6	3	3	3	3	6	0	0
3	,	3	,	6	,	6	,	0	,	0	,	0	,	0	,	3	,	3	,	3	,	3	,	6	,	0	,	0	,	0	,	 // 	0	6	3	3	3	3	3	6	6	3	3	3	3	3	6	0
6	,	3	,	3	,	3	,	3	,	6	,	0	,	0	,	6	,	3	,	3	,	3	,	3	,	3	,	6	,	0	,	 // 	0	6	3	3	3	3	3	3	3	3	3	3	3	3	6	0
3	,	3	,	3	,	3	,	3	,	3	,	6	,	0	,	6	,	3	,	3	,	3	,	3	,	3	,	6	,	0	,	 // 	0	6	3	3	3	3	3	6	6	3	3	3	3	3	6	0
0	,	6	,	3	,	3	,	3	,	3	,	3	,	6	,	0	,	6	,	3	,	3	,	3	,	3	,	3	,	6	,	 // 	0	6	3	3	3	3	3	6	6	3	3	3	3	3	6	0
0	,	0	,	6	,	3	,	3	,	3	,	3	,	6	,	0	,	0	,	0	,	6	,	3	,	3	,	3	,	6	,	 // 	0	6	3	3	3	3	3	6	6	3	3	3	3	3	6	0
0	,	0	,	0	,	0	,	6	,	6	,	3	,	3	,	0	,	0	,	0	,	0	,	6	,	3	,	3	,	3	,	 // 	0	0	6	3	3	3	3	6	6	3	3	3	3	3	6	0
0	,	0	,	0	,	6	,	3	,	3	,	3	,	3	,	0	,	0	,	0	,	6	,	6	,	6	,	6	,	6	,	 // 	0	0	0	6	3	3	3	6	6	3	3	3	3	6	0	0
6	,	3	,	3	,	3	,	3	,	3	,	6	,	0	,	6	,	3	,	3	,	3	,	3	,	3	,	6	,	0	,	 // 	0	0	0	0	6	6	3	3	3	3	3	3	6	0	0	0
6	,	3	,	3	,	3	,	3	,	3	,	6	,	0	,	6	,	3	,	3	,	3	,	3	,	6	,	0	,	0	,	 // 	0	0	0	0	6	3	3	3	3	3	6	6	0	0	0	0
3	,	3	,	3	,	3	,	6	,	0	,	0	,	0	,	3	,	3	,	6	,	6	,	0	,	0	,	0	,	0	,	 // 	0	0	0	6	3	3	3	3	6	6	0	0	0	0	0	0
6	,	6	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	 // 	0	0	0	6	6	6	6	6	0	0	0	0	0	0	0	0


};

u8 romboGrande[1024] = 
{
	0,0,0,0,0,0,2,2,0,0,0,0,0,2,2,2,0,0,0,0,2,2,2,2,0,0,0,2,2,2,2,2,0,0,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,	

	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	

	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	
 
	2,2,0,0,0,0,0,0,2,2,2,0,0,0,0,0,2,2,2,2,0,0,0,0,2,2,2,2,2,0,0,0,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,	

	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,

	0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,	

	1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,	

	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,0,0,0,2,2,2,2,2,0,0,0,0,2,2,2,2,0,0,0,0,0,2,2,2,0,0,0,0,0,0,2,2,	

	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,0,0,2,2,2,2,2,0,0,0,2,2,2,2,0,0,0,0,2,2,2,0,0,0,0,0,2,2,0,0,0,0,0,0,	

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,	

	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	

	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,	

	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,	
};


u8 axel[1024] = 
{

0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	0 ,	0 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	6 ,	6 ,	10 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	6 ,	10 ,	3 ,	6 ,	10 ,	3 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	3 ,	3 ,	10 ,	3 ,	3 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	6 ,	10 ,	3 ,	3 ,	10 ,	10 ,	3 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	3 ,	3 ,	3 ,	10 ,	10 ,	3 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	3 ,	3 ,	3 ,	24 ,	24 ,	3 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	3 ,	24 ,	24 ,	24 ,	24 ,	24 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	3 ,	24 ,	6 ,	6 ,	6 ,	24 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24 ,	24 ,	3 ,	3 ,	6 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24 ,	24 ,	3 ,	3 ,	6 ,	24 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24 ,	3 ,	3 ,	6 ,	24 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24 ,	24 ,	24 ,	24 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	6 ,	24 ,	24 ,	24 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	3 ,	10 ,	6 ,	6 ,	6 ,
6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	3 ,	6 ,	0 ,	0 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	3 ,	3 ,	6 ,	6 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	3 ,	3 ,	3 ,	6 ,	10 ,	3 ,	6 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
3 ,	3 ,	3 ,	10 ,	3 ,	3 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	3 ,	3 ,	10 ,	10 ,	3 ,	3 ,	10 ,	6 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	3 ,	3 ,	10 ,	10 ,	3 ,	3 ,	10 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	3 ,	3 ,	24 ,	24 ,	3 ,	3 ,	10 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
3 ,	24 ,	24 ,	24 ,	24 ,	24 ,	10 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	24 ,	24 ,	6 ,	6 ,	6 ,	24 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	24 ,	6 ,	6 ,	3 ,	3 ,	24 ,	24 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	24 ,	24 ,	6 ,	3 ,	3 ,	24 ,	24 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
24 ,	24 ,	6 ,	3 ,	3 ,	24 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	24 ,	24 ,	24 ,	24 ,	24 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	24 ,	24 ,	24 ,	24 ,	6 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	6 ,	6 ,	6 ,	10 ,	3 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	3 ,	3 ,	10 ,	24 ,	24 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	1 ,	3 ,	3 ,	3 ,	10 ,	24 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	3 ,	6 ,	1 ,	1 ,	3 ,	3 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	3 ,	3 ,	6 ,	1 ,	1 ,	1 ,	10 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	3 ,	3 ,	6 ,	1 ,	1 ,	1 ,	1 ,	3 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	19 ,	19 ,	6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	3 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24 ,	24 ,	6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	3 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24 ,	24 ,	6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	3 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	6 ,	6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	3 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	3 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,		6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	19 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	19 ,	19 ,	19 ,	6 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	19 ,	19 ,	19 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	2 ,	3 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	3 ,	3 ,	3 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	6 ,	6 ,	6 ,	6 ,	0 ,
24 ,	24 ,	10 ,	3 ,	3 ,	3 ,	1 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	10 ,	3 ,	3 ,	1 ,	1 ,	6 ,	3 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	3 ,	10 ,	1 ,	1 ,	1 ,	6 ,	3 ,	3 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	6 ,	3 ,	3 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,
3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	19 ,	19 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	24 ,	24 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	24 ,	24 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	6 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	19 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	19 ,	19 ,	19 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	19 ,	19 ,	19 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
0 ,	0 ,	6 ,	10 ,	3 ,	2 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	3 ,	3 ,	3 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	6 ,	6 ,	6 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,


};


/* Carga en memoria cada uno de los sprites que hemos dibujado */

void GuardarSpritesMemoria(){ 
	
int i;
	//sprite de 16*16
	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxrombo[i] = rombo[i*2] | (rombo[(i*2)+1]<<8);	
		gfxbalon1[i] = balon1[i*2] | (balon1[(i*2)+1]<<8);
		gfxbalon2[i] = balon2[i*2] | (balon2[(i*2)+1]<<8);
		gfxflecha[i] = flecha[i*2] | (flecha[(i*2)+1]<<8);	
		gfxinfo[i] = info[i*2] | (info[(i*2)+1]<<8);
	}
	//sprite de 32x32
	for(i = 0; i < 32 * 32 / 2; i++) 
	{	
		gfxromboGrande[i] = romboGrande[i*2] | (romboGrande[(i*2)+1]<<8);	
		gfxaxel[i] = axel[i*2] | (axel[(i*2)+1]<<8);				
	}
}

/* Esta función dibuja un rombo en la posición x-y de pantalla. A cada rombo que se quiera mostrar en pantalla se le debe asignar un índice distinto, un valor entre 0 y 126 */

void MostrarRombo(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxrombo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

void MostrarBalon1(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxbalon1,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

void MostrarBalon2(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxbalon2,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

void MostrarFlecha(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxflecha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función borra de la pantalla el Rombo con el índice indicado */
void BorrarRombo(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxrombo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}

void BorrarBalon1(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxbalon1,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}

void BorrarBalon2(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxbalon2,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}

void BorrarFlecha(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxflecha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}




void MostrarInfo(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxinfo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

void BorrarInfo(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxinfo,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}






void MostrarRomboGrande(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxromboGrande,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 

	  
oamUpdate(&oamMain);  
}

void BorrarRomboGrande(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxromboGrande,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}

void MostrarAxel(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxaxel,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 

	  
oamUpdate(&oamMain);  
}

void BorrarAxel(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixel location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_32x32,     
		SpriteColorFormat_256Color, 
		gfxaxel,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}