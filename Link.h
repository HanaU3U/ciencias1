#include <iostream>
#include <string>
#include "FormatearCSV.h"

#ifndef LINK_H
#define LINK_H

using namespace std;


struct Link {
    string nombrePlataforma;
    string link;
    
    Link(string nombrePlataforma, string link)
        : nombrePlataforma(nombrePlataforma), link(link) {}

    Link()
        : nombrePlataforma(""), link("") {}

    string toCSV(const string& clave)  {
        string result = formatearCSV(clave) + ";" 
			+ formatearCSV(nombrePlataforma) + ";" 
			+ formatearCSV(link);
			
		return result;
    }
    
    friend ostream& operator<<(ostream& os, const Link& link) {
        os << "Link: " << link.link;
        return os;
    }
};



#endif
