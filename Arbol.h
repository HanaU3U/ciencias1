#ifndef ARBOLB_H
#define ARBOLB_H
#include <iostream>
#include <cmath>
using namespace std;

template <class T>
struct Clave{
    T dato;      // El dato a almacenar
    int valor;   // Índice en la lista original
    bool operator==(const Clave& otra) const {
        return (valor == otra.valor);
    }
};

template <class T>
struct nodos{Clave<T> *claves;
		nodos<T> **hijos;
		int Nclaves;
		bool hoja;
		};
		
template <class T>
class arbolB {nodos<T> *raiz;
		        int d;
		        
	private:
		    // Función auxiliar para eliminar
    	void eliminar(nodos<T>* nodos, int clave);
    
    	// Funciones para manejar los casos de eliminación
    	Clave<T> getPredecesor(nodos<T>* nodos);
    	Clave<T> getSucesor(nodos<T>* nodos);
    	void fusionar(nodos<T>* nodos, int idx);
    	void redistribuirIzquierda(nodos<T>* nodos, int idx);
    	void redistribuirDerecha(nodos<T>* nodos, int idx);
    	void eliminarElemento(nodos<T> *Actual, int pos);
    	
		nodos<T> *crear_nodos();
		Clave<T>  dividir_nodos(nodos<T> *actual, nodos<T> **hermano);
		int InsertarNodoNormal(Clave<T> clave, nodos<T> *Actual);
	    void InsertarNodoLleno(Clave<T> clave, nodos<T> *Actual, nodos<T> *padre);
	    nodos<T> *buscar_padre (int clave, nodos<T> *Actual, nodos<T> *padre);

		
	public: arbolB(int ord){d = ord;
					 raiz = crear_nodos();
					 raiz->Nclaves = 0; raiz-> hoja = true;}
		   void insertar(string clave, T data);
		   void insertar(int clave, T data);
		   	int stringToNumber(string palabra);
	   	    int charToNumber(char c);
		   nodos<T> *buscar_nodos(int clave, nodos<T> *Actual, nodos<T> **padre);
		   T buscar(string clave);
		   T buscar(int clave);
		};	
	
template <class T>
int arbolB<T>::charToNumber(char c) {
    return c - '0';
}
	
template <class T>
int arbolB<T>::stringToNumber(string palabra){
	int total=0;
	for(char i: palabra){
		total+=charToNumber(i);
	}
	return total;
}

	
template <class T>
nodos<T> *arbolB<T>::crear_nodos()
			{
			nodos<T> *nuevo = new nodos<T>();
			 nuevo -> claves= new Clave<T>[2*d-1];
			 nuevo->hijos = new nodos<T>* [2*d];
			 nuevo->Nclaves=0;
			 nuevo->hoja=true;
			 return nuevo;
			}
			
template <class T>
void arbolB<T>:: eliminarElemento(nodos<T> *Actual, int pos) {    
    if (pos < Actual->Nclaves) {
        while (pos < Actual->Nclaves) {
            Actual->claves[pos] = Actual->claves[pos + 1];  // Mover los elementos hacia la izquierda
            pos++;
        }
	Actual->Nclaves --;
	}
}

template <class T>	
nodos<T> *arbolB<T>:: buscar_nodos(int clave, nodos<T> *Actual, nodos<T> **padre)
			{ int i=0;
			 while((i < Actual ->Nclaves) && clave > Actual->claves[i].valor) i++;
			 	
			 if (Actual->hoja)
				{if (Actual==raiz){
					*padre=NULL;
			}
				 return Actual;}
			else if(Actual->claves[i].valor == clave)
				return Actual; 	
			 else  {*padre= Actual;
				 Actual= Actual ->hijos[i];
				 return buscar_nodos(clave, Actual, padre);}
			}

template <class T>
int arbolB<T>::InsertarNodoNormal(Clave<T> clave, nodos<T> *Actual)
			{
			 int i, j;
			 i=Actual->Nclaves;
			 while((i-1)>=0 && clave.valor< Actual->claves[i-1].valor)
				{Actual->claves[i]=Actual->claves[i-1];
				 if (!Actual->hoja) //si el nodos no es una hoja
					Actual->hijos[i+1]=Actual->hijos[i];
				 i--;
				}
			 Actual->claves[i]=clave;
			( Actual->Nclaves)++;
			cout << "Pos en nodo: " << i << endl << "ID: " << clave.valor << endl;
			return i;
			}

