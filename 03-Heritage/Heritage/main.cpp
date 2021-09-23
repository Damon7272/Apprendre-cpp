#include <iostream>
#include <contenant.h>
#include <carton.h>
#include <caissedebouteilles.h>

using namespace std;

int main()
{

    Carton unCarton(10,11,12,50);
    cout << "poid maxi de uncarton : " << unCarton.ObtenirPoidsMaxi() << endl;
    cout << "volume de uncarton : " << unCarton.CalculerVolume() << endl;
    CaisseDeBouteilles uneCaisse(10,10,10,24,1);

    cout << uneCaisse.Contenant::CalculerVolume() << endl;
    cout << "Test 1-2 1-2" << endl;
    return 0;
}
