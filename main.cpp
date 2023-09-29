//Projet C++ : Application de gestion de taches.
//l'utilisateur pourra créer une tache, la supprimer et il y a la  possibilité d'afficher toutes les taches
//ce projet utilise les entrées et sorties, les tableaux dynamique et la gestion de fichiers.
//Version 1 (28/09/2023)
//Par Anis Youcef-Zahra
//GitHub.com/AnisBzrs

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "fonctions.h"

using namespace std;

//fonction main

int main()
{
    //declaration des variables

    int choix, numTache;
    vector<string> tache;

    menu(); //appelle la fonction comprenant le menu de l'application

    do
    {
        cin >> choix;

        switch (choix) //j'utilise une boucle switch car elle s'adapte mieux a mon programme
        {
        case 1 :
            ajoutTache(tache, numTache); //si l'utilisateur entre 1, il pourra ajouter une tache
            break;

        case 2 : 
            supprTache(tache);//si l'utilisateur entre 2, il pourra supprimer une tache sélectionnée
            break;

        case 3 :
            afficherTaches(tache);//si l'utilisateur entre 3, il pourra afficher les taches contenues dans le fichier
            break;

        case 4 :
            quitter(); //en tapant 4, le programme se fermera.
            break;

        default: ;
        }


    } while (choix != 5);
    
    return 0;
}