extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;

extern void memoriaReserva();

/* Para cada uno de los 256 valores que puede tomar un Pixel le da un color en la pantalla principal. El valor 0 es transparente y los valores sin definir negros */
extern void EstablecerPaletaPrincipal();


/* Para cada uno de los 256 valores que puede tomar un Pixel le da un color en la pantalla secundaria. El valor 0 es transparente y los valores sin definir negros */
extern void EstablecerPaletaSecundaria();


/* Carga en memoria los Sprites dibujados.*/
extern void GuardarSpritesMemoria();


/* Esta función dibuja un rombo en la posición de pantalla x-y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126. */
extern void MostrarRombo(int indice, int x, int y);


/*Esta función borra de la pantalla el rombo con el índice que se le indique como parámetro */
extern void BorrarRombo(int indice, int x, int y);


extern void MostrarRomboGrande(int indice, int x, int y);
extern void BorrarRomboGrande(int indice, int x, int y);


extern void MostrarBalon1(int indice, int x, int y);
extern void BorrarBalon1(int indice, int x, int y);
extern void MostrarBalon2(int indice, int x, int y);
extern void BorrarBalon2(int indice, int x, int y);


extern void MostrarFlecha(int indice, int x, int y);
extern void BorrarFlecha(int indice, int x, int y);


extern void MostrarAxel(int indice, int x, int y);
extern void BorrarAxel(int indice, int x, int y);
extern void MostrarAxelBlack(int indice, int x, int y);
extern void BorrarAxelBlack(int indice, int x, int y);
extern void MostrarInfo(int indice, int x, int y);
extern void BorrarInfo(int indice, int x, int y);


extern void MostrarXavier(int indice, int x, int y);
extern void BorrarXavier(int indice, int x, int y);
extern void MostrarXavierBalck(int indice, int x, int y);
extern void BorrarXavierBlack(int indice, int x, int y);


extern void MostrarShawn(int indice, int x, int y);
extern void BorrarShawn(int indice, int x, int y);
extern void MostrarShawnBlack(int indice, int x, int y);
extern void BorrarShawnBlack(int indice, int x, int y);

