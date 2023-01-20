/*
Cours OpenClassRoom sur le polymorphisme
*/

#include "Vehicule.hpp" // ATTENTION ! Ici ce sont des "" et pas des <>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void presenter(Vehicule v)  //Présente le véhicule passé en argument
{
    v.affiche();
}

void presenterRef(Vehicule const& v)  //Présente le véhicule passé en argument
{
    v.afficheVirtual();
}

int main()
{
    vector<Vehicule*> listeVehicules;

    listeVehicules.push_back(new Voiture(15000,5));
    listeVehicules.push_back(new Voiture(8000,3));
    listeVehicules.push_back(new Moto(4000,140));
    listeVehicules.push_back(new Vehicule(10000));

    for (int i=0; listeVehicules.size() ; i++)
    {
        delete listeVehicules[i]; //On libère la i-ème case mémoire allouée
        listeVehicules[i] = 0; // on met le pointeur à 0 pour éviter les soucis ...
    }

    return 0;
}