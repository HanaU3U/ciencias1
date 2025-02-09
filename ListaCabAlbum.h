#ifndef LISTACABALBUM_H
#define LISTACABALBUM_H

#include "MapaPersonalizado.h"
#include "Album.h"
#include <string>
#include <iostream>

using namespace std;

class ListaCabAlbum {
private:
    // Mapa personalizado para almacenar las cabeceras
    MapaPersonalizado<string, Album*> cabeceras;

public:
    // M�todo para insertar un �lbum en la lista correspondiente a su pa�s
    void insertarPaisAlbum(Album* nuevoAlbum) {
        string pais = nuevoAlbum->paisGrabacion;

        // Buscar si ya existe una cabecera para este pa�s
        Album** cabecera = cabeceras.buscar(pais);

        if (cabecera == NULL) {
            // Si no existe, crear una nueva entrada en el mapa
            cabeceras.insertar(pais, nuevoAlbum);
        } else {
            // Si ya existe, enlazar el nuevo �lbum al final de la lista
            Album* ultimo = *cabecera;
            while (ultimo->sigPais != NULL) {
                ultimo = ultimo->sigPais;
            }
            ultimo->sigPais = nuevoAlbum;
        }
    }
    
    void insertarFotografoAlbum(Album* nuevoAlbum) {
        string fotografo = nuevoAlbum->fotografia;

        // Buscar si ya existe una cabecera para este fotografo
        Album** cabecera = cabeceras.buscar(fotografo);

        if (cabecera == NULL) {
            // Si no existe, crear una nueva entrada en el mapa
            cabeceras.insertar(fotografo, nuevoAlbum);
        } else {
            // Si ya existe, enlazar el nuevo �lbum al final de la lista
            Album* ultimo = *cabecera;
            while (ultimo->sigFotografia != NULL) {
                ultimo = ultimo->sigFotografia;
            }
            ultimo->sigFotografia = nuevoAlbum;
        }
    }
    
    void insertarEditoraAlbum(Album* nuevoAlbum) {
        string editora = nuevoAlbum->editora;

        // Buscar si ya existe una cabecera para este editor
        Album** cabecera = cabeceras.buscar(editora);

        if (cabecera == NULL) {
            // Si no existe, crear una nueva entrada en el mapa
            cabeceras.insertar(editora, nuevoAlbum);
        } else {
            // Si ya existe, enlazar el nuevo �lbum al final de la lista
            Album* ultimo = *cabecera;
            while (ultimo->sigEditora != NULL) {
                ultimo = ultimo->sigEditora;
            }
            ultimo->sigEditora = nuevoAlbum;
        }
    }
    
    void insertarEstudioAlbum(Album* nuevoAlbum) {
        string estudio = nuevoAlbum->estudioGrabacion;

        // Buscar si ya existe una cabecera para este estudio
        Album** cabecera = cabeceras.buscar(estudio);

        if (cabecera == NULL) {
            // Si no existe, crear una nueva entrada en el mapa
            cabeceras.insertar(estudio, nuevoAlbum);
        } else {
            // Si ya existe, enlazar el nuevo �lbum al final de la lista
            Album* ultimo = *cabecera;
            while (ultimo->sigEstudio != NULL) {
                ultimo = ultimo->sigEstudio;
            }
            ultimo->sigEstudio = nuevoAlbum;
        }
    }

    // M�todo para obtener la lista de �lbumes de una caracteristica espec�fica
    Album* obtenerAlbumesPorCaract(const string& caract) {
        Album** cabecera = cabeceras.buscar(caract);
        if (cabecera != NULL) {
            return *cabecera; // Retorna el primer �lbum de la lista
        }
        return NULL; // Si no hay �lbumes para ese pa�s
    }
    
    // M�todo para imprimir todos los �lbumes de un pa�s
    void imprimirAlbumesPorPais(const string& pais) {
        Album* actual = obtenerAlbumesPorCaract(pais);
        while (actual != NULL) {
            cout << *actual << endl; // Usa la sobrecarga del operador <<
            actual = actual->sigPais;
        }
    }
    
	// M�todo para imprimir todos los �lbumes de un fotografo
    void imprimirAlbumesPorFotografo(const string& fotografo) {
        Album* actual = obtenerAlbumesPorCaract(fotografo);
        while (actual != NULL) {
            cout << *actual << endl; // Usa la sobrecarga del operador <<
            actual = actual->sigFotografia;
        }
    }
    
	// M�todo para imprimir todos los �lbumes de un estudio
    void imprimirAlbumesPorEstudio(const string& estudio) {
        Album* actual = obtenerAlbumesPorCaract(estudio);
        while (actual != NULL) {
            cout << *actual << endl; // Usa la sobrecarga del operador <<
            actual = actual->sigEstudio;
        }
    }
    
    // M�todo para imprimir todos los �lbumes de un editora
    void imprimirAlbumesPorEditora(const string& editora) {
        Album* actual = obtenerAlbumesPorCaract(editora);
        while (actual != NULL) {
            cout << *actual << endl; // Usa la sobrecarga del operador <<
            actual = actual->sigEditora;
        }
    }
    
};

#endif
