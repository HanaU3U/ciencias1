#include <iostream>
#include "Artista.h"
#include "Lista.h"
#include "FormatearCSV.h"
#include "Version.h"
#include "Link.h"

#ifndef CANCION_H
#define CANCION_H

struct Cancion {
    string nombreArtistico;
    string nombreCancion;
    string duracion;
    int numArtistasPrincipales;
    string compositorLetra;
    string compositorMusica;
    string arreglosMusicales;
    string ciudadGrabacion;
    string paisGrabacion;
    int anioPrimeraPublicacion;
    string genero;
    int cantPlataformas;
    Cancion* sigGenero;
    Cancion* sigCompositor;
	Cancion* sigPais;
	Cancion* sigPlataforma;
	
    Lista<Artista> listadoArtistas;
    Lista<Version> listadoVersion;
    Lista<Link> listadoLink;
    
    Cancion(string nombreArtistico, string nombreCancion, string duracion, int numArtistasPrincipales,
            string compositorLetra, string compositorMusica, string arreglosMusicales, 
            string ciudadGrabacion, string paisGrabacion, int anioPrimeraPublicacion, string genero)
        : nombreArtistico(nombreArtistico), nombreCancion(nombreCancion), duracion(duracion), 
          numArtistasPrincipales(numArtistasPrincipales), compositorLetra(compositorLetra), 
          compositorMusica(compositorMusica), arreglosMusicales(arreglosMusicales), 
          ciudadGrabacion(ciudadGrabacion), paisGrabacion(paisGrabacion), 
          anioPrimeraPublicacion(anioPrimeraPublicacion), genero(genero),
          sigGenero(NULL), sigCompositor(NULL), sigPais(NULL), cantPlataformas(0) {}
          
    Cancion()
        : nombreArtistico(""), nombreCancion(""), duracion(""), 
          numArtistasPrincipales(0), compositorLetra(""), 
          compositorMusica(""), arreglosMusicales(""), 
          ciudadGrabacion(""), paisGrabacion(""), 
          anioPrimeraPublicacion(0), genero(""),
          sigGenero(NULL), sigCompositor(NULL), sigPais(NULL), cantPlataformas(0) {}      
    
    string toCSV(const string& clave) {
        string result = formatearCSV(clave) + ";"  // Campo "Album"
                      + formatearCSV(nombreCancion) + ";"  // Campo "Nombre"
                      + formatearCSV(duracion) + ";"  // Campo "Duracion"
                      + formatearCSV(genero) + ";"  // Campo "Genero"
                      + formatearCSV(nombreArtistico) + ";"  // Campo "Nombre Artístico"
                      + formatearCSV(compositorLetra) + ";"  // Campo "Compositor Letra"
                      + formatearCSV(compositorMusica) + ";"  // Campo "Compositor Música"
                      + formatearCSV(arreglosMusicales) + ";"  // Campo "Arreglos Musicales"
                      + formatearCSV(ciudadGrabacion) + ";"  // Campo "Ciudad Grabación"
                      + formatearCSV(paisGrabacion) + ";"  // Campo "País Grabación"
                      + formatearCSV(to_string(anioPrimeraPublicacion));  // Campo "Año Publicación"
        return result;
    }
    
    friend ostream& operator<<(ostream& os, const Cancion& cancion) {
        os << "Nombre Cancion: " << cancion.nombreCancion;
        return os;
    }
};



#endif
