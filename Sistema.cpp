#include <iostream>
#include <list>
#include "Sistema.h"
#include "Evento.h"
#include "Asistente.h"
#include "Conferencia.h"
#include "Concierto.h"
#include "Taller.h"
#include "Profesional.h"
#include "Estudiante.h"
#include "Artista.h"

using namespace std;

Sistema::Sistema() {
	list<Evento*> ev;
	this -> eventos = ev;
	this -> asistentes = asistentes;

}

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

	eventos.push_back(evento);

	cout<<"Evento creado"<<endl;
}

void Sistema::registrarAsistente() {

	cout<<"Desea registrar un nuevo Asistente o uno ya existente? \n1)Nuevol 2)Existente"<<endl;
	int resp;
	cin >> resp;

	if(resp == 1) {
		cout<<"=====Registrar nuevo Asistente===== \nElija de asistente: \n1)Profesional 2)Estudiante 3)Artista"<<endl;
		int tipo;
		cin >> tipo;

		if(tipo != 1 && tipo != 2 && tipo != 3) {
			cout<<"Dato invalido";
			return;
		}

		cout<<"Ingrese nombre del asistente: "<<endl;
		string nombre;
		cin >> nombre;

		cout<<"Ingrese edad del asistente: "<<endl;
		int edad;
		cin >> edad;

		string atributo;
		Asistente* asistente;

		switch(tipo) {
			case 1:
				cout<<"Profesional: señale la ocupacion: "<<endl;
				cin >> atributo;
				asistente = new Profesional(nombre,edad,atributo);
				break;
			case 2:
				cout<<"Estudiante: indique la institucion: "<<endl;
				cin >> atributo;
				asistente = new Estudiante(nombre,edad,atributo);
				break;
			case 3:
				cout<<"Artista: indique el nombre artistico: "<<endl;
				cin >> atributo;
				asistente = new Artista(nombre,edad,atributo);
				break;
			}
	}

	else if(resp == 2) {

	}
}

void Sistema::getEventos() {

}




