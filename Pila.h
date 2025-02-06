#include "NodoCP.h"

#ifndef Pila_H     
#define Pila_H   
#include <iostream>

using namespace std;

template <class T>
class Pila {
private:
    NodoCP<T>* cab;
    size_t tam;
public:
    Pila() : cab(NULL), tam(0) {}
    void push(T v);
    T pop();
    T top();
    bool empty();
    size_t size();
    ~Pila();
};

// M�todo para insertar un elemento en la pila
template <class T>
void Pila<T>::push(T v) {
    NodoCP<T>* t = new NodoCP<T>;
    t->info = v;
    t->sig = cab;
    cab = t;
    tam++;
}

// M�todo para extraer un elemento de la pila
template <class T>
T Pila<T>::pop() {
    if (empty()) cout<<"La pila est� vac�a"<<endl;
    NodoCP<T>* t = cab;
    T x = t->info;
    cab = t->sig;
    delete t;
    tam--;
    return x;
}

// M�todo para obtener el elemento en la cima
template <class T>
T Pila<T>::top() {
    if (empty()) cout<<"La pila est� vac�a"<<endl;
    return cab->info;
}

// M�todo para verificar si la pila est� vac�a
template <class T>
bool Pila<T>::empty() {
    return cab == NULL;
}

// M�todo para obtener el tama�o de la pila
template <class T>
size_t Pila<T>::size() {
    return tam;
}

// Destructor de la pila
template <class T>
Pila<T>::~Pila() {
    while (!empty()) {
        pop();
    }
} 
#endif


