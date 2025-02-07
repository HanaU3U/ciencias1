#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio> 
#include "Link.h"
#include "Cancion.h"
#include "Album.h"
#include "Artista.h"
#include "Version.h"
#include "Lista.h"
#include "Cabecera.h"
#include "ArbolAVL.h"
#include "CharStrToNumber.h"
#include "MapCustom.h"


using namespace std;


Lista<Album> cargarAlbumesYCanciones(const string& archivoAlbumes, const string& archivoCanciones) {
    Lista<Album> albumes;

    // Leer el archivo de álbumes
    ifstream archivoAlbums(archivoAlbumes);
    if (!archivoAlbums.is_open()) {
        cerr << "Error al abrir el archivo de álbumes: " << archivoAlbumes << endl;
        return albumes;
    }

    string lineaAlbum;
    getline(archivoAlbums, lineaAlbum); // Leer y descartar la primera línea (encabezado)

    while (getline(archivoAlbums, lineaAlbum)) {
        stringstream ss(lineaAlbum);
        string titulo, artista, paisGrabacion, fotografo, disenadorPortada, discografica, estudioGrabacion;
        int anio=0;

        getline(ss, titulo, ';');
        getline(ss, artista, ';');
        getline(ss, paisGrabacion, ';');
        ss >> anio;
        ss.ignore(); // Ignorar el delimitador
        getline(ss, fotografo, ';');
        getline(ss, disenadorPortada, ';');
        getline(ss, discografica, ';');
        getline(ss, estudioGrabacion, ';');

        Album nuevoAlbum(titulo, artista, paisGrabacion, anio, fotografo, disenadorPortada, discografica, estudioGrabacion);
        albumes.insert(nuevoAlbum);
    }
    archivoAlbums.close();

    // Leer el archivo de canciones y agregarlas a los álbumes correspondientes
    ifstream archivoCancions(archivoCanciones);
    if (!archivoCancions.is_open()) {
        cerr << "Error al abrir el archivo de canciones: " << archivoCanciones << endl;
        return albumes;
    }

    string lineaCancion;
    getline(archivoCancions, lineaCancion); // Leer y descartar la primera línea (encabezado)

    while (getline(archivoCancions, lineaCancion)) {
        stringstream ss(lineaCancion);
        string tituloAlbum,nombreArtistico,tituloCancion, duracion, genero, compositorLetra, compositorMusica, arreglosMusicales, paisGrabacion, ciudadGrabacion;
        int numArtistasPrincipales, anioPublicacion;

        getline(ss, tituloAlbum, ';');
        getline(ss, tituloCancion, ';');
        getline(ss, duracion, ';');
        ss >> numArtistasPrincipales;
        getline(ss, compositorLetra, ';');
        getline(ss, compositorMusica, ';');
        getline(ss, arreglosMusicales, ';');
        getline(ss, nombreArtistico, ';');
        getline(ss, ciudadGrabacion, ';');
        getline(ss, paisGrabacion, ';');
        ss >> anioPublicacion;
        getline(ss, genero, ';');
        

        Cancion nuevaCancion(nombreArtistico, tituloCancion, duracion, numArtistasPrincipales,
            compositorLetra, compositorMusica, arreglosMusicales,
            ciudadGrabacion, paisGrabacion, anioPublicacion, genero);


        // Buscar el álbum correspondiente y agregar la canción
        for (auto& album : albumes) {
            if (album.titulo == tituloAlbum) {
                album.listadoCanciones.insert(nuevaCancion);
                break;
            }
        }
    }
    archivoCancions.close();

    return albumes;
}


void cargarLinks(Lista<Album>& albumes, const string& archivoLinks) {
    ifstream archivo(archivoLinks);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de links: " << archivoLinks << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // Leer y descartar la primera línea (encabezado)

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tituloCancion, nombrePlataforma, linkAlbum, linkCancion;

        getline(ss, tituloCancion, ';');
        getline(ss, nombrePlataforma, ';');
        getline(ss, linkAlbum, ';');
        getline(ss, linkCancion, ';');

        Link nuevoLink(nombrePlataforma, linkAlbum, linkCancion);

        // Buscar la canción correspondiente y agregar el link
        for (auto& album : albumes) {
            for (auto& cancion : album.listadoCanciones) {
                if (cancion.nombreCancion == tituloCancion) {
                    cancion.listadoLink.insert(nuevoLink);
                    break;
                }
            }
        }
    }
    archivo.close();
}

