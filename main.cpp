#include <iostream>
#include <fstream>
#include <string>
#include "Link.h"
#include "Cancion.h"
#include "Album.h"
#include "Artista.h"
#include "Version.h"
#include "Vectorh.h"

using namespace std;



// Funci�n para cargar datos desde un archivo
Vectorh<string> cargarDatos(const string& nombreArchivo) {
    Vectorh<string> datos;
    ifstream archivo(nombreArchivo.c_str()); // Convertir string a const char*
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return datos; // Retorna un vector vac�o si no se puede abrir el archivo
    }

    string linea;
    while (getline(archivo, linea)) {
        datos.push_back(linea);
    }
    archivo.close();
    return datos;
}

// Funci�n para guardar datos en un archivo
void guardarDatos(const string& nombreArchivo, const Vectorh<string>& datos) {
    ofstream archivo(nombreArchivo.c_str()); // Convertir string a const char*
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return; // Sale de la funci�n si no se puede abrir el archivo
    }

    for (const string& linea : datos) {
        archivo << linea << endl;
    }
    archivo.close();
}

int main() {
    Vectorh<Album> albumes;
    Vectorh<Cancion> canciones;
    Vectorh<Artista> artistas;
    Vectorh<Version> versiones;
    Vectorh<Link> links;

    // Cargar datos desde archivos
    Vectorh<string> datosAlbumes = cargarDatos("albumes.txt");
    Vectorh<string> datosCanciones = cargarDatos("canciones.txt");
    Vectorh<string> datosArtistas = cargarDatos("artistas.txt");
    Vectorh<string> datosVersiones = cargarDatos("versiones.txt");
    Vectorh<string> datosLinks = cargarDatos("links.txt");

    // Aqu� puedes procesar los datos cargados y convertirlos en estructuras

    // Creaci�n de artistas
    Artista artista1 = {"Juan P�rez", "JP", "M�xico", "Guitarra"};
    Artista artista2 = {"Ana L�pez", "Anita", "Espa�a", "Voz"};
    Artista artista3 = {"Carlos G�mez", "Charlie", "Argentina", "Bater�a"};

    // Creaci�n de canciones
    Cancion cancion1 = {
        "JP", "Caminos del Alma", "3:45", 
        Vectorh<Artista>(), 1, 
        "Juan P�rez", "Juan P�rez", "JP & Band", 
        "Ciudad de M�xico", "M�xico", 2023, "Rock", 
        Vectorh<Link>()
    };
    cancion1.listadoArtistas.push_back(artista1);
    cancion1.listadoLinks.push_back({"Spotify", "https://spotify.com/album123", "https://spotify.com/track1"});

    Cancion cancion2 = {
        "Anita", "Vuela Alto", "4:10", 
        Vectorh<Artista>(), 1, 
        "Ana L�pez", "Ana L�pez", "Anita & Co.", 
        "Madrid", "Espa�a", 2023, "Pop", 
        Vectorh<Link>()
    };
    cancion2.listadoArtistas.push_back(artista2);
    cancion2.listadoLinks.push_back({"YouTube", "https://youtube.com/album123", "https://youtube.com/track2"});

    Cancion cancion3 = {
        "Charlie", "Ritmo Salvaje", "5:02", 
        Vectorh<Artista>(), 1, 
        "Carlos G�mez", "Carlos G�mez", "Charlie & The Beats", 
        "Buenos Aires", "Argentina", 2023, "Jazz", 
        Vectorh<Link>()
    };
    cancion3.listadoArtistas.push_back(artista3);
    cancion3.listadoLinks.push_back({"Apple Music", "https://apple.com/album123", "https://apple.com/track3"});

    // Creaci�n del �lbum
    Album album = {
        "Colores del Mundo", "Varios Artistas", "Latinoam�rica", 2023,
        "cover.jpg", "fotografia.jpg", "Universal Music", "Estudios Latam",
        Vectorh<string>(), Vectorh<Cancion>()
    };

    album.listadoCanciones.push_back(cancion1);
    album.listadoCanciones.push_back(cancion2);
    album.listadoCanciones.push_back(cancion3);
    album.listadoLinks.push_back("https://spotify.com/album123");
    
    datosAlbumes.push_back(album.toCSV());
    

    // Guardar datos en archivos al finalizar
    // (Aqu� deber�as convertir las estructuras de nuevo a texto)
    guardarDatos("albumes.txt", datosAlbumes);
    guardarDatos("canciones.txt", datosCanciones);
    guardarDatos("artistas.txt", datosArtistas);
    guardarDatos("versiones.txt", datosVersiones);
    guardarDatos("links.txt", datosLinks);

    return 0;
}
