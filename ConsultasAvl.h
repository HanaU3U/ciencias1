//Consultas AVL
#ifndef CONSULTASAVL_H
#define CONSULTASAVL_H

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

class ConsultasAvl {
	
	Lista<Album> albumes;
public:
	
	ConsultasAvl(Lista<Album>& albumes): albumes(albumes){};

private:
	
	Lista<Album> albumes;
	
    void consulta1(string editora, ListaCabAlbum  cabEditora) {
        Cola<Album> cola_album;
        ArbolAVL<Album> arbol1;
	    int acumulador = 0;
	    Album* actual = cabEditora.obtenerAlbumesPorCaract(editora);
	    while (actual != NULL) {
	        //cout << *actual << endl; // Usa la sobrecarga del operador <<
	        arbol1.insertar(*actual, actual->anioPublicacion);
	    	acumulador++;
	        actual = actual->sigEditora;
	    }
	    
	    cout<<"Cantidad de albumes de "<<editora<<": "<<acumulador<<endl;
	    
	    
	    cout<<"Albumes"<<endl;
	    arbol1.postOrderIterativo(cola_album);
	    
	
	    // Imprimir la cola resultante
	    while (!cola_album.empty()) {
	        Album album = cola_album.front(); 
	        cout << album << endl<<" ("<<album.anioPublicacion<<")"<<endl;
	        cola_album.pop(); 
	    }
    }

	
    void consulta2(string& estudio,ListaCabAlbum  cabEditora) {
    	
    	Cola<Album> cola_album;
	
	    ArbolAVL<Album> arbol2;
	    
	    Album* actual = cabEstudio.obtenerAlbumesPorCaract(studio);
	    while (actual != NULL) {
	        //cout << *actual << endl; // Usa la sobrecarga del operador <<
	        arbol2.insertar(*actual, actual->anioPublicacion);
	        actual = actual->sigEstudio;
	    }
	    
	    cout<<"Albumes"<<endl;
	    arbol1.postOrderIterativo(cola_album);
	    
	    // Imprimir la cola resultante
	    while (!cola_album.empty()) {
	        Album album = cola_album.front(); 
	        cout << album << endl<<" ("<<album.anioPublicacion<<")"<<endl;
	        for(int i=0; i<album.listadoCanciones.get_size(); i++){
	        	cout <<"Cancion "<<album.listadoCanciones.get(i).nombreCancion<<" ("<<album.listadoCanciones.get(i).paisGrabacion<<")"<<endl;
			}
	        
	        cola_album.pop(); 
	    }
    }

    void consulta3(string dur, string pais, ListaCabCancion  cabPais) {
        cout<<"Canciones con duración mayor a "<< dur << endl;
		Cancion* actual = cabPais.obtenerCancionesPorCaract(pais);
        ArbolAVL<Cancion> arbol3;
        int i=0;
        while (actual != NULL) {
        	if(stringToNumber(actual->duracion) > stringToNumber(ciudad))
        	arbol3.insertar(*actual, charToNumber(actual->paisGrabacion[0]));
            actual = actual->sigPais;
            i++;
        }
        Cola<Cancion> cola = arbol.inorder();
        cout << "Total: " << i << endl;
        cola.print();
    }
    
    void Consu4(ListaCabCancion cabGenero, string genero, string instrumento){
		cout<<"Canciones del mismo genero "<< genero << " Y mismo instrumento " << instrumento << endl;	
		Cancion* actual = cabGenero.obtenerCancionesPorCaract(genero);
        ArbolAVL<Cancion> arbol4;
        int i=0;
        string inst;
        Artista ar;
        int art;
        while (actual != NULL) {
        	art = actual->listadoArtistas.get_size();
        	ar = actual->listadoArtistas.get(0);
				for(int j=1; j<=art; j++){
        		ar = actual->listadoArtistas.get(j);
        		inst=ar.instrumento;
     	 		if(inst == instrumento){
        			arbol4.insertar(*actual, charToNumber(actual->nombreCancion[0]) );
        			i++;
        			cout << "c";
        			break;
				}
			}
            actual = actual->sigGenero;
            
        }
        
        Cola<Cancion> cola = arbol.inorder();
        cout << "Total: " << i << endl;
        cola.print();   
	}
	
	
	void consulta5(int numero){
		ArbolAVL<Cancion> arbol5;
	    Cola<Cancion> cola_cancion5;
	    
	    for(int i=0; i<albumes.get_size(); i++ ){
        	Album album = albumes.get(i);
        	for(int j=0; j<album.listadoCanciones.get_size(); j++ ){
        		Cancion cancion1 = album.listadoCanciones.get(j);
        		arbol5.insertar(cancion1, charToNumber(cancion1.genero[0]));
			}
		}
		
	    int acumulador = 0;
	    arbol5.inOrderIterativo(cola_cancion5);
	    while (!cola_cancion5.empty()) {
	    	if(cola_cancion5.front().ListadoVersiones.get_size() > numero){
	    		acumulador++;
			}
	        cola_cancion5.pop();
	    }
	    cout << "la cantidad de albumes con una cantidad de versiones mayor a " << numero <<" es " << acumulador << endl << endl;
	}
	
