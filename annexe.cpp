/*
-------------------------------------------------------------------------------------
Nom du fichier : annexe.cpp
Nom du labo    : Labo 7 - Matrice
Auteur(s)      : Grégory Rey-Mermet, Paul Gillet
Date creation  : 08.12.2021
Description    : Ce fichier définit diverses fonctions utiles dont l'on pourrait
                 avoir besoin dans une multitude de projets différents.
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#include <iostream> //cout, cin
#include <limits>   //numeric_limits
#include <cassert>  //assert

#include "annexe.h"

using namespace std;

void viderBuffer() {
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void pause(const string& message) {
   cout << message;
   viderBuffer();
}