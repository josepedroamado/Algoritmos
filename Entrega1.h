#ifndef ENTREGA1_H
#define ENTREGA1_H

#include "Definiciones.h"

#include "ListaOrd.h"
#include "ListaPos.h"
#include "Pila.h"
#include "Cola.h"

#include "ListaOrdImp.h"
#include "ListaPosImp.h"
#include "PilaImp.h"
#include "ColaImp.h"

// Ver Entrega1.txt para la documentación de estas funciones

template <class T>
ListaOrd<T> *UnionListaOrd(const ListaOrd<T> &l1, const ListaOrd<T> &l2)
{
	//IMPLEMENTADA
	ListaOrd<int> *lista = new ListaOrdImp<int>();
	Iterador<T> &i = l1.GetIterador();
	Iterador<T> &j = l2.GetIterador();
	while (!j.EsFin()) {
		lista->AgregarOrd(j.Elemento());
		j.Resto();
	}
	while (!i.EsFin()) {
		lista->AgregarOrd(i.Elemento());
		i.Resto();
	}
	return lista;	
}

ListaOrd<int>* Enlistar(NodoAB* a);

template <class T>
bool EstaContenida(const Pila<T> &p1, const Pila<T> &p2)
{
	//IMPLEMENTADA
	if (p1.CantidadElementos() > p2.CantidadElementos()) return false;
	else {
		Pila<T>* copiaP1 = p1.Clon();
		ListaPos<T>* pila1 = new ListaPosImp<T>();
		while (!copiaP1->EsVacia()){
			pila1->AgregarFin(copiaP1->Pop());
		}
		delete copiaP1;
		Pila<T>* copiaP2 = p2.Clon();
		ListaPos<T>* pila2 = new ListaPosImp<T>();
		while (!copiaP2->EsVacia()) {
			pila2->AgregarFin(copiaP2->Pop());
		}
		delete copiaP2;
		Iterador<T> &i = pila1->GetIterador();
		while (!i.EsFin()){
			if (pila2->Existe(i.Elemento())) pila2->Borrar(i.Elemento());
			else return false;
			i.Resto();
		}
		delete pila1;
		delete pila2;
		return true;
	}
}

int CantidadDeHojas(NodoAB* a);

void ImprimirPorNiveles(NodoAB *a);

#endif