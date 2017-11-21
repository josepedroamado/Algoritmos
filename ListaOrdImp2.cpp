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
}

template <class T>
void ListaOrdImp2<T>::BorrarMinimo() 
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaOrdImp2<T>::BorrarMaximo() 
{
	// NO IMPLEMENTADA
}

template <class T>
void ListaOrdImp2<T>::Borrar(const T &e)
{
	// NO IMPLEMENTADA
}

template <class T>
const T& ListaOrdImp2<T>::Minimo() const 
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
const T& ListaOrdImp2<T>::Maximo() const 
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
const T& ListaOrdImp2<T>::Recuperar(const T &e) const 
{
	// NO IMPLEMENTADA
	return *new T();
}

template <class T>
bool ListaOrdImp2<T>::Existe(const T &e) const 
{
	// NO IMPLEMENTADA
	return false;
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

template<class T>
void ListaOrdImp2<T>::agregarAux(NodoABB<T>* arbol, const T & e) const
{
	if (e == arbol->dato){
		arbol->auxiliar++;
	}
	else{
		if (e < arbol->dato){

		}
	}
}


#endif