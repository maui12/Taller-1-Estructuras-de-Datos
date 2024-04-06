#pragma once
#include <iostream>
#include "Evento.h"

using namespace std;

class Taller:public Evento {

	private:
		string ubicacion;
	public:
		Taller(string nombre,string ubicacion);
		string getUbicacion();
		void setUbicacion(string ubicacion);
		string toString();
		string getAtributoEvento();
		int getTipo();
};
