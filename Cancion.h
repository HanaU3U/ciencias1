#include <iostream>
#include "Artista.h"
#include "Link.h"
#include "Lista.h"
#include "FormatearCSV.h"
#include "Album.h"

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
    Cancion* sigGenero;
    Cancion* sigCompositor;
	Cancion* sigTipoVersion;
	Cancion* sigPlataforma;
	Cancion* sigPais;
    Lista<Link> listadoLinks;
    Lista<Artista> listadoArtistas;
    Lista<Version> listadoVersion;
    
    
    string toCSV(const Album& alb) {
        string result = formatearCSV(alb.titulo) + ";"  // Campo "Album"
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
};



#endif
