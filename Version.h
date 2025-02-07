#include <iostream>
#include <string>
#include "Lista.h"
#include "Link.h"
#include "Artista.h"
#include "FormatearCSV.h"
#include "Cancion.h"

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
    
    string toCSV(const Cancion& can) {
        string result = formatearCSV(can.nombreCancion) + ";"
                      + formatearCSV(tituloVersion) + ";" 
                      + formatearCSV(artistaPrincipal) + ";"  
                      + formatearCSV(nombreArtistico) + ";" 
                      + formatearCSV(ciudadGrabacion) + ";"  
                      + formatearCSV(paisGrabacion) + ";"  
                      + formatearCSV(genero) + ";"  
                      + formatearCSV(to_string(anioPublicacion));  
        return result;
    }
};



#endif
