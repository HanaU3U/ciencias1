#include <iostream>
#include "Artista.h"
#include "Link.h"
#include "Lista.h"
#include "FormatearCSV.h"

#ifndef CANCION_H
#define CANCION_H

struct Cancion {
    string nombreArtistico;
    string nombreCancion;
    string duracion;
    Lista<Artista> listadoArtistas;
    int numArtistasPrincipales;
    string compositorLetra;
    string compositorMusica;
    string arreglosMusicales;
    string ciudadGrabacion;
    string paisGrabacion;
    int anioPrimeraPublicacion;
    string genero;
    Lista<Link> listadoLinks;
    
    string toCSV() {
        string result = formatearCSV(nombreCancion) + ";" + formatearCSV(duracion) + ";" + formatearCSV(genero) + ";";
        
        // Lista de artistas
        for (size_t i = 0; i < listadoArtistas.get_size(); ++i) {
            result += listadoArtistas.get(i).toCSV();
            if (i < listadoArtistas.get_size() - 1) result += ",";
        }
        result += ";";

        // Lista de links
        for (size_t i = 0; i < listadoLinks.get_size(); ++i) {
            result += listadoLinks.get(i).toCSV();
            if (i < listadoLinks.get_size() - 1) result += ",";
        }

        return result;
    }
};



#endif
