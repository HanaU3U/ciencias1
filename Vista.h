#ifndef VISTA_H
#define VISTA_H
#include <iostream>
#include <string>
#include "Cancion.h"
#include "Album.h"
#include "Artista.h"
#include "Lista.h"
#include "Link.h"
#include "Version.h"
#include <cstdlib> 
using namespace std;

void limpiarConsola() {
    system("cls"); 
}


Lista<Artista> menuArt(Lista<Artista>& lista){
	limpiarConsola();
	cout << "Por favor brindar informacion sobre artistas colaboradores:";
	string nomR;
    string nomA;
    string pais;
    string inst;
    
    cout << endl << endl << "Nombre Real: ";
    cin.ignore();
	getline(cin,  nomR);
	cout << endl << endl << "Nombre Artistico: ";
	getline(cin,  nomA);
	cout << endl << endl << "Pais de Origen: ";
	getline(cin,  pais);
	cout << endl << endl << "Instrumento que toca: ";
	getline(cin,  inst);
	
	Artista artist = Artista(nomR, nomA, pais, inst);
	
	lista.insert(artist);
	return lista;
}
    
void menuLink(Lista<Link>& links){
	limpiarConsola();
	cout << "Por favor brindar informacion sobre los enlaces a la cancion:";
    string nomPlat;
    string linke;
    
    cout << endl << endl << "Nombre de la Plataforma: ";
	getline(cin,  nomPlat);
	cout << endl << endl << "Enlace: ";
	getline(cin,  linke);
	
	Link link = Link(nomPlat, linke);
	
	links.insert(link);
	}

void menuCan(Lista<Cancion>& canciones){
	limpiarConsola();
	string nArt;
	string nCan;
	string dur;
	string compL;
	string compM;
	string arr;
	string ciu;
	string pai;
	string gene;
	int art;
	int ano;
	int link;
	Lista<Artista> artistas;
    Lista<Link> links;
	
	cout << "Para insertar una nueva cancion, Por favor brindar la siguiente informacion:";
	cout << endl << endl << "Nombre artistico: ";
	cin.ignore();
	getline(cin,  nArt);
	cout << endl << endl << "Nombre de la cancion: ";
	getline(cin,  nCan);
	cout << endl << endl << "Duracion en formato minutos:segundos: ";
	getline(cin,  dur);
	cout << endl << endl << "Compositor(a) de la letra: ";
	getline(cin,  compL);
	cout << endl << endl << "Compositor(a) de la musica: ";
	getline(cin,  compM);
	cout << endl << endl << "Encargad@ del arreglo musical: ";
	getline(cin,  arr);
	cout << endl << endl << "Ciudad donde fue grabada: ";
	getline(cin,  ciu);
	cout << endl << endl << "Pais donde fue grabada: ";
	getline(cin,  pai);
	cout << endl << endl << "A o de publicacion: ";
	cin >> ano;
	cout << endl << endl << "Genero: ";
	cin.ignore();
	getline(cin,  gene);
	cout << endl << endl << "Cantidad de artistas que participan: ";
	cin >>  art;
	cout << endl << endl << "Cantidad de plataformas en las que se puede encontrar la cancion: ";
	cin >>  link;
	
	Cancion nueva = Cancion( nArt,  nCan,  dur,  art, compL,  compM,  arr, ciu,  pai,  ano,  gene);
	
	for(int i=0; i<art; i++){
		menuArt(artistas);
	}
	
	for(int i=0; i<link; i++){
		menuLink(links);
	}
	
	nueva.listadoArtistas=artistas;
	nueva.listadoLink=links;
	canciones.insert(nueva);
	}

void menuAl(Lista<Album>& general){
	limpiarConsola();
	Lista<Cancion> canciones;
	Lista<Link> links;
	string tit;
    string nomArt;
    string pais;
    int ano;
    string cover;
    string foto;
    string edit;
    string estud;
    int canc, link;
	cout << "Para insertar un nuevo Album, Por favor suministre la siguiente informacion: ";
	cout << endl << endl << "Titulo del Album: ";
	cin.ignore();
	getline(cin,  tit);
	cout << endl << endl << "Nombre Artistico: ";
	getline(cin,  nomArt);
	cout << endl << endl << "Pais de grabacion: ";
	getline(cin,  pais);
	cout << endl << endl << "Artista de la portada: ";
	getline(cin,  cover);
	cout << endl << endl << "Encargad@ de fotograf a: ";
	getline(cin,  foto);
	cout << endl << endl << "Editorial: ";
	getline(cin,  edit);
	cout << endl << endl << "Estudio: ";
	getline(cin,  estud);
	cout << endl << endl << "A o de publicacion: ";
	cin >> ano;
	cout << endl << endl << "Cantidad de canciones: ";
	cin >> canc;
	cout << endl << endl << "Cantidad de Links: ";
	cin >> link;
	
	Album album = Album( tit,  nomArt,  pais,  ano, cover, foto,  edit,  estud);
	
	for(int i=0; i<canc;i++){	
	menuCan(canciones);
	}
	album.listadoCanciones = canciones;	
	
	for(int i=0; i<link; i++){
		menuLink(links);
	}
	
	album.listadoLink = links;	
	
	general.insert(album);
	
}




Lista<Version> menuVer(Lista<Version> versiones){
	string tit;
    string tipo;
    string art;
    Lista<Artista> artistas;
    string ciu;
    string pais;
    string gene;
    int ano;
    int arts;

	cout << "Para insertar una nueva version, Por favor brindar la siguiente informacion:";
	cout << endl << endl << "Titulo: ";
	
	getline(cin,  tit);
	cout << endl << endl << "Tipo: ";
	getline(cin,  tipo);
	cout << endl << endl << "Artista principal: ";
	getline(cin,  art);
	cout << endl << endl << "Ciudad de grabacion: ";
	getline(cin,  ciu);
	cout << endl << endl << "Pais de grabacion: ";
	getline(cin,  pais);
	cout << endl << endl << "A o de publicacion: ";
	cin >> ano; 
	cout << endl << endl << "Cantiadad de artistas involucrados: ";
	cin >> arts;


	Version nueva = Version( tit,  tipo,  art, ciu,  pais,  gene,  ano);
	
	for(int i=0; i<arts; i++){
		menuArt(artistas);
	}
	         
    nueva.listadoArtistasPrincipales = artistas;

	versiones.insert(nueva);
	return versiones;
}



void menuBusq(){
	limpiarConsola();
	cout << "Indique la categoria de busqueda:";
	cout << endl << endl << "1. Ciudad";
	cout << endl << endl << "2. Pais";
	cout << endl << endl << "3. Genero";
	cout << endl << endl << "4. Busqueda mas especifica";
	
}


void menu(Lista<Album>& general){
	int opcion;
 while (true) { // Bucle infinito hasta que el usuario elija salir
 	limpiarConsola();
 	cout << general.empty() << endl;
 	cout << "Bienvenid@ a Sontify, no es plagio de Spotify, es una mejor version" << endl << "Por favor seleccione una opcion:";
	cout << endl << endl << "1. Subir un almbum \n";
	cout << endl << endl << "2. Buscar un almbum \n";
	cout << endl << endl << "3. Salir de Sontify \n";
 	cin >>  opcion;
        switch (opcion) {
            case 1:
				menuAl(general);	
                break;  // Regresa al menú sin necesidad de recursión
            case 2:
            	return;  // Sale del método, deteniendo el bucle

                //break;
            case 3:
                cout << "Saliendo...\n";
                return;  // Sale del método, deteniendo el bucle
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
        }
    }
}
#endif
