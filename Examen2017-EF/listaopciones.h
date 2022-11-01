#ifndef LISTAOPCIONES_H
#define LISTAOPCIONES_H

#include <iostream>
#include <string>
#include <vector>
#include "listalugares.h"
using namespace std;

struct tOpc  {
	tLugar * OpcPlaya = nullptr;
	tLugar* OpcSierra = nullptr;
	int cost = 0;
};
using tListaOpciones = vector<tOpc>;

ostream & operator<< (ostream & out, tListaOpciones & lista);

// Libera la memoria de la lista
void liberar(tListaOpciones & lista);
// Añade una nueva opción a la lista de opciones
void nuevoViaje(tListaOpciones & lista, tListaLugares & playas, tListaLugares & sierras);

#endif
