#include "Vehicule.hpp" // ATTENTION ! Ici ce sont des "" et pas des <>
#include <iostream>
#include <string>

using namespace std;

Vehicule::Vehicule() : m_nom("Vehicule"), m_prix(10000){}
Voiture::Voiture() : Vehicule(), m_portes(5){}
Moto::Moto() : Vehicule(), m_vitesse(360){}


void Vehicule::affiche() const
{
    cout << "Nom: " << m_nom << endl;
    cout << "Prix: " << m_prix << endl;
}


void Voiture::affiche() const
{
    Vehicule::affiche();
    cout << "Nombre de portes: " << m_portes << endl;

}

void Moto::affiche() const
{
    Vehicule::affiche();
    cout << "Vitesse max.: " << m_vitesse << endl;

}