template <class T>
void arbolB<T>::InsertarNodoLleno( Clave<T> clave, nodos<T> *Actual, nodos<T> *padre)
			{
				cout << endl<<"NODO LLENO";
			int pos;
			 nodos<T> *nuevo = new nodos<T>();
			 nodos<T> * nivelad=NULL;
			 Clave<T> sube = dividir_nodos(Actual, &nuevo);
			 if(clave.valor < sube.valor)
				{
				InsertarNodoNormal(clave, Actual);	
				 }
			 else {
			 	InsertarNodoNormal(clave, nuevo);
			 }
			 if(Actual != raiz && padre->Nclaves< 2*d-1)
				{
				pos= InsertarNodoNormal(sube, padre);
				 padre->hijos[pos]=Actual;
				 padre->hijos[pos+1]=nuevo;}
			 else{if (Actual==raiz)
					{
					nivelad=crear_nodos();
					 nivelad->hoja = false;
					 nivelad->Nclaves=0;
					 nivelad->hijos[0]= Actual;
					 nivelad->hijos[1]=nuevo;
					 cout << raiz->claves[0].valor << endl;
					 InsertarNodoNormal(sube, nivelad);
					 raiz=nivelad;
					 cout << "RAIZ" <<  raiz->claves[0].valor << endl;
					 }				 
				 else{nivelad=buscar_padre(padre->claves[0].valor, padre, nivelad);
					 InsertarNodoLleno(padre->claves[d-1], padre, nivelad);}
				}
			}
	
template <class T>		
void arbolB<T>::insertar(int valor, T data)
			{
			Clave<T> clave;
			clave.data = data;
			clave.valor = valor;
			nodos<T> *padre= NULL, *Actual=raiz;
			Actual = buscar_nodos( clave.valor, Actual, &padre);
			if (Actual->Nclaves<2*d-1) InsertarNodoNormal(clave, Actual);
			else InsertarNodoLleno(clave, Actual, padre);
			}
	
template <class T>		
void arbolB<T>::insertar(string valor, T data)
			{
			Clave<T> clave;
			clave.dato = data;
			clave.valor = stringToNumber(valor);
			nodos<T> *padre= NULL, *Actual=raiz;
			cout << clave.valor;
			Actual = buscar_nodos( clave.valor, Actual, &padre);
			if (Actual->Nclaves<2*d-1) InsertarNodoNormal(clave, Actual);
			else InsertarNodoLleno(clave, Actual, padre);
			}

template <class T>
Clave<T> arbolB<T>::dividir_nodos(nodos<T> *actual, nodos<T> **hermano)
			{int i;
			nodos<T>* nuevo = crear_nodos();
			 nuevo->hoja=actual->hoja;
			 for(i=0; i<d-1; i++)
				nuevo->claves[i]=actual->claves[i+d];
			 if(!actual->hoja)
				for (i=0; i<d; i++)
					nuevo->hijos[i]=actual->hijos[i+d];
			 nuevo->Nclaves=actual->Nclaves=d-1;
			 *hermano = nuevo;
			 cout << nuevo->claves[0].valor;
			 return actual->claves[d-1];
			}

template <class T>
nodos<T> *arbolB<T>::buscar_padre (int clave, nodos<T> *Actual, nodos<T> *padre)
			{int i=0;
			if(clave == Actual->claves[i].valor)
				return padre;
			 else	{while(i < Actual->Nclaves && clave > Actual->claves[i].valor) i++;
			 if(i<Actual->Nclaves && clave == Actual->claves[i].valor)
				 return padre;
			 else{
				 padre=Actual;
				 Actual= Actual -> hijos[i];
				 return buscar_padre(clave, Actual, padre);
				 }
				}
			}

