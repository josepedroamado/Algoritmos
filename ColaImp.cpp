#include "ColaImp.h"

#ifndef COLAIMP_CPP
#define COLAIMP_CPP

template <class T>
ostream &operator<<(ostream& out, const ColaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

template <class T>
ColaImp<T>::ColaImp(){
	//IMPLEMENTADA
	this->cola = NULL;
	this->fin = NULL;
	this->cantElem = 0;
}

template <class T>
ColaImp<T>::ColaImp(const Cola<T> &c){
	//IMPLEMENTADA
	this->cola = NULL;
	this->fin = NULL;
	this->cantElem = 0;
	*this = c;
}

template <class T>
ColaImp<T>::ColaImp(const ColaImp<T> &c){
	//IMPLEMENTADA
	this->cola = NULL;
	this->fin = NULL;
	this->cantElem = 0;
	*this = c;
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const Cola<T> &c){
	//IMPLEMENTADA
	if (this != &c) {
		this->Vaciar();
		Cola<T> * clone = c.Clon();
		int i = 0;
		T* arrayElem = new T[c.CantidadElementos()];
		while (!clone->EsVacia()) {
			T e = clone->Desencolar();
			arrayElem[i] = e;
			i++;
		}
		delete clone;
		for (i = 0; i <= c.CantidadElementos() - 1; i++) {
			this->Encolar(arrayElem[i]);
		}
		delete arrayElem;
	}
	return *this;
}

template <class T>
Cola<T> & ColaImp<T>::operator=(const ColaImp<T> &c){
	//IMPLEMENTADA
	if (this != &c) {
		this->Vaciar();
		Cola<T> * clone = c.Clon();
		int i = 0;
		T* arrayElem = new T[c.CantidadElementos()];
		while (!clone->EsVacia()) {
			T e = clone->Desencolar();
			arrayElem[i] = e;
			i++;
		}
		delete clone;
		for (i = 0; i <= c.CantidadElementos() - 1; i++) {
			this->Encolar(arrayElem[i]);
		}
		delete arrayElem;
	}
	return *this;
}

template <class T>
bool ColaImp<T>::operator==(const Cola<T>& c) const{
	//IMPLEMENTADA
	bool ret = true;
	Cola<T> * thisClone = this->Clon();
	Cola<T> * cClone = c.Clon();
	while (!thisClone->EsVacia() && !cClone->EsVacia()) {
		T eThis = thisClone->Desencolar();
		T eC = cClone->Desencolar();
		if (eThis != eC) return false;
	}
	delete thisClone;
	delete cClone;
	return ret;
}

template <class T>
ColaImp<T>::~ColaImp(){
	//IMPLEMENTADA
	this->Vaciar();
}

template<class T>
Cola<T>* ColaImp<T>::CrearVacia() const {
	return new ColaImp<T>();
}

template <class T>
void ColaImp<T>::Encolar(const T &e){
	//IMPLEMENTADA
	if (cola == NULL){
		NodoLista<T> *nuevo = new NodoLista<T>(e, NULL, NULL);
		cola = nuevo;
		fin = cola;
	}
	else {
		NodoLista<T> *nuevo = new NodoLista<T>(e, NULL, NULL);
		fin->sig = nuevo;
		fin = fin->sig;
	}
	cantElem++;
}

template <class T>
T& ColaImp<T>::Principio()const{
	//IMPLEMENTADA
	return this->cola->dato;
}

template <class T>
T ColaImp<T>::Desencolar(){
	//IMPLEMENTADA
	T e = cola->dato;
	NodoLista<T> *borrar = cola;
	cola = cola->sig;
	delete borrar;
	cantElem--;
	return e;
}

template <class T>
void ColaImp<T>::Vaciar(){
	//IMPLEMENTADA
	this->cantElem = 0;
	this->fin = NULL;
	delete this->cola;
	this->cola = NULL;
}

template <class T>
unsigned int ColaImp<T>::CantidadElementos()const{
	//IMPLEMENTADA
	return cantElem;
}

template <class T>
bool ColaImp<T>::EsVacia() const{
	//IMPLEMENTADA
	if (cantElem == 0) return true;
	else return false;
}

template <class T>
bool ColaImp<T>::EsLlena() const{
	//IMPLEMENTADA
	return false;
}

template <class T>
Cola<T>* ColaImp<T>::Clon()const{
	//IMPLEMENTADA
	NodoLista<T> *iter = cola;
	Cola<T>* newCola = this->CrearVacia();
	for (int i = 0; i <= cantElem - 1; i++) {
		newCola->Encolar(iter->dato);
		iter = iter->sig;
	}
	return newCola;
}

template <class T>
void ColaImp<T>::Imprimir(ostream& o)const{
	//IMPLEMENTADA
	// en lugar de hacer cout << ... poner o << ...
	Cola<T> * clone = this->Clon();
	while (!clone->EsVacia()) {
		T e = clone->Desencolar();
		o << e;
		if (!clone->EsVacia()) o << " ";
	}
	delete clone;
}

#endif