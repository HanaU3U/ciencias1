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

    // M�todo para insertar una nueva cabecera en la lista
    void insertarCabecera(const Cabecera<T>& nuevaCabecera) {
        cabeceras.insert(nuevaCabecera);
    }

    // M�todo para buscar si un texto est� en alguna de las cabeceras
    bool buscarCabecera(const string& texto) {
        for (int i = 0; i < cabeceras.get_size(); i++) {
            if (cabeceras.get(i).coincideCaracteristica(texto)) {
                return true; // Se encontr� una coincidencia
            }
        }
        return false; // No se encontr� coincidencia
    }
};

#endif

