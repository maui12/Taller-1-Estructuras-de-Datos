#pragma once
#include <iostream>
#include "Evento.h"

using namespace std;

class Concierto:public Evento {

	private:
		int duracion;
	public:
		Concierto(string nombre,int duracion);
		int getDuracion();
		void setDuracion(int duracion);
		string toString();

};
