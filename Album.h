#include <iostream>
#include "Lista.h"
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
    Lista<string> listadoLinks;
    Lista<Cancion> listadoCanciones;
    
    string toCSV(){
        string result = formatearCSV(titulo) + ";" + formatearCSV(nombreArtistico) + ";" + 
                        formatearCSV(to_string(anioPublicacion)) + ";" + formatearCSV(paisGrabacion) + ";" + 
                        formatearCSV(editora) + ";" + formatearCSV(estudioGrabacion) + "\n";

        result += "Nombre Canción;Duración;Género;Artistas;Links\n";
        for (int i = 0; i < listadoCanciones.get_size(); ++i) {
            result += listadoCanciones.get(i).toCSV() + "\n";
        }

        result += "Links del álbum;\n";
        for (int i = 0; i < listadoLinks.get_size(); ++i) {
            result += listadoLinks.get(i) + "\n";
        }

        return result;
    }
};

#endif
