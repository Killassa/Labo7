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
#include <numeric>
#include <iostream>

#include "matrice.h"

int addition(int a, int b);
Vecteur1D sommeVecteur(const Vecteur1D& v1, const Vecteur1D& v2);

ostream& operator << (ostream& os, const Vecteur1D& vecteur) {
   os << "(";
   for (Vecteur1D::const_iterator it = vecteur.begin(); it < vecteur.end(); ++it) {
      if (it != vecteur.begin())
         os << ", ";
      os << *it;
   }
   os << ")";
   return os;
}

ostream& operator << (ostream& os, const Matrice& matrice) {
   os << "[";
   for (Matrice::const_iterator it = matrice.begin(); it < matrice.end(); ++it) {
      if (it != matrice.begin())
         os << ", ";
      os << *it;
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

Vecteur1D sommeLigne(const Matrice& matrice) {

}

Vecteur1D sommeColonne(const Matrice& matrice) {
   if (estReguliere(matrice) && !matrice.empty())
      return Vecteur1D();

   return accumulate(matrice.begin(), matrice.end(), Vecteur1D(matrice[0].size()), sommeVecteur);
}

vector<int> vectSommeMin(const Matrice& matrice) {

}

void shuffleMatrice(const Matrice& matrice) {

}

void sortMatrice(const Matrice& matrice) {

}


int addition(int a, int b) {
   return a + b;
}

Vecteur1D sommeVecteur(const Vecteur1D& v1, const Vecteur1D& v2) {
   Vecteur1D somme(v1.size());

   transform(v1.begin(), v1.end(), v2.begin(), somme.begin(), addition);

   return somme;
}