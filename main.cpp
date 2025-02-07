#include <iostream>
#include <fstream>
#include <string>
#include "Link.h"
#include "Cancion.h"
#include "Album.h"
#include "Artista.h"
#include "Version.h"
#include "Lista.h"
#include "Cabecera.h"
#include "ArbolAVL.h"


using namespace std;

int charToNumber(char c) {
    return c - '0';
}

int stringToNumber(string palabra){
	int total=0;
	for(char i: palabra){
		cout<<i<<" "<<charToNumber(i)<<endl;
		total+=charToNumber(i);
	}
	return total;
}

// Función para cargar datos desde un archivo
Lista<string> cargarDatos(const string& nombreArchivo) {
    Lista<string> datos;
    ifstream archivo(nombreArchivo.c_str()); // Convertir string a const char*
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return datos; // Retorna un vector vacío si no se puede abrir el archivo
    }

    string linea;
    while (getline(archivo, linea)) {
        datos.insert(linea);
    }
    archivo.close();
    return datos;
}

// Función para guardar datos en un archivo
void guardarDatos(const string& nombreArchivo, const Lista<string>& datos) {
    ofstream archivo(nombreArchivo.c_str()); // Convertir string a const char*
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return; // Sale de la función si no se puede abrir el archivo
    }

    for (const string& linea : datos) {
        archivo << linea << endl;
    }
    archivo.close();
}

Lista<Cabecera> editora;
Lista<Cabecera> fotografia;
Lista<Cabecera> estudio;
Lista<Cabecera> pais_album;
Lista<Cabecera> pais_can;
Lista<Cabecera> genero;
Lista<Cabecera> compositor;
Lista<Cabecera> tipo_version;
Lista<Cabecera> plataforma;
Lista<Cabecera> instrumento;

/*
int main() {
    ArbolAVL<int> arbol;
    Cola<int> cola;
    
    // Insertar elementos en el árbol
    arbol.insertar(10, 10);
    arbol.insertar(20, 20);
    arbol.insertar(30, 30);
    arbol.insertar(40, 40);
    arbol.insertar(50, 50);
    arbol.insertar(25, 25);

    // Imprimir recorrido In-Order
    cout << "Recorrido In-Order: ";
    arbol.inOrderIterativo(cola);
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;

    // Imprimir recorrido Pre-Order
    cout << "Recorrido Pre-Order: ";
    arbol.preOrderIterativo(cola);
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;
    
    // Eliminar un nodo
    arbol.eliminar(30);
    cout << "Recorrido In-Order tras eliminar 30: ";
    arbol.inOrderIterativo(cola);
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;

    return 0;
}
*/


int main() {
	
	Cola<Artista> cola;
	
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

    // Aquí puedes procesar los datos cargados y convertirlos en estructuras

    // Creación de artistas
    Artista artista1 = {"Juan Pérez", "JP", "México", "Guitarra"};
    Artista artista2 = {"Ana López", "Anita", "España", "Voz"};
    Artista artista3 = {"Carlos Gómez", "Charlie", "Argentina", "Batería"};
    
    
    datosArtistas.insert(artista1.toCSV());
    datosArtistas.insert(artista2.toCSV());
    datosArtistas.insert(artista3.toCSV());

    // Creación de canciones
    Cancion cancion1 = {
        "JP", "Caminos del Alma", "3:45", 
        Lista<Artista>(), 1, 
        "Juan Pérez", "Juan Pérez", "JP & Band", 
        "Ciudad de México", "México", 2023, "Rock", 
        Lista<Link>()
    };
    cancion1.listadoArtistas.insert(artista1);
    cancion1.listadoLinks.insert({"Spotify", "https://spotify.com/album123", "https://spotify.com/track1"});

    Cancion cancion2 = {
        "Anita", "Vuela Alto", "4:10", 
        Lista<Artista>(), 1, 
        "Ana López", "Ana López", "Anita & Co.", 
        "Madrid", "España", 2023, "Pop", 
        Lista<Link>()
    };
    cancion2.listadoArtistas.insert(artista2);
    cancion2.listadoLinks.insert({"YouTube", "https://youtube.com/album123", "https://youtube.com/track2"});

    Cancion cancion3 = {
        "Charlie", "Ritmo Salvaje", "5:02", 
        Lista<Artista>(), 1, 
        "Carlos Gómez", "Carlos Gómez", "Charlie & The Beats", 
        "Buenos Aires", "Argentina", 2023, "Jazz", 
        Lista<Link>()
    };
    cancion3.listadoArtistas.insert(artista3);
    cancion3.listadoLinks.insert({"Apple Music", "https://apple.com/album123", "https://apple.com/track3"});
    
    datosCanciones.insert(cancion1.toCSV());
    datosCanciones.insert(cancion2.toCSV());
    datosCanciones.insert(cancion3.toCSV());

    // Creación del álbum
    Album album = {
        "Colores del Mundo", "Varios Artistas", "Latinoamérica", 2023,
        "cover.jpg", "fotografia.jpg", "Universal Music", "Estudios Latam",
        Lista<string>(), Lista<Cancion>()
    };

    album.listadoCanciones.insert(cancion1);
    album.listadoCanciones.insert(cancion2);
    album.listadoCanciones.insert(cancion3);
    album.listadoLinks.insert("https://spotify.com/album123");
    
    datosAlbumes.insert(album.toCSV());
    

    // Guardar datos en archivos al finalizar
    // (Aquí deberías convertir las estructuras de nuevo a texto)
    guardarDatos("albumes.txt", datosAlbumes);
    guardarDatos("canciones.txt", datosCanciones);
    guardarDatos("artistas.txt", datosArtistas);
    guardarDatos("versiones.txt", datosVersiones);
    guardarDatos("links.txt", datosLinks);

    
    char c=artista1.nombreArtistico[0];
    cout<<"Artista 1"<<endl;
    cout<<stringToNumber(artista1.nombreArtistico)<<endl;
	char c2=artista2.nombreArtistico[0];
    cout<<"Artista 2"<<endl;
    cout<<stringToNumber(artista2.nombreArtistico)<<endl;
    char c3=artista3.nombreArtistico[0];
    cout<<"Artista 3"<<endl;
    cout<<stringToNumber(artista3.nombreArtistico)<<endl;
    
    ArbolAVL<Artista> arbol;
    
    arbol.insertar(artista1, charToNumber(c));
    arbol.insertar(artista2, charToNumber(c2));
    arbol.insertar(artista3, charToNumber(c3));
    
    cout << "Recorrido In-Order: ";
    arbol.inOrderIterativo(cola);
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    
    return 0;

    
    
}
