#ifndef VISTA_H
#define VISTA_H
#include <iostream>
#include <string>
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
#include "ConsultasAvl.h"
#include "CharStrToNumber.h"

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



void menu(Lista<Album>& general, ListaCabAlbum cabPais_album, ListaCabAlbum  cabEditora, ListaCabAlbum  cabFotografia, ListaCabAlbum  cabEstudio, ListaCabCancion  cabGenero, ListaCabCancion  cabCompositor, ListaCabCancion  cabPais, ListaCabVersion  cabTipoVersion){
	int opcion;
 while (true) { // Bucle infinito hasta que el usuario elija salir
 	limpiarConsola();
 	cout << general.empty() << endl;
 	cout << "Bienvenid@ a Sontify, no es plagio de Spotify, es una mejor version" << endl << "Por favor seleccione una opcion:";
	cout << endl << endl << "1. Subir un almbum \n";
	cout << endl << endl << "2. Realizar una busqueda \n";
	cout << endl << endl << "3. Salir de Sontify \n";
 	cin >>  opcion;
        switch (opcion) {
            case 1:
				menuAl(general);	
                break;  // Regresa al men煤 sin necesidad de recursi贸n
            case 2:
            	
            	limpiarConsola();
				int opcion=1;
				cout << "Indique la categoria de busqueda:";
				cout << endl << endl << "1. Numero total de albumes cuyos derechos pertenecen a una editora dada, clasific醤dolos a駉 de publicacion y nombre artistico";
				cout << endl << endl << "2. Listado de las canciones y los albumes a los que pertenecen, que fueron grabados en un estudio dado, clasificandolos por a駉 y pais de grabacion.";
				cout << endl << endl << "3. Listado de las canciones con su arreglista y sus autores de letra y musica cuya duraci髇 es mayor a un tiempo dado, clasificadas por ciudad de grabacion.";
				cout << endl << endl << "4. Listado de las canciones de un genero dado que incluyan un instrumento dado. La lista debe incluir el nombre de la cancion, El nombre artistico y los datos del artista que interpreta el instrumento.";
				cout << endl << endl << "5. Numero de canciones que tienen una cantidad de versiones >= a un numero dado, clasificadas por genero y a駉 de la primera grabacion.";
				cout << endl << endl << "6. Listado de las versiones que pertenecen a un tipo de version dado y que est醤 en mas de una plataforma. El listado debe incluir en t韙ulo de la version, el nombre del artista principal, el genero, el a駉 y pais de publicaci髇, el nombre de la obra original y las plataformas en las que se encuentra.";
				cout << endl << endl << "7. Dada una cancion, listado de los links de todas las plataformas donde se encuentra la original y todas las versiones de dicha cancion, el link debe estar acompa馻do del nombre de la plataforma.";
				cout << endl << endl << "8. Obtener el numero de canciones y el numero de versiones que ha hecho cada encargado del Cover Art, Clasificando la informacion por genero y a駉 de publicacion, mostrando el nombre del encargado, el genero y el a駉.";
				cout << endl << endl << "9. Dado el nombre del encargado de fotografia y del estudio de grabacion, mostrar la lista de los albumes que han sido grabados en ese estudio y a cargo de ese encargado de fotografia, clasificados por pais de grabacion.";
				cout << endl << endl << "10.Dado el nombre de un compositor de la letra, mostrar todas las canciones compuestas por esa persona incluyendo genero, a駉, nombre de la cancion album al que pertenece y numero de plataformas en las que se encuentra.";
				cout << endl << endl << "11.Volver al menu principal.";
				cin >>  opcion;
				switch (opcion) {
			        case 1:
			        	
						menuAl(general);	
			            break; 
			            
			        case 2:
			        	
			        	
						
			            break;
			            
			        case 3:
			        	
			        	
						
			            break;
			    	case 4:
			        	
			        	
						
			            break;
			        case 5:
			        	
			        	
						
			            break;
			        case 6:
			        	
			        	
						
			            break;
			        case 7:
			        	
			        	
						
			            break;
			        case 8:
			        	
			        	
						
			            break;
			        case 9:
			        	
			        	
						
			            break;
			        case 10:
			        	
			        	
						
			            break;
			        case 11:
			        	cout << "Regresando...\n";
			        	menu(general);
			            return;   
			            
			        default:
			            cout << "Opci贸n inv谩lida. Intente de nuevo.\n";
			    }
            	return; 
				
                //break;
            case 3:
                cout << "Saliendo...\n";
                return;  // Sale del m茅todo, deteniendo el bucle
            default:
                cout << "Opci贸n inv谩lida. Intente de nuevo.\n";
        }
    }
}


/*
void menuBusq(Lista<Album>& general){
	limpiarConsola();
	int opcion=1;
	cout << "Indique la categoria de busqueda:";
	cout << endl << endl << "1. Numero total de albumes cuyos derechos pertenecen a una editora dada, clasific醤dolos a駉 de publicacion y nombre artistico";
	cout << endl << endl << "2. Listado de las canciones y los albumes a los que pertenecen, que fueron grabados en un estudio dado, clasificandolos por a駉 y pais de grabacion.";
	cout << endl << endl << "3. Listado de las canciones con su arreglista y sus autores de letra y musica cuya duraci髇 es mayor a un tiempo dado, clasificadas por ciudad de grabacion.";
	cout << endl << endl << "4. Listado de las canciones de un genero dado que incluyan un instrumento dado. La lista debe incluir el nombre de la cancion, El nombre artistico y los datos del artista que interpreta el instrumento.";
	cout << endl << endl << "5. Numero de canciones que tienen una cantidad de versiones >= a un numero dado, clasificadas por genero y a駉 de la primera grabacion.";
	cout << endl << endl << "6. Listado de las versiones que pertenecen a un tipo de version dado y que est醤 en mas de una plataforma. El listado debe incluir en t韙ulo de la version, el nombre del artista principal, el genero, el a駉 y pais de publicaci髇, el nombre de la obra original y las plataformas en las que se encuentra.";
	cout << endl << endl << "7. Dada una cancion, listado de los links de todas las plataformas donde se encuentra la original y todas las versiones de dicha cancion, el link debe estar acompa馻do del nombre de la plataforma.";
	cout << endl << endl << "8. Obtener el numero de canciones y el numero de versiones que ha hecho cada encargado del Cover Art, Clasificando la informacion por genero y a駉 de publicacion, mostrando el nombre del encargado, el genero y el a駉.";
	cout << endl << endl << "9. Dado el nombre del encargado de fotografia y del estudio de grabacion, mostrar la lista de los albumes que han sido grabados en ese estudio y a cargo de ese encargado de fotografia, clasificados por pais de grabacion.";
	cout << endl << endl << "10.Dado el nombre de un compositor de la letra, mostrar todas las canciones compuestas por esa persona incluyendo genero, a駉, nombre de la cancion album al que pertenece y numero de plataformas en las que se encuentra.";
	cout << endl << endl << "11.Volver al menu principal.";
	cout << endl << endl << "12.Salir.";
	cin >>  opcion;
	switch (opcion) {
        case 1:
        	
			menuAl(general);	
            break; 
            
        case 2:
        
        case 11:
        	cout << "Regresando...\n";
        	menu(general);
            break;   
        case 12:
            cout << "Saliendo...\n";
            return;  // Sale del m茅todo, deteniendo el bucle
        default:
            cout << "Opci贸n inv谩lida. Intente de nuevo.\n";
    }
	
	
}
*/


#endif
