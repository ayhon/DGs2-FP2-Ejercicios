#include <iostream>
#include <string>
#include <fstream>
#include "listaLonja.h"
#include "listaCompradores.h"
using namespace std;

const string ARCHIVO_ENTRADA = "datos.txt";

int main() {
	ifstream archivoEntrada;
	archivoEntrada.open(ARCHIVO_ENTRADA);

	lonja::tListaLonja listaLonja; 
	inicializar(listaLonja);

	comp::tListaComprador listaComprador;
	inicializar(listaComprador);

	cargar(listaLonja, archivoEntrada);
	for(int i = 0; i < numLotes(listaLonja); i++) {
		mostrarLote(obtenerLote(listaLonja, i));
		cout << "Introduzca comprador y precio\n> ";
		comp::tComprador comprador;
		cin >> comprador.idComprador >> comprador.importe;

		modificarLote(listaLonja.lotes[i], comprador.idComprador, comprador.importe);
		comp::insertar(listaComprador, comprador);
	}

	comp::mostrar(listaComprador);
	lonja::mostrar(listaLonja);

	system("echo \"Presione Enter para continuar . . .\"; read");
	return 0;
}
