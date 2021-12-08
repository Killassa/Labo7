/*
-----------------------------------------------------------------------------------
Nom du fichier : main.cpp
Nom du labo    : Labo 7 - Matrice
Auteur(s)      : Grégory Rey-Mermet, Paul Gillet
Date creation  : 08.12.2021
Description    :
Remarque(s)    :
Compilateur    : Mingw-w64 g++ 11.2.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>

#include "annexe.h"
#include "matrice.h"

using namespace std;


int main() {
   //Message de fin pour quitter le programme
   const string MSG_QUITTER = "Presser ENTER pour quitter";

   //Utilisation d'un vecteur de matrice pour tester différents cas possibles
   vector<Matrice> vecteurTest;
   vecteurTest.push_back( {});
   vecteurTest.push_back({{},
                          {},
                          {}
   });
   vecteurTest.push_back({{},
                          {2, 4},
                          {1,-5, 1, 3, 9},
                          {3, 8, 4}
   });
   vecteurTest.push_back({{1, 2, 3},
                          {4, 5, 6},
                          {3,-2, 1},
                          {6, 5, 4}
   });
   vecteurTest.push_back({{7, 8, 9},
                          {4, 5, 6},
                          {1, 2, 3},
   });

   cout << boolalpha;
   for (Matrice mat : vecteurTest) {
      cout << "============================================================" << endl;
      cout << "Matrice                        : " << mat                     << endl;
      //cout << "Carree                         : " << estCarre(mat)           << endl;
      //cout << "Reguliere                      : " << estReguliere(mat)       << endl;
      //cout << "Longueur du plus petit vecteur : " << minCol(mat)             << endl;
      //cout << "Sommes des lignes              : " << sommeLigne(mat)         << endl;
      cout << "Sommes des colonnes            : " << sommeColonne(mat)       << endl;
      cout << "Plus petite somme              : " << vectSommeMin(mat)       << endl;
      shuffleMatrice(mat);
      cout << "Melange matrice                : " << mat                     << endl;
      sortMatrice(mat);
      cout << "Tri matrice                    : " << mat                     << endl;
      cout << "============================================================" << endl;
      cout << endl << endl;
   }

   /* -------------------------------------------------------------------------------
    *  Message de fin
    * -----------------------------------------------------------------------------*/
   pause(MSG_QUITTER);

   return EXIT_SUCCESS;
}