void cargarVersiones(Lista<Album>& albumes, const string& archivoVersiones) {
    ifstream archivo(archivoVersiones);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de versiones: " << archivoVersiones << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // Leer y descartar la primera línea (encabezado)

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tituloCancion, tituloVersion, tipoVersion, artistaPrincipal, ciudadGrabacion, paisGrabacion, genero;
        int anioPublicacion;

        getline(ss, tituloCancion, ';');
        getline(ss, tituloVersion, ';');
        getline(ss, tipoVersion, ';');
        getline(ss, artistaPrincipal, ';');
        getline(ss, ciudadGrabacion, ';');
        getline(ss, paisGrabacion, ';');
        getline(ss, genero, ';');
        ss >> anioPublicacion;

        Version nuevaVersion(tituloVersion, tipoVersion, artistaPrincipal, ciudadGrabacion, paisGrabacion, genero, anioPublicacion);

        // Buscar la canción correspondiente y agregar la versión
        for (auto& album : albumes) {
            for (auto& cancion : album.listadoCanciones) {
                if (cancion.nombreCancion == tituloCancion) {
                    cancion.listadoVersion.insert(nuevaVersion);
                    break;
                }
            }
        }
    }
    archivo.close();
}

void cargarArtistas(Lista<Album>& albumes, const string& archivoArtistas) {
    ifstream archivo(archivoArtistas);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de artistas: " << archivoArtistas << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // Leer y descartar la primera línea (encabezado)

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombreReal, nombreArtistico, pais, instrumento;

        getline(ss, nombreReal, ';');
        getline(ss, nombreArtistico, ';');
        getline(ss, pais, ';');
        getline(ss, instrumento, ';');

        Artista nuevoArtista(nombreReal, nombreArtistico, pais, instrumento);
        
        cout<<nombreArtistico<<endl;

        // Buscar la canción o versión correspondiente y agregar el artista
        for (auto& album : albumes) {
            for (auto& cancion : album.listadoCanciones) {
            	//cout<<cancion.nombreArtistico<<" == "<<nombreArtistico<<endl;
                if (cancion.nombreArtistico == nombreArtistico) {
                    cancion.listadoArtistas.insert(nuevoArtista);
                }
                for (auto& version : cancion.listadoVersion) {
                    if (version.artistaPrincipal == nombreArtistico) {
                        version.listadoArtistasPrincipales.insert(nuevoArtista);
                    }
                }
            }
        }
    }
    archivo.close();
}

Lista<Album> cargarTodo(const string& archivoAlbumes, const string& archivoCanciones, const string& archivoLinks, const string& archivoVersiones, const string& archivoArtistas) {
    Lista<Album> albumes = cargarAlbumesYCanciones(archivoAlbumes, archivoCanciones);
    cargarLinks(albumes, archivoLinks);
    cargarVersiones(albumes, archivoVersiones);
    cargarArtistas(albumes, archivoArtistas);
    return albumes;
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

Lista<Cabecera<Album>> editora;
Lista<Cabecera<Album>> fotografia;
Lista<Cabecera<Album>> estudio;
Lista<Cabecera<Album>> pais_album;
Lista<Cabecera<Cancion>> pais_can;
Lista<Cabecera<Cancion>> genero;
Lista<Cabecera<Cancion>> compositor;
Lista<Cabecera<Cancion>> tipo_version;
Lista<Cabecera<Cancion>> plataforma;
Lista<Cabecera<Artista>> instrumento;

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
	
    Lista<Album> albumes = cargarTodo("albumes.txt", "canciones.txt", "links.txt", "versiones.txt", "artistas.txt");

    // Imprimir los álbumes, canciones, links y versiones
    for (auto& album : albumes) {
        cout << "Album: " << album.titulo << " (" << album.anioPublicacion << ")" << endl;
        cout << "Artista: " << album.nombreArtistico << endl;
        cout << "Canciones:" << endl;
        for (auto& cancion : album.listadoCanciones) {
            cout << "  - " << cancion.nombreCancion << " (" << cancion.duracion << ")" << endl;
            cout << "    Links:" << endl;
            for (auto& link : cancion.listadoLink) {
                cout << "      * " << link.nombrePlataforma << ": " << link.linkCancion << endl;
            }
            cout << "    Versiones:" << endl;
            for (auto& version : cancion.listadoVersion) {
                cout << "      * " << version.tituloVersion << " (" << version.tipoVersion << ")" << endl;
            }
            cout << "    Artistas:" << endl;
            for (auto& artista : cancion.listadoArtistas) {
                cout << "      - " << artista.nombreReal << " (" << artista.instrumento << ")" << endl;
            }
        }
        cout << endl;
    }

    
    
    return 0;
    /*

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
*/
    
    
}
