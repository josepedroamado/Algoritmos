#include "Entrega2.h"

#ifndef ENTREGA2_CPP
#define ENTREGA2_CPP

bool ParentesisBalanceados(char *formula)
{
	//IMPLEMENTADA
	int ret = true;
	Pila<char>* pila = new PilaImp<char>();
	int i = 0;
	while (formula[i] != '\0'){
		if (formula[i] == '(' || formula[i] == '[' || formula[i] == '{') pila->Push(formula[i]);
		if (formula[i] == ')') {
			if (pila->EsVacia()) pila->Push(formula[i]);
			else if (pila->Top() == '(') pila->Pop();
		}
		if (formula[i] == ']') {
			if (pila->EsVacia()) pila->Push(formula[i]);
			else if (pila->Top() == '[') pila->Pop();
		}
		if (formula[i] == '}') {
			if (pila->EsVacia()) pila->Push(formula[i]);
			else if (pila->Top() == '{') pila->Pop();
		}
		i++;
	}
	ret = pila->EsVacia();
	delete pila;
	return ret;
}

void ImprimirPorNiveles(NodoAG* a)
{
	//IMPLEMENTADA
	if (a != NULL) {
		Cola<NodoAG*>* colaNivel = new ColaImp<NodoAG*>();
		Pila<NodoAG*>* pilaHermanos = new PilaImp<NodoAG*>();
		colaNivel->Encolar(a);
		while (!colaNivel->EsVacia()){
			NodoAG* nodo = colaNivel->Desencolar();
			if (nodo->ph != NULL) colaNivel->Encolar(nodo->ph);
			if (nodo->sh != NULL) pilaHermanos->Push(nodo->sh);
			cout << nodo->dato;
			while (!pilaHermanos->EsVacia()){
				nodo = pilaHermanos->Pop();
				if (nodo->ph != NULL) colaNivel->Encolar(nodo->ph);
				if (nodo->sh != NULL) pilaHermanos->Push(nodo->sh);
				cout << ' ' << nodo->dato;
			}
			if (!colaNivel->EsVacia()) cout << ' ';
		}
		delete colaNivel;
		delete pilaHermanos;
	}
}

#endif
