#pragma once
#include <iostream>
#include "Asistente.h"

using namespace std;

class Artista:public Asistente{

    private:
        string nombreArtistico;
    public:
        Artista(string nombre, int edad, string nombreArtistico);
        string getNombreArtistico();
        void setNombreArtistico(string nombreArtistico);
        string toStringAsistente();
};
