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
    Artista* sigInstrumento;
    
    
    Artista(string nombreReal, string nombreArtistico, string paisOrigen, string instrumento)
        : nombreReal(nombreReal), nombreArtistico(nombreArtistico), paisOrigen(paisOrigen),
          instrumento(instrumento), sigInstrumento(NULL) {}
    
    string toCSV() {
        return formatearCSV(nombreReal) + ";" 
             + formatearCSV(nombreArtistico) + ";" 
             + formatearCSV(paisOrigen) + ";" 
             + formatearCSV(instrumento);
    }
    
    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Artista& artista) {
        os << "Nombre: " << artista.nombreReal <<endl;
        return os;
    }
};



#endif
