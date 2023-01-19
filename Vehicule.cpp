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
void Vehicule::afficheVirtual() const
{
    cout << "Nom: " << m_nom << endl;
    cout << "Prix: " << m_prix << endl;
}
Vehicule::~Vehicule() //Même si le destructeur ne fait rien, on doit le mettre !
{}


void Voiture::affiche() const
{
    Vehicule::affiche();
    cout << "Nombre de portes: " << m_portes << endl;

}
void Voiture::afficheVirtual() const
{
    Vehicule::afficheVirtual();
    cout << "Nombre de portes: " << m_portes << endl;

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
Moto::~Moto() //Même si le destructeur ne fait rien, on doit le mettre !
{}

