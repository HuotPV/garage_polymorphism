#include "Vehicule.hpp" // ATTENTION ! Ici ce sont des "" et pas des <>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


Vehicule::Vehicule() : m_nom("Vehicule"), m_prix(10000), m_annee(2000), m_roues(4){}
Vehicule::Vehicule(int prix, int annee) : m_nom("Vehicule"), m_prix(prix), m_annee(annee), m_roues(4){}


void Vehicule::affiche() const
{
    cout << "Nom: " << m_nom << endl;
    cout << "Prix: " << m_prix << endl;
    cout << "Annee de fabrication: " << m_annee << endl;
}
void Vehicule::afficheVirtual() const
{
    cout << "Nom: " << m_nom << endl;
    cout << "Prix: " << m_prix << endl;
    cout << "Annee de fabrication: " << m_annee << endl;
}
int Vehicule::getRoues() const
{
    return m_roues;
}

Vehicule::~Vehicule()
{} //Même si le destructeur ne fait rien, on doit le mettre !


Voiture::Voiture() : Vehicule(), m_portes(5){}
Voiture::Voiture(int prix, int annee, int portes) : Vehicule(prix,annee), m_portes(portes){}
Moto::Moto() : Vehicule(), m_vitesse(360){}
Moto::Moto(int prix, int annee, int vitesse) : Vehicule(prix,annee), m_roues(2), m_vitesse(vitesse){}
Camion::Camion() : Vehicule(), m_poids(35){}
Camion::Camion(int prix, int annee, int poids) : Vehicule(prix,annee), m_roues(6), m_poids(poids){}
Garage::Garage() : m_listeVehicules(0){}

void Garage::ajoutVehicule(Vehicule* inVehicule) // ici j'utilise le pointeur inVehicule en entrée ...
{
    m_listeVehicules.push_back(inVehicule);
}

void Garage::retraitVehicule(int i)
{
    delete m_listeVehicules[i]; // on supprime l'instance de Vehicule vers lequel m_listeVehicules[i] pointe ...
    m_listeVehicules[i] = nullptr; // reset le pointeur à 0 pour qu'il ne pointe nulle par ...
    // On a effectivement enlever un élément du garage, mais la taille de listeVehicules n'a pas diminué ....
}

int Garage::getNombreVehicules()
{
    return m_listeVehicules.size();
}

void Garage::afficherVehicules()
{ 
    cout << "La liste de vehicules est:" << endl;
    for (int i = 0; i < m_listeVehicules.size() ; i++)
        {
            m_listeVehicules[i]->afficheVirtual();
        }
}


void Voiture::affiche() const  // En pratique, il n'y a pas besoin de duppliquer les méthodes en "methode normale" et "méthode virtuelle". C'est juste pour l'exemple ivi
{
    Vehicule::affiche();
    cout << "Nombre de portes: " << m_portes << endl;

}
void Voiture::afficheVirtual() const
{
    Vehicule::afficheVirtual();
    cout << "Nombre de portes: " << m_portes << endl;

}
int Voiture::getRoues() const
{
    return m_roues;
}
Voiture::~Voiture() //Même si le destructeur ne fait rien, on doit le mettre !
{}


void Moto::affiche() const
{
    Vehicule::affiche();
    cout << "Vitesse max.: " << m_vitesse << endl;

}
void Moto::afficheVirtual() const
{
    Vehicule::afficheVirtual();
    cout << "Vitesse max.: " << m_vitesse << endl;
}
int Moto::getRoues() const
{
    return m_roues;
}
Moto::~Moto() //Même si le destructeur ne fait rien, on doit le mettre !
{}



void Camion::affiche() const
{
    Vehicule::affiche();
    cout << "Charge max.: " << m_poids << endl;

}
void Camion::afficheVirtual() const
{
    Vehicule::afficheVirtual();
    cout << "Charge max.: " << m_poids << endl;
}
int Camion::getRoues() const
{
    return m_roues;
}
Camion::~Camion() //Même si le destructeur ne fait rien, on doit le mettre !
{}

