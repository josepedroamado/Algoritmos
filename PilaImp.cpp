#include "PilaImp.h"

#ifndef PILAIMP_CPP
#define PILAIMP_CPP

template <class T>
inline ostream &operator<<(ostream& out, const PilaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

template <class T>
PilaImp<T>::PilaImp() {
	//IMPLEMENTADA
	this->pila = NULL;
	this->cantElem = 0;
}

template<class T>
PilaImp<T>::PilaImp(const Pila<T>& p) {
	//IMPLEMENTADA
	this->pila = NULL;
	this->cantElem = 0;
	*this = p;
}

template<class T>
PilaImp<T>::PilaImp(const PilaImp<T>& p) {
	//IMPLEMENTADA
	this->pila = NULL;
	this->cantElem = 0;
	*this = p;
}

template<class T>
Pila<T>& PilaImp<T>::operator=(const Pila<T>& p) {
	//IMPLEMENTADA
	if (this != &p) {
		this->Vaciar();
		Pila<T> * clone = p.Clon();
		int i = 0;
		T* arrayElem = new T[p.CantidadElementos()];
		while (!clone->EsVacia()) {
			T e = clone->Pop();
			arrayElem[i] = e;
			i++;
		}
		delete clone;
		for (i = p.CantidadElementos() - 1; i >= 0; i--) {
			this->Push(arrayElem[i]);
		}
		delete arrayElem;
	}
	return *this;
}

template<class T>
Pila<T>& PilaImp<T>::operator=(const PilaImp<T>& p) {
	//IMPLEMENTADA
	if (this != &p) {
		this->Vaciar();
		Pila<T> * clone = p.Clon();
		int i = 0;
		T* arrayElem = new T[p.CantidadElementos()];
		while (!clone->EsVacia()) {
			T e = clone->Pop();
			arrayElem[i] = e;
			i++;
		}
		delete clone;
		for (i = p.CantidadElementos() - 1; i >= 0; i--) {
			this->Push(arrayElem[i]);
		}
		delete arrayElem;
	}
	return *this;
}

template<class T>
bool PilaImp<T>::operator==(const Pila<T> &p) const {
	//IMPLEMENTADA
	bool ret = true;
	Pila<T> * thisClone = this->Clon();
	Pila<T> * pClone = p.Clon();
	while (!thisClone->EsVacia() && !pClone->EsVacia()) {
		T eThis = thisClone->Pop();
		T eP = pClone->Pop();
		if (eThis != eP) return false;
	}
	delete thisClone;
	delete pClone;
	return ret;
}

template<class T>
PilaImp<T>::~PilaImp() {
	//IMPLEMENTADA
	this->Vaciar();
}

template<class T>
Pila<T>* PilaImp<T>::CrearVacia() const {
	return new PilaImp<T>();
}

template<class T>
void PilaImp<T>::Push(const T& e) {
	//IMPLEMENTADA
	NodoLista<T> *nuevo = new NodoLista<T>(e, NULL, pila);
	pila = nuevo;
	cantElem++;
}

template<class T>
T& PilaImp<T>::Top() const {
	//IMPLEMENTADA
	return pila->dato;
}

template<class T>
T PilaImp<T>::Pop() {
	//IMPLEMENTADA
	T ret = pila->dato;
	NodoLista<T> *borrar = pila;
	pila = pila->sig;
	delete borrar;
	cantElem--;
	return ret;
}

template<class T>
void PilaImp<T>::Vaciar() {
	//IMPLEMENTADA
	this->cantElem = 0;
	delete this->pila;
	this->pila = NULL;
}

template<class T>
unsigned int PilaImp<T>::CantidadElementos() const {
	//IMPLEMENTADA
	return cantElem;
}

template<class T>
bool PilaImp<T>::EsVacia() const {
	//IMPLEMENTADA
	return cantElem == 0;
}

template <class T>
bool PilaImp<T>::EsLlena() const{
	//IMPLEMENTADA
	return false;
}

template<class T>
Pila<T>* PilaImp<T>::Clon() const {
	//IMPLEMENTADA
	NodoLista<T> *iter = pila;
	T* arrayElem = new T[cantElem];
	for (int i = 0; i <= cantElem-1; i++){
		arrayElem[i] = iter->dato;
		iter = iter->sig;
	}
	Pila<T>* newPila = this->CrearVacia();
	for (int i = cantElem-1; i >= 0; i--) {
		newPila->Push(arrayElem[i]);
	}
	delete arrayElem;
	return newPila;
}

template<class T>
void PilaImp<T>::Imprimir(ostream & o) const
{
	// IMPLEMENTADA
	// en lugar de hacer cout << ... poner o << ...
	Pila<T> * clone = this->Clon();
	while (!clone->EsVacia()){
		T e = clone->Pop();
		o << e;
		if (!clone->EsVacia()) o << " ";
	}
	delete clone;
}

#endif