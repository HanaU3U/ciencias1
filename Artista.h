#include <iostream>
#include <string>
#include "FormatearCSV.h"

#ifndef ARTISTA_H
#define ARTISTA_H


struct Artista {
    string nombreReal;
    string nombreArtistico;
    string paisOrigen;
    string instrumento;
    
    string toCSV() const {
        return formatearCSV(nombreArtistico) + " (" + formatearCSV(instrumento) + ")";
    }
};





#endif