template <class T>
void arbolB<T>::eliminar(nodos<T>* nodos, int clave) {
    int i = 0;
    while (i < nodos->Nclaves && clave > nodos->claves[i].valor) {
        i++;
    }

    // Caso 1: Clave en una hoja
    if (i < nodos->Nclaves && nodos->claves[i].valor == clave) {
        if (nodos->hoja) {
            for (int j = i; j < nodos->Nclaves - 1; j++) {
                nodos->claves[j] = nodos->claves[j + 1];
            }
            nodos->Nclaves--;
        }
        // Caso 2: Clave en un nodos interno
        else {
            if (nodos->hijos[i + 1]->Nclaves >= d) {
                Clave<T> succ = getSucesor(nodos->hijos[i + 1]);
                nodos->claves[i] = succ;
                eliminar(nodos->hijos[i + 1], succ);
            }
            else if (nodos->hijos[i]->Nclaves >= d) {
                Clave<T> pred = getPredecesor(nodos->hijos[i]);
                nodos->claves[i] = pred;
                eliminar(nodos->hijos[i], pred);
            }
            else {
                fusionar(nodos, i);
                eliminar(nodos->hijos[i], clave);
            }
        }
    }
    else {
        if (nodos->hoja) {
            cout << "Clave no encontrada.\n";
            return;
        }

        bool ultimoHijo = (i == nodos->Nclaves);
        if (nodos->hijos[i]->Nclaves < d) {
            if (i > 0 && nodos->hijos[i - 1]->Nclaves >= d) {
                redistribuirIzquierda(nodos, i);
            }
            else if (i < nodos->Nclaves && nodos->hijos[i + 1]->Nclaves >= d) {
                redistribuirDerecha(nodos, i);
            }
            else {
                fusionar(nodos, i);
            }
        }
        eliminar(nodos->hijos[ultimoHijo ? i - 1 : i], clave);
    }
}

// Obtener el predecesor de una clave
template <class T>
Clave<T> arbolB<T>::getPredecesor(nodos<T>* nodos) {
    while (!nodos->hoja) {
        nodos = nodos->hijos[nodos->Nclaves];
    }
    return nodos->claves[nodos->Nclaves - 1];
}

// Obtener el sucesor de una clave
template <class T>
Clave<T> arbolB<T>::getSucesor(nodos<T>* nodos) {
    while (!nodos->hoja) {
        nodos = nodos->hijos[0];
    }
    return nodos->claves[0];
}

// Fusionar dos nodoss y bajar una clave del padre
template <class T>
void arbolB<T>::fusionar(nodos<T>* nod, int idx) {
	nodos<T>* hijo = nod->hijos[idx]; 
    nodos<T> *hermano = nod->hijos[idx + 1];

    hijo->claves[d - 1] = nod->claves[idx];

    for (int i = 0; i < hermano->Nclaves; i++)
        hijo->claves[i + d] = hermano->claves[i];

    if (!hijo->hoja) {
        for (int i = 0; i <= hermano->Nclaves; i++)
            hijo->hijos[i + d] = hermano->hijos[i];
    }

    for (int i = idx; i < nod->Nclaves - 1; i++)
        nod->claves[i] = nod->claves[i + 1];

    for (int i = idx + 1; i < nod->Nclaves; i++)
        nod->hijos[i] = nod->hijos[i + 1];

    hijo->Nclaves += hermano->Nclaves + 1;
    nod->Nclaves--;

    delete hermano;
}

// Redistribuir una clave del hermano izquierdo
template <class T>
void arbolB<T>::redistribuirIzquierda(nodos<T>* nod, int idx) {
    nodos<T>* hijo = nod->hijos[idx];
    nodos<T>* hermano = nod->hijos[idx - 1];

    for (int i = hijo->Nclaves - 1; i >= 0; i--)
        hijo->claves[i + 1] = hijo->claves[i];

    hijo->claves[0] = nod->claves[idx - 1];
    nod->claves[idx - 1] = hermano->claves[hermano->Nclaves - 1];

    hijo->Nclaves++;
    hermano->Nclaves--;
}

// Redistribuir una clave del hermano derecho
template <class T>
void arbolB<T>::redistribuirDerecha(nodos<T>* nod, int idx) {
    nodos<T>* hijo = nod->hijos[idx];
    nodos<T>* hermano = nod->hijos[idx + 1];

    hijo->claves[hijo->Nclaves] = nod->claves[idx];
    nod->claves[idx] = hermano->claves[0];

    for (int i = 0; i < hermano->Nclaves - 1; i++)
        hermano->claves[i] = hermano->claves[i + 1];

    hijo->Nclaves++;
    hermano->Nclaves--;
}

template <class T>
T arbolB<T>::buscar(string clave){
	int i=0;
	int valor = stringToNumber(clave);
	nodos<T> *padre= NULL, *Actual=raiz;
	Actual = buscar_nodos(valor, Actual, &padre);
	while(i<Actual->Nclaves && Actual->claves[i].valor != valor)
	i++;
	return Actual->claves[i].dato;
}

template <class T>
T arbolB<T>::buscar(int valor){
	int i=0;
	nodos<T> *padre= NULL, *Actual=raiz;
	Actual = buscar_nodos(valor, Actual, &padre);
	while(i<Actual->Nclaves && Actual->claves[i].valor != valor)
	i++;
	
	return Actual->claves[i].dato;
}

#endif
