#ifndef ARBOL_AVL_H
#define ARBOL_AVL_H

#include "Cola.h"
#include "Pila.h"
#include <iostream>
using namespace std;

// Nodo del �rbol AVL
template <class T>
struct Nodo {
    T dato;
    int clave;
    Nodo* izquierda;
    Nodo* derecha;
    int altura;

    Nodo(T info, int valor) {
        dato = info;
        clave = valor;
        izquierda = derecha = nullptr;
        altura = 1;
    }
};

// Clase �rbol AVL
template <class T>
class ArbolAVL {
	Nodo<T>* raiz;
private:
    
    Nodo<T>* rotarDerecha(Nodo<T>* y);
    Nodo<T>* rotarIzquierda(Nodo<T>* x);
    Nodo<T>* NodoMinimo(Nodo<T>* nodo);
    Nodo<T>* insertarNodo(Nodo<T>* nodo, T info, int valor);
    Nodo<T>* eliminarNodo(Nodo<T>* nodo, int valor);

public:
    ArbolAVL() { raiz = NULL; }

    int obtenerAltura(Nodo<T>* nodo);
    int obtenerBalance(Nodo<T>* nodo);
    void insertar(T info, int valor);
    void eliminar(int valor);
    void inOrderIterativo(Cola<T>& cola);
    void preOrderIterativo(Cola<T>& cola);
    void postOrderIterativo(Cola<T>& cola);
};

// Implementaciones

template <class T>
int ArbolAVL<T>::obtenerAltura(Nodo<T>* nodo) {
    return nodo ? nodo->altura : 0;
}

template <class T>
int ArbolAVL<T>::obtenerBalance(Nodo<T>* nodo) {
    return nodo ? obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha) : 0;
}

template <class T>
Nodo<T>* ArbolAVL<T>::rotarDerecha(Nodo<T>* y) {
    Nodo<T>* x = y->izquierda;
    Nodo<T>* T2 = x->derecha;
    x->derecha = y;
    y->izquierda = T2;
    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
    return x;
}

template <class T>
Nodo<T>* ArbolAVL<T>::rotarIzquierda(Nodo<T>* x) {
    Nodo<T>* y = x->derecha;
    Nodo<T>* T2 = y->izquierda;
    y->izquierda = x;
    x->derecha = T2;
    x->altura = max(obtenerAltura(x->izquierda), obtenerAltura(x->derecha)) + 1;
    y->altura = max(obtenerAltura(y->izquierda), obtenerAltura(y->derecha)) + 1;
    return y;
}

template <class T>
Nodo<T>* ArbolAVL<T>::NodoMinimo(Nodo<T>* nodo) {
    while (nodo->izquierda)
        nodo = nodo->izquierda;
    return nodo;
}

template <class T>
void ArbolAVL<T>::insertar(T info, int valor) {
    raiz = insertarNodo(raiz, info, valor);
}

template <class T>
Nodo<T>* ArbolAVL<T>::insertarNodo(Nodo<T>* nodo, T info, int valor) {
    if (!nodo) return new Nodo<T>(info, valor);

    if (valor < nodo->clave)
        nodo->izquierda = insertarNodo(nodo->izquierda, info, valor);
    else if (valor > nodo->clave)
        nodo->derecha = insertarNodo(nodo->derecha, info, valor);
    else
        return nodo;

    nodo->altura = 1 + max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha));
    int balance = obtenerBalance(nodo);

    if (balance > 1 && valor < nodo->izquierda->clave)
        return rotarDerecha(nodo);
    if (balance < -1 && valor > nodo->derecha->clave)
        return rotarIzquierda(nodo);
    if (balance > 1 && valor > nodo->izquierda->clave) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }
    if (balance < -1 && valor < nodo->derecha->clave) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }
    return nodo;
}

template <class T>
void ArbolAVL<T>::eliminar(int valor) {
    raiz = eliminarNodo(raiz, valor);
}

template <class T>
Nodo<T>* ArbolAVL<T>::eliminarNodo(Nodo<T>* nodo, int valor) {
    if (!nodo) return nodo;

    if (valor < nodo->clave)
        nodo->izquierda = eliminarNodo(nodo->izquierda, valor);
    else if (valor > nodo->clave)
        nodo->derecha = eliminarNodo(nodo->derecha, valor);
    else {
        if (!nodo->izquierda || !nodo->derecha) {
            Nodo<T>* temp = nodo->izquierda ? nodo->izquierda : nodo->derecha;
            if (!temp) {
                temp = nodo;
                nodo = nullptr;
            } else
                *nodo = *temp;
            delete temp;
        } else {
            Nodo<T>* temp = NodoMinimo(nodo->derecha);
            nodo->clave = temp->clave;
            nodo->derecha = eliminarNodo(nodo->derecha, temp->clave);
        }
    }
    return nodo;
}

template <class T>
void ArbolAVL<T>::inOrderIterativo(Cola<T>& cola) {
    if (!raiz) return;
    Pila<Nodo<T>*> pila;
    Nodo<T>* actual = raiz;
    while (actual || !pila.empty()) {
        while (actual) {
            pila.push(actual);
            actual = actual->izquierda;
        }
        actual = pila.top(); pila.pop();
        cola.push(actual->dato);  //Insertar el dato en la cola
        actual = actual->derecha;
    }
}

template <class T>
void ArbolAVL<T>::preOrderIterativo(Cola<T>& cola) {
    if (!raiz) return;

    Pila<Nodo<T>*> pila;
    pila.push(raiz);

    while (!pila.empty()) {
        Nodo<T>* nodo = pila.top();
        pila.pop();

        cola.push(nodo->dato); // A�adir el dato a la cola

        if (nodo->derecha) pila.push(nodo->derecha);
        if (nodo->izquierda) pila.push(nodo->izquierda);
    }
}


template <class T>
void ArbolAVL<T>::postOrderIterativo(Cola<T>& cola) {
    if (!raiz) return;

    Pila<Nodo<T>*> pila;
    Nodo<T>* actual = raiz;
    Nodo<T>* ultimoVisitado = nullptr;

    while (!pila.empty() || actual) {
        if (actual) {
            // Ir lo m�s a la izquierda posible
            pila.push(actual);
            actual = actual->izquierda;
        } else {
            // Verificar el nodo en el tope de la pila
            Nodo<T>* nodo = pila.top();

            // Si el nodo tiene un hijo derecho y no lo hemos visitado
            if (nodo->derecha && nodo->derecha != ultimoVisitado) {
                actual = nodo->derecha; // Ir al sub�rbol derecho
            } else {
                // Procesar el nodo actual
                cola.push(nodo->dato);
                ultimoVisitado = nodo;
                pila.pop(); // Eliminar el nodo de la pila
            }
        }
    }
}

#endif

