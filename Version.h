#include <iostream>
#include <string>
#include "Vectorh.h"
#include "Link.h"
#include "Artista.h"
#include "FormatearCSV.h"

#ifndef VERSION_H
#define VERSION_H



struct Version {
    string tituloVersion;
    string tipoVersion;
    string artistaPrincipal;
    Vectorh<Artista> listadoArtistasPrincipales;
    string ciudadGrabacion;
    string paisGrabacion;
    string genero;
    int anioPublicacion;
    Vectorh<string> listadoLinks;
};



#endif
