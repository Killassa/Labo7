/*
-------------------------------------------------------------------------------------
Nom du fichier : matrice.h
Nom du labo    : Labo 7 - Matrice
Auteur(s)      : Grégory Rey-Mermet, Paul Gillet
Date creation  : 08.12.2021
Description    : Ce fichier d'en-tête (.h) met à la disposition de l'utilisateur
                 diverses fonctions utiles ...
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef LABO7_MATRICE_H
#define LABO7_MATRICE_H

#include <vector>

using namespace std;

using Vecteur1D = vector<int>;
using Matrice = vector<Vecteur1D>;

/**
 *
 * @param os
 * @param vecteur
 * @return
 */
ostream& operator << (ostream& os, const Vecteur1D& vecteur);

/**
 *
 * @param os
 * @param matrice
 * @return
 */
ostream& operator << (ostream& os, const Matrice& matrice);

/**
 *
 * @param matrice
 * @return
 */
bool estCarre(const Matrice& matrice);

/**
 *
 * @param matrice
 * @return
 */
bool estReguliere(const Matrice& matrice);

/**
 *
 * @param matrice
 * @return
 */
int minCol(const Matrice& matrice);

/**
 *
 * @param matrice
 * @return
 */
vector<int> sommeLigne(const Matrice& matrice);

/**
 *
 * @param matrice
 * @return
 */
vector<int> sommeColonne(const Matrice& matrice);

/**
 *
 * @param matrice
 * @return
 */
vector<int> vectSommeMin(const Matrice& matrice);

/**
 *
 * @param matrice
 */
void shuffleMatrice(const Matrice& matrice);

/**
 *
 * @param matrice
 */
void sortMatrice(const Matrice& matrice);

#endif //LABO7_MATRICE_H
