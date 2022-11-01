#include <iostream>
#include <string>
#include <iomanip>
#include "listaCompradores.h"

using namespace comp;
namespace comp {
	void ampliar(tListaComprador & lista) {
		lista.size *= INC;

		tComprador * newls = new tComprador[lista.size];
		for(int i = 0; i < lista.cont; i++) 
			newls[i] = lista.compradores[i];
		delete[] lista.compradores;
		lista.compradores = newls; }

	void inicializar(tListaComprador & lista) {
		lista.size = INC;
		lista.cont = 0;
		lista.compradores = new tComprador[lista.size];
	}

	void liberar(tListaComprador & lista) {
		lista.cont = 0;
		lista.size = 0;
		delete[] lista.compradores;
	}

	bool binSearch(tListaComprador const& lista, long long idComprador, int & idx, int ini, int fin) {
		// Casos base
		if(fin == ini) return false;
		if(fin - ini == 1){
			idx = (lista.compradores[ini].idComprador < idComprador? fin: ini);
			return lista.compradores[ini].idComprador == idComprador;
		} 
		int mid = ini + (fin-ini)/2;
		if(lista.compradores[mid].idComprador == idComprador) {
			idx = ini;
			return true;
		}

		// Casos recursivos
		else if (lista.compradores[mid].idComprador < idComprador) {
			return binSearch(lista, idComprador, idx, mid, fin);
		}
		else {
			return binSearch(lista, idComprador, idx, ini, mid);
		}
	}

	bool buscar(tListaComprador const& lista, long long idComprador, int & idx) {
		idx = lista.cont;
		return binSearch(lista, idComprador, idx, 0, lista.cont);
	}

	void insertar(tListaComprador & lista, tComprador & comprador) {
		if(lista.cont == lista.size) ampliar(lista);

		int pos;
		if(!buscar(lista, comprador.idComprador, pos)) {
			for(int i = lista.cont; i > pos; i--) 
				lista.compradores[i] = lista.compradores[i-1];
			lista.compradores[pos] = comprador;

			lista.cont++;
		} else {
			lista.compradores[pos].importe += comprador.importe;
		}
	}

	void mostrar(tListaComprador & lista, ostream & salida) {
		for(int i = 0; i < lista.cont; i++) {
			cout << "Comprador: " << setw(10) << right << lista.compradores[i].idComprador << SEP;
			cout << "Total: " << setw(4) << right << fixed << setprecision(3) << lista.compradores[i].importe << '\n';
		}
	}
}
