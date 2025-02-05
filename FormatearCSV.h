#include <string>
#include <iostream>

#ifndef FORMATEARCSV_H
#define FORMATEARCSV_H

using namespace std;


string formatearCSV(const string& valor) {
    if (valor.find(',') != string::npos || valor.find(';') != string::npos) {
        return "\"" + valor + "\"";  // Se pone entre comillas si hay comas o puntos y comas
    }
    return valor;
}

#endif
