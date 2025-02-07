#include <iostream>
#include <string>
#include "FormatearCSV.h"

#ifndef LINK_H
#define LINK_H

using namespace std;


struct Link {
    string nombrePlataforma;
    string linkAlbum;
    string linkCancion;
    
    Link(string nombrePlataforma, string linkAlbum, string linkCancion)
        : nombrePlataforma(nombrePlataforma), linkAlbum(linkAlbum), linkCancion(linkCancion) {}

    Link()
        : nombrePlataforma(""), linkAlbum(""), linkCancion("") {}

    string toCSV(const string& clave)  {
        string result = formatearCSV(clave) + ";" 
			+ formatearCSV(nombrePlataforma) + ";" 
			+ formatearCSV(linkAlbum)+ ";"
			+ formatearCSV(linkCancion);
			
		return result;
    }
};



#endif
