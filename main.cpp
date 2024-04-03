#include <iostream>
#include "Asistente.h"
#include "Evento.h"

using namespace std;

bool menu(Evento* eventos,Asistente* asistentes) {
   	int entrada = 0;

   	cout<<"MENU"<<endl;
   	cout<<"1.- Crear nuevo evento"<<endl;
   	cout<<"2.- Registrar nuevo Asistente"<<endl;
   	cout<<"3.- Consultar lista de Asistentes"<<endl;
   	cout<<"4.- Generar Informe"<<endl;
   	cout<<"5.- Guardar cambios y salir"<<endl;
   	cout<<"-Ingrese una opcion: "<<endl;
   	cin>>entrada;

   	switch(entrada) {

   	case 1:

   		break;
   	case 2:

   		break;
   	case 3:

   		break;
   	case 4:

   		break;
   	case 5:

   		return false;
   	default:
   		cout<<"Opcion invalida. ingrese otra opcion "<<endl;
   		break;
   	}
   	return true;
}

void CrearNuevoEvento(Evento* eventos) {

}

int main() {

	bool salir = true;

	Evento* eventos = new Evento[100];
	Asistente* asistentes = new Asistente[100];

	do {
		salir = menu(eventos,asistentes);
	}
	while(salir);

    return 0;
}
