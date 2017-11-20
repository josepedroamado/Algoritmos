#include "Entrega1.h"

#ifndef ENTREGA1_CPP
#define ENTREGA1_CPP

void recorrerArbol(NodoAB* a, ListaOrd<int>* lista) {
	if (a != NULL) {
		recorrerArbol(a->izq, lista);
		lista->AgregarOrd(a->dato);
		recorrerArbol(a->der, lista);
	}
}

ListaOrd<int>* Enlistar(NodoAB* a)
{
	//IMPLEMENTADA
	ListaOrd<int> *lista = new ListaOrdImp<int>();
	recorrerArbol(a, lista);
	return lista;
}

int CantidadDeHojas(NodoAB* a)
{
	//IMPLEMENTADA
	if (a != NULL){
		int cantHojas = 0;
		Cola<NodoAB*>* cola = new ColaImp<NodoAB*>();
		if (a->izq == NULL && a->der == NULL) cantHojas++;
		if (a->izq != NULL) cola->Encolar(a->izq);
		if (a->der != NULL) cola->Encolar(a->der);
		while (!cola->EsVacia()){
			NodoAB* actual = cola->Desencolar();
			if (actual->izq == NULL && actual->der == NULL) cantHojas++;
			if (actual->izq != NULL) cola->Encolar(actual->izq);
			if (actual->der != NULL) cola->Encolar(actual->der);
		}
		delete cola;
		return cantHojas;
	}
	else return 0;
}

void ImprimirPorNiveles(NodoAB *a)
{
	//IMPLEMENTADA
	if (a != NULL){
		Pila<int>* pila = new PilaImp<int>();
		Cola<NodoAB*>* cola = new ColaImp<NodoAB*>();
		cola->Encolar(a);
		while (!cola->EsVacia()){
			NodoAB* actual = cola->Desencolar();
			pila->Push(actual->dato);
			if (actual->izq != NULL) cola->Encolar(actual->izq);
			if (actual->der != NULL) cola->Encolar(actual->der);
		}
		delete cola;
		while (!pila->EsVacia()){
			int actual = pila->Pop();
			cout << actual;
			if (!pila->EsVacia()) cout << " ";
		}
		delete pila;
	}
}

#endif