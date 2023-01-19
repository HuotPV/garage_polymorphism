/*
Cours OpenClassRoom sur le polymorphisme
*/

#include "Vehicule.hpp" // ATTENTION ! Ici ce sont des "" et pas des <>
#include <iostream>
#include <string>

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
    cout << "Avec les methodes (et les methodes masquées) de chaque classe: " << endl;
    Vehicule v1;
    v1.affiche();

    Voiture v2;
    v2.affiche();

    Moto m1;
    m1.affiche();

    cout << "Avec la fonction presenter(Vehicule v): " << endl;

    presenter(v1); // de base, dans ce cas de figure, la fonction présenter va utiliser la méthode 
    presenter(v2); // "affiche" de l'objet en argument: càd Vehicule, que ce soit la classe mère (Vehicule)
    presenter(m1); // ou des classes filles (Voiture, Moto)

    cout << "Avec les méthodes virtuelles et la référence: " << endl;

    presenterRef(v1); // ici, on se retrouve bien avec la méthode propre à chaque classe
    presenterRef(v2); // c'est grace au fait qu'on utilise ici une méthode virtuelle: virtual afficheVirtual() const;
    presenterRef(m1); // et que l'on passe une reference à un Vehicule en argument, et non un Vehicule (ça marcherait aussi avec un pointeur)

    Vehicule *v3, *v4;
    v3 = new Vehicule();
    v4 = new Moto();

    cout << "Avec des pointeurs, en utilisant la méthode affiche" << endl;
    v3->affiche();
    v4->affiche();

    cout << "Avec des pointeurs, en utilisant la méthode virtuelle afficheVirtual" << endl;
    v3->afficheVirtual();
    v4->afficheVirtual();

    return 0;
}