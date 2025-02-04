#include <iostream>
#include "Artista.h"
#include "Link.h"
#include "Version.h"

#ifndef CANCION_H
#define CANCION_H



struct Cancion {
    string nombreArtistico;
    string nombreCancion;
    string duracion;
    vector<Artista> listadoArtistas;
    int numArtistasPrincipales;
    string compositorLetra;
    string compositorMusica;
    string arreglosMusicales;
    string ciudadGrabacion;
    string paisGrabacion;
    int anioPrimeraPublicacion;
    string genero;
    vector<Link> listadoLinks;
    vector<Version> listadoVersiones;
};

#endif
