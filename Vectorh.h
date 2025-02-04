#include <iostream>
#include <stdexcept>

using namespace std;

#ifndef VECTORH_H
#define VECTORH_H


// Plantilla de la clase Vector
template <class T>
class Vectorh {
private:
    T* data;         // Puntero al array dinámico
    size_t size;     // Número de elementos en el vector
    size_t capacity; // Capacidad actual del array

    // Función para redimensionar el array
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    // Constructor
    Vectorh() : data(NULL), size(0), capacity(0) {
        resize(1); // Capacidad inicial
    }

    // Destructor
    ~Vectorh() {
        delete[] data;
    }

    // Añadir un elemento al final
    void push_back(const T& value) {
        if (size >= capacity) {
            resize(capacity * 2); // Duplicar la capacidad si es necesario
        }
        data[size++] = value;
    }

    // Eliminar el último elemento
    void pop_back() {
        if (size == 0) {
            throw out_of_range("Vector is empty");
        }
        --size;
    }

    // Obtener el número de elementos
    size_t get_size() const {
        return size;
    }

    // Verificar si el vector está vacío
    bool empty() const {
        return size == 0;
    }

    // Acceder a un elemento por índice
    T& at(size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // Acceder a un elemento por índice (const)
    const T& get(size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // Acceder al primer elemento
    T& front() {
        if (size == 0) {
            throw out_of_range("Vector is empty");
        }
        return data[0];
    }

    // Acceder al último elemento
    T& back() {
        if (size == 0) {
            throw out_of_range("Vector is empty");
        }
        return data[size - 1];
    }

    // Limpiar el vector
    void clear() {
        size = 0;
    }

    // Insertar un elemento en una posición específica
    void insert(size_t index, const T& value) {
        if (index > size) {
            throw out_of_range("Index out of range");
        }
        if (size >= capacity) {
            resize(capacity * 2);
        }
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    // Eliminar un elemento en una posición específica
    void erase(size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    // Redimensionar el vector
    void resize(size_t new_size, const T& value = T()) {
        if (new_size > capacity) {
            resize(new_size);
        }
        if (new_size > size) {
            for (size_t i = size; i < new_size; ++i) {
                data[i] = value;
            }
        }
        size = new_size;
    }

    // Sobrecarga del operador [] para acceso directo
    T& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    T* begin() { return data; }
    T* end() { return data + size; }

    const T* begin() const { return data; }
    const T* end() const { return data + size; }

    // Sobrecarga del operador [] para acceso directo (const)
    const T& operator[](size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // Sobrecarga del operador << para imprimir el vector
    friend ostream& operator<<(ostream& os, const Vectorh<T>& vec) {
        os << "[";
        for (size_t i = 0; i < vec.size; ++i) {
            os << vec.data[i];
            if (i < vec.size - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

#endif


