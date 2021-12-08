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

/**
 *
 * @param os
 * @param vecteur
 * @return
 */
ostream& operator << (ostream& os, const vector<int>& vecteur);

/**
 *
 * @param os
 * @param matrice
 * @return
 */
ostream& operator << (ostream& os, const vector<vector<int>>& matrice);

/**
 *
 * @param matrice
 * @return
 */
bool estCarre(const vector<vector<int>>& matrice);

/**
 *
 * @param matrice
 * @return
 */
bool estReguliere(const vector<vector<int>>& matrice);

/**
 *
 * @param matrice
 * @return
 */
int minCol(const vector<vector<int>>& matrice);

/**
 *
 * @param matrice
 * @return
 */
vector<int> sommeLigne(const vector<vector<int>>& matrice);

/**
 *
 * @param matrice
 * @return
 */
vector<int> sommeColonne(const vector<vector<int>>& matrice);

/**
 *
 * @param matrice
 * @return
 */
vector<int> vectSommeMin(const vector<vector<int>>& matrice);

/**
 *
 * @param matrice
 */
void shuffleMatrice(const vector<vector<int>>& matrice);

/**
 *
 * @param matrice
 */
void sortMatrice(const vector<vector<int>>& matrice);

#endif //LABO7_MATRICE_H
