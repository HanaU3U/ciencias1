#ifndef LISTA_H
#define LISTA_H

template <class T>
struct nodo {
    nodo<T>* sig;
    T info;

    // Constructor por defecto
    nodo() : sig(NULL), info() {}

    // Constructor con parámetros
    nodo(const T& dato) : sig(NULL), info(dato) {}
};

template <class T>
class Lista {
private:
    nodo<T>* cab;
    int tam;

public:
    Lista() : cab(NULL), tam(0) {}

    // Métodos de la lista...
    bool empty() { return tam == 0; }
    int get_size() { return tam; }
    void insert(T dato);
    void insert_pos(T dato, int pos);
    bool drop(int pos);
    bool edit(int pos, T datonuevo);
    T get(int pos);
    void print();

    struct iterator {
        nodo<T>* actual;

        iterator(nodo<T>* nodoActual) : actual(nodoActual) {}

        T& operator*() { return actual->info; }
        iterator& operator++() { actual = actual->sig; return *this; }
        bool operator!=(const iterator& otro) const { return actual != otro.actual; }
    };

    iterator begin() const { return iterator(cab); }
    iterator end() const { return iterator(nullptr); }
};

template <class T>
void Lista<T>::insert(T dato) {
    nodo<T>* aux = new nodo<T>(dato);
    if (empty()) {
        cab = aux;
    } else {
        nodo<T>* temp = cab;
        while (temp->sig != nullptr) {
            temp = temp->sig;
        }
        temp->sig = aux;
    }
    tam++;
}


template <class T>
void Lista<T>::insert_pos(T dato, int pos)
{
	nodo <T> *aux=new nodo<T>();
	aux->info=dato;
	
	if(pos==1){
		nodo <T> *temp=cab;
		temp=cab;
		
		cab->info=aux->info;
		cab->sig=aux;
		
		
		aux->sig=temp->sig;
		aux->info=temp->info;
		
		tam++;	
		
	}
	else if(pos>tam){
		insertar_final(dato);
	}
	else{
		nodo <T> *temp=cab;
		nodo <T> *ant=NULL;
		for(int i=1; i<pos; i++){
			ant=temp;
			temp=temp->sig;
		}
		aux->sig=temp;
		ant->sig=aux;
		tam++;
	}
	
}


template <class T>
bool Lista<T>::edit(int pos, T datonuevo)
{
	if(pos>tam){
		return false;
	}
	else if(pos==1){
		cab->info=datonuevo;
	}
	else{
		nodo <T> *temp=cab;
		for(int i=1; i<pos; i++){
			temp=temp->sig;
		}
		temp->info=datonuevo;
	}
	return true;
}

template <class T>
bool Lista<T>::drop(int pos)
{
	nodo <T> *actual=cab;
	if(pos>tam){
		return false;
	}
	else if(pos==1){	
		cab=cab->sig;
		delete actual;
	}
	else{
		nodo <T> *anterior=cab;
		for(int i=1; i<pos; i++){
			anterior=actual;
			actual=actual->sig;
		}
		anterior->sig=actual->sig;
		delete actual;
	}
	tam--;
	return true;
}

template <class T>
T Lista<T>::get(int pos)
{
	
	if(pos==1){
		return cab->info;
	}
	else{
		nodo <T> *temp=cab;
		for(int i=1; i<pos; i++){
			temp=temp->sig;
		}
		return temp->info;
	}
}




#endif
