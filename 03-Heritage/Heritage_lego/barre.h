#ifndef BARRE_H
#define BARRE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class Barre
{
public:
    Barre(string _ref,string _nom);
    ~Barre();

    void AfficherCaracteristiques();

private:
    string ref;
    string nom;
};

#endif // BARRE_H
