#include <iostream>
#include "NodoCP.h"

#ifndef COLA_H     
#define COLA_H 

using namespace std;

// Implementaci�n de la Cola
template <class T>
class Cola {
private:
    NodoCP<T>* cab;
    NodoCP<T>* fin;
    size_t tam;
public:
    Cola() : cab(NULL), fin(NULL), tam(0) {}
    void push(T i);
    T pop();
    T front();
    T back();
    bool empty();
    size_t size();
    void print();
    ~Cola();
};

// M�todo para insertar un elemento en la cola
template <class T>
void Cola<T>::push(T i) {
    NodoCP<T>* nuevo = new NodoCP<T>;
    nuevo->info = i;
    nuevo->sig = NULL;
    if (cab == NULL) {
        cab = fin = nuevo;
    } else {
        fin->sig = nuevo;
        fin = nuevo;
    }
    tam++;
}

// M�todo para extraer un elemento de la cola
template <class T>
T Cola<T>::pop() {
    if (empty()) cout<<"La cola est� vac�a"<<endl;
    NodoCP<T>* aux = cab;
    T x = aux->info;
    cab = aux->sig;
    if (cab == NULL) {
        fin = NULL;
    }
    delete aux;
    tam--;
    return x;
}

// M�todo para obtener el primer elemento
template <class T>
T Cola<T>::front() {
    if (empty()) cout<<"La cola est� vac�a"<<endl;
    return cab->info;
}

// M�todo para obtener el �ltimo elemento
template <class T>
T Cola<T>::back() {
    if (empty()) cout<<"La cola est� vac�a"<<endl;
    return fin->info;
}

// M�todo para verificar si la cola est� vac�a
template <class T>
bool Cola<T>::empty() {
    return (cab == NULL);
}

// M�todo para obtener el tama�o de la cola
template <class T>
size_t Cola<T>::size() {
    return tam;
}

// M�todo para imprimir la cola
template <class T>
void Cola<T>::print() {
    NodoCP<T>* aux = cab;
    while (aux != NULL) {
        cout << aux->info << " ";
        aux = aux->sig;
    }
    cout << endl;
}

// Destructor de la cola
template <class T>
Cola<T>::~Cola() {
    while (!empty()) {
        pop();
    }
}

#endif


