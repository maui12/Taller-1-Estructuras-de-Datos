#include <iostream>
#include "Sistema.h"
#include "Evento.h"
#include "Asistente.h"
#include "Conferencia.h"
#include "Concierto.h"
#include "Taller.h"

using namespace std;

Sistema::Sistema() {}

void Sistema::CrearEvento() {
	cout<<"=====Crear un nuevo Evento===== \nElija el tipo de evento: \n1)Conferencia 2)Concierto 3)Taller"<<endl;
	int tipo;
	cin >> tipo;

	if(tipo != 1 && tipo != 2 && tipo != 3) {
		cout<<"Dato invalido";
		return;
	}

	cout<<"Ingrese nombre del nuevo evento: "<<endl;
	string nombre;
	cin >> nombre;

	string atributo;
	Evento* evento;

	switch(tipo) {
	case 1:
		cout<<"Conferencia: señale el tema: "<<endl;
		cin >> atributo;
		evento = new Conferencia(nombre,atributo);
		break;
	case 2:
		cout<<"Concierto: señale la duracion: "<<endl;
		cin >> atributo;
		evento = new Concierto(nombre,stoi(atributo));

		break;
	case 3:
		cout<<"Taller: señale la ubicacion: "<<endl;
		cin >> atributo;
		evento = new Taller(nombre,atributo);
		break;

	}

	eventos.push_front(evento);

	cout<<"Evento creado"<<endl;
}


