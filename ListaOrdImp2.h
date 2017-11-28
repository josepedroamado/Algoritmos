#ifndef LISTAORDIMP2_H
#define LISTAORDIMP2_H

#include <assert.h>
#include "ListaOrd.h"
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

	//PRE: 
	//POS: Modifica el arbol para que contenga el elemento en la posicion correspondiente
	void agregarAux(NodoABB<T>* &a, const T &e) const;

	//PRE: 
	//POS: Retorna true si el elemento existe en el arbol y false si no existe
	bool existeAux(NodoABB<T>* a, const T &e) const;

	//PRE: 
	//POS: Elimina el elemento del arbol, si el mismo se encontraba mas de una vez, elimina una instancia del mismo
	void borrarAux(NodoABB<T>* &a, const T &e);

	//PRE: 
	//POS: Elimina el elemento mayor del arbol
	void borrarMaxAux(NodoABB<T>* &a);

	//PRE: 
	//POS: Elimina el elemento minimo del arbol
	void borrarMinAux(NodoABB<T>* &a);

	//PRE:
	//POS: Retorna el valor del minimo del arbol
	T& minAux(NodoABB<T>* a) const;

	//PRE: 
	//POS: Retorna el nodo del minimo valor del arbol o null si el mismo es vacio
	NodoABB<T> * minAuxNodo(NodoABB<T>* a) const;

	//PRE: 
	//POS: Retorna el valor del maximo del arbol
	T& maxAux(NodoABB<T>* a) const;

	//PRE: 
	//POS: Retorna el valor del maximo del arbol
	T& recuperarAux(NodoABB<T> *a, const T &e) const;

	//PRE:
	//POS: Carga los elementos del arbol en la lista de menor a mayor
	void getIteradorAux(NodoABB<T> *a, ListaPosImp<T> *lista) const;

	//PRE:
	//POS: Imprime los elementos del arbol de menor a mayor
	void imprimirAux(NodoABB<T> *a, ostream& o) const;

	//PRE: 
	//POS: Elimina todos los nodos del arbol
	void borrarTodo(NodoABB<T>* &a);
};

#include "ListaOrdImp2.cpp"

#endif