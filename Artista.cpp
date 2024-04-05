#include <iostream>
#include "Asistente.h"
#include "Artista.h"

using namespace std;

Artista::Artista(string nombre, int edad, string nombreArtistico):Asistente(nombre,edad){

    this -> nombreArtistico = nombreArtistico;
}

string Artista::getNombreArtistico(){
    return nombreArtistico;
}
void Artista::setNombreArtistico(string nombreArtistico){
    this -> nombreArtistico = nombreArtistico;
}

string Artista::toStringAsistente() {
	return "Artista - Nombre: "+getNombre()+" - Nombre Artistico: "+getNombreArtistico();
}
