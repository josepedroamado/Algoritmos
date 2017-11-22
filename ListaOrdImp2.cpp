#include "ListaOrdImp2.h"

#ifndef LISTAORDIMP2_CPP
#define LISTAORDIMP2_CPP

template <class T>
inline ostream &operator<<(ostream& out, const ListaOrdImp2<T> &l) 
{
	l.Imprimir(out);
	return out;
}

template <class T>
ListaOrd<T>* ListaOrdImp2<T>::CrearVacia() const 
{
	return new ListaOrdImp2<T>();
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2()
{
	//IMPLEMENTADA
	this->arbol = NULL;
	this->cantElem = 0;
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2(const ListaOrd<T> &l) 
{
	//IMPLEMENTADA
	this->arbol = NULL;
	this->cantElem = 0;
	*this = l;
}

template <class T>
ListaOrdImp2<T>::ListaOrdImp2(const ListaOrdImp2<T> &l) 
{
	//IMPLEMENTADA
	this->arbol = NULL;
	this->cantElem = 0;
	*this = l;
}

template <class T>
ListaOrd<T> &ListaOrdImp2<T>::operator=(const ListaOrd<T> &l) 
{ 
	if (this != &l) {
		//IMPLEMENTADA
		this->Vaciar();
		this->cantElem = l.CantidadElementos();
		for (Iterador<T> &i = l.GetIterador(); !i.EsFin(); i.Resto()) {
			this->AgregarOrd(i.Elemento());
		}
	}
	return *this;
}

template <class T>
ListaOrd<T> &ListaOrdImp2<T>::operator=(const ListaOrdImp2<T> &l) 
{ 
	if (this != &l) {
		//IMPLEMENTADA
		this->Vaciar();
		this->cantElem = l.CantidadElementos();
		for (Iterador<T> &i = l.GetIterador(); !i.EsFin(); i.Resto()) {
			this->AgregarOrd(i.Elemento());
		}
	}
	return *this;
}

template <class T>
ListaOrdImp2<T>::~ListaOrdImp2()
{
	//IMPLEMENTADA
	this->Vaciar();
}

template <class T>
void ListaOrdImp2<T>::AgregarOrd(const T &e) 
{
	//IMPLEMENTADA
	this->agregarAux(arbol, e);
	cantElem++;
}

template <class T>
void ListaOrdImp2<T>::BorrarMinimo() 
{
	//IMPLEMENTADA
	if (arbol != NULL) {
		NodoABB<T> * nodo = minAux(arbol);
		if (nodo->auxiliar == 0) {
			NodoAB<T> *borrar = nodo;
			nodo = nodo->der;
			delete borrar;
			cantElem--;
		}
		else {
			a->auxiliar--;
			cantElem--;
		}
	}
}

template <class T>
void ListaOrdImp2<T>::BorrarMaximo() 
{
	//IMPLEMENTADA
	if (arbol != NULL) {
		NodoABB<T> * nodo = maxAux(arbol);
		if (nodo->auxiliar == 0) {
			NodoAB<T> *borrar = nodo;
			nodo = nodo->izq;
			delete borrar;
			cantElem--;
		}
		else {
			a->auxiliar--;
			cantElem--;
		}
	}
}

template <class T>
void ListaOrdImp2<T>::Borrar(const T &e)
{
	//IMPLEMENTADA
	borrarAux(arbol, e);
	cantElem--;
}

template <class T>
const T& ListaOrdImp2<T>::Minimo() const 
{
	//IMPLEMENTADA
	return minAux(arbol)->dato;
}

template <class T>
const T& ListaOrdImp2<T>::Maximo() const 
{
	//IMPLEMENTADA
	return maxAux(arbol)->dato;
}

template <class T>
const T& ListaOrdImp2<T>::Recuperar(const T &e) const 
{
	//IMPLEMENTADA
	return recuperarAux(arbol, e)->dato;
}

template <class T>
bool ListaOrdImp2<T>::Existe(const T &e) const 
{
	//IMPLEMENTADA
	return existeAux(arbol, e);
}

template <class T>
void ListaOrdImp2<T>::Vaciar() 
{
	//IMPLEMENTADA
	this->cantElem = 0;
	delete this->arbol;
	this->arbol = NULL;
}

template <class T>
unsigned int ListaOrdImp2<T>::CantidadElementos()const 
{ 
	//IMPLEMENTADA
	return this->cantElem;
}

template <class T>
bool ListaOrdImp2<T>::EsVacia()const 
{
	//IMPLEMENTADA
	if (cantElem == 0) return true;
	else return false;
}

template <class T>
bool ListaOrdImp2<T>::EsLlena()const 
{ 
	//IMPLEMENTADA
	return false;
}

template<class T>
ListaOrd<T>* ListaOrdImp2<T>::Clon() const
{
	//IMPLEMENTADA
	ListaOrd<T>* newList = this->CrearVacia();
	*newList = *this;
	return newList;
}

template <class T>
Iterador<T> ListaOrdImp2<T>::GetIterador() const 
{
	// NO IMPLEMENTADA

	ListaPosImp<T> l;
	// SUGERENCIA: aqui cargar en l con los elementos de this ordenados de menor a mayor (con funcion auxiliar)
	return IteradorListaOrdImp2<T>(l);
}

template <class T>
void ListaOrdImp2<T>::Imprimir(ostream& o) const
{
	// NO IMPLEMENTADA
	// en luegar de hacer cout << ... poner o << ...
}

//AUXILIARES

template<class T>
void ListaOrdImp2<T>::agregarAux(NodoABB<T>* a, const T & e) const
{
	if (a == NULL){
		NodoABB<T> * nuevo = new NodoABB(e);
		nuevo->auxiliar++;
		a = nuevo;
	}
	else {
		if (e == a->dato) a->auxiliar++;
		else {
			if (e < a->dato) agregarAux(a->izq, e);
			else agregarAux(a->der, e);
		}
	}
}

template<class T>
bool ListaOrdImp2<T>::existeAux(NodoABB<T>* a, const T & e) const
{
	if (a != NULL) {
		if (e == a->dato) return true;
		else {
			if (e < a->dato) return existeAux(a->izq, e);
			else return existeAux(a->der, e);
		}
	}
	else return false;
}


template<class T>
void ListaOrdImp2<T>::borrarAux(NodoABB<T>* a, const T & e)
{
	if (a != NULL){
		if (e < a->dato) borrarAux(a->izq, e);
		else{
			if (e > a->dato) borrarAux(a->der, e);
			else {
				if (a->izq == NULL){
					if (a->auxiliar == 1) {
						NodoAB<T> *borrar = a;
						a = a->der;
						delete borrar;
					}
					else a->auxiliar--;
				}
				else{
					if (a->der == NULL) {
						if (a->auxiliar == 1) {
							NodoAB<T> *borrar = a;
							a = a->izq;
							delete borrar;
						}
						else a->auxiliar--;
					}
					else {
						if (a->auxiliar == 1){
							NodoABB<T>* minDer = minAux(a->der);
							a->dato = minDer->dato;
							a->auxiliar = minDer->auxiliar;
							int i = minDer->auxiliar;
							while (i != 0){
								borrarAux(a->der, minDer->dato);
							}	
						}
						else a->auxiliar--;		
					}
				}
			}
		}
	}
}

template<class T>
NodoABB<T>* ListaOrdImp2<T>::minAux(NodoABB<T>* a)
{
	if (a != NULL) {
		if (a->izq != NULL) return minAux(a->izq);
		else return a;
	}
	else return NULL;
}

template<class T>
NodoABB<T>* ListaOrdImp2<T>::maxAux(NodoABB<T>* a)
{
	if (a != NULL) {
		if (a->der != NULL) return maxAux(a->der);
		else return a;
	}
	else return NULL;
}

template<class T>
NodoABB<T>* ListaOrdImp2<T>::recuperarAux(NodoABB<T>* a, const T & e)
{
	if (a != NULL){
		if (e == a->dato) return a;
		else {
			if (e < a->dato) return recuperarAux(a->izq, e);
			else return recuperarAux(a->der, e);
		}
	}
	else return NULL;
}

#endif