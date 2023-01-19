#ifndef VEHICULE_H_INCLUDED
#define VEHICULE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

class Vehicule
{
    public:
    Vehicule();
    void affiche() const;  //Affiche une description du Vehicule

    protected:
    std::string m_nom;
    int m_prix;  //Chaque véhicule a un prix
};

class Voiture : Vehicule
{
    public:
    void affiche() const;
    Voiture();

    protected: 
    int m_portes;
};

class Moto : Vehicule
{
    public:
    void affiche() const;
    Moto();

    protected: 
    double m_vitesse;
};


#endif // VEHICULE_H_INCLUDED