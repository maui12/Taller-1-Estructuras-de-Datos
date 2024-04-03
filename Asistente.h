#pragma once
#include <iostream>
class Evento;

using namespace std;

class Asistente {
    private:
        string nombre;
        int edad;
        Evento* eventos;

    public:
        Asistente(string nombre,int edad);
        Asistente();
        string getNombre();
        int getEdad();
        void setNombre(string nombre);
        void setEdad(int edad);
        void agregarEvento(Evento* evento);

};
