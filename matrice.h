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
 * Retourne un vecteur contenant la somme des valeurs de chacune des colonnes
 *
 * @param matrice   Matrice sur laquelle on effectue la somme des valeurs des colonnes
 * @return          Vecteur contenant la somme des valeurs des colonnes
 */
vector<int> sommeColonne(const Matrice& matrice);

/**
 * Retour le vecteur d’une matrice dont la somme des valeurs est la plus faible
 * Si plusieurs vecteurs présentent la même somme, la fonction retourne celui
 * d’indice le plus faible
 *
 * @param matrice   Matrice pour la recherche du vecteur
 * @return          Vecteur comprenant la somme des valeurs la plus faible
 */
vector<int> vectSommeMin(const Matrice& matrice);

/**
 * Mélanger les vecteurs d’une matrice sans altérer les vecteurs, La seed du
 * générateur est basée sur l’heure
 *
 * Remarque : Inspiré du fonctionnement suivant :
 *            http://www.cplusplus.com/reference/algorithm/shuffle/?kw=shuffle
 *
 * @param matrice   La matrice à mélanger
 */
void shuffleMatrice(Matrice& matrice);

/**
 * Effectue un tri dans l’ordre croissant une matrice en fonction de l’élément min
 * d’un vecteur
 *
 * @param matrice   La matrice à trier
 */
void sortMatrice(Matrice& matrice);

#endif //LABO7_MATRICE_H
