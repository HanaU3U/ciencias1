#include <iostream>
#include <fstream>
#include <string>
#include "Link.h"
#include "Cancion.h"
#include "Album.h"
#include "Artista.h"
#include "Version.h"
#include "Lista.h"

using namespace std;



// Funci�n para cargar datos desde un archivo
Lista<string> cargarDatos(const string& nombreArchivo) {
    Lista<string> datos;
    ifstream archivo(nombreArchivo.c_str()); // Convertir string a const char*
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return datos; // Retorna un vector vac�o si no se puede abrir el archivo
    }

    string linea;
    while (getline(archivo, linea)) {
        datos.insert(linea);
    }
    archivo.close();
    return datos;
}

// Funci�n para guardar datos en un archivo
void guardarDatos(const string& nombreArchivo, const Lista<string>& datos) {
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
    Lista<Album> albumes;
    Lista<Cancion> canciones;
    Lista<Artista> artistas;
    Lista<Version> versiones;
    Lista<Link> links;

    // Cargar datos desde archivos
    Lista<string> datosAlbumes = cargarDatos("albumes.txt");
    Lista<string> datosCanciones = cargarDatos("canciones.txt");
    Lista<string> datosArtistas = cargarDatos("artistas.txt");
    Lista<string> datosVersiones = cargarDatos("versiones.txt");
    Lista<string> datosLinks = cargarDatos("links.txt");

    // Aqu� puedes procesar los datos cargados y convertirlos en estructuras

    // Creaci�n de artistas
    Artista artista1 = {"Juan P�rez", "JP", "M�xico", "Guitarra"};
    Artista artista2 = {"Ana L�pez", "Anita", "Espa�a", "Voz"};
    Artista artista3 = {"Carlos G�mez", "Charlie", "Argentina", "Bater�a"};
    
    datosArtistas.insert(artista1.toCSV());
    datosArtistas.insert(artista2.toCSV());
    datosArtistas.insert(artista3.toCSV());

    // Creaci�n de canciones
    Cancion cancion1 = {
        "JP", "Caminos del Alma", "3:45", 
        Lista<Artista>(), 1, 
        "Juan P�rez", "Juan P�rez", "JP & Band", 
        "Ciudad de M�xico", "M�xico", 2023, "Rock", 
        Lista<Link>()
    };
    cancion1.listadoArtistas.insert(artista1);
    cancion1.listadoLinks.insert({"Spotify", "https://spotify.com/album123", "https://spotify.com/track1"});

    Cancion cancion2 = {
        "Anita", "Vuela Alto", "4:10", 
        Lista<Artista>(), 1, 
        "Ana L�pez", "Ana L�pez", "Anita & Co.", 
        "Madrid", "Espa�a", 2023, "Pop", 
        Lista<Link>()
    };
    cancion2.listadoArtistas.insert(artista2);
    cancion2.listadoLinks.insert({"YouTube", "https://youtube.com/album123", "https://youtube.com/track2"});

    Cancion cancion3 = {
        "Charlie", "Ritmo Salvaje", "5:02", 
        Lista<Artista>(), 1, 
        "Carlos G�mez", "Carlos G�mez", "Charlie & The Beats", 
        "Buenos Aires", "Argentina", 2023, "Jazz", 
        Lista<Link>()
    };
    cancion3.listadoArtistas.insert(artista3);
    cancion3.listadoLinks.insert({"Apple Music", "https://apple.com/album123", "https://apple.com/track3"});
    
    datosCanciones.insert(cancion1.toCSV());
    datosCanciones.insert(cancion2.toCSV());
    datosCanciones.insert(cancion3.toCSV());

    // Creaci�n del �lbum
    Album album = {
        "Colores del Mundo", "Varios Artistas", "Latinoam�rica", 2023,
        "cover.jpg", "fotografia.jpg", "Universal Music", "Estudios Latam",
        Lista<string>(), Lista<Cancion>()
    };

    album.listadoCanciones.insert(cancion1);
    album.listadoCanciones.insert(cancion2);
    album.listadoCanciones.insert(cancion3);
    album.listadoLinks.insert("https://spotify.com/album123");
    
    datosAlbumes.insert(album.toCSV());
    

    // Guardar datos en archivos al finalizar
    // (Aqu� deber�as convertir las estructuras de nuevo a texto)
    guardarDatos("albumes.txt", datosAlbumes);
    guardarDatos("canciones.txt", datosCanciones);
    guardarDatos("artistas.txt", datosArtistas);
    guardarDatos("versiones.txt", datosVersiones);
    guardarDatos("links.txt", datosLinks);

    return 0;
}
