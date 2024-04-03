#pragma once
#include <iostream>
#include "Asistente.h"

using namespace std;

class Artista:Asistente{

    private:
        string nombreArtistico;
    public:
        Artista(string nombre, int edad, nombreArtistico);
        string getNombreArtistico();
        void setNombreArtistico(string nombreArtistico);
};