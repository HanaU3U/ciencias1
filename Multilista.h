#ifndef MULTILISTA_H
#define MULTILISTA_H

#include <iostream>
using namespace std;

// Nodo de la multilista
template <typename T>
struct NodoM {
    T dato;
    NodoM* siguiente;
    NodoM* sublista;

    NodoM(T valor) : dato(valor), siguiente(NULL), sublista(NULL) {}
};


// Clase Multilista
template <typename T>
class Multilista {
private:
    NodoM<T>* cabeza;

public:
    Multilista() : cabeza(NULL) {}

    // Insertar en la lista principal
    bool InsertarM(T dato) {
        NodoM<T>* nuevo = new NodoM<T>(dato);
        if (!cabeza) {
            cabeza = nuevo;
            return true;
        }
        NodoM<T>* temp = cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
        return true;
    }

    // Insertar en la sublista de un nodo específico (por clave, título, etc.)
    bool InsertarEnSublista(const string& clave, T dato) {
	    NodoM<T>* temp = cabeza;
	    while (temp && temp->dato.titulo != clave) { // Comparando por título del álbum
	        temp = temp->siguiente;
	    }
	    if (!temp) return false; // No encontrado
	
	    NodoM<T>* nuevo = new NodoM<T>(dato);
	    if (!temp->sublista) {
	        temp->sublista = nuevo;
	    } else {
	        NodoM<T>* subTemp = temp->sublista;
	        while (subTemp->siguiente) {
	            subTemp = subTemp->siguiente;
	        }
	        subTemp->siguiente = nuevo;
	    }
	    return true;
	}

    // Borrar un nodo de la lista principal
    bool BorraM(T dato) {
        if (!cabeza) return false;

        NodoM<T>* temp = cabeza;
        NodoM<T>* prev = NULL;

        while (temp && temp->dato.titulo != dato.titulo) {
            prev = temp;
            temp = temp->siguiente;
        }

        if (!temp) return false; // No encontrado

        if (!prev) {
            cabeza = cabeza->siguiente;
        } else {
            prev->siguiente = temp->siguiente;
        }

        delete temp;
        return true;
    }

    // Obtener el primer elemento
    T Primero() {
        if (!cabeza) cout<<"Multilista vacía"<<endl;
        return cabeza->dato;
    }

    // Obtener el último elemento
    T UltimoM() {
        if (!cabeza) cout<<"Multilista vacía"<<endl;
        NodoM<T>* temp = cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        return temp->dato;
    }

    // Mostrar la multilista con sus sublistas
    void Mostrar() {
        NodoM<T>* temp = cabeza;
        while (temp) {
            cout << "?? " << temp->dato.titulo << "\n------------------\n";
            NodoM<T>* subTemp = temp->sublista;
            while (subTemp) {
                cout << " ?? " << subTemp->dato.nombreCancion << endl;
                subTemp = subTemp->siguiente;
            }
            temp = temp->siguiente;
        }
    }

    ~Multilista() {
        while (cabeza) {
            NodoM<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

#endif

