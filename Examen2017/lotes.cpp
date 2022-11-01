#include <iostream>
#include <iomanip>
#include "lotes.h"
using namespace std;

bool operator <(tLote const& l1, tLote const& l2){
	 return (l1.pescado < l2.pescado || (l1.pescado == l2.pescado && l1.idLote < l2.idLote));
}
bool operator==(tLote const& l1, tLote const& l2){
	return l1.idLote == l2.idLote;
}
void mostrarLote(tLote const& lote, ostream & salida) { 
	cout << "Lote: " << setw(10) << right << lote.idLote << SEP;
	cout << "Peso del lote: " << fixed << setprecision(2) << lote.peso << '\n';
	cout << "Tipo: " << setw(10) << right << lote.pescado << SEP;
	cout << "Precio de salida: " << fixed << setprecision(2) << lote.precio << '\n';
}

void mostrarPrecio(tLote const& lote, ostream & salida) {
	cout << "Lote: " << setw(10) << right << lote.idLote << SEP;
	cout << "Comprador: " << lote.idComprador << '\n';
	cout << "Tipo: " << setw(10) << right << lote.pescado << SEP;
	cout << "Precio de compra: " << fixed << setprecision(2) << lote.precio << '\n';
}

void modificarLote (tLote & lote, long long idComprador, double precio) {
	lote.idComprador = idComprador;
	lote.precio = precio;
}
