#include <iostream>
#include <fstream>
#include <string>
#include "Link.h"
#include "Cancion.h"
#include "Album.h"
#include "Artista.h"
#include "Version.h"
#include "Lista.h"
#include "ArbolAVL.h"
#include "Multilista.h"


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

/*
int main() {
    ArbolAVL<int> arbol;
    Cola<int> cola;
    
    // Insertar elementos en el �rbol
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
	
	/*Cola<Artista> cola;
	
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
    
    /*
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
    
    return 0;*/
    
    Multilista<Album> listaAlbums;
    
    Album album1 = {"Mi Primer �lbum", "Juan P�rez", "M�xico", 2023, "cover.jpg", "foto.jpg",
                    "Sony Music", "Estudio A", Lista<string>(), Lista<Cancion>()};

    Album album2 = {"Rock Latino", "Los Rockeros", "Argentina", 2020, "cover2.jpg", "foto2.jpg",
                    "Universal", "Estudio B", Lista<string>(), Lista<Cancion>()};

    listaAlbums.InsertarM(album1);
    listaAlbums.InsertarM(album2);

    // Insertar canciones en la sublista de un �lbum
    Cancion cancion1 = {"Juan P�rez", "Canci�n 1", "3:45", Lista<Artista>(), 1, "Compositor A", "Compositor B",
                        "Arreglos X", "CDMX", "M�xico", 2022, "Rock", Lista<Link>()};

    Cancion cancion2 = {"Juan P�rez", "Canci�n 2", "4:12", Lista<Artista>(), 1, "Compositor C", "Compositor D",
                        "Arreglos Y", "Monterrey", "M�xico", 2023, "Pop", Lista<Link>()};

    listaAlbums.InsertarEnSublista("Mi Primer �lbum", cancion1);
	listaAlbums.InsertarEnSublista("Mi Primer �lbum", cancion2);

    cout << "Lista de �lbumes y Canciones:\n";
    listaAlbums.Mostrar();

    return 0;
    
    
}
