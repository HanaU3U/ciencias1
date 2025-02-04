#include <iostream>
#include "Artista.h"
#include "Link.h"
#include "Vectorh.h"

#ifndef CANCION_H
#define CANCION_H



struct Cancion {
    string nombreArtistico;
    string nombreCancion;
    string duracion;
    Vectorh<Artista> listadoArtistas;
    int numArtistasPrincipales;
    string compositorLetra;
    string compositorMusica;
    string arreglosMusicales;
    string ciudadGrabacion;
    string paisGrabacion;
    int anioPrimeraPublicacion;
    string genero;
    Vectorh<Link> listadoLinks;
};

#endif
