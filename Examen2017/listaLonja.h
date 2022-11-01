#ifndef LONJA_H
#define LONJA_H

#include <iostream>
#include <string>
#include "lotes.h"

namespace lonja {
	struct tListaLonja {
		tLote* lotes = nullptr;
		int cont = 0;
		int size = 0;
	};

	// Crea una lista vacía de lotes
	void inicializar(tListaLonja & lista);
	// Libera la memoria dinámica reservada
	void liberar(tListaLonja & lista);
	// Devuelve el número de lotes
	int numLotes(tListaLonja const& lista);

	// Busca recursivamente en la lista la posición en la que está el lote
	bool buscar(tListaLonja const& lista, string idLote, string pescado, int & idx);
	// Inserta un lote en la lista ya ordenada. Si ya está, no hace nada
	void insertar(tListaLonja & lista, tLote const& lote);
	// Devuelve el lote en pos
	tLote obtenerLote(tListaLonja & lista, int pos);
	// Carga una lista de lotes de un fichero, y los ordena
	void cargar(tListaLonja & lista, istream & entrada);
	// Muestra la lista de lotes con el formato anterior (Usa función mostrarPrecio)
	void mostrar(tListaLonja & lista, ostream & salida = std::cout);

}

#endif
