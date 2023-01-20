#ifndef VEHICULE_H_INCLUDED
#define VEHICULE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

class Vehicule
{
    public:
    Vehicule();
    Vehicule(int prix);
    void affiche() const;  //Affiche une description du Vehicule
    virtual void afficheVirtual() const;  //Affiche une description du Vehicule
    virtual ~Vehicule();          //Remarquez le 'virtual' ici

    protected:
    std::string m_nom;
    int m_prix;  //Chaque véhicule a un prix
};

class Voiture : public Vehicule // attention à ne pas oublier le public ici
{
    public:
    void affiche() const;
    virtual void afficheVirtual() const;
    Voiture();
    Voiture(int prix, int portes);

    virtual ~Voiture();          //Remarquez le 'virtual' ici

    protected: 
    int m_portes;
};

class Moto : public Vehicule
{
    public:

    void affiche() const;
    virtual void afficheVirtual() const;
    Moto();
    Moto(int prix, int vitesse);
    virtual ~Moto();          //Remarquez le 'virtual' ici

    protected: 
    double m_vitesse;
};

#endif // VEHICULE_H_INCLUDED