//Consultas AVL
#ifndef CONSULTASAVL_H
#define CONSULTASAVL_H

#include "ArbolAVL.h"
#include "Cola.h"
#include "Album.h"
#include "Cancion.h"
#include <iostream>


using namespace std;

class ConsultasAvl {
	
	Lista<Album> albumes;
public:
	
	ConsultasAvl(Lista<Album> albumes): albumes(albumes){};
	
    void ejecutarConsulta(int numeroConsulta) {
        switch (numeroConsulta) {
            case 1: consulta1(); break;
            /*case 2: consulta2(); break;
            case 3: consulta3(); break;
            case 4: consulta4(); break;
            case 5: consulta5(); break;
            case 6: consulta6(); break;
            case 7: consulta7(); break;
            case 8: consulta8(); break;
            case 9: consulta9(); break;*/
            default: cout << "Consulta no válida.\n"; break;
        }
    }

private:
	
	
	
    void consulta1() {
        Cola<Album> cola_album;
        ArbolAVL<Album> arbol1;
        for(int i=0; i<albumes.get_size(); i++ ){
        	Album album = albumes.get(i);
        	arbol1.insertar(album, album.anioPublicacion);
        	arbol1.inOrderIterativo(cola_album);
		}
        
        int acumulador = 0;
        while (!cola_album.empty()) {
            if (cola_album.front().editora == "Universal Music") {
                acumulador++;
            }
            cola_album.pop();
        }
        cout << "El número total de álbumes de Universal Music es: " << acumulador << "\n\n";
    }

