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
#include "Vista.h"
#include "Lista.h"
#include "ListaCabAlbum.h"
#include "ListaCabCancion.h"
#include "ListaCabVersion.h"
#include "ArbolAVL.h"
#include "CharStrToNumber.h"


using namespace std;


ListaCabAlbum  cabPais_album;
ListaCabAlbum  cabEditora;
ListaCabAlbum  cabFotografia;
ListaCabAlbum  cabEstudio;

ListaCabCancion  cabGenero;
ListaCabCancion  cabCompositor;
ListaCabCancion  cabPais;


ListaCabVersion  cabTipoVersion;

Lista<Album> cargarAlbumesYCanciones(const string& archivoAlbumes, const string& archivoCanciones) {
    Lista<Album> albumes;

    // Leer el archivo de �lbumes
    ifstream archivoAlbums(archivoAlbumes);
    if (!archivoAlbums.is_open()) {
        cerr << "Error al abrir el archivo de �lbumes: " << archivoAlbumes << endl;
        return albumes;
    }

    string lineaAlbum;
    getline(archivoAlbums, lineaAlbum); // Leer y descartar la primera l�nea (encabezado)

    while (getline(archivoAlbums, lineaAlbum)) {
        stringstream ss(lineaAlbum);
        string titulo, artista, paisGrabacion, fotografo, editora, discografica, estudioGrabacion;
        int anio=0;

        getline(ss, titulo, ';');
        getline(ss, artista, ';');
        getline(ss, paisGrabacion, ';');
        ss >> anio;
        ss.ignore(); 
        getline(ss, fotografo, ';');
        getline(ss, editora, ';');
        getline(ss, discografica, ';');
        getline(ss, estudioGrabacion, ';');
        
        //Album nuevoAlbum(titulo, artista, paisGrabacion, anio, fotografo, editora, discografica, estudioGrabacion);
        Album* album = new Album(titulo, artista, paisGrabacion, anio, fotografo, editora, discografica, estudioGrabacion);
        
	    albumes.insert(*album);
	    cabPais_album.insertarPaisAlbum(album);
	    cabEditora.insertarEditoraAlbum(album);
	    cabFotografia.insertarFotografoAlbum(album);
	    cabEstudio.insertarEstudioAlbum(album);
	}
    archivoAlbums.close();

    // Leer el archivo de canciones y agregarlas a los �lbumes correspondientes
    ifstream archivoCancions(archivoCanciones);
    if (!archivoCancions.is_open()) {
        cerr << "Error al abrir el archivo de canciones: " << archivoCanciones << endl;
        return albumes;
    }

    string lineaCancion;
    getline(archivoCancions, lineaCancion); // Leer y descartar la primera l�nea (encabezado)

    while (getline(archivoCancions, lineaCancion)) {
        stringstream ss(lineaCancion);
        string tituloAlbum,nombreArtistico,tituloCancion, duracion, genero, compositorLetra, compositorMusica, arreglosMusicales, paisGrabacion, ciudadGrabacion;
        int numArtistasPrincipales, anioPublicacion;

        getline(ss, tituloAlbum, ';');
        getline(ss, tituloCancion, ';');
        getline(ss, duracion, ';');
        ss >> numArtistasPrincipales;
        ss.ignore(); 
        getline(ss, compositorLetra, ';');
        getline(ss, compositorMusica, ';');
        getline(ss, arreglosMusicales, ';');
        getline(ss, nombreArtistico, ';');
        getline(ss, ciudadGrabacion, ';');
        getline(ss, paisGrabacion, ';');
        ss >> anioPublicacion;
        ss.ignore(); 
        getline(ss, genero, ';');
        

		Cancion* cancion = new Cancion(nombreArtistico, tituloCancion, duracion, numArtistasPrincipales,
            compositorLetra, compositorMusica, arreglosMusicales,
            ciudadGrabacion, paisGrabacion, anioPublicacion, genero);
            
            
        // Buscar el �lbum correspondiente y agregar la canci�n
        for (auto& album : albumes) {
            if (album.titulo == tituloAlbum) {
                album.listadoCanciones.insert(*cancion);
                cabGenero.insertarGeneroCancion(cancion);
                cabCompositor.insertarCompositorCancion(cancion);
                cabPais.insertarPaisCancion(cancion);
                
                break;
            }
        }
    }
    archivoCancions.close();

    return albumes;
}


