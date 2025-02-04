#include <iostream>
#include <fstream>
#include "Link.h"
#include "Cancion.h"
#include "Album.h"
#include "Artista.h"
#include "Version.h"
#include <vector>

using namespace std;

// Función para cargar datos desde un archivo
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

// Función para guardar datos en un archivo
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

    // Aquí puedes procesar los datos cargados y convertirlos en estructuras

    // Ejemplo de agregar un nuevo álbum
    Album nuevoAlbum = {
        "Título del Álbum",
        "Nombre Artístico",
        "País de Grabación",
        2023,
        "Cover Art",
        "Fotografía",
        "Editora",
        "Estudio de Grabación",
        {"link1", "link2"},
        {"canción1", "canción2"}
    };
    agregarAlbum(albumes, nuevoAlbum);

    // Guardar datos en archivos al finalizar
    // (Aquí deberías convertir las estructuras de nuevo a texto)
    guardarDatos("albumes.txt", datosAlbumes);
    guardarDatos("canciones.txt", datosCanciones);
    guardarDatos("artistas.txt", datosArtistas);
    guardarDatos("versiones.txt", datosVersiones);
    guardarDatos("links.txt", datosLinks);

    return 0;
}