	void consulta6(string tipoVer){
		ArbolAVL<Cancion> arbol6;
	    Cola<Cancion> cola_cancion6;
	    
	    for(int i=0; i<albumes.get_size(); i++ ){
        	Album album = albumes.get(i);
        	for(int j=0; j<album.listadoCanciones.get_size(); j++ ){
        		Cancion cancion1 = album.listadoCanciones.get(j);
        		arbol6.insertar(cancion1, charToNumber(cancion1.genero[0]));
			}
		}
	    
	    
	    arbol6.inOrderIterativo(cola_cancion6);
	    while (!cola_cancion6.empty()) {
	    	for(int i=0; i < cola_cancion6.front().ListadoVersiones.get_size() ;i++){
	    		if(cola_cancion6.front().ListadoVersiones.get(i).tipoVersion == tipoVer){
	    			cout << "El artista princicipal es: "<< cola_cancion6.front().ListadoVersiones.get(i).artistaPrincipal << endl
					<< "El genero de la cancion es: "<< cola_cancion6.front().genero << endl
					<< "El año de publicacion es: " << cola_cancion6.front().anioPrimeraPublicacion << endl
					<< "El pais de piblicacionn es: " << cola_cancion6.front().paisGrabacion << endl
					<< "El nombre de la cancion es: " << cola_cancion6.front().nombreCancion << endl;
					cout<< "Las plataformas donde esta publicada son: ";
					for(int i=0; i<cola_cancion6.front().listadoLinks.get_size() ; i++){
						cout<< cola_cancion6.front().listadoLinks.get(i).nombrePlataforma << " ";
					}
				}
			}
	        cola_cancion6.pop();
	    }
	    cout << endl;
	}
	
	void consulta7(Cancion& cancion){
		ArbolAVL<Cancion> arbol7;
	    Cola<Cancion> cola_cancion7;
	    
	    for(int i=0; i<albumes.get_size(); i++ ){
        	Album album = albumes.get(i);
        	for(int j=0; j<album.listadoCanciones.get_size(); j++ ){
        		Cancion cancion1 = album.listadoCanciones.get(j);
        		arbol7.insertar(cancion1, charToNumber(cancion1.nombreArtistico[0]));
			}
		}

	    arbol7.inOrderIterativo(cola_cancion7);
	    while (!cola_cancion7.empty()) {
	    	for(int i=0; i<cola_cancion7.front().listadoLinks.get_size(); i++){
	    		cout<<cancion<<endl;
				cout<<"Lista Enlaces"<<endl;
			    for(int i=0; i<cancion.listadoLink.get_size(); i++){
			    	cout << cancion.listadoLinks.get(i).nombrePlataforma << " link: "<< cancion.listadoLinks.get(i).link;
				}
				cout<<"Lista Versiones"<<endl;
			    for(int i=0; i<cancion.listadoVersion.get_size(); i++){
			    	if(cancion.listadoVersion.get(i).tipoVersion == "Original"){
			    		cout << cancion.listadoVersion.get(i).tituloVersion << " link: "<< cancion.listadoVersion.get(i).artistaPrincipal;
					}
				}
			}
			cout << endl;
	        cola_cancion7.pop();
	    }   
	 
	}
	
	void consulta8(string cover){
		ArbolAVL<Album> arbol8;
	    Cola<Album> cola_album8;
	    
	    for(int i=0; i<albumes.get_size(); i++ ){
        	Album album = albumes.get(i);
        	arbol8.insertar(album, album.anioPublicacion);
		}

	    arbol8.inOrderIterativo(cola_album8);
	    while (!cola_album8.empty()) {
	    	if(cola_album8.front().coverArt == cover){
	    		for(int i=1; i < cola_album8.front().listadoCanciones.get_size() + 1;i++){
					cout << cola_album8.front().listadoCanciones.get(i).nombreCancion << "\n";
				}
			}
	    	
	        cola_album8.pop();
	    }
	}
	
	void consulta9(string fotografia, string estudio){
		ArbolAVL<Album> arbol9;
	    Cola<Album> cola_album9;
	    
	    Album* actual = cabEstudio.obtenerAlbumesPorCaract(fotografia);
	    while (actual != NULL) {
	        //cout << *actual << endl; // Usa la sobrecarga del operador <<
	        if(actual->estudioGrabacion == estudio){
	        	arbol9.insertar(*actual, charToNumber(actual->paisGrabacion[0]));
	        	actual = actual->sigEstudio;
			}
	    }
	    
	    
	    arbol9.inOrderIterativo(cola_album9);
	    while (!cola_album9.empty()){
	    	cout << cola_album9.front().titulo;
			cola_album9.pop();
	    }
    
	}
	
	void consulta10(string compositor){
		cout<<compositor<<endl;
    
	}
	
};

#endif

