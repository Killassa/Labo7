/*
-------------------------------------------------------------------------------------
Nom du fichier : matrice.cpp
Nom du labo    : Labo 7 - Matrice
Auteur(s)      : Grégory Rey-Mermet, Paul Gillet
Date creation  : 08.12.2021
Description    : Ce fichier définit diverses fonctions utiles ...
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#include <algorithm>
#include <iostream>
#include "matrice.h"

ostream& operator << (ostream& os, const Vecteur1D& vecteur) {
      os << "[";
      for (size_t i=0; i<vecteur.size(); ++i) {
         if (i)
            os << ", ";
         os << vecteur[i];
      }
      os << "]";
      return os;
   }


ostream& operator << (ostream& os, const Matrice& matrice) {
   os << "[";
   for (size_t i=0; i<matrice.size(); ++i) {
      if (i)
         os << ", ";
      os << matrice[i];
   }
   os << "]";
   return os;
}

bool estCarre(const vector<vector<int>>& matrice) {

}

bool estReguliere(const Matrice& matrice) {

}

int minCol(const Matrice& matrice) {

}

vector<int> sommeLigne(const Matrice& matrice) {

}

vector<int> sommeColonne(const Matrice& matrice) {

}

vector<int> vectSommeMin(const Matrice& matrice) {

}

void shuffleMatrice(const Matrice& matrice) {

}

void sortMatrice(const Matrice& matrice) {

}