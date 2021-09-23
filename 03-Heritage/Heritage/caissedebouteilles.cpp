#include "caissedebouteilles.h"
#include <iostream>
using namespace std;



CaisseDeBouteilles::CaisseDeBouteilles(const int _largeur, const int _hauteur, const int _profondeur, const int _nbBouteilles, const int _contenance):
    Contenant(_largeur,_hauteur,_profondeur),
    nbBouteilles(_nbBouteilles),
    contenance(_contenance)
    {
    cout << "constructeur de la classe CaisseDeBouteilles" << endl ;
}

int CaisseDeBouteilles::CalculerVolume()
{
    return contenance/nbBouteilles;
}


CaisseDeBouteilles::~CaisseDeBouteilles()
{
    cout << "Destructeur de la classe CaisseDeBouteilles" << endl;
}
