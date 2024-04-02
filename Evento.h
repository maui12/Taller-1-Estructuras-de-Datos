#pragma once
#include <iostream>
#include "Asistente.h"

using namespace std;

class Evento {

    private:
        string nombre;
        Asistente* asistentes[];

    public:
        Evento(string nombre);
        string getNombre();
        void setNombre(string nombre);
        void agregarAsistente(Asistente asistente);

};
