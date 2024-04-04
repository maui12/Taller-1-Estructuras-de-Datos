#include <iostream>
#include "Asistente.h"
#include "Evento.h"
#include "Sistema.h"

using namespace std;

bool menu(Sistema sistema) {

   	int entrada = 0;

   	cout<<"MENU"<<endl;
   	cout<<"1.- Crear nuevo evento"<<endl;
   	cout<<"2.- Registrar Asistente"<<endl;
   	cout<<"3.- Consultar lista de Asistentes"<<endl;
   	cout<<"4.- Generar Informe"<<endl;
   	cout<<"5.- Guardar cambios y salir"<<endl;
   	cout<<"-Ingrese una opcion: "<<endl;
   	cin>>entrada;

   	switch(entrada) {

   	case 1:
   		sistema.CrearEvento();
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


int main() {

	Sistema sistema;

	bool salir = true;

	do {
		salir = menu(sistema);
	}
	while(salir);

    return 0;
}
