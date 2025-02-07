#include <iostream>
#include <string>
#include "Lista.h"
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
    
    Version(string tituloVersion, string tipoVersion, string artistaPrincipal, 
            string ciudadGrabacion, string paisGrabacion, string genero, int anioPublicacion)
        : tituloVersion(tituloVersion), tipoVersion(tipoVersion), artistaPrincipal(artistaPrincipal),
          ciudadGrabacion(ciudadGrabacion), paisGrabacion(paisGrabacion),
          genero(genero), anioPublicacion(anioPublicacion) {}

	Version()
        : tituloVersion(""), tipoVersion(""), artistaPrincipal(""),
          ciudadGrabacion(""), paisGrabacion(""),
          genero(""), anioPublicacion(0) {}
		      
    string toCSV(const string& clave) {
        string result = formatearCSV(clave) + ";"
                      + formatearCSV(tituloVersion) + ";" 
                      + formatearCSV(artistaPrincipal) + ";"  
                      + formatearCSV(ciudadGrabacion) + ";"  
                      + formatearCSV(paisGrabacion) + ";"  
                      + formatearCSV(genero) + ";"  
                      + formatearCSV(to_string(anioPublicacion));  
        return result;
    }
};



#endif