void cargarLinksCancion(Lista<Album>& albumes, const string& archivoLinks) {
    ifstream archivo(archivoLinks);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de links: " << archivoLinks << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // Leer y descartar la primera l�nea (encabezado)

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tituloCancion, nombrePlataforma, link;

        getline(ss, tituloCancion, ';');
        getline(ss, nombrePlataforma, ';');
        getline(ss, link);

        Link nuevoLink(nombrePlataforma, link);

        // Buscar la canci�n correspondiente y agregar el link
        for (auto& album : albumes) {
            for (auto& cancion : album.listadoCanciones) {
                if (cancion.nombreCancion == tituloCancion) {
                    cancion.listadoLink.insert(nuevoLink);
                    cancion.cantPlataformas+=1;
                    break;
                }
            }
        }
    }
    archivo.close();
}

void cargarLinksAlbum(Lista<Album>& albumes, const string& archivoLinks) {
    ifstream archivo(archivoLinks);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de links: " << archivoLinks << endl;
        return;
    }

    string linea;
    getline(archivo, linea); // Leer y descartar la primera l�nea (encabezado)

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tituloAlbum, nombrePlataforma, link;

        getline(ss, tituloAlbum, ';');
        getline(ss, nombrePlataforma, ';');
        getline(ss, link);

        Link nuevoLink(nombrePlataforma, link);

        // Buscar la canci�n correspondiente y agregar el link
        for (auto& album : albumes) {
            if (album.titulo == tituloAlbum) {
                album.listadoLink.insert(nuevoLink);
                break;
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
    getline(archivo, linea); // Leer y descartar la primera l�nea (encabezado)

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
		
		Version* version = new Version(tituloVersion, tipoVersion, artistaPrincipal, ciudadGrabacion, paisGrabacion, genero, anioPublicacion);
            
        // Buscar la canci�n correspondiente y agregar la versi�n
        for (auto& album : albumes) {
            for (auto& cancion : album.listadoCanciones) {
                if (cancion.nombreCancion == tituloCancion) {
                    cancion.listadoVersion.insert(*version);
                    cabTipoVersion.insertarTipoVersion(version);
                    
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
    getline(archivo, linea); // Leer y descartar la primera l�nea (encabezado)

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombreReal, nombreArtistico, pais, instrumento;

        getline(ss, nombreReal, ';');
        getline(ss, nombreArtistico, ';');
        getline(ss, pais, ';');
        getline(ss, instrumento, ';');

        Artista nuevoArtista(nombreReal, nombreArtistico, pais, instrumento);
        
        //cout<<nombreArtistico<<endl;

        // Buscar la canci�n o versi�n correspondiente y agregar el artista
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

Lista<Album> cargarTodo(const string& archivoAlbumes, const string& archivoCanciones, const string& archivoLinksCan, const string& archivoLinksAl, const string& archivoVersiones, const string& archivoArtistas) {
    Lista<Album> albumes = cargarAlbumesYCanciones(archivoAlbumes, archivoCanciones);
    cargarLinksCancion(albumes, archivoLinksCan);
    cargarLinksAlbum(albumes, archivoLinksAl);
    cargarVersiones(albumes, archivoVersiones);
    cargarArtistas(albumes, archivoArtistas);
    return albumes;
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
	
	Cola<Artista> cola;
	
    Lista<Album> albumes = cargarTodo("albumes.txt", "canciones.txt", "linksCancion.txt", "linksAlbum.txt", "versiones.txt", "artistas.txt");
	
	menu(albumes);
    
    return 0;
}


	
	/*
	Album album = albumes.get(0);
    
	cout << "Album: " << album.titulo << " (" << album.anioPublicacion << ")" << endl;
    cout << "Artista: " << album.nombreArtistico << endl;
    cout << "Canciones:" << endl;
    
    for (auto& cancion : album.listadoCanciones) {
        cout << "  - " << cancion.nombreCancion << " (" << cancion.duracion << ")" << endl;
        cout<<"cantidad Plataformas "<<cancion.cantPlataformas<<endl;
        cout << "    Links:" << endl;
        for (auto& link : cancion.listadoLink) {
        	cout << "      * " << link.nombrePlataforma << ": " << link.link << endl;
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
     
    
    
    cout<<"Albumes del mismo pais Estados Unidos"<<endl;
    cabPais_album.imprimirAlbumesPorPais("Estados Unidos");
    
    cout<<"Canciones del mismo genero Pop"<<endl;
    cabGenero.imprimirCancionesPorGenero("Folk Rock");
    
    cout<<"Versiones del mismo tipo Special Edition"<<endl;
    cabTipoVersion.imprimirVersionesPortipoVer("Special Edition");
    */
    
    /*

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

