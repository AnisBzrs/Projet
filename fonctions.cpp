#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "fonctions.h"

using namespace std;

void menu()
{
    cout << "\tBienvenue dans ce programme de gestions de taches :" << endl;
    cout << "Pour choisir une action a realiser, appuyez sur les touches de 1 à 5." << endl;
    cout << "1 : Ajouter une tache." << endl;
    cout << "2 : Supprimmer une tache." << endl;
    cout << "3 : Afficher toutes les taches." << endl;
    cout << "4 : Quitter." << endl;   
}

void ajoutTache(vector<string>& tachesTab, int& numero)
{
    int num;
    string nom;
    string descrip;

    cout << "Numero de tache : ";
    getchar();
    cin >> numero ; 
    
    cout << "Nom de la tache : ";
    getchar();
    getline(cin, nom);   
    
    cout << "Description de la tache : ";
    getline(cin, descrip);
   
    string tache = to_string(numero) + " " + nom + " " + descrip; //stocke le nom et la description dans un string tache. to_string converti un int en chaine de caractere
    tachesTab.push_back(tache); //insere la tache dans le tableau dynamique tachesTab

    ofstream monFichier("C:/Users/bzrsa/Desktop/Code/C++_2023/Projet/taches.txt", ios::app | ios::out);
    if (monFichier)
    {
        monFichier << "  " << nom << descrip << endl;
        cout << "Tache ajoutee avec succes." << endl;
    }
    else
    {
        cout << "ERREUR : Impossible d'ouvrir le fichier." << endl;
    }
}

void supprTache(vector<string>& tachesTab)
{
    int numero; 
    int i;
    cout << "Entrez le numero de la tache a supprimer : " ; 
    cin >> numero;

    ofstream monFichier("C:/Users/bzrsa/Desktop/Code/C++_2023/Projet/taches.txt", ios::out); //ouvre le fichier en mode écriture
    if (!monFichier)
    {
        cout << "ERREUR : Impossible d'ouvrir le fichier." << endl;
        return;
    }

    for (auto it = tachesTab.begin(); it != tachesTab.end(); ++it) //parcourt le tableau tachesTab
    {
        string tache = *it;
        int num = stoi(tache.substr(0, tache.find(" "))); //extrait le numéro de la tâche
        if (num == numero) //vérifie si le numéro correspond à celui de la tâche à supprimer
        {
            tachesTab.erase(it); //supprime la tâche du tableau
            for (string tache : tachesTab) //parcourt le tableau tachesTab
            {
                monFichier << tache << endl; //écrit chaque tâche dans le fichier
            }
            cout << "Tache supprimee avec succes." << endl;
            return;
        }
    }
    cout << "ERREUR : Tache non trouvee." << endl;
}


void afficherTaches(vector<string>& tachesTab)
{
    if (tachesTab.empty()) //verifie si le tableau est vide
    {
        cout << "Aucune taches a afficher." << endl;
    }
    
    cout << "Liste des taches : " << endl;
    for (string tache : tachesTab) //la boucle parcours tout le fichier de taches et en affiche le contenu.
    {
        cout << tache << endl;
    }
    
}

void quitter() //ferme simplement le programme
{
    cout << "Fermeture du programme, a bientot !" << endl;
    exit(0); 
}