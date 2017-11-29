#include "MultiSetImp.h"

#ifndef MULTISET_IMP_CPP
#define MULTISET_IMP_CPP

template <class T>
MultiSetImp<T>::MultiSetImp() { 
	//IMPLEMENTADA
	this->lista = new ListaOrdImp2<T>();
	this->cardinal = 0;
}

template <class T>
MultiSetImp<T>::MultiSetImp(const MultiSet<T> &multiSet) { 
	//IMPLEMENTADA
	this->lista = new ListaOrdImp2<T>();
	this->cardinal = 0;
	*this = multiset;
}

template <class T>
MultiSetImp<T>::MultiSetImp(const MultiSetImp<T> &multiSet) { 
	//IMPLEMENTADA
	this->lista = new ListaOrdImp2<T>();
	this->cardinal = 0;
	*this = multiset;
}

template <class T>
MultiSet<T>& MultiSetImp<T>::operator=(const MultiSet<T> &multiSet) { 
	if (this != &multiSet) {
		//IMPLEMENTADA
		this->Vaciar();
		MultiSet<T>* clone = multiSet.Clon();
		while (!clone->EsVacia()){
			T elem = clone->Elemento();
			this->Insertar(elem, 1);
			clone->Borrar(elem, 1);
		}
		delete clone;
	}
	return *this;
}

template <class T>
MultiSet<T>& MultiSetImp<T>::operator=(const MultiSetImp<T> &multiSet) { 
	if (this != &multiSet) {
		//IMPLEMENTADA
		this->Vaciar();
		MultiSet<T>* clone = multiSet.Clon();
		while (!clone->EsVacia()) {
			T elem = clone->Elemento();
			this->Insertar(elem, 1);
			clone->Borrar(elem, 1);
		}
		delete clone;
	}
	return *this;
}

template <class T>
bool MultiSetImp<T>::operator==(const MultiSet<T> &multiSet) const {
	//IMPLEMENTADA
	MultiSet<T>* cloneThis = this->Clon();
	MultiSet<T>* cloneMultiSet = multiSet.Clon();
	bool ret = true;
	while (!cloneThis->EsVacia() && !cloneMultiSet->EsVacia()){
		T elem = cloneThis->Elemento();
		if (!cloneMultiSet->Pertenece(elem)) {
			ret = false;
			cloneThis->Vaciar();
			cloneMultiSet->Vaciar();
		}
		cloneThis->Borrar(elem, 1);
		cloneMultiSet->Borrar(elem, 1);
	}
	delete cloneThis;
	delete cloneMultiSet;
	return ret;
}

template <class T>
MultiSetImp<T>::~MultiSetImp() { 
	//IMPLEMENTADA
	delete this->lista;
}

template <class T>
void MultiSetImp<T>::Insertar(const T &e, unsigned int cantidad) { 
	//IMPLEMENTADA
	if (lista->EsVacia()) this->cardinal++;
	else if (!this->Pertenece(e)) this->cardinal++;
	while (cantidad != 0){
		this->lista->AgregarOrd(e);
		cantidad--;
	}
}

template <class T>
void MultiSetImp<T>::Borrar(const T &e, unsigned int cantidad) {
	//IMPLEMENTADA
	while (cantidad != 0){
		this->lista->Borrar(e);
		cantidad--;
	}
	if (!this->Pertenece(e)) this->cardinal--;
}

template <class T>
const T& MultiSetImp<T>::Elemento() const {
	//IMPLEMENTADA
	return this->lista->Minimo();
}

template <class T>
const T& MultiSetImp<T>::Recuperar(const T &e) const {
	//IMPLEMENTADA
	return this->lista->Recuperar(e);
}

template <class T>
unsigned int MultiSetImp<T>::OcurrenciasElemento(const T &e) const {
	//IMPLEMENTADA
	ListaOrd<T>* clone = this->lista->Clon();
	int cantidad = 0;
	while (clone->Existe(e)){
		cantidad++;
		clone->Borrar(e);
	}
	delete clone;
	return cantidad;
}

template <class T>
bool MultiSetImp<T>::Pertenece(const T &e) const { 
	//IMPLEMENTADA
	return lista->Existe(e);
}

template <class T>
void MultiSetImp<T>::Vaciar() { 
	//IMPLEMENTADA
	delete this->lista;
	this->lista = new ListaOrdImp2<T>();
	this->cardinal = 0;
}

