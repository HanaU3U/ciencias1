#include <iostream>
#include <string>
#include "Lista.h"
#include "CharStrToNumber.h"

#ifndef MAPCUSTOM_H
#define MAPCUSTOM_H


using namespace std;


template <typename T>
class MapCustom {
private:
    // Tamaño inicial de la tabla hash
    static int TAMANO_INICIAL = 10;

    // Estructura para almacenar los pares clave-valor
    struct ParClaveValor {
        string clave;
        T valor;
        ParClaveValor(const string& k, const T& v) : clave(k), valor(v) {}
    };

    // Tabla hash: un arreglo de Listas para manejar colisiones
    Lista<ParClaveValor> tabla[TAMANO_INICIAL];

    // Función hash para convertir una clave en un índice
    int index(const string& clave) const {
	    return stringToNumber(clave) % TAMANO_INICIAL;
	}

public:
    // Constructor
    MapCustom() {}

    // Función para insertar un elemento en el mapa
    void insertar(const string& clave, const T& valor) {
        int indice = index(clave);
        for (auto& par : tabla[indice]) {
            if (par.clave == clave) {
                par.valor = valor; // Actualizar valor si la clave ya existe
                return;
            }
        }
        tabla[indice].insert(ParClaveValor(clave, valor)); // Insertar nuevo par
    }

    // Función para obtener el valor asociado a una clave
    T obtener(const string& clave) const {
        int indice = index(clave);
        for (const auto& par : tabla[indice]) {
            if (par.clave == clave) {
                return par.valor; // Devolver valor si la clave existe
            }
        }
        cout<<"Clave no encontrada en el mapa"<<endl;
        return 0;
    }

    // Función para verificar si una clave existe en el mapa
    bool existe(const string& clave) const {
        int indice = index(clave);
        for (const auto& par : tabla[indice]) {
            if (par.clave == clave) {
                return true;
            }
        }
        return false;
    }

    // Función para eliminar un elemento del mapa
    void eliminar(const string& clave) {
        int indice = index(clave);
        auto& lista = tabla[indice];
        int pos = 0;
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if ((*it).clave == clave) {
                lista.drop(pos + 1); // Eliminar nodo si la clave existe
                return;
            }
            pos++;
        }
    }

    // Función para obtener el tamaño del mapa
    int tamanio() const {
        int count = 0;
        for (int i = 0; i < TAMANO_INICIAL; i++) {
            count += tabla[i].get_size();
        }
        return count;
    }

    // Función para imprimir todos los elementos del mapa
    void imprimir() const {
        for (int i = 0; i < TAMANO_INICIAL; i++) {
            for (const auto& par : tabla[i]) {
                cout << par.clave << ": " << par.valor << endl;
            }
        }
    }
};


#endif
