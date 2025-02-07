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
    Album* sigEditora;
    Album* sigFotografia;
    Album* sigEstudio;
    Album* sigPais;
    Lista<Cancion> listadoCanciones;
    
    string toCSV() {
        string result = formatearCSV(titulo) + ";" 
                      + formatearCSV(nombreArtistico) + ";" 
                      + formatearCSV(to_string(anioPublicacion)) + ";" 
                      + formatearCSV(coverArt) + ";" 
                      + formatearCSV(fotografia) + ";" 
                      + formatearCSV(editora) + ";" 
                      + formatearCSV(estudioGrabacion);
        return result;
    }
};

#endif
