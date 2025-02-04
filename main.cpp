#include <iostream>
#include <fstream>
#include "Link.h"
#include "Cancion.h"
#include "Album.h"
#include "Artista.h"
#include "Version.h"
#include <vector>

using namespace std;

// Funci�n para cargar datos desde un archivo
vector<string> cargarDatos(const string& nombreArchivo) {
    vector<string> datos;
    ifstream archivo(nombreArchivo);
    string linea;
    while (getline(archivo, linea)) {
        datos.push_back(linea);
    }
    archivo.close();
    return datos;
}

// Funci�n para guardar datos en un archivo
void guardarDatos(const string& nombreArchivo, const vector<string>& datos) {
    ofstream archivo(nombreArchivo);
    for (const string& linea : datos) {
        archivo << linea << endl;
    }
    archivo.close();
}

int main() {
    vector<Album> albumes;
    vector<Cancion> canciones;
    vector<Artista> artistas;
    vector<Version> versiones;
    vector<Link> links;

    // Cargar datos desde archivos
    vector<string> datosAlbumes = cargarDatos("albumes.txt");
    vector<string> datosCanciones = cargarDatos("canciones.txt");
    vector<string> datosArtistas = cargarDatos("artistas.txt");
    vector<string> datosVersiones = cargarDatos("versiones.txt");
    vector<string> datosLinks = cargarDatos("links.txt");

    // Aqu� puedes procesar los datos cargados y convertirlos en estructuras

    // Ejemplo de agregar un nuevo �lbum
    Album nuevoAlbum = {
        "T�tulo del �lbum",
        "Nombre Art�stico",
        "Pa�s de Grabaci�n",
        2023,
        "Cover Art",
        "Fotograf�a",
        "Editora",
        "Estudio de Grabaci�n",
        {"link1", "link2"},
        {"canci�n1", "canci�n2"}
    };
    agregarAlbum(albumes, nuevoAlbum);

    // Guardar datos en archivos al finalizar
    // (Aqu� deber�as convertir las estructuras de nuevo a texto)
    guardarDatos("albumes.txt", datosAlbumes);
    guardarDatos("canciones.txt", datosCanciones);
    guardarDatos("artistas.txt", datosArtistas);
    guardarDatos("versiones.txt", datosVersiones);
    guardarDatos("links.txt", datosLinks);

    return 0;
}
