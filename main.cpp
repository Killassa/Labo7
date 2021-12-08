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


   /* -------------------------------------------------------------------------------
    *  Test temporaire
    * -----------------------------------------------------------------------------*/
   Matrice mat(1);
   mat[0] = {3, 2, 3, 4, 5, 6};
   mat[1] = {5, 7, 3, 4};
   mat[2] = {1, 2, 3, 4};
   mat[3] = {};

   cout << sommeColonne(mat) << endl;
   cout << vectSommeMin(mat) << endl;

   cout << mat << endl;
   shuffleMatrice(mat);
   cout << mat << endl;
   sortMatrice(mat);
   cout << mat << endl;



   /* -------------------------------------------------------------------------------
    *  Message de fin
    * -----------------------------------------------------------------------------*/
   pause(MSG_QUITTER);

   return EXIT_SUCCESS;
}