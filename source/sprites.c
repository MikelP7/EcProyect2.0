/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

#include "sprites.h"
#include "definiciones.h"

u16* gfxPJ1; // Dinosaurio de pies (ambas piernas tocando el suelo)



/* Reservar memoria para cada sprite que se quiera mostrar en pantalla.*/
void memoriaReserva()
{
	/* Pantaila nagusian gehitu nahi den sprite bakoitzarentzako horrelako bat egin behar da. */
	gfxPJ1= oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);

}

/* A cada uno de los 256 valores que puede tomar un pixel en la PALETA PRINCIPAL
   se le puede asignar un color. El valor 0 es transparente. Los valores sin definir son negros. 
   MODIFICAR SEGÚN LOS COLORES QUE QUERAIS UTILIZAR EN VUESTROS SPRITES*/
void EstablecerPaletaPrincipal() {

	SPRITE_PALETTE[1] = RGB15(31,0,0); // los píxeles con valor 3 serán ROJO.

    SPRITE_PALETTE[3] = RGB15(31,31,31); // los píxeles con valor 3 serán BLANCO.
    SPRITE_PALETTE[6] = RGB15(0,0,0); // los píxeles con valor 6 serán NEGRO.
	SPRITE_PALETTE[9] = RGB15(16,16,16); // los píxeles con valor 9 GRIS NORMAL
	SPRITE_PALETTE[11] = RGB15(8,8,8); // los píxeles con valor 3 serán GRIS OSCURO.


}

/* definición de un sprite de 16x16 píxeles */
/* Por la forma que tienen de trabajar los bancos de memoria, la imagen del sprite se divide en bloques de 8x8 píxeles. Los primeros 64 (8x8) píxeles que indicamos
aparecerán en el cuadrante superior izquierdo de la imagen del sprite, los siguientes 64 en el cuadrante superior derecho, los siguientes en el cuadrante inferior izquierdo y los
últimos en el cuadrante inferior derecho. */

u8 PJ1[1024] = {
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
	 0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	0 ,	0 ,	6 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	6 ,	6 ,
	10 , 0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	6 ,	10 ,	3 ,	6 ,	10 ,	3 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	3 ,	3 ,	10 ,	3 ,	3 , 0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	6 ,	10 ,	3 ,	3 ,	10 ,	10 ,	3 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	3 ,	3 ,	3 ,	10 ,	10 ,	3 , 0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	3 ,	3 ,	3 ,	24	24	3 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	3 ,	24	24	24	24	24 0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	3 ,	24	6 ,	6 ,	6 ,	24
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24	24	3 ,	3 ,	6 ,	6 , 0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24	24	3 ,	3 ,	6 ,	24
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24	3 ,	3 ,	6 ,	24 0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24	24	24	24
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	6 ,	24	24	24 0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	10 ,	3 ,	10 ,	6 ,	6 ,	6 ,
6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 , 3 ,	6 ,	0 ,	0 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
3 ,	3 ,	6 ,	6 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 , 3 ,	3 ,	3 ,	6 ,	10 ,	3 ,	6 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
3 ,	3 ,	3 ,	10 ,	3 ,	3 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 , 3 ,	3 ,	10 ,	10 ,	3 ,	3 ,	10 ,	6 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
3 ,	3 ,	10 ,	10 ,	3 ,	3 ,	10 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 , 3 ,	3 ,	24	24	3 ,	3 ,	10 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
3 ,	24	24	24	24	24	10 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 , 24	24	6 ,	6 ,	6 ,	24	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
24	6 ,	6 ,	3 ,	3 ,	24	24	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 , 24	24	6 ,	3 ,	3 ,	24	24	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
24	24	6 ,	3 ,	3 ,	24	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 , 24	24	24	24	24	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
24	24	24	24	6 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 , 6 ,	6 ,	6 ,	6 ,	10 ,	3 ,	10 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	3 ,	3 ,	10 ,	24	24 0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	1 ,	3 ,	3 ,	3 ,	10 ,	24
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	3 ,	6 ,	1 ,	1 ,	3 ,	3 ,0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	3 ,	3 ,	6 ,	1 ,	1 ,	1 ,	10 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	3 ,	3 ,	6 ,	1 ,	1 ,	1 ,	1 ,	3 ,0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	19 ,	19 ,	6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	3 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24 ,	24 ,	6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	3 ,0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	24 ,	24 ,	6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	3 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	6 ,	6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	3 ,0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	3 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,		6 ,	1 ,	1 ,	1 ,	1 ,	1 ,	19 ,0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	1 ,	19 ,	19 ,	19 ,	6 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	19 ,	19 ,	19 ,	6 ,	0 ,0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	2 ,	3 ,	10 ,	6 ,	0 ,
0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	3 ,	3 ,	3 ,	6 ,	0 ,0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	6 ,	6 ,	6 ,	6 ,	6 ,	0 ,
24	24	24	10 ,	3 ,	3 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,24	24	10 ,	3 ,	3 ,	3 ,	1 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
10 ,	3 ,	3 ,	1 ,	1 ,	6 ,	3 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,3 ,	10 ,	1 ,	1 ,	1 ,	6 ,	3 ,	3 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	6 ,	3 ,	3 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	19	19	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,
3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	24 ,	24 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	24 ,	24 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,
3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	6 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,3 ,	3 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
6 ,	19 ,	1 ,	1 ,	1 ,	1 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,0 ,	6 ,	19 ,	19 ,	19 ,	1 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
0 ,	0 ,	6 ,	19 ,	19 ,	19 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,0 ,	0 ,	6 ,	10 ,	3 ,	2 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
0 ,	0 ,	6 ,	3 ,	3 ,	3 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,0 ,	0 ,	6 ,	6 ,	6 ,	6 ,	6 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,	0 ,
};

