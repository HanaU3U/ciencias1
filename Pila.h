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

// Método para insertar un elemento en la pila
template <class T>
void Pila<T>::push(T v) {
    NodoCP<T>* t = new NodoCP<T>;
    t->info = v;
    t->sig = cab;
    cab = t;
    tam++;
}

// Método para extraer un elemento de la pila
template <class T>
T Pila<T>::pop() {
    if (empty()) cout<<"La pila está vacía"<<endl;
    NodoCP<T>* t = cab;
    T x = t->info;
    cab = t->sig;
    delete t;
    tam--;
    return x;
}

// Método para obtener el elemento en la cima
template <class T>
T Pila<T>::top() {
    if (empty()) cout<<"La pila está vacía"<<endl;
    return cab->info;
}

// Método para verificar si la pila está vacía
template <class T>
bool Pila<T>::empty() {
    return cab == NULL;
}

// Método para obtener el tamaño de la pila
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


