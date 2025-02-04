#include <iostream>
#include <vector>
#include "Link.h"
#include "Cancion.h"

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
    vector<string> listadoLinks;
    vector<Cancion> listadoCanciones;
};

#endif
