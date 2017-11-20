
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
	// NO IMPLEMENTADA
	return new ListaOrdImp<T>();	
}

template <class T>
Tabla<T, int> *ContarOcurrencias(const ListaOrd<T>& l)
{
	// NO IMPLEMENTADA
	return new TablaImp<T, int>();	
}


//Observando que: AxorB = (AuB)-(AnB)
template <class T>
MultiSet<T>* Xor(const MultiSet<T> &m1, const MultiSet<T> &m2) {
	// NO IMPLEMENTADA
	return new MultiSetImp<T>();	
}

bool ParentesisBalanceados(char *formula);

void ImprimirPorNiveles(NodoAG* a);

#endif
