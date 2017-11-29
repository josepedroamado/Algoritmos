#include "ListaPosImp.h"

#ifndef LISTAPOSIMP_CPP
#define LISTAPOSIMP_CPP
#define FACTOR_VEC 10 //Factor de tamaño del array

template <class T>
inline ostream & operator<<(ostream &out, const ListaPosImp<T> &l)
{
	l.Imprimir(out);
	return out;
}

template <class T>
ListaPos<T>* ListaPosImp<T>::CrearVacia() const
{
	return new ListaPosImp<T>();
}

template <class T>
ListaPosImp<T>::ListaPosImp()
{
	//IMPLEMENTADA
	this->max = FACTOR_VEC;
	this->cantElem = 0;
	this->list = new T[FACTOR_VEC];
}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPos<T> &l)
{
	//IMPLEMENTADA
	this->max = FACTOR_VEC;
	this->cantElem = 0;
	this->list = new T[FACTOR_VEC];
	*this = l;
}

template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPosImp<T> &l)
{
	//IMPLEMENTADA
	this->max = FACTOR_VEC;
	this->cantElem = 0;
	this->list = new T[FACTOR_VEC];
	*this = l;
}

template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPos<T> &l)
{
	if (this != &l) {
		//IMPLEMENTADA
		this->Vaciar();
		for (Iterador<T> &i = l.GetIterador(); !i.EsFin(); i.Resto()) {
			this->AgregarFin(i.Elemento());
		}
	}
	return *this;
}

template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPosImp<T> &l)
{
	if (this != &l) {
		//IMPLEMENTADA
		this->Vaciar();
		for (Iterador<T> &i = l.GetIterador(); !i.EsFin(); i.Resto()) {
			this->AgregarFin(i.Elemento());
		}
	}
	return *this;
}

template <class T>
ListaPosImp<T>::~ListaPosImp()
{
	//IMPLEMENTADA
	delete[] this->list;
}

template <class T>
void ListaPosImp<T>::AgregarPpio(const T &e) 
{
	//IMPLEMENTADA
	if (this->cantElem == this->max) this->Redimensionar();
	this->Shift_Right(0);
	list[0] = e;
	cantElem++;
}

template <class T>
void ListaPosImp<T>::AgregarFin(const T &e) 
{
	//IMPLEMENTADA
	if (this->cantElem == this->max) this->Redimensionar();
	list[cantElem++] = e;
}

template <class T>
void ListaPosImp<T>::AgregarPos(const T &e, unsigned int pos)
{
	//IMPLEMENTADA
	if (this->cantElem == this->max) this->Redimensionar();
	if (pos > this->cantElem) pos = cantElem;
	this->Shift_Right(pos);
	list[pos] = e;
	cantElem++;
}

template <class T>
void ListaPosImp<T>::BorrarPpio()
{
	//IMPLEMENTADA
	this->Shift_Left(0);
	cantElem--;
}

template <class T>
void ListaPosImp<T>::BorrarFin()
{
	//IMPLEMENTADA
	cantElem--;
}

template <class T>
void ListaPosImp<T>::BorrarPos(unsigned int pos)
{
	//IMPLEMENTADA
	this->Shift_Left(pos);
	cantElem--;
}

template <class T>
void ListaPosImp<T>::Borrar(const T &e)
{
	//IMPLEMENTADA
	if (this->Existe(e)) this->BorrarPos(this->Posicion(e));
}

template <class T>
T& ListaPosImp<T>::ElementoPpio() const
{
	//IMPLEMENTADA
	return list[0];
}

template <class T>
T& ListaPosImp<T>::ElementoFin() const
{
	//IMPLEMENTADA
	return list[cantElem-1];
}

template <class T>
T& ListaPosImp<T>::ElementoPos(unsigned int pos) const
{
	//IMPLEMENTADA
	return list[pos];
}

template <class T>
unsigned int ListaPosImp<T>::Posicion(const T &e) const
{
	//IMPLEMENTADA
	int pos = 0;
	while (list[pos] != e) pos++;
	return pos;
}

template <class T>
bool ListaPosImp<T>::Existe(const T &e) const
{
	//IMPLEMENTADA
	for (unsigned int i = 0; i < this->cantElem; i++) if (list[i] == e) return true;
	return false;
}

template <class T>
void ListaPosImp<T>::Vaciar()
{
	//IMPLEMENTADA
	this->cantElem = 0;
}

template <class T>
unsigned int ListaPosImp<T>::CantidadElementos() const
{ 
	//IMPLEMENTADA
	return this->cantElem; 
}

template <class T>
bool ListaPosImp<T>::EsVacia() const
{
	//IMPLEMENTADA
	return this->cantElem == 0;
}

template <class T>
bool ListaPosImp<T>::EsLlena() const
{
	//IMPLEMENTADA
	return false;
}

template <class T>
ListaPos<T>* ListaPosImp<T>::Clon() const
{
	//IMPLEMENTADA
	ListaPos<T>* newList = this->CrearVacia();
	*newList = *this;
	return newList;
}

template <class T>
Iterador<T> ListaPosImp<T>::GetIterador() const
{
	return IteradorListaPosImp<T>(*this);
}

template <class T>
void ListaPosImp<T>::Imprimir(ostream& o) const
{
	//IMPLEMENTADA
	// en lugar de hacer cout << ... poner o << ...
	for (unsigned int i = 0; i < this->cantElem; i++){
		o << list[i];
		if (i != cantElem - 1) o << " ";
	}
}

//Funciones Auxiliares

template <class T>
void ListaPosImp<T>::Redimensionar() {
	T* extendedList = new T[this->max + FACTOR_VEC];
	for (int i = 0; i < this->cantElem; i++) extendedList[i] = list[i];
	delete[] this->list;
	this->list = extendedList;
}

template <class T>
void ListaPosImp<T>::Shift_Right(int pos) {
	for (int i = this->cantElem - 1; i >= pos && i > -1; i--) list[i + 1] = list[i];
}

template <class T>
void ListaPosImp<T>::Shift_Left(int pos) {
	for (int i = pos; i <= this->cantElem - 1; i++)	list[i] = list[i+1];
}
#endif