#pragma once
#include <iostream>
#include "Evento.h"
#include "Asistente.h"
#include <list>

using namespace std;

class Sistema {
	private:
		list<Evento*> eventos;
		list<Asistente*> asistentes;
	public:
		Sistema();
		void CrearEvento();
		void registrarAsistente();
		void getEventos();


};
