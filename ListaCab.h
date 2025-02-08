#ifndef LISTACAB_H
#define LISTACAB_H

#include "Lista.h"
#include "Cabecera.h"

template <class T>
class ListaCab {
private:
    Lista<Cabecera<T>> cabeceras;

public:
    // Constructor por defecto
    ListaCab() {}

    // Método para insertar una nueva cabecera en la lista
    void insertarCabecera(const Cabecera<T>& nuevaCabecera) {
        cabeceras.insert(nuevaCabecera);
    }

    // Método para buscar si un texto está en alguna de las cabeceras
    bool buscarCabecera(const string& texto) {
        for (int i = 0; i < cabeceras.get_size(); i++) {
            if (cabeceras.get(i).coincideCaracteristica(texto)) {
                return true; // Se encontró una coincidencia
            }
        }
        return false; // No se encontró coincidencia
    }
};

#endif

