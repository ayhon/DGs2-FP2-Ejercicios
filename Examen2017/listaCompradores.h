#ifndef COMPRADORES_H
#define COMPRADORES_H

#include <iostream>
#include <string>
#include "lotes.h"

namespace comp{
	struct tComprador {
		long long idComprador = 0;
		double importe;
	};

	struct tListaComprador{
		tComprador * compradores = nullptr;
		int cont = 0, size=0;
	};

	// Inicializa una lista vacía de compradores
	void inicializar(tListaComprador & lista);
	// Libera la memoria de la lista
	void liberar(tListaComprador & lista);

	// Devuelve la posición de dicho comprador si está
	bool buscar(tListaComprador const& lista, long long idComprador, int & idx);
	// Inserta un nuevo comprador, o incrementa el importe de la compra
	void insertar(tListaComprador & lista, tComprador & comprador);

	// Muestra un listado de los compradores
	void mostrar(tListaComprador & lista, ostream & salida = std::cout);
}

#endif
