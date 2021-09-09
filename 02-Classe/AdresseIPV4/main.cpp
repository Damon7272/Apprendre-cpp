#include <iostream>
#include "ipv4.h"

using namespace std;
//void AfficherTableau(unsigned char *tab);
int main()
{
    unsigned char adresse[4]= {192,168,1,1};
    unsigned char masque[4];
    unsigned char reseau[4];
    unsigned char diffusion[4];
    unsigned char pmachine[4];
    unsigned char dmachine[4];
    unsigned char AutreAdresse[4];

    IPv4 uneAdresse(adresse, 24); // instanciation de la classe IPv4
    IPv4 uneAutreAdresse;
    IPv4 AdresseCopie(uneAdresse);
    IPv4 Adresse3 = uneAdresse;

    cout << "Adresse IPv4 : ";
    IPv4::AfficherTableau(adresse);
    uneAdresse.ObtenirMasque(masque); // appel d'une méthode
    cout << "Masque : ";
    IPv4::AfficherTableau(masque);
    uneAdresse.ObtenirAdresseReseau(reseau);
    cout << "Réseau : ";
    IPv4::AfficherTableau(reseau);
    uneAdresse.ObtenirAdresseDiffusion(diffusion);
    cout << "Diffusion : ";
    IPv4::AfficherTableau(diffusion);
    uneAdresse.ObtenirAdressePMachine(pmachine);
    cout << "Première machine : ";
    IPv4::AfficherTableau(pmachine);
    uneAdresse.ObtenirAdresseDMachine(dmachine);
    cout << "Dernière machine : ";
    IPv4::AfficherTableau(dmachine);

    cout << "Nombre machine : " <<uneAdresse.ObtenirNombreMachine()<< endl;

    cout << "Adresse par défaut : ";
    uneAutreAdresse.ObtenirAdresseReseau(reseau);
    IPv4::AfficherTableau(reseau);

    cout << "Adresse reseau de l'adresse copié : ";
    AdresseCopie.ObtenirAdresseReseau(reseau);
    IPv4::AfficherTableau(reseau);


    cout << "Adresse reseau de l'adresse3 : ";
    Adresse3.ObtenirAdresseReseau(reseau);
    IPv4::AfficherTableau(reseau);

    return 0;
}

 /*void AfficherTableau(unsigned char *tab)
{
    for(int indice=0 ; indice < 4 ; indice ++)
    {
        cout  << static_cast<int> (tab[indice]);
        if(indice < 3)
            cout << "." ;
    }
    cout << endl;
}*/

