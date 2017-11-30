
#ifndef ENTREGA2_H
#define ENTREGA2_H

#include "Definiciones.h"

#include "ColaImp.h"
#include "PilaImp.h"
#include "ListaOrd.h"
#include "TablaImp.h"
#include "MultiSet.h"
#include "ListaOrdImp.h"
#include "MultiSetImp.h"


template <class T>
ListaOrd<T>* ObtenerRepetidos(const MultiSet<T> &m)
{
	//IMPLEMENTADA
	ListaOrd<T>* lista = new ListaOrdImp2<T>();
	MultiSet<T>* clone = m.Clon();
	while (!clone->EsVacia()){
		T elem = clone->Elemento();
		int cant = clone->OcurrenciasElemento(elem);
		if (cant > 1) lista->AgregarOrd(elem);
		clone->Borrar(elem, cant);
	}
	delete clone;
	return lista;	
}

template <class T>
Tabla<T, int> *ContarOcurrencias(const ListaOrd<T>& l)
{
	//IMPLEMENTADA
	Tabla<T, int>* tabla = new TablaImp<T, int>();
	for (Iterador<T> &i = l.GetIterador(); !i.EsFin(); i.Resto()) {
		T elem = i.Elemento();
		if (tabla->EstaDefinida(elem)) tabla->Insertar(elem, tabla->Recuperar(elem) + 1);
		else tabla->Insertar(i.Elemento(), 1);	
	}
	return tabla;	
}


//Observando que: AxorB = (AuB)-(AnB)
template <class T>
MultiSet<T>* Xor(const MultiSet<T> &m1, const MultiSet<T> &m2) {
	//IMPLEMENTADA
	MultiSet<T>* tablaDifM1 = m1.Diferencia(m2);
	MultiSet<T>* tablaDifM2 = m2.Diferencia(m1);
	MultiSet<T>* ret = tablaDifM1->Union(*tablaDifM2);
	delete tablaDifM1;
	delete tablaDifM2;
	return ret;
}

bool ParentesisBalanceados(char *formula);

void ImprimirPorNiveles(NodoAG* a);

#endif
