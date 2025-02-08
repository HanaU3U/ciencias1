#ifndef CABECERA_H
#define CABECERA_H


template <class T>
struct Cabecera{
	string caract;
	T* cab;
	T* ult;
	Cabecera(string caract, T* cab, T* ult)
        : caract(caract), cab(cab), ult(ult) {}
    
    Cabecera()
        : caract(""), cab(NULL), ult(NULL) {}
        
    bool coincideCaracteristica(const string& texto) const {
	    return caract.find(texto) != string::npos;
	}
};
#endif
