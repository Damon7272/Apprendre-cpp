#include <iostream>  // pour cin et cout
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
      /*  float temperature = 0.0;
        float humidite = 0.0;
        int pression= 0;
        cout << "Saisir la température, l'humidité et la pression : " ;
        cin >> temperature >> humidite >> pression ;
        cout  << "la température est : " << temperature << " °"  << endl;
        cout  << "le taux d'humidité est : " << humidite << " %" << endl;
        cout  << "la pression est : " << pression <<  " hPa" << endl ;
        return 0;
         */

     /*  char phrase[80+1];
       cout << "Saisir une phrase : " ;
       cin.getline(phrase,80, '\n') ;
       cout  << "Votre phrase est :" << phrase << endl;
       return 0;
    */

   /*    int val = 192;
        float val2 = 3.141592654;
        bool sortie = true;
        cout  << "Affichage par défaut     : " << val << endl;
        cout  << "Affichage en hexadécimal : " << hex << val << endl;
        cout  << "Affichage en décimal     : " << dec << val << endl;
        cout << hex << val << " " << uppercase << val << " " ;
        cout << showbase  << val << nouppercase << " " << val << endl;
        cout << "+" << setfill('-') << setw(21) << "+" << setfill(' ') << endl;
        cout << "|" << setw(20) << left << "abc" << "|" << endl;
        cout << "|" << setw(20) << right << "abc" << "|" << endl;
        cout << "+" << setfill('-') << setw(21) << "+" << setfill(' ') << endl;
        cout << dec << sortie << " " << boolalpha << sortie << endl;
        cout << val2 << " " << fixed << val2 << " " << scientific << val2 << " ";
        cout << fixed << setprecision(2) << val2 << endl;
        cout << "Entrez un nombre en octal : " ;
        cin >> oct >> val ;
        cout << "vous avez saisie " << dec << val << " en décimal" << endl;
        return 0;
*/



        string motCle ;
        // string remplace un tableau de caractères. la taille de la chaîne est dynamique
        int valeur;
        ifstream fichier("medailles.txt");
       if (!fichier.is_open())
           cerr << "Erreur lors de l'ouverture du fichier" << endl;
       else
       {
           cout <<"le fichier est ouvert" << endl;
           // traitement sur le fichier ouvert en écriture
           do
                   {
                       // le fichier contient sur chaque ligne des couples mot clé + valeur
                       fichier >> motCle >> valeur ;
                       if (fichier.good())//Si les valeurs ont bien été lues
                       {

                               //cout << "+" << setfill('-') << setw(41) << "+" << setfill(' ') << endl;
                               cout << "|" << setw(20) << left << motCle << "|" << setw(5) << valeur  << endl;

                               //cout << "+" << setfill('-') << setw(41) << "+" << setfill(' ') << flush;

                           // traitement des variables motCle et valeur
                       }
                   } while(!fichier.eof());
       }
       return 0 ;


}
