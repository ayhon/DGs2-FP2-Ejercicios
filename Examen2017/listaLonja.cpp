#include <iostream>
#include <vector> 
#include "listaLonja.h" 
using namespace lonja;

namespace lonja{
	void ampliar(tListaLonja & lista) {
		lista.size *= INC;
		tLote * newls = new tLote[lista.size];
		for(int i = 0; i < lista.cont; i++) 
			newls[i] = lista.lotes[i];

		delete[] lista.lotes;
		lista.lotes = newls;
	}

	void inicializar(tListaLonja & lista) {
		lista.size = INC;
		lista.cont = 0;
		lista.lotes = new tLote[lista.size];
	}

	void liberar(tListaLonja & lista) {
		lista.cont = 0;
		lista.size = 0;
		delete[] lista.lotes;
	}

	int numLotes(tListaLonja const& lista) {
		return lista.cont;
	}

	bool binSearch(tListaLonja const& lista, tLote const& target, int & idx, int ini, int fin) {
		// Casos base
		if(ini == fin) return false;
		if (fin - ini == 1){
			idx = (lista.lotes[ini] < target? fin : ini);
			return lista.lotes[ini] == target;
		} 
		int mid = ini + (fin-ini)/2;
		if(lista.lotes[mid] == target) {
			idx = ini;
			return true;
		}

		// Casos recursivos
		else if (lista.lotes[mid] < target) {
			return binSearch(lista, target, idx, mid, fin);
		} else {
			return binSearch(lista, target, idx, ini, mid);
		}

	}
	bool buscar(tListaLonja const& lista, string idLote, string pescado, int & idx) {
		idx = numLotes(lista);
		tLote target;
		target.idLote = idLote;
		target.pescado = pescado;
		return binSearch(lista, target, idx, 0, numLotes(lista));
	}

	void insertar(tListaLonja & lista, tLote const& lote) {
		if(lista.cont == lista.size) ampliar(lista);
		int pos;
		if(!buscar(lista, lote.idLote, lote.pescado, pos)) {
			for(int i = numLotes(lista); i > pos; i--)
				lista.lotes[i] = lista.lotes[i-1];
			lista.lotes[pos] = lote;

			lista.cont++;
		}
	}

	tLote obtenerLote(tListaLonja & lista, int pos) {
		return lista.lotes[pos];
	}

	void cargar(tListaLonja & lista, istream & entrada) {
		tLote nuevo;
		while(!(entrada.eof() || !entrada)) {
			entrada >> nuevo.idLote >> nuevo.pescado >> nuevo.peso >> nuevo.precio;
			insertar(lista, nuevo);
		}
	}

	void mostrar(tListaLonja & lista, ostream & salida) {
		for(int i = 0; i < numLotes(lista); i++) {
			mostrarPrecio(lista.lotes[i], salida);
		}
	}

}
