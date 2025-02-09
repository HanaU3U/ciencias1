#ifndef LISTACABCANCION_H
#define LISTACABCANCION_H

#include "MapaPersonalizado.h"
#include "Album.h"
#include <string>
#include <iostream>

using namespace std;

class ListaCabCancion {
private:
    // Mapa personalizado para almacenar las cabeceras de cada pa�s
    MapaPersonalizado<string, Cancion*> cabeceras;

public:
    // M�todo para insertar un �lbum en la lista correspondiente a su pa�s
    void insertarPaisCancion(Cancion* nuevoCancion) {
        string pais = nuevoCancion->paisGrabacion;

        // Buscar si ya existe una cabecera para este pa�s
        Cancion** cabecera = cabeceras.buscar(pais);

        if (cabecera == NULL) {
            // Si no existe, crear una nueva entrada en el mapa
            cabeceras.insertar(pais, nuevoCancion);
        } else {
            // Si ya existe, enlazar el nuevo �lbum al final de la lista
            Cancion* ultimo = *cabecera;
            while (ultimo->sigPais != NULL) {
                ultimo = ultimo->sigPais;
            }
            ultimo->sigPais = nuevoCancion;
        }
    }
    
    void insertarGeneroCancion(Cancion* nuevaCancion) {
        string genero = nuevaCancion->genero;
        //cout<<"genero "<<nuevaCancion->genero<<endl;

        // Buscar si ya existe una cabecera para este g�nero
        Cancion** cabecera = cabeceras.buscar(genero);

        if (cabecera == NULL) {
            // Si no existe, crear una nueva entrada en el mapa
            cabeceras.insertar(genero, nuevaCancion);
        } else {
            // Si ya existe, enlazar la nueva canci�n al final de la lista
            Cancion* ultima = *cabecera;
            while (ultima->sigGenero != nullptr) {
                ultima = ultima->sigGenero;
            }
            ultima->sigGenero = nuevaCancion;
        }
    }
    
    void insertarCompositorCancion(Cancion* nuevoCancion) {
        string compositor = nuevoCancion->compositorLetra;

        // Buscar si ya existe una cabecera para este compositor
        Cancion** cabecera = cabeceras.buscar(compositor);

        if (cabecera == NULL) {
            // Si no existe, crear una nueva entrada en el mapa
            cabeceras.insertar(compositor, nuevoCancion);
        } else {
            // Si ya existe, enlazar el nuevo �lbum al final de la lista
            Cancion* ultimo = *cabecera;
            while (ultimo->sigCompositor != NULL) {
                ultimo = ultimo->sigCompositor;
            }
            ultimo->sigCompositor = nuevoCancion;
        }
    }
    
    // M�todo para obtener la lista de �lbumes de un pa�s espec�fico
    Cancion* obtenerCancionesPorCaract(const string& caract) {
        Cancion** cabecera = cabeceras.buscar(caract);
        if (cabecera !=  NULL) {
            return *cabecera; // Retorna la primera canci�n de la lista
        }
        return NULL; // Si no hay canciones para ese g�nero
    }
    
    // M�todo para imprimir todos los �lbumes de un pa�s
    void imprimirCancionesPorPais(const string& pais) {
        Cancion* actual = obtenerCancionesPorCaract(pais);
        while (actual != NULL) {
            cout << *actual << endl; // Usa la sobrecarga del operador <<
            actual = actual->sigPais;
        }
    }
    
	// M�todo para imprimir todos los �lbumes de un genero
    void imprimirCancionesPorGenero(const string& genero) {
        Cancion* actual = obtenerCancionesPorCaract(genero);
        while (actual != NULL) {
            cout << *actual << endl; // Usa la sobrecarga del operador <<
            actual = actual->sigGenero;
        }
    }
    
    // M�todo para imprimir todos los �lbumes de un compositorLetra
    void imprimirCancionesPorCompositorLetra(const string& compositorLetra) {
        Cancion* actual = obtenerCancionesPorCaract(compositorLetra);
        while (actual != NULL) {
            cout << *actual << endl; // Usa la sobrecarga del operador <<
            actual = actual->sigCompositor;
        }
    }
    
};

#endif
