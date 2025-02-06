#ifndef NodoCP_H     
#define NodoCP_H  

template <class T>
struct NodoCP {
    T info;
    NodoCP<T>* sig;
};

#endif
