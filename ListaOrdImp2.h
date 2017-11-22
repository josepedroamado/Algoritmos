#ifndef LISTAORDIMP2_H
#define LISTAORDIMP2_H

#include <assert.h>
#include "ListaOrd.h"
#include "ListaPosImp.h"
#include "IteradorListaOrdImp2.h"
#include "NodoABB.h"

template <class T>
class IteradorListaOrdImp2;

template <class T>
class ListaOrdImp2: public ListaOrd<T> {
	friend class IteradorListaOrdImp2<T>; 
	friend ostream &operator<<(ostream& o, const ListaOrdImp2<T> & l);
public:

	// Constructor por defecto
	ListaOrdImp2();

	// Constructor copia
	ListaOrdImp2(const ListaOrd<T> &l);
	ListaOrdImp2(const ListaOrdImp2<T> &l);

	// Operador de asignacion
	ListaOrd<T> &operator=(const ListaOrd<T> &l);
	ListaOrd<T> &operator=(const ListaOrdImp2<T> &l);

	// Para ver la documentacion del resto de las funciones ver la especificacion
	ListaOrd<T>* CrearVacia() const;
	virtual ~ListaOrdImp2();

	void AgregarOrd(const T &e);
	void BorrarMinimo();	
	void BorrarMaximo();
	void Borrar(const T &e);

	const T& Minimo() const;
	const T& Maximo() const;

	const T& Recuperar(const T&) const; 
	bool Existe(const T &e) const;	

	void Vaciar();

	unsigned int CantidadElementos() const;

	bool EsVacia() const;
	bool EsLlena() const;

	ListaOrd<T>* Clon() const;

	Iterador<T> GetIterador() const;
	void Imprimir(ostream& o) const;

protected:
	// Atributos
	NodoABB<T> * arbol; //Lista de elementos en forma de arbol
	int cantElem; //Cantidad de elementos en la lista

	//METODOS AUXILIARES

	//PRE: Recibe un ABB y un elemento a agregar
	//POS: Modifica el ABB para que contenga el elemento en la posicion correspondiente
	void agregarAux(NodoABB<T> *a, const T &e) const;

	bool existeAux(NodoABB<T> *a, const T &e) const;

	void borrarAux(NodoABB<T>* a, const T &e);

	NodoABB<T>* minAux(NodoABB<T>* a);

	NodoABB<T>* maxAux(NodoABB<T>* a);

	NodoABB<T>* recuperarAux(NodoABB<T> *a, const T &e);

	
};

#include "ListaOrdImp2.cpp"

#endif