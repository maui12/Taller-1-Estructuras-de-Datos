#pragma once
#include <iostream>
#include <list>
#include "Asistente.h"

using namespace std;

class Evento {

    private:
        string nombre;
        list<Asistente*> asistentes;

    public:
        Evento(string nombre);
        string getNombre();
        void setNombre(string nombre);
        void agregarAsistente(Asistente* asistente);
        virtual string toString() = 0;
        int getNumeroAsistente();
        virtual string getAtributoEvento() = 0;
        virtual int getTipo() = 0;
        list<Asistente*> getAsistentes();

};
