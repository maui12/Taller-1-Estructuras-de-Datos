#pragma once
#include <iostream>
#include <list>
class Evento;

using namespace std;

class Asistente {
    private:
        string nombre;
        int edad;
        list<Evento*> eventos;

    public:
        Asistente(string nombre,int edad);
        Asistente();
        string getNombre();
        int getEdad();
        void setNombre(string nombre);
        void setEdad(int edad);
        void agregarEvento(Evento* evento);
        virtual string toStringAsistente() = 0;
        virtual int yoSoy() = 0;
};
