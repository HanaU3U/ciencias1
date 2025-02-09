#ifndef LISTACABCANCION_H
#define LISTACABCANCION_H

#include "MapaPersonalizado.h"
#include "Album.h"
#include <string>
#include <iostream>

using namespace std;

class ListaCabCancion {
private:
    // Mapa personalizado para almacenar las cabeceras de cada país
    MapaPersonalizado<string, Cancion*> cabeceras;

public:
    // Método para insertar un álbum en la lista correspondiente a su país
    void insertarPaisCancion(Cancion* nuevoCancion) {
        string pais = nuevoCancion->paisGrabacion;

        // Buscar si ya existe una cabecera para este país
        Cancion** cabecera = cabeceras.buscar(pais);

        if (cabecera == NULL) {
            // Si no existe, crear una nueva entrada en el mapa
            cabeceras.insertar(pais, nuevoCancion);
        } else {
            // Si ya existe, enlazar el nuevo álbum al final de la lista
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

        // Buscar si ya existe una cabecera para este género
        Cancion** cabecera = cabeceras.buscar(genero);

        if (cabecera == NULL) {
            // Si no existe, crear una nueva entrada en el mapa
            cabeceras.insertar(genero, nuevaCancion);
        } else {
            // Si ya existe, enlazar la nueva canción al final de la lista
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
            // Si ya existe, enlazar el nuevo álbum al final de la lista
            Cancion* ultimo = *cabecera;
            while (ultimo->sigCompositor != NULL) {
                ultimo = ultimo->sigCompositor;
            }
            ultimo->sigCompositor = nuevoCancion;
        }
    }
    
    // Método para obtener la lista de álbumes de un país específico
    Cancion* obtenerCancionesPorCaract(const string& caract) {
        Cancion** cabecera = cabeceras.buscar(caract);
        if (cabecera !=  NULL) {
            return *cabecera; // Retorna la primera canción de la lista
        }
        return NULL; // Si no hay canciones para ese género
    }
    
    // Método para imprimir todos los álbumes de un país
    void imprimirCancionesPorPais(const string& pais) {
        Cancion* actual = obtenerCancionesPorCaract(pais);
        while (actual != NULL) {
            cout << *actual << endl; // Usa la sobrecarga del operador <<
            actual = actual->sigPais;
        }
    }
    
	// Método para imprimir todos los álbumes de un genero
    void imprimirCancionesPorGenero(const string& genero) {
        Cancion* actual = obtenerCancionesPorCaract(genero);
        while (actual != NULL) {
            cout << *actual << endl; // Usa la sobrecarga del operador <<
            actual = actual->sigGenero;
        }
    }
    
    // Método para imprimir todos los álbumes de un compositorLetra
    void imprimirCancionesPorCompositorLetra(const string& compositorLetra) {
        Cancion* actual = obtenerCancionesPorCaract(compositorLetra);
        while (actual != NULL) {
            cout << *actual << endl; // Usa la sobrecarga del operador <<
            actual = actual->sigCompositor;
        }
    }
    
};

#endif
