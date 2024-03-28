#pragma once
#include <iostream>
#include "Evento.h"

using namespace std;

class Asistente {
    private:
        string nombre;
        int edad;
        Evento eventos[20]; //preguntar si se usan arrays normales, cambiar string por clase evento
        //falta poner la ocupacion de cada asistente

    public:
        Asistente(string nombre,int edad);
        string getNombre();
        int getEdad();
        void setNombre(string nombre);
        void setEdad(int edad);
        void agregarEvento(string evento);

};