#include <vector>
#include <string.h>
#ifndef FONCTIONS_H
#define FONCTIONS_H

using namespace std;

void menu();
void ajoutTache(vector<string>& tachesTab, int& numero);
void supprTache(vector<string>& tachesTab);
void afficherTaches(vector<string>& tachesTab);
void quitter();

#include "fonctions.cpp"
#endif //FONCTIONS_H