	/*
    void consulta2() {
        Cola<Album> cola_album;
        ArbolAVL<Album> arbol2;
        arbol2.insertar(album, album.anioPublicacion);
        arbol2.inOrderIterativo(cola_album);
        while (!cola_album.empty()) {
            if (cola_album.front().estudioGrabacion == "Estudios Latam") {
                std::cout << cola_album.front().titulo << "\n";
                for (int i = 1; i <= cola_album.front().listadoCanciones.get_size(); i++) {
                    cout << cola_album.front().listadoCanciones.get(i).nombreCancion << "\n";
                }
            }
            cola_album.pop();
        }
        cout << "\n";
    }

    void consulta3() {
        Cola<Cancion> cola_cancion;
        ArbolAVL<Cancion> arbol3;
        arbol3.insertar(cancion1, charToNumber(cancion1.ciudadGrabacion[0]));
        arbol3.insertar(cancion2, charToNumber(cancion2.ciudadGrabacion[0]));
        arbol3.insertar(cancion3, charToNumber(cancion3.ciudadGrabacion[0]));
        arbol3.inOrderIterativo(cola_cancion);
        while (!cola_cancion.empty()) {
            if (stringToNumber(cola_cancion.front().duracion) > 10) {
               	cout << cola_cancion.front().arreglosMusicales << " "
                          << cola_cancion.front().compositorLetra << " "
                          << cola_cancion.front().compositorMusica << "\n";
            }
            cola_cancion.pop();
        }
        cout << "\n\n";
    }
    
    void consulta4(){
    	//Crear arbol y cola para la consulta 4 e insertar canciones
		ArbolAVL<Cancion> arbol4;
		Cola<Cancion> cola_cancion4;
		
		char nombre_cancion1 = cancion1.nombreCancion[0];
	    char nombre_cancion2 = cancion2.nombreCancion[0];
	    char nombre_cancion3 = cancion3.nombreCancion[0];
	    
	    arbol4.insertar(cancion1, charToNumber(nombre_cancion1));
	    arbol4.insertar(cancion2, charToNumber(nombre_cancion2));
	    arbol4.insertar(cancion3, charToNumber(nombre_cancion3));
	    
	
	    //Verificar los requisitos e imprimir las canciones que coinciden 
	    arbol4.inOrderIterativo(cola_cancion4);
	    while (!cola_cancion4.empty()) {
	    	if(cola_cancion4.front().genero == "Rock" && cola_cancion4.front().listadoArtistas.get(0).instrumento == "Guitarra"){
	        	cout << cola_cancion4.front().nombreCancion << " " << cola_cancion4.front().nombreArtistico << " Datos del artista: " << cola_cancion4.front().listadoArtistas.get(0).toCSV() <<"\n";
	    	}
	        cola_cancion4.pop();
	    }
	    cout << "\n";
	}
	
	
	void consulta5(){
		ArbolAVL<Cancion> arbol5;
	    Cola<Cancion> cola_cancion5;
		
		char genero_cancion1 = cancion1.genero[0];
	    char genero_cancion2 = cancion2.genero[0];
	    char genero_cancion3 = cancion3.genero[0];
	    
	    arbol5.insertar(cancion1, charToNumber(genero_cancion1));
	    arbol5.insertar(cancion2, charToNumber(genero_cancion2));
	    arbol5.insertar(cancion3, charToNumber(genero_cancion3));
	    
	    acumulador = 0;
	    arbol5.inOrderIterativo(cola_cancion5);
	    while (!cola_cancion5.empty()) {
	    	if(cola_cancion5.front().ListadoVersiones.get_size() > 2){
	    		acumulador++;
			}
	        cola_cancion5.pop();
	    }
	    cout << "la cantidad de albumes con una cantidad de versiones mayor a " << 2 <<" es " << acumulador << endl << endl;
	}
	
	void consulta6(){
		ArbolAVL<Cancion> arbol6;
	    Cola<Cancion> cola_cancion6;
	    
	    arbol6.insertar(cancion1, charToNumber(genero_cancion1));
	    arbol6.insertar(cancion2, charToNumber(genero_cancion2));
	    arbol6.insertar(cancion3, charToNumber(genero_cancion3));
	    
	    arbol6.inOrderIterativo(cola_cancion6);
	    while (!cola_cancion6.empty()) {
	    	for(int i=0; i < cola_cancion6.front().ListadoVersiones.get_size() ;i++){
	    		if(cola_cancion6.front().ListadoVersiones.get(i).tipoVersion == "remix"){
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
	
	void consulta7(){
		ArbolAVL<Cancion> arbol7;
	    Cola<Cancion> cola_cancion7;
	    
	    arbol7.insertar(cancion1, charToNumber(genero_cancion1));
	    arbol7.insertar(cancion2, charToNumber(genero_cancion2));
	    arbol7.insertar(cancion3, charToNumber(genero_cancion3));
	    
	    arbol7.inOrderIterativo(cola_cancion7);
	    while (!cola_cancion7.empty()) {
	    	for(int i=0; i<cola_cancion7.front().listadoLinks.get_size(); i++){
	    		cout << cola_cancion7.front().listadoLinks.get(i).nombrePlataforma << " link: "<< cola_cancion7.front().listadoLinks.get(i).linkCancion;
			}
			cout << endl;
	        cola_cancion7.pop();
	    }   
	 
	}
	
	void consulta8(){
		ArbolAVL<Album> arbol8;
	    Cola<Album> cola_album8;
	    
	    arbol8.insertar(album, album.anioPublicacion);
	    
	    
	    arbol8.inOrderIterativo(cola_album8);
	    while (!cola_album8.empty()) {
	    	if(cola_album8.front().coverArt == "cover.jpg"){
	    		for(int i=1; i < cola_album8.front().listadoCanciones.get_size() + 1;i++){
					cout << cola_album8.front().listadoCanciones.get(i).nombreCancion << "\n";
				}
			}
	    	
	        cola_album8.pop();
	    }
	}
	
	void consulta9(){
		ArbolAVL<Album> arbol9;
	    Cola<Album> cola_album9;
	    
	    char Pais_album = album.paisGrabacion[0];
	    
	    arbol9.insertar(album, charToNumber(Pais_album));
	    
	    arbol9.inOrderIterativo(cola_album9);
	    while (!cola_album9.empty()){
	    	if(cola_album9.front().fotografia == "fotografia.jpg" && cola_album9.front().estudioGrabacion == "Estudios Latam"){
	    		cout << cola_album9.front().titulo;
			}
	        cola_album9.pop();
	    }
    
	}
	*/
};

#endif

