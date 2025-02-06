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
    
    string toCSV() {
        return formatearCSV(nombreArtistico) + " (" + formatearCSV(instrumento) + ")";
    }
    
    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Artista& artista) {
        os << "Nombre: " << artista.nombreReal 
           << ", Alias: " << artista.nombreArtistico 
           << ", País: " << artista.paisOrigen 
           << ", Instrumento: " << artista.instrumento;
        return os;
    }
};





#endif
