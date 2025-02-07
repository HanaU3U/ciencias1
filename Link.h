#include <iostream>
#include <string>
#include "FormatearCSV.h"
#include "Cancion.h"

#ifndef LINK_H
#define LINK_H

using namespace std;


struct Link {
    string nombrePlataforma;
    string linkAlbum;
    string linkCancion;
    
    Link(string nombrePlataforma, string linkAlbum, string linkCancion)
        : nombrePlataforma(nombrePlataforma), linkAlbum(linkAlbum), linkCancion(linkCancion) {}

    
    string toCSV(const Cancion& can)  {
        string result = formatearCSV(can.nombreCancion) + ";" 
			+ formatearCSV(nombrePlataforma) + ";" 
			+ formatearCSV(linkAlbum)+ ";"
			+ formatearCSV(linkCancion);
			
		return result;
    }
};



#endif
