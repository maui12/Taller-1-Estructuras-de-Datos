#include <iostream>
#include "Asistente.h"
#include "Artista.h"

using namespace std;

class Artista::Artista(string nombre, int edad, string nombreArtistico):Asistente(nombre,edad){
    this -> nombreArtistico = nombreArtistico;
}
string Artista::getNombreArtistico(){
    return nombreArtistico;
}
void Artista::setNombreArtistico(string nombreArtistico){
    this -> nombreArtistico = nombreArtistico;
}