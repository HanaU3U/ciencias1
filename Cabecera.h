#ifndef CABECERA_H
#define CABECERA_H


template <class T>
struct Cabecera{
	string caract;
	T* cab;
	Cabecera(string caract, string cab)
        : caract(caract), cab(cab) {}
};

#endif
