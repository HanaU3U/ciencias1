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
    
    string toCSV() const {
        return formatearCSV(nombrePlataforma) + ";" + formatearCSV(linkCancion);
    }
};



#endif
