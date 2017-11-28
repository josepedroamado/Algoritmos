#include "TablaImp.h"
#include "ListaOrdImp2.h"

#ifndef TABLAIMP_CPP
#define TABLAIMP_CPP

template <class D, class R>
inline ostream &operator<<(ostream& out, const TablaImp<D, R> &t) {
	t.Imprimir(out);
	return out;
}

template <class D, class R>
TablaImp<D, R>::TablaImp() {
	//IMPLEMENTADA
	ListaOrd<Asociacion<D, R>> * lista = new ListaOrdImp2<Asociacion<D, R>>();
	this->tabla = lista;
}

template <class D, class R>
TablaImp<D, R>::TablaImp(const Tabla<D,R> &t) {
	//IMPLEMENTADA
	ListaOrd<Asociacion<D, R>> * lista = new ListaOrdImp2<Asociacion<D, R>>();
	this->tabla = lista;
}

template <class D, class R>
TablaImp<D, R>::TablaImp(const TablaImp<D,R> &t) {
	//IMPLEMENTADA
	ListaOrd<Asociacion<D, R>> * lista = new ListaOrdImp2<Asociacion<D, R>>();
	this->tabla = lista;
	*this = t;
}

template <class D, class R>
Tabla<D,R>& TablaImp<D,R>::operator=(const Tabla<D,R> &t) {
	if (this != &t) {
		//IMPLEMENTADA
		this->Vaciar();
		Tabla<D, R> *clone = t.Clon();
		while (!clone->EsVacia()){
			D dom = clone->Elemento();
			R ran = clone->Recuperar(dom);
			this->Insertar(dom, ran);
			clone->Borrar(dom);
		}
	}
	return *this;
}

template <class D, class R>
Tabla<D,R>& TablaImp<D,R>::operator=(const TablaImp<D,R> &t) {
	if (this != &t) {
		//IMPLEMENTADA
		this->Vaciar();
		Tabla<D, R> *clone = t.Clon();
		while (!clone->EsVacia()){
		D dom = clone->Elemento();
		R ran = clone->Recuperar(dom);
		this->Insertar(dom, ran);
		clone->Borrar(dom);
		}
	}
	return *this;
}

template <class D, class R>
TablaImp<D, R>::~TablaImp() {
	//IMPLEMENTADA
	this->Vaciar();
	delete this->tabla;
	this->tabla = NULL;
}

template <class D, class R>
Tabla<D, R>* TablaImp<D, R>::CrearVacia() const {
	return new TablaImp<D, R>();
}

template <class D, class R>
void TablaImp<D, R>::Vaciar() {
	//IMPLEMENTADA
	delete this->tabla;
	this->tabla = new ListaOrdImp2<Asociacion<D, R>>();
}

template <class D, class R>
void TablaImp<D, R>::Insertar(const D &d, const R &r) {
	//IMPLEMENTADA
	if (tabla->Existe(d)) tabla->Borrar(d);
	Asociacion<D, R> a(d, r);
	tabla->AgregarOrd(a);
}

template <class D, class R>
bool TablaImp<D, R>::EstaDefinida(const D &d) const {
	//IMPLEMENTADA
	if (tabla->Existe(d)) return true;
	else return false;
}

template <class D, class R>
bool TablaImp<D,R>::operator==(const Tabla<D,R> &t) const {
	//IMPLEMENTADA
	if (this->EsVacia() && t.EsVacia()) return true;
	Tabla<D, R> *clone = t.Clon();
	while (!clone->EsVacia()) {
		Asociacion<D, R> elemClone = clone->Elemento();	
		elemClone.SetRango(clone->Recuperar(elemClone.GetDominio()));
		if (this->tabla->Existe(elemClone)) {
			Asociacion<D, R> elemThis = this->tabla->Recuperar(elemClone);
			if (elemClone.GetRango() != elemThis.GetRango()) return false;
		}
		else return false;
		clone->Borrar(elemClone.GetDominio());
	}
	return true; 
}; 

template <class D, class R>
const R& TablaImp<D, R>::Recuperar(const D &d) const {
	//IMPLEMENTADA
	return this->tabla->Recuperar(d).GetRango();
}

template <class D, class R>
const D& TablaImp<D, R>::Elemento() const {
	//IMPLEMENTADA
	/*Asociacion<D, R> elem = this->tabla->Minimo();
	D ret = elem.GetDominio();*/
	return this->tabla->Minimo().GetDominio();
}

template <class D, class R>
void TablaImp<D, R>::Borrar(const D &d) {
	//IMPLEMENTADA
	this->tabla->Borrar(d);
}

template <class D, class R>
bool TablaImp<D, R>::EsVacia() const {
	//IMPLEMENTADA
	return this->tabla->EsVacia();
}

template <class D, class R>
bool TablaImp<D, R>::EsLlena() const {
	//IMPLEMENTADA
	return false;
}

template <class D, class R>
unsigned int TablaImp<D, R>::CantidadElementos() const {
	//IMPLEMENTADA
	return this->tabla->CantidadElementos();
}

template <class D, class R>
Tabla<D,R>* TablaImp<D, R>::Clon() const {
	//IMPLEMENTADA
	Tabla<D, R> *newTabla = this->CrearVacia();
	for (Iterador<Asociacion<D, R>> &i = tabla->GetIterador(); !i.EsFin(); i.Resto()) {
		Asociacion<D, R> asoc = i.Elemento();
		newTabla->Insertar(asoc.GetDominio(), asoc.GetRango());
	}
	return newTabla;
}

template <class D, class R>
void TablaImp<D, R>::Imprimir(ostream & o) const
{
	//IMPLEMENTADA
	// en lugar de hacer cout << ... poner o << ...
	for (Iterador<Asociacion<D, R>> &i = tabla->GetIterador(); !i.EsFin(); i.Resto()) {
		Asociacion<D, R> asoc = i.Elemento();
		o << "{" << "D" << ":" << asoc.GetDominio() << "|" << "R" << ":" << asoc.GetRango() << "}";
		if (!i.EsFin()) o << " ";
	}
}


#endif