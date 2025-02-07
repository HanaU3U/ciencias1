#include <iostream>
#include <string>

#ifndef PARCLAVEVALOR_H
#define PARCLAVEVALOR_H

using namespace std;

template <typename T>
struct ParClaveValor {
    string clave;
    T valor;

    // Constructor por defecto necesario
    ParClaveValor() : clave(""), valor() {}

    // Constructor personalizado
    ParClaveValor(const string& k, const T& v) : clave(k), valor(v) {}
    
    string getClave() {
        return clave;  
    }

    T getValor() {
        return valor;
    }
};


#endif

