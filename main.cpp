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

/*

// Función para cargar datos link desde un archivo
Lista<ParClaveValor<Lista<Link>>> cargarDatosLink(const string& nombreArchivo) {
    Lista<ParClaveValor<Lista<Link>>> datos;
    ifstream archivo(nombreArchivo.c_str()); // Convertir string a const char*
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return datos; // Retorna una lista vacía si no se puede abrir el archivo
    }

    string linea;
    string nombreCancionActual = "";
    Lista<Link> enlacesActuales;

    while (getline(archivo, linea)) {
        size_t posNombre = linea.find(';');
        string nombreCancion = linea.substr(0, posNombre);

        size_t posPlataforma = linea.find(';', posNombre + 1);
        size_t posLinkCancion = linea.find(';', posPlataforma + 1);
        size_t posLinkAlbum = linea.find(';', posLinkCancion + 1);

        string nombrePlataforma = linea.substr(posNombre + 1, posPlataforma - (posNombre + 1));
        string linkCancion = linea.substr(posLinkCancion + 1, posLinkAlbum - (posLinkCancion + 1));
        string linkAlbum = linea.substr(posLinkAlbum + 1);

        if (nombreCancion != nombreCancionActual) {
            if (!nombreCancionActual.empty()) {
                datos.insert(ParClaveValor<Lista<Link>>(nombreCancionActual, enlacesActuales));
            }
            nombreCancionActual = nombreCancion;
            enlacesActuales = Lista<Link>(); // Reiniciar la lista de enlaces
        }

        // Crear un objeto Link y agregarlo a la lista de enlaces actuales
        Link nuevoLink(nombrePlataforma, linkAlbum, linkCancion);
        enlacesActuales.insert(nuevoLink);
    }

    // Agregar la última lista de enlaces
    if (!nombreCancionActual.empty()) {
        datos.insert(ParClaveValor<Lista<Link>>(nombreCancionActual, enlacesActuales));
    }

    archivo.close();
    return datos;
}



Lista<ParClaveValor<Lista<Version>>> cargarDatosVersion(const string& nombreArchivo) {
    Lista<ParClaveValor<Lista<Version>>> datos;
    ifstream archivo(nombreArchivo.c_str()); // Convertir string a const char*
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return datos; // Retorna una lista vacía si no se puede abrir el archivo
    }

    string linea;
    string nombreCancionActual = "";
    Lista<Version> versionesActuales;

    // Saltar la primera línea (cabecera del CSV)
    getline(archivo, linea);

    while (getline(archivo, linea)) {
        size_t posNombre = linea.find(';');
        string nombreCancion = linea.substr(0, posNombre);

        size_t posTituloVersion = linea.find(';', posNombre + 1);
        size_t posTipoVersion = linea.find(';', posTituloVersion + 1);
        size_t posArtistaPrincipal = linea.find(';', posTipoVersion + 1);
        size_t posCiudadGrabacion = linea.find(';', posArtistaPrincipal + 1);
        size_t posPaisGrabacion = linea.find(';', posCiudadGrabacion + 1);
        size_t posGenero = linea.find(';', posPaisGrabacion + 1);
        size_t posAnioPublicacion = linea.find(';', posGenero + 1);

        string tituloVersion = linea.substr(posNombre + 1, posTituloVersion - (posNombre + 1));
        string tipoVersion = linea.substr(posTituloVersion + 1, posTipoVersion - (posTituloVersion + 1));
        string artistaPrincipal = linea.substr(posTipoVersion + 1, posArtistaPrincipal - (posTipoVersion + 1));
        string ciudadGrabacion = linea.substr(posArtistaPrincipal + 1, posCiudadGrabacion - (posArtistaPrincipal + 1));
        string paisGrabacion = linea.substr(posCiudadGrabacion + 1, posPaisGrabacion - (posCiudadGrabacion + 1));
        string genero = linea.substr(posPaisGrabacion + 1, posGenero - (posPaisGrabacion + 1));
        int anioPublicacion = stoi(linea.substr(posGenero + 1, posAnioPublicacion - (posGenero + 1)));

        if (nombreCancion != nombreCancionActual) {
            if (!nombreCancionActual.empty()) {
                datos.insert(ParClaveValor<Lista<Version>>(nombreCancionActual, versionesActuales));
            }
            nombreCancionActual = nombreCancion;
            versionesActuales = Lista<Version>(); // Reiniciar la lista de versiones
        }

        // Crear un objeto Version y agregarlo a la lista de versiones actuales
        Version nuevaVersion(tituloVersion, tipoVersion, artistaPrincipal, ciudadGrabacion, paisGrabacion, genero, anioPublicacion);
        versionesActuales.insert(nuevaVersion);
    }

    // Agregar la última lista de versiones
    if (!nombreCancionActual.empty()) {
        datos.insert(ParClaveValor<Lista<Version>>(nombreCancionActual, versionesActuales));
    }

    archivo.close();
    return datos;
}

*/

