#include <sprites.c>

void visualizarPersonaje(){
    if(PJ==0){
        ocultarPersonajes();
        visualizarPJ1();
    }else if(PJ==1){
        ocultarPersonajes();
        visualizarPJ2();
    }else if(PJ==2){
        ocultarPersonajes();
        visualizarPJ3();
    }else if(PJ==3){
        ocultarPersonajes();
        visualizarPJ4();
    }else if(PJ==4){
        ocultarPersonajes();
        visualizarPJ5();
    }
}

void ocultarPersonajes(){
    ocultarPJ1();
    ocultarPJ2();
    ocultarPJ3();
    ocultarPJ4();
    ocultarPJ5();
}

void visualizarPersonajeE(){
    if(PJ==0){
        ocultarPersonajes();
        visualizarPJ1E();
    }else if(PJ==1){
        ocultarPersonajes();
        visualizarPJ2E();
    }else if(PJ==2){
        ocultarPersonajes();
        visualizarPJ3E();
    }else if(PJ==3){
        ocultarPersonajes();
        visualizarPJ4E();
    }else if(PJ==4){
        ocultarPersonajes();
        visualizarPJ5E();
    }
}

void ocultarPersonajes(){
    ocultarPJ1E();
    ocultarPJ2E();
    ocultarPJ3E();
    ocultarPJ4E();
    ocultarPJ5E();
}