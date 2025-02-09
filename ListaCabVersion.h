#ifndef LISTACABVERSION_H
#define LISTACABVERSION_H

#include "MapaPersonalizado.h"
#include "Album.h"
#include <string>
#include <iostream>

using namespace std;

class ListaCabVersion {
private:
    // Mapa personalizado para almacenar las cabeceras de cada TipoVersion
    MapaPersonalizado<string, Version*> cabeceras;

public:
    // Método para insertar una version en la lista correspondiente a su TipoVersion
    void insertarTipoVersion(Version* nuevoVersion) {
        string tipoVer = nuevoVersion->tipoVersion;

        // Buscar si ya existe una cabecera para este TipoVersion
        Version** cabecera = cabeceras.buscar(tipoVer);

        if (cabecera == NULL) {
            // Si no existe, crear una nueva entrada en el mapa
            cabeceras.insertar(tipoVer, nuevoVersion);
        } else {
            // Si ya existe, enlazar la nueva version al final de la lista
            Version* ultimo = *cabecera;
            while (ultimo->sigTipoVersion != NULL) {
                ultimo = ultimo->sigTipoVersion;
            }
            ultimo->sigTipoVersion = nuevoVersion;
        }
    }
    
    // Método para obtener la lista de las versiones de un TipoVersion específico
    Version* obtenerVersionesPorCaract(const string& caract) {
        Version** cabecera = cabeceras.buscar(caract);
        if (cabecera !=  NULL) {
            return *cabecera; // Retorna la primera version de la lista
        }
        return NULL; // Si no hay Versiones para ese TipoVersion
    }
    
    // Método para imprimir todos las versiones de un TipoVersion
    void imprimirVersionesPortipoVer(const string& tipoVer) {
        Version* actual = obtenerVersionesPorCaract(tipoVer);
        while (actual != NULL) {
            cout << *actual << endl; // Usa la sobrecarga del operador <<
            actual = actual->sigTipoVersion;
        }
    }
    
};

#endif
