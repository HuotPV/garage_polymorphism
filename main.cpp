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
    vector<Vehicule*> listeVehicules1;

    listeVehicules1.push_back(new Voiture(15000,5,2008));
    listeVehicules1.push_back(new Voiture(8000,3,2007));
    listeVehicules1.push_back(new Moto(4000,140,2012));
    listeVehicules1.push_back(new Vehicule(10000,2000));
    listeVehicules1.push_back(new Camion(30000,1995,20));
    listeVehicules1.push_back(new Camion(120000,2005,35));

    listeVehicules1[0]->afficheVirtual();
    listeVehicules1[2]->afficheVirtual();
    listeVehicules1[5]->afficheVirtual();

    Garage garage1;
    Moto maMoto(10000,1985,100);
    Camion monCamion(30000,1985,35);

    cout << "Nombre de roues !" << endl;

    cout << maMoto.getRoues() << endl;
    cout << monCamion.getRoues() << endl;

    cout << "Ajout vehicules tests" << endl;
    //garage1.ajoutVehicule(maMoto);
    //garage1.ajoutVehicule(monCamion);
    garage1.ajoutVehicule(new Camion(120000,2005,35));
    garage1.ajoutVehicule(new Moto(1000,1988,100));
    cout << "liste vehicules tests" << endl;
    garage1.afficherVehicules();
    cout << garage1.getNombreVehicules() << endl;
    cout << "retrait vehicules tests" << endl;
    garage1.retraitVehicule(0);
    garage1.retraitVehicule(1);
    cout << "fin tests" << endl;
    cout << garage1.getNombreVehicules() << endl; 
    //garage1.afficherVehicules(); // ce truc ne fonctionne pas ici ... J'ai un Segmentation fault ! à revoir

    for (int i=0; i<listeVehicules1.size() ; i++)
    {
        delete listeVehicules1[i]; //On libère la i-ème case mémoire allouée
        listeVehicules1[i] = 0; // on met le pointeur à 0 pour éviter les soucis ...
    }

    return 0;
}