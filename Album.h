#include <iostream>
#include "Vectorh.h"
#include <string>
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
    Vectorh<string> listadoLinks;
    Vectorh<Cancion> listadoCanciones;
};

#endif
