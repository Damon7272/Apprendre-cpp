#include "barre.h"


Barre::Barre(string _ref, string _nom):
    ref(_ref),
    nom(_nom)
{
    cout << "constructeur de la classe Barre" << endl ;
}

Barre::~Barre()
{
    cout << "Destructeur de la classe Barre" << endl ;
}

void Barre::AfficherCaracteristiques()
{

    cout << "Reférence : " << ref << endl << "Nom : " << nom << endl;

}

