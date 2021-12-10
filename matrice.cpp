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
Vecteur1D::size_type maxCol(const Matrice& matrice);

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

/**
 * Indique si le premier vecteur est de même taille que le deuxième
 *
 * @param v1    Premier vecteur
 * @param v2    Deuxième vecteur
 * @return      True : les deux vecteurs ont la même taille / False : les deux
 *                     vecteurs ont une taille différentes
 */
bool estDeMemeTaille(const Vecteur1D& v1, const Vecteur1D& v2);

/**
 * Retourne la somme des éléments de chaque vecteur de la matrice
 *
 * @param vecteur   Vecteur qui va être sommé
 * @return          Entier qui vaut la somme de tous les éléments du vecteur
 */
int sommeVecteurLigne(const Vecteur1D& vecteur);

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
   if (!matrice.empty()) {
      bool carree = (*min_element(matrice.begin(),matrice.end(),plusGrandeTaille))
                    .size() == matrice.size();

      return carree;
   }
   return true;
}

bool estReguliere(const Matrice& matrice) {
   if (!matrice.empty()) {
      return equal(matrice.begin(),matrice.end()-1,matrice.begin()+1,
                   estDeMemeTaille);
   }
   return true;
}

Vecteur1D::size_type minCol(const Matrice& matrice) {
   Vecteur1D::size_type longueurMinimum = 0;
   if(!matrice.empty()){
      longueurMinimum = (*min_element(matrice.begin(),matrice.end(),
                                    plusGrandeTaille)).size();
   }
   return longueurMinimum;
}

Vecteur1D sommeLigne(const Matrice& matrice) {
   Vecteur1D vecteur(matrice.size());
   if(!matrice.empty()){
      transform(matrice.begin(),matrice.end(),vecteur.begin(),sommeVecteurLigne);
   }
   return vecteur;
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
   unsigned seed = (unsigned)std::chrono::system_clock::now().time_since_epoch().count();

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

bool estDeMemeTaille(const Vecteur1D& v1, const Vecteur1D& v2) {
   return v1.size() == v2.size();
}

Vecteur1D::size_type maxCol(const Matrice& matrice) {
   if (matrice.empty())
      return 0;

   return (*max_element(matrice.begin(), matrice.end(), plusGrandeTaille)).size();
}

Vecteur1D sommeVecteur(const Vecteur1D& v1, const Vecteur1D& v2) {
   Vecteur1D::size_type tailleMin = min(v1.size(), v2.size());
   Vecteur1D::size_type tailleMax = max(v1.size(), v2.size());

   //Ajout du dernier éléments si l'un des tableaux est plus grand que l'autre, sinon
   //ne fait rien
   Vecteur1D somme(tailleMax);

   copy(v1.begin() + (Vecteur1D::difference_type)tailleMin,
        v1.end(),
        somme.begin() + (Vecteur1D::difference_type)tailleMin);
   copy(v2.begin() + (Vecteur1D::difference_type)tailleMin,
        v2.end(),
        somme.begin() + (Vecteur1D::difference_type)tailleMin);

   transform(v1.begin(),
             v1.begin() + (Vecteur1D::difference_type)tailleMin,
             v2.begin(),
             somme.begin(),
             addition);

   return somme;
}

bool sommeEstPlusPetite(const Vecteur1D& v1, const Vecteur1D& v2) {
   if (accumulate(v1.begin(), v1.end(), 0) < accumulate(v2.begin(), v2.end(), 0))
      return true;

   return false;
}

int sommeVecteurLigne(const Vecteur1D& vecteur) {
   int sommeLigne = accumulate(vecteur.begin(),vecteur.end(),0);
   return sommeLigne;
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