/* Carga en memoria cada uno de los sprites que hemos dibujado. */
void GuardarSpritesMemoria(){ 
	
int i;
	//sprite de 16*16
	for(i = 0; i < 16 * 16 / 2; i++) 
	{	
		gfxPJ1[i] = PJ1[i*2] | (PJ1[(i*2)+1]<<8);
	}

}




/* -- FUNCIONES PARA MOSTRAR GRÁFICAMENTE LOS SPRITES -- */



//DINO CORRIENDO
/* Esta función dibuja un DINO NORMAL en la posición x-y de pantalla. ( indice -> un valor entre 0 y 126.) */
void visualizarPJ1(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxPJ1,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

void visualizarPJ1E(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}


/*Esta función borra de la pantalla el DINOSAURIO(pies abajo) con el índice indicado*/
void ocultarPJ1(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}

void ocultarPJ1E(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}




/* Esta función dibuja el dino con PIERNA DERECHA LEVANTADA*/
void visualizarPJ2(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_dcha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

void visualizarPJ2E(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_dcha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función BORRA el dino que ha sido dibujado con la PIERNA DERECHA LEVANTADA*/
void ocultarPJ2(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_dcha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}

void ocultarPJ2E(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_dcha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 

}


/* Esta función dibuja el dino con la PIERNA IZQUIERDA LEVANTADA*/
void visualizarPJ3(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_izda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

void visualizarPJ3E(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_izda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función BORRA el dino con PIERNA IZQUIERDA LEVANTADA*/
void ocultarPJ3(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_izda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}

void ocultarPJ3E(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_izda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}




// DINO AGACHADO
/* Esta función dibuja el dino AGACHADO*/
void visualiazarPJ3(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

void visualiazarPJ3E(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}


/* Esta función BORRA el dino el cuál ha sido dibujado AGACHADO*/
void ocultarPJ3(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}

void ocultarPJ3E(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}





/* Esta función dibuja el dino AGACHAD (pierna izda levantada) O*/
void visualizarPJ4(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar_izda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

void visualizarPJ4E(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar_izda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función BORRA el dino el cuál ha sido dibujado AGACHADO*/
void OcultarPJ4(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar_izda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}

void OcultarPJ4E(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar_izda,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}







/* Esta función dibuja el dino AGACHADO (pierna derecha levantada)*/
void visualizarPJ5(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar_dcha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

void visualizarPJ5E(int indice, int x, int y)
{ 
 
oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar_dcha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		false,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
	  
oamUpdate(&oamMain);  
}

/* Esta función BORRA el dino el cuál ha sido dibujado AGACHADO*/
void ocultarPJ5(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar_dcha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}

void ocultarPJ5E(int indice, int x, int y)
{

oamSet(&oamMain, //main graphics engine context
		indice,           //oam index (0 to 127)  
		x, y,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite	
		SpriteSize_16x16,     
		SpriteColorFormat_256Color, 
		gfxdino_agachar_dcha,//+16*16/2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data  
		false,               //double the size when rotating?
		true,			//hide the sprite?
		false, false, //vflip, hflip
		false	//apply mosaic
		); 
oamUpdate(&oamMain); 
}