/*
Lista<ParClaveValor<Lista<Cancion>>> cargarDatosCancion(const string& nombreArchivo) {
    Lista<ParClaveValor<Lista<Cancion>>> datos;
    ifstream archivo(nombreArchivo.c_str()); // Convertir string a const char*
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return datos; // Retorna una lista vacía si no se puede abrir el archivo
    }

    string linea;
    string albumActual = "";
    Lista<Cancion> cancionesActuales;

    // Saltar la primera línea (cabecera del CSV)
    getline(archivo, linea);

    while (getline(archivo, linea)) {
        size_t posAlbum = linea.find(';');
        string album = linea.substr(0, posAlbum);

        size_t posNombreArtistico = linea.find(';', posAlbum + 1);
        size_t posNombreCancion = linea.find(';', posNombreArtistico + 1);
        size_t posDuracion = linea.find(';', posNombreCancion + 1);
        size_t posNumArtistasPrincipales = linea.find(';', posDuracion + 1);
        size_t posCompositorLetra = linea.find(';', posNumArtistasPrincipales + 1);
        size_t posCompositorMusica = linea.find(';', posCompositorLetra + 1);
        size_t posArreglosMusicales = linea.find(';', posCompositorMusica + 1);
        size_t posCiudadGrabacion = linea.find(';', posArreglosMusicales + 1);
        size_t posPaisGrabacion = linea.find(';', posCiudadGrabacion + 1);
        size_t posAnioPrimeraPublicacion = linea.find(';', posPaisGrabacion + 1);
        size_t posGenero = linea.find(';', posAnioPrimeraPublicacion + 1);

        string nombreArtistico = linea.substr(posAlbum + 1, posNombreArtistico - (posAlbum + 1));
        string nombreCancion = linea.substr(posNombreArtistico + 1, posNombreCancion - (posNombreArtistico + 1));
        string duracion = linea.substr(posNombreCancion + 1, posDuracion - (posNombreCancion + 1));
        int numArtistasPrincipales = stoi(linea.substr(posDuracion + 1, posNumArtistasPrincipales - (posDuracion + 1)));
        string compositorLetra = linea.substr(posNumArtistasPrincipales + 1, posCompositorLetra - (posNumArtistasPrincipales + 1));
        string compositorMusica = linea.substr(posCompositorLetra + 1, posCompositorMusica - (posCompositorLetra + 1));
        string arreglosMusicales = linea.substr(posCompositorMusica + 1, posArreglosMusicales - (posCompositorMusica + 1));
        string ciudadGrabacion = linea.substr(posArreglosMusicales + 1, posCiudadGrabacion - (posArreglosMusicales + 1));
        string paisGrabacion = linea.substr(posCiudadGrabacion + 1, posPaisGrabacion - (posCiudadGrabacion + 1));
        int anioPrimeraPublicacion = stoi(linea.substr(posPaisGrabacion + 1, posAnioPrimeraPublicacion - (posPaisGrabacion + 1)));
        string genero = linea.substr(posAnioPrimeraPublicacion + 1, posGenero - (posAnioPrimeraPublicacion + 1));

        if (album != albumActual) {
            if (!albumActual.empty()) {
                datos.insert(ParClaveValor<Lista<Cancion>>(albumActual, cancionesActuales));
            }
            albumActual = album;
            cancionesActuales = Lista<Cancion>(); // Reiniciar la lista de canciones
        }

        // Crear un objeto Cancion y agregarlo a la lista de canciones actuales
        Cancion nuevaCancion(nombreArtistico, nombreCancion, duracion, numArtistasPrincipales, compositorLetra, compositorMusica, arreglosMusicales, ciudadGrabacion, paisGrabacion, anioPrimeraPublicacion, genero);
        cancionesActuales.insert(nuevaCancion);
    }

    // Agregar la última lista de canciones
    if (!albumActual.empty()) {
        datos.insert(ParClaveValor<Lista<Cancion>>(albumActual, cancionesActuales));
    }

    archivo.close();
    return datos;
}

Lista<Album> cargarDatosAlbum(const string& nombreArchivo) {
    Lista<Album> datos;
    ifstream archivo(nombreArchivo.c_str());

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return datos;
    }

    string linea;
    getline(archivo, linea); // Leer y descartar la primera línea (encabezado)

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string titulo, nombreArtistico, paisGrabacion, anioStr, coverArt, fotografia, editora, estudioGrabacion;
        
        // Leer cada campo separado por ';'
        getline(ss, titulo, ';');
        getline(ss, nombreArtistico, ';');
        getline(ss, anioStr, ';');
        getline(ss, coverArt, ';');
        getline(ss, fotografia, ';');
        getline(ss, editora, ';');
        getline(ss, estudioGrabacion, ';');

        // Convertir el año a entero
        int anioPublicacion = 0;
        istringstream(anioStr) >> anioPublicacion; 
        // Crear el objeto Album utilizando el constructor
        Album album(titulo, nombreArtistico, paisGrabacion, anioPublicacion, coverArt, fotografia, editora, estudioGrabacion);
        
        // Insertar en la lista
        datos.insert(album);
    }

    archivo.close();
    return datos;
}

Lista<ParClaveValor<Lista<Artista>>> cargarDatosArtista(const string& nombreArchivo) {
    Lista<ParClaveValor<Lista<Artista>>> datos;
    ifstream archivo(nombreArchivo.c_str());

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        return datos;
    }

    string linea;
    getline(archivo, linea); // Leer y descartar la primera línea (encabezado)

    string nombreArtisticoActual = "";
    Lista<Artista> artistasActuales;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombreReal, nombreArtistico, pais, instrumento;

        // Leer los campos del CSV
        getline(ss, nombreReal, ';');
        getline(ss, nombreArtistico, ';');
        getline(ss, pais, ';');
        getline(ss, instrumento, ';');

        Artista nuevoArtista(nombreReal, nombreArtistico, pais, instrumento);

        // Si seguimos con el mismo nombre artístico, agregamos el artista a la lista
        if (nombreArtistico == nombreArtisticoActual) {
            artistasActuales.insert(nuevoArtista);
        } else {
            // Si ya tenemos una lista anterior, la agregamos a la estructura de datos
            if (!nombreArtisticoActual.empty()) {
                datos.insert(ParClaveValor<Lista<Artista>>(nombreArtisticoActual, artistasActuales));
            }

            // Reiniciar con el nuevo nombre artístico
            nombreArtisticoActual = nombreArtistico;
            artistasActuales = Lista<Artista>(); // Reiniciar la lista de artistas
            artistasActuales.insert(nuevoArtista);
        }
    }

    // Guardar la última agrupación de artistas
    if (!nombreArtisticoActual.empty()) {
        datos.insert(ParClaveValor<Lista<Artista>>(nombreArtisticoActual, artistasActuales));
    }

    archivo.close();
    return datos;
}

*/

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
        string tituloAlbum,nombreArtistico, tituloCancion, duracion, genero, compositorLetra, compositorMusica, arreglosMusicales, paisGrabacion, ciudadGrabacion;
        int numArtistasPrincipales, anioPublicacion;

        getline(ss, tituloAlbum, ';');
        getline(ss, tituloCancion, ';');
        getline(ss, duracion, ';');
        ss >> numArtistasPrincipales;
        ss.ignore(); // Ignorar el delimitador
        getline(ss, compositorLetra, ';');
        getline(ss, compositorMusica, ';');
        getline(ss, arreglosMusicales, ';');
        getline(ss, nombreArtistico, ';');
        getline(ss, paisGrabacion, ';');
        getline(ss, ciudadGrabacion, ';');
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
	
    Lista<Album> albumes;
    Lista<Cancion> canciones;
    Lista<Artista> artistas;
    Lista<Version> versiones;
    Lista<Link> links;

    // Cargar datos desde archivos
    //Lista<Album> datosAlbumes = cargarDatosAlbum("albumes.txt");
    //Lista<ParClaveValor<Lista<Cancion>>> datosCanciones = cargarDatosCancion("canciones.txt");
    //Lista<string> datosArtistas = cargarDatosArtista("artistas.txt");
    //Lista<string> datosVersiones = cargarDatosVersion("versiones.txt");
    //Lista<string> datosLinks = cargarDatosLink("links.txt");
    
    Lista<Album> datosAlbumes = cargarAlbumesYCanciones("albumes.txt", "canciones.txt");
    
    
    cout<<datosAlbumes.get(0).titulo<<endl;
    
    
    // Imprimir los álbumes y sus canciones
    for (auto& album : datosAlbumes) {
        cout << "Album: " << album.titulo << " (" << album.anioPublicacion << ")" << endl;
        cout << "Artista: " << album.nombreArtistico << endl;
        cout << "Canciones:" << endl;
        for (auto& cancion : album.listadoCanciones) {
            cout << "  - " << cancion.nombreCancion << " (" << cancion.duracion << ")" << endl;
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
