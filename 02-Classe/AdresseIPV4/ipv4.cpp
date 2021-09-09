#include "ipv4.h"
#include <iostream>


void IPv4::CalculerMasque(unsigned char _cidr)
{
    int indice ;
    // Le masque est remis à 0 -> 0.0.0.0
    for(indice = 0 ; indice < 4 ; indice++)
        masque[indice] = 0 ;
    indice = 0;
    // tant que le cidr est un multiple de 8
    while(_cidr >= 8)
    {
        masque[indice++] = 255 ;
        _cidr -= 8 ;
    }
    // Complément pour la fin du cidr (<8)
    unsigned char puissance = 128 ;
    while(_cidr-- > 0) // Après le test la variable _cidr est décrémentée
    {   // les puissances de 2 sont ajoutées à l'octet par valeur décroissante
        masque[indice] += puissance ;
        puissance /=2 ;
    }
}



IPv4::IPv4(const unsigned char *_adresse, const unsigned char _cidr)
{
    adresse = new unsigned char [4];
    masque  = new unsigned char [4];
    for(int indice = 0 ; indice < 4 ; indice++)
        adresse[indice] = _adresse[indice];
    if(_cidr <= 32)
        CalculerMasque(_cidr);
}

IPv4::IPv4(const unsigned char *_adresse, const unsigned char *_masque)
{
    adresse = new unsigned char [4];
    masque  = new unsigned char [4];
    for(int indice = 0 ; indice < 4 ; indice++)
    {
        adresse[indice] = _adresse[indice];
        masque[indice]  = _masque[indice];
    }
}

IPv4::~IPv4()
{
    delete [] adresse;
    delete [] masque ;
}

/**
 * @brief IPv4::IPv4
 * @details : constructeur par defaut
 */
IPv4::IPv4()
{
    adresse = new unsigned char [4];
    masque  = new unsigned char [4];
}

/**
 * @brief IPv4::IPv4
 * @param une adresse original a cloner
 * @details constructeur de copie
 */
IPv4::IPv4(const IPv4 &_ipv4)
{
    adresse = new unsigned char [4];
    masque  = new unsigned char [4];
    for(int indice = 0 ; indice < 4 ; indice++)
    {
        adresse[indice] = _ipv4.adresse[indice];
        masque[indice]  = _ipv4.masque[indice];
    }
}

IPv4 &IPv4::operator=(const IPv4 &_ipv4)
{
    if(adresse != _ipv4.adresse || masque != _ipv4.masque)
    {
        if(adresse != nullptr && masque != nullptr)
        {
            delete [] adresse;
            delete [] masque ;
        }
        adresse = new unsigned char [4];
        masque  = new unsigned char [4];

        for(int indice = 0 ; indice < 4 ; indice++)
        {
            masque[indice]  = _ipv4.masque[indice];
            adresse[indice] = _ipv4.adresse[indice];
        }

    }
    return *this;
}

void IPv4::ObtenirMasque(unsigned char * _masque)
{
    for(int indice = 0 ; indice < 4 ; indice++)
        _masque[indice] = masque[indice];
}


void IPv4::ObtenirAdresseReseau(unsigned char * _reseau)
{
    for(int indice = 0 ; indice < 4 ; indice++)
        _reseau[indice] = adresse[indice] & masque[indice] ;
}

void IPv4::ObtenirAdresseDiffusion(unsigned char *_diffusion)
{
    unsigned char adresseDuReseau[4];
    ObtenirAdresseReseau(adresseDuReseau);
    for(int indice = 0 ; indice < 4 ; indice++)
        _diffusion[indice] = adresseDuReseau[indice] | ~masque[indice] ;
}

void IPv4::ObtenirAdressePMachine(unsigned char *_pmachine)
{
    ObtenirAdresseReseau(_pmachine);
    _pmachine[3]++;
}

void IPv4::ObtenirAdresseDMachine(unsigned char *_dmachine)
{

    ObtenirAdresseDiffusion(_dmachine);
    _dmachine[3]--;
}

void IPv4::AfficherTableau(unsigned char *tab)
{
    for(int indice=0 ; indice < 4 ; indice ++)
    {
        std::cout  << static_cast<int> (tab[indice]);
        if(indice < 3)
            std::cout << "." ;
    }
    std::cout << std::endl;
}

int IPv4::NbBital(unsigned char val)
{
    int n=0;
    do{
        n += val & 1;
    }while(val >>= 1);
    return n;
}


unsigned int IPv4::ObtenirNombreMachine()
{
    unsigned int nb=0;
    for(int i=1;i<4;i++){
        nb += NbBital(masque[i]);
    }
    return exp2(32-nb)-2;
}



