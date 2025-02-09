#ifndef MAPAPERSONALIZADO_H
#define MAPAPERSONALIZADO_H

#include <string>

using namespace std;

template <typename K, typename V>
struct NodoMapa {
    K clave;
    V valor;
    NodoMapa<K, V>* siguiente;

    NodoMapa(const K& clave, const V& valor)
        : clave(clave), valor(valor), siguiente(NULL) {}
};

template <typename K, typename V>
class MapaPersonalizado {
private:
    NodoMapa<K, V>* cabeza;

public:
    MapaPersonalizado() : cabeza(NULL) {}

    // Insertar un elemento en el mapa
    void insertar(const K& clave, const V& valor) {
        NodoMapa<K, V>* nuevoNodo = new NodoMapa<K, V>(clave, valor);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    // Buscar un elemento en el mapa
    V* buscar(const K& clave) {
        NodoMapa<K, V>* actual = cabeza;
        while (actual != NULL) {
            if (actual->clave == clave) {
                return &(actual->valor);
            }
            actual = actual->siguiente;
        }
        return NULL; // No se encontró la clave
    }

    // Destructor para liberar memoria
    ~MapaPersonalizado() {
        while (cabeza != nullptr) {
            NodoMapa<K, V>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

#endif
