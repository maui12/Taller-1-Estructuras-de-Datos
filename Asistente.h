#pragma once
#include <iostream>

using namespace std;

class Asistente {
    private:
        string nombre;
        string eventos[20]; //preguntar si se usan arrays normales, cambiar string por clase evento
        //falta poner la ocupacion de cada asistente

    public:
        Asistente(string nombre);
        string getNombre();
        void setNombre(string nombre);
        void agregarEvento(string evento);

};