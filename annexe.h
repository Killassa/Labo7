/*
-------------------------------------------------------------------------------------
Nom du fichier : annexe.h
Nom du labo    : Labo 7 - Matrice
Auteur(s)      : Grégory Rey-Mermet, Paul Gillet
Date creation  : 08.12.2021
Description    : Ce fichier d'en-tête (.h) met à la disposition de l'utilisateur
                 diverses fonctions utiles dont l'on pourrait avoir besoin dans une
                 multitude de projets différents.
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef LABO6_ANNEXE_H
#define LABO6_ANNEXE_H

#include <string>

/**
 * Vide le buffer
 */
void viderBuffer();

/**
 * Affiche un message et met en pause le programme jusqu'à ce que l'utilisateur
 * presse la touche ENTER
 *
 * @param message Message à afficher lors de la pause
 */
void pause(const std::string& message);

#endif //LABO6_ANNEXE_H
