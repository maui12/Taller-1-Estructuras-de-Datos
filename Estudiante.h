#pragma once
#include <iostream>
#include "Asistente.h"

using namespace std;

class Estudiante:public Asistente{
    private:
        string institucion;
    public:
        Estudiante(string nombre, int edad, string institucion);
        string getInstitucion();
        void setInstitucion(string institucion);
        string toStringAsistente();
        int yoSoy();
};
