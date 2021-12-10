/*
-------------------------------------------------------------------------------------
Nom du fichier : matrice.h
Nom du labo    : Labo 7 - Matrice
Auteur(s)      : Grégory Rey-Mermet, Paul Gillet
Date creation  : 08.12.2021
Description    : Ce fichier d'en-tête (.h) met à la disposition de l'utilisateur
                 diverses fonctions utiles permettant une manipulation facilitées de
                 vecteurs et de matrices d'entier
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef LABO7_MATRICE_H
#define LABO7_MATRICE_H

#include <iostream>  //cout
#include <vector>

using Vecteur1D = std::vector<int>;
using Matrice = std::vector<Vecteur1D>;

/**
 * Surcharge de l'opérateur de flux d'écriture pour afficher un vecteur
 *
 * @param os        Flux
 * @param vecteur   Vecteur dont l'affichage sera formaté
 * @return          Le flux d'origine avec affichage formaté
 */
std::ostream& operator << (std::ostream& os, const Vecteur1D& vecteur);

/**
 * Surcharge de l'opérateur de flux d'écriture pour afficher un matrice
 *
 * @param os        Flux
 * @param matrice   Matrice dont l'affichage sera formaté
 * @return          Le flux d'origine avec affichage formaté
 */
std::ostream& operator << (std::ostream& os, const Matrice& matrice);

/**
 * Retourne si une matrice est carrée (est carrée si le nombre de ligne est égal
 * au nombre de colonne)
 *
 * @param matrice   Matrice
 * @return          True : la matrice est carrée / False : la matrice n'est pas carrée
 */
bool estCarre(const Matrice& matrice);

/**
 * Retourne si une matrice est régulière (est régulière si chaque ligne à la même
 * taille)
 *
 * @param matrice   Matrice
 * @return          True :  La matrice est régulière / False : la matrice n'est pas
 *                  régulière
 */
bool estReguliere(const Matrice& matrice);

/**
 * Retourne la taille du plus petit vecteur de la matrice
 *
 * @param matrice   Matrice dans laquelle on va chercher la taille du vecteur le
 *                  plus petit
 * @return          Taille du plus petit vecteur
 */
size_t minCol(const Matrice& matrice);

/**
 * Retourne un vecteur contenant la somme des éléments de chaque vecteur de la
 * matrice (ligne)
 *
 * @param matrice   Matrice sur laquelle on effectue la somme
 * @return          Vecteur contenant la somme des éléments des lignes
 */
Vecteur1D sommeLigne(const Matrice& matrice);

/**
 * Retourne un vecteur contenant la somme des valeurs de chacune des colonnes
 *
 * @param matrice   Matrice sur laquelle on effectue la somme des valeurs des colonnes
 * @return          Vecteur contenant la somme des valeurs des colonnes
 */
Vecteur1D sommeColonne(const Matrice& matrice);

/**
 * Retour le vecteur d’une matrice dont la somme des valeurs est la plus faible
 * Si plusieurs vecteurs présentent la même somme, la fonction retourne celui
 * d’indice le plus faible
 *
 * @param matrice   Matrice pour la recherche du vecteur
 * @return          Vecteur comprenant la somme des valeurs la plus faible
 */
Vecteur1D vectSommeMin(const Matrice& matrice);

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
