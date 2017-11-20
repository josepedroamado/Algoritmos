#ifndef COLAIMP_H
#define COLAIMP_H

#include "Cola.h"
#include "NodoLista.h"

template <class T>
class ColaImp : public Cola<T>{

public:
	//Constructor por defecto
	ColaImp();
	
	//Constructor copia
	ColaImp(const Cola<T> &c);
	ColaImp(const ColaImp<T> &c);
	
	//Operador de asignacion
	Cola<T> &operator=(const Cola<T> &c);
	Cola<T> &operator=(const ColaImp<T> &c);

	//Documentacion en la especificacion
	virtual ~ColaImp();
	
	Cola<T> *CrearVacia() const;
	Cola<T> *Clon()const;
	
	void Encolar(const T &e);
	T& Principio() const;
	T Desencolar();

	void Vaciar();
	unsigned int CantidadElementos() const;
	bool EsVacia() const;
	bool EsLlena() const;

	bool operator==(const Cola<T>& c) const;

	void Imprimir(ostream& o) const;

private:
	// Atributos de la clase
	NodoLista<T> *cola; //Lista con los elementos de la cola
	NodoLista<T> *fin; //Puntero al ultimo elemento de la cola
	int cantElem; //Cantidad de elementos en la pila
	
};

#include "ColaImp.cpp"

#endif