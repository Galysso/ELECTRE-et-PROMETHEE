/* ---------------------- -*- Decision Engineering -*- ----------------------- */
//                                 main.cpp                                    //
//                                   C++                                       //
//                                  Projet                                     //
/* --------------------------------------------------------------------------- */
//              Réalisation de deux méthodes ELECTRE et PROMETHEE              //
/* --------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include "Electre.hpp"
#include "Promethee.hpp"

using namespace std;

void  lecture                (char*, int [][10]);
void  affichage              (int d[][10]);
float fonction_de_preference (int, int, int);

int main(int argc, char* argv[]) {
    
    // Matrice de taille 100*10 destinée à stocker la matrice du fichier d'entrée
    int d[200][10];
    
    // Poids des critères
    double poids = 0.1;
    
    // Indices de concordance et discordance pour ELECTRE
    double concordance[4] = {0.6,0.7,0.8,0.9};
    double discordance[5] = {0.1,0.15,0.2,0.25,0.3};
    
    // Seuils d'indifférence pour PROMETHEE
    int p[3] = {10,15,20};
    int q[3] = {90,85,80};
    
    // Lecture des données    
    lecture(argv[1], d);
    // Vérification de la lecture
    ///affichage(d);
    
    // Ensuite, c'est à vous à .... 
    
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"---------------------------------ELECTRE--------------------------------"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
//~ 
    Electre electre(d, poids, concordance, discordance);
    electre.afficherIndexC();
    cout << endl;
    electre.afficherIndexD();
    cout << endl;
    electre.afficherNonSurclasses();
    cout << endl;
    electre.afficherNbSurclassee();
    
    cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"--------------------------------PROMETHEE-------------------------------"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
    
    Promethee promethee(d, poids, p, q);
    promethee.afficherPreferencesGlobales();
    promethee.afficherScores();
	return 0;
}

// Lecture des données à partir du fichier "nom"
void lecture (char* nom, int d[][10]) {
		
	ifstream f(nom);
	
	// Lecture du fichier
	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 10; j++)	
			f >> d[i][j];
    f.close(); 
}

// Affichage des données sur console 
void affichage (int d[][10]) {
	
	// Lecture du fichier
	for (int i = 0; i < 200; i++) {
		for (int j = 0; j < 10; j++) 	
			cout << d[i][j] << "\t";	 
		cout << endl;
	}
}
