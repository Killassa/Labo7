/*
-------------------------------------------------------------------------------------
Nom du fichier : matrice.cpp
Nom du labo    : Labo 7 - Matrice
Auteur(s)      : Grégory Rey-Mermet, Paul Gillet
Date creation  : 08.12.2021
Description    : Ce fichier définit diverses fonctions utiles permettant une
                 manipulation facilitées de vecteurs et de matrices d'entier
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#include <algorithm> //Pour les différents algorithmes utilisés
#include <numeric>   //accumulate
#include <chrono>    //chrono::system_clock
#include <random>    //default_random_engine

#include "matrice.h"

using namespace std;

/**
 * Additionner 2 entiers
 *
 * @param a     Premier entier
 * @param b     Deuxième entier
 * @return      La somme de 2 entiers
 */
int addition(int a, int b);

/**
 * Indique si le premier vecteur est plus grand que le deuxième
 *
 * @param v1    Premier vecteur
 * @param v2    Deuxième vecteur
 * @return      True : v2 est plus grand que v1 / False : v1 est plus grand que v2
 */
bool plusGrandeTaille(const Vecteur1D& v1, const Vecteur1D& v2);

/**
 * Indique le nombre de colonne de la ligne la plus longue de la matrice
 *
 * @param matrice   Matrice pour la recherche de la ligne la plus longue
 * @return          Nombre total de colonne de la ligne la plus longue
 */
int maxCol(const Matrice& matrice);

/**
 * Effectue la somme de 2 vecteurs
 *
 * @param v1    Premier vecteur
 * @param v2    Deuxième vecteur
 * @return      Le vecteur résultant de la somme des 2 vecteurs
 */
Vecteur1D sommeVecteur(const Vecteur1D& v1, const Vecteur1D& v2);

/**
 * Indique si la somme des éléments du premier vecteur est plus petite que celle du
 * deuxième vecteur
 *
 * @param v1    Premier vecteur
 * @param v2    Deuxième vecteur
 * @return      True : la somme de v1 est plus petite / False : la somme de v2 est
 *                     plus petite
 */
bool sommeEstPlusPetite(const Vecteur1D& v1, const Vecteur1D& v2);

/**
 * Indique si le plus petit élément du premier vecteur est plus petit que le plus
 * petit élément du deuxième vecteur
 *
 * @param v1    Premier vecteur
 * @param v2    Deuxième vecteur
 * @return      True : le plus petit élément de v1 est plus petit / False : le plus
 *                     petit élément de v2 est plus petit
 */
bool estPlusPetitVecteur(const Vecteur1D& v1, const Vecteur1D& v2);

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
   return Vecteur1D();
}

Vecteur1D sommeColonne(const Matrice& matrice) {
   return accumulate(matrice.begin(), matrice.end(), Vecteur1D(maxCol(matrice)), sommeVecteur);
}

Vecteur1D vectSommeMin(const Matrice& matrice) {
   if (matrice.empty())
      return Vecteur1D{};

   return *min_element(matrice.begin(), matrice.end(), sommeEstPlusPetite);
}

void shuffleMatrice(Matrice& matrice) {
   //Obtenir une seed basée sur l'horloge système
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

   shuffle(matrice.begin(), matrice.end(), std::default_random_engine(seed));
}

void sortMatrice(Matrice& matrice) {
   sort(matrice.begin(), matrice.end(), estPlusPetitVecteur);
}

/* -------------------------------------------------------------------------------
 *  Fonctions utiles
 * -----------------------------------------------------------------------------*/
int addition(int a, int b) {
   return a + b;
}

bool plusGrandeTaille(const Vecteur1D& v1, const Vecteur1D& v2) {
   return v1.size() < v2.size();
}

int maxCol(const Matrice& matrice) {
   if (matrice.empty())
      return 0;

   return (int)max_element(matrice.begin(), matrice.end(), plusGrandeTaille)->size();
}


Vecteur1D sommeVecteur(const Vecteur1D& v1, const Vecteur1D& v2) {
   int tailleMin = (int)min(v1.size(), v2.size());
   int tailleMax = (int)max(v1.size(), v2.size());

   //Ajout du dernier éléments si l'un des tableaux est plus grand que l'autre, sinon
   //ne fait rien
   Vecteur1D somme(tailleMax);
   copy(v1.begin() + tailleMin, v1.end(), somme.begin() + tailleMin);
   copy(v2.begin() + tailleMin, v2.end(), somme.begin() + tailleMin);

   transform(v1.begin(), v1.begin() + tailleMin, v2.begin(), somme.begin(), addition);

   return somme;
}

bool sommeEstPlusPetite(const Vecteur1D& v1, const Vecteur1D& v2) {
   if (accumulate(v1.begin(), v1.end(), 0) < accumulate(v2.begin(), v2.end(), 0))
      return true;

   return false;
}

bool estPlusPetitVecteur(const Vecteur1D& v1, const Vecteur1D& v2) {
   if (v1.empty())
      return true;

   if (v2.empty())
      return false;

   if (*min_element(v1.begin(), v1.end()) < *min_element(v2.begin(), v2.end()))
      return true;

   return false;
}