#include <iostream>
#include <string>
#include "Lista.h"
#include "Link.h"
#include "Artista.h"
#include "FormatearCSV.h"

#ifndef VERSION_H
#define VERSION_H



struct Version {
    string tituloVersion;
    string tipoVersion;
    string artistaPrincipal;
    Lista<Artista> listadoArtistasPrincipales;
    string ciudadGrabacion;
    string paisGrabacion;
    string genero;
    int anioPublicacion;
    Lista<string> listadoLinks;
};



#endif
