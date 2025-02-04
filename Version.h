#include <iostream>
#include "Link.h"
#include "Artista.h"

#ifndef VERSION_H
#define VERSION_H


struct Version {
    string tituloVersion;
    string tipoVersion;
    string artistaPrincipal;
    vector<Artista> listadoArtistasPrincipales;
    string ciudadGrabacion;
    string paisGrabacion;
    string genero;
    int anioPublicacion;
    vector<string> listadoLinks;
};

#endif
