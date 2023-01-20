#ifndef VEHICULE_H_INCLUDED
#define VEHICULE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Vehicule
{
    public:
    Vehicule();
    Vehicule(int prix, int annee);
    void affiche() const;  //Affiche une description du Vehicule
    virtual void afficheVirtual() const;  //Affiche une description du Vehicule
    virtual int getRoues() const;  // ici, si je n'avais pas utilisé une methode virtuelle, alors Moto.getRoues() et Camion.getRoues() m'auraient renvoyé 4.
                                    // la methode getRoues est delicate pour un Vehicule lambda, car on ne sait pas combien de roues le vehicule a.
                                   // si on ne déclare pas cette fonction ici, on ne pourra pas l'utiliser depuis notre collection hétérogène.
                                   // la solution est alors de crée une méthode virtuelle pure, ce qui se fait en ajouant le  "=0" à la fin (ici après le const).
                                   // par contre, faire ceci rendra la classe vehicule "abstraite", et on ne pourra plus créer d'instance de cette classe
                                   // le reste du code ne fonctionnera plus, donc je ne le fais pas ici ... mais il faudrait essayer !
    virtual ~Vehicule();          //Remarquez le 'virtual' ici

    protected:
    std::string m_nom;
    int m_prix, m_annee;  //Chaque véhicule a un prix et une année de fabriacation
};

class Voiture : public Vehicule // attention à ne pas oublier le public ici
{
    public:
    void affiche() const;
    virtual void afficheVirtual() const;
    virtual int getRoues() const;
    Voiture();
    Voiture(int prix, int annee, int portes);

    virtual ~Voiture();          //Remarquez le 'virtual' ici

    protected: 
    int m_portes;
};

class Moto : public Vehicule
{
    public:

    void affiche() const;
    virtual void afficheVirtual() const;
    virtual int getRoues() const;
    Moto();
    Moto(int prix, int annee,int vitesse);
    virtual ~Moto();          //Remarquez le 'virtual' ici

    protected: 
    double m_vitesse;
};

class Camion : public Vehicule
{
    public:

    void affiche() const;
    virtual void afficheVirtual() const;
    virtual int getRoues() const;
    Camion();
    Camion(int prix, int annee, int poids);
    virtual ~Camion();          //Remarquez le 'virtual' ici

    protected: 
    int m_poids;
};



class Garage
{
    public:

    Garage();
    void ajoutVehicule(Vehicule* inVehicule); // ici, j'ai mis un pointeur Vehicule, pas sûr que ce soit la bonne méthode, mais ça fonctionne ...
    void retraitVehicule(int i);
    void afficherVehicules();
    int getNombreVehicules();

    protected:
    std::vector<Vehicule*> m_listeVehicules;
};


#endif // VEHICULE_H_INCLUDED