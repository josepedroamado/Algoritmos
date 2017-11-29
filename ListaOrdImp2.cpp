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
	borrarMinAux(arbol);
}

template <class T>
void ListaOrdImp2<T>::BorrarMaximo() 
{
	//IMPLEMENTADA
	borrarMaxAux(arbol);
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
	return minAux(arbol);
}

template <class T>
const T& ListaOrdImp2<T>::Maximo() const 
{
	//IMPLEMENTADA
	return maxAux(arbol);
}

template <class T>
const T& ListaOrdImp2<T>::Recuperar(const T &e) const 
{
	//IMPLEMENTADA
	return recuperarAux(arbol, e);
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
	borrarTodo(arbol);
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
	return cantElem == 0;
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
	//IMPLEMENTADA
	ListaPosImp<T> l;
	// SUGERENCIA: aqui cargar en l con los elementos de this ordenados de menor a mayor (con funcion auxiliar)
	getIteradorAux(arbol, &l);
	return IteradorListaOrdImp2<T>(l);
}

template <class T>
void ListaOrdImp2<T>::Imprimir(ostream& o) const
{
	//IMPLEMENTADA
	// en lugar de hacer cout << ... poner o << ...
	//imprimirAux(arbol, o);
	ListaPosImp<T> list;
	getIteradorAux(arbol, &list);
	Iterador<T> &i = list.GetIterador();
	while (!i.EsFin()) {
		o << i.Elemento();
		i.Resto();
		if (!i.EsFin()) o << " ";
	}
}

//AUXILIARES

template<class T>
void ListaOrdImp2<T>::agregarAux(NodoABB<T>* &a, const T & e) const
{
	if (a == NULL){
		NodoABB<T> * nuevo = new NodoABB<T>(e);
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
void ListaOrdImp2<T>::borrarAux(NodoABB<T>* &a, const T & e)
{
	if (a != NULL){
		if (e < a->dato) borrarAux(a->izq, e);
		else{
			if (e > a->dato) borrarAux(a->der, e);
			else {
				if (a->izq == NULL){
					if (a->auxiliar == 1) {
						NodoABB<T> *borrar = a;
						a = a->der;
						delete borrar;
					}
					else a->auxiliar--;
				}
				else{
					if (a->der == NULL) {
						if (a->auxiliar == 1) {
							NodoABB<T> *borrar = a;
							a = a->izq;
							delete borrar;
						}
						else a->auxiliar--;
					}
					else {
						if (a->auxiliar == 1){
							NodoABB<T>* minDer = minAuxNodo(a->der);
							a->dato = minDer->dato;
							a->auxiliar = minDer->auxiliar;
							int i = minDer->auxiliar;
							while (i != 0) borrarAux(a->der, minDer->dato);
						}
						else a->auxiliar--;		
					}
				}
			}
		}
	}
}

template<class T>
void ListaOrdImp2<T>::borrarMaxAux(NodoABB<T>* &a)
{
	if (a != NULL) {
		if (a->der != NULL) borrarMaxAux(a->der);
		else {
			if (a->auxiliar == 0) {
				NodoABB<T> *borrar = a;
				a = a->izq;
				delete borrar;
				cantElem--;
			}
			else {
				a->auxiliar--;
				cantElem--;
			}
		}
	}
}

template<class T>
void ListaOrdImp2<T>::borrarMinAux(NodoABB<T>* &a)
{
	if (a != NULL) {
		if (a->izq != NULL) borrarMinAux(a->izq);
		else {
			if (a->auxiliar == 0) {
				NodoABB<T> *borrar = a;
				a = a->der;
				delete borrar;
				cantElem--;
			}
			else {
				a->auxiliar--;
				cantElem--;
			}
		}
	}
}

template<class T>
T& ListaOrdImp2<T>::minAux(NodoABB<T>* a) const
{
	assert(a != NULL);
	if (a->izq != NULL) return minAux(a->izq);
	else return a->dato;
}

template<class T>
NodoABB<T>* ListaOrdImp2<T>::minAuxNodo(NodoABB<T>* a) const
{
	if (a != NULL) {
		if (a->izq != NULL) return minAuxNodo(a->izq);
		else return a;
	}
	else return NULL;
}

template<class T>
T& ListaOrdImp2<T>::maxAux(NodoABB<T>* a) const
{
	assert(a != NULL);
	if (a->der != NULL) return maxAux(a->der);
	else return a->dato;
}

template<class T>
T& ListaOrdImp2<T>::recuperarAux(NodoABB<T>* a, const T & e) const
{
	assert(a != NULL);
	if (e == a->dato) return a->dato;
	else {
		if (e < a->dato) return recuperarAux(a->izq, e);
		else return recuperarAux(a->der, e);
	}
}

template<class T>
void ListaOrdImp2<T>::getIteradorAux(NodoABB<T>* a, ListaPosImp<T>* lista) const
{
	if (a != NULL){
		getIteradorAux(a->izq, lista);
		int i = a->auxiliar;
		while (i != 0){
			lista->AgregarFin(a->dato);
			i--;
		}
		getIteradorAux(a->der, lista);
	}
}

template<class T>
void ListaOrdImp2<T>::borrarTodo(NodoABB<T>* &a)
{
	if (a != NULL){
		borrarTodo(a->izq);
		borrarTodo(a->der);
		delete a;
		a = NULL;
	}
}

#endif