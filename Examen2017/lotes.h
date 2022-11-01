#ifndef LOTES_H
#define LOTES_H

#include <iostream>
#include <string>
using namespace std;

const string SEP = "          ";
const int INC = 2;
struct tLote{
	string idLote = "";
	string pescado = "";
	double peso = 0.0;
	double precio = 0.0;
	long long idComprador = 0;
};

bool operator <(tLote const& l1, tLote const& l2);
bool operator==(tLote const& l1, tLote const& l2);
void mostrarLote(tLote const& lote, ostream & salida = cout);
/* 
 *  Muestra la información del lote con el siguiente formato
 *  Lote: XYYYYYY 		Peso del lote: XX.XX
 *  Tipo: XXXXXXX 		Precio de salida: XX.XX
 *  Double con 2 decimales, máximo de 10 caracteres en idLote y pescado
 */
void mostrarPrecio(tLote const& lote, ostream & salida = cout);
/* 
 *  Muestra la información del lote con el siguiente formato
 *  Lote: XYYYYYY 		Comprador: XX.XX
 *  Tipo: XXXXXXX 		Precio de compra: XX.XX
 *  Double con 2 decimales, máximo de 10 caracteres en idLote y pescado
 */
void modificarLote (tLote & lote, long long idComprador, double precio);

#endif