template <class T>
bool MultiSetImp<T>::EsVacia() const {
	//IMPLEMENTADA
	return this->cardinal == 0;
}

template <class T>
bool MultiSetImp<T>::EsLlena() const { 
	//IMPLEMENTADA
	return false;
}

template <class T>
unsigned int MultiSetImp<T>::Cardinal() const { 
	//IMPLEMENTADA
	return this->cardinal;
}

template <class T>
MultiSet<T>* MultiSetImp<T>::Union(const MultiSet<T>& s) const
{
	//IMPLEMENTADA
	MultiSet<T>* nuevo = this->Clon();
	MultiSet<T>* cloneS = s.Clon();
	while (!cloneS->EsVacia()){
		T elem = cloneS->Elemento();
		int cantElemEnS = 0;
		while (cloneS->Pertenece(elem)) {
			cantElemEnS++;
			cloneS->Borrar(elem, 1);
		}
		MultiSet<T>* cloneNuevo = nuevo->Clon();
		int cantElemEnNuevo = 0;
		while (cloneNuevo->Pertenece(elem)) {
			cantElemEnNuevo++;
			cloneNuevo->Borrar(elem, 1);
		}
		delete cloneNuevo;
		int cantAgregar = cantElemEnS - cantElemEnNuevo;
		if (cantAgregar < 0) cantAgregar = 0;
		nuevo->Insertar(elem, cantAgregar);
	}
	delete cloneS;
	return nuevo;
}

template <class T>
MultiSet<T>* MultiSetImp<T>::Interseccion(const MultiSet<T>& s) const
{
	//IMPLEMENTADA
	MultiSet<T>* nuevo = this->CrearVacia();
	MultiSet<T>* cloneThis = this->Clon();
	MultiSet<T>* cloneS = s.Clon();
	while (!cloneThis->EsVacia()) {
		T elem = cloneThis->Elemento();
		if (cloneS->Pertenece(elem)) {
			nuevo->Insertar(elem, 1);
			cloneThis->Borrar(elem, 1);
			cloneS->Borrar(elem, 1);
		}
		else cloneThis->Borrar(elem, 1);
	}
	delete cloneThis;
	delete cloneS;
	return nuevo;
}
 
template <class T>
MultiSet<T>* MultiSetImp<T>::Diferencia(const MultiSet<T>& s) const
{
	//IMPLEMENTADA
	MultiSet<T>* nuevo = this->Clon();
	MultiSet<T>* cloneS = s.Clon();
	while (!cloneS->EsVacia()) {
		T elem = cloneS->Elemento();
		if (nuevo->Pertenece(elem)) {
			nuevo->Borrar(elem, 1);
			cloneS->Borrar(elem, 1);
		}
		else cloneS->Borrar(elem, 1);
	}
	delete cloneS;
	return nuevo;
}
 
template <class T>
bool MultiSetImp<T>::ContenidoEn(const MultiSet<T> &s) const
{
	//IMPLEMENTADA
	bool ret = true;
	MultiSet<T>* cloneThis = this->Clon();
	MultiSet<T>* cloneS = s.Clon();
	while (!cloneThis->EsVacia()) {
		T elem = cloneThis->Elemento();
		if (cloneS->Pertenece(elem)){
			cloneThis->Borrar(elem, 1);
			cloneS->Borrar(elem, 1);
		}
		else {
			ret = false;
			cloneThis->Vaciar();
		}
	}
	delete cloneThis;
	delete cloneS;
	return ret;
}

template <class T>
MultiSet<T>* MultiSetImp<T>::Clon() const { 
	//IMPLEMENTADA
	MultiSet<T>* newMultiSet = new MultiSetImp<T>();
	for (Iterador<T> &i = this->lista->GetIterador(); !i.EsFin(); i.Resto()) {
		newMultiSet->Insertar(i.Elemento(), 1);
	}
	return newMultiSet;
}

template <class T>
MultiSet<T>* MultiSetImp<T>::CrearVacia() const { 
	//IMPLEMENTADA
	return new MultiSetImp<T>();
}

template<class T>
void MultiSetImp<T>::Imprimir(ostream& o) const
{
	//IMPLEMENTADA
	// en lugar de hacer cout << ... poner o << ...
	this->lista->Imprimir(o);
}

#endif
