#include <iostream>
#include "Vectorh.h"
#include <string>
#include "Link.h"
#include "FormatearCSV.h"

#ifndef ALBUM_H
#define ALBUM_H



struct Album {
    string titulo;
    string nombreArtistico;
    string paisGrabacion;
    int anioPublicacion;
    string coverArt;
    string fotografia;
    string editora;
    string estudioGrabacion;
    Vectorh<string> listadoLinks;
    Vectorh<Cancion> listadoCanciones;
    
    string toCSV() const {
        string result = formatearCSV(titulo) + ";" + formatearCSV(nombreArtistico) + ";" + 
                        formatearCSV(to_string(anioPublicacion)) + ";" + formatearCSV(paisGrabacion) + ";" + 
                        formatearCSV(editora) + ";" + formatearCSV(estudioGrabacion) + "\n";

        result += "Nombre Canción;Duración;Género;Artistas;Links\n";
        for (size_t i = 0; i < listadoCanciones.get_size(); ++i) {
            result += listadoCanciones[i].toCSV() + "\n";
        }

        result += "Links del álbum;\n";
        for (size_t i = 0; i < listadoLinks.get_size(); ++i) {
            result += listadoLinks[i] + "\n";
        }

        return result;
    }
};

#endif
