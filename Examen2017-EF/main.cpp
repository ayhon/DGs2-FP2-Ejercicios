#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "listalugares.h"
#include "listaopciones.h"
using namespace std;

const string ARCHIVO_SIERRAS = "sierras.txt";
const string ARCHIVO_PLAYAS = "playas.txt";
const string PAUSE_CMD = "echo \"Presione Enter para continuar\"; read";

void cargar(tListaLugares & vct, string filename) {
	ifstream entrada;
	entrada.open(filename);
	if(entrada.is_open()) {
		int numElem;
		entrada >> numElem;
		for(int i = 0; i < numElem; i++) {
			tLugar aux;
			entrada >> aux.name >> aux.cost;
			vct.push_back(aux);
		}
	}
	else {
		cout << "El archivo " << filename << " no existe\n";
	}
	entrada.close();
}

int menu() {
	int reply;
	cout << "1. Mostrar lugares con playa\n";
	cout << "2. Mostrar lugares con montaña\n";
	cout << "3. Introduce un nuevo posible viaje\n";
	cout << "4. Mostrar todas las opciones e viaje\n";
	cout << "0. Terminar\n";
	cout << "> "; cin >> reply;
	while(reply > 4 || reply < 0){
		cout << "> "; cin >> reply;
	} 
	return reply;
}

int main() {
	tListaLugares playas, sierras; 

	cargar(playas, ARCHIVO_PLAYAS);
	cargar(sierras, ARCHIVO_SIERRAS);

	tListaOpciones opciones;

	int reply;
	bool exit = false;
	while(!exit) {
		reply = menu();
		switch(reply) {
			case 1:
				cout << playas;		
				break;
			case 2:
				cout << sierras;		
				break;
			case 3:
				nuevoViaje(opciones, playas, sierras);
				break;
			case 4:
				cout << "Lista de opciones:\n";
				cout << opciones;
				system(PAUSE_CMD.c_str());
				break;
			case 0:
			default:
				exit = true;
		}
	}
}
