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
    
    Album(string titulo, string nombreArtistico, string paisGrabacion, int anioPublicacion,
          string coverArt, string fotografia, string editora, string estudioGrabacion)
        : titulo(titulo), nombreArtistico(nombreArtistico), paisGrabacion(paisGrabacion),
          anioPublicacion(anioPublicacion), coverArt(coverArt), fotografia(fotografia),
          editora(editora), estudioGrabacion(estudioGrabacion), 
          sigEditora(NULL), sigFotografia(NULL), sigEstudio(NULL), sigPais(NULL) {}
    
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
