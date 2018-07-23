/* S'entren 3 nombres naturals que representen hores (<24), minuts (<60) i segons (<60) i s'escriu el resultat d'afegir un segon a les dades anteriors, tenint en compte que el nombre de minuts i el nombre de segons segueixin essent <60.
*/
// Entrada: llegeix 3 nombres naturals (hora, minut, segon)
// Sortida: escriu hora, minut i segon després d'haver incrementat un segon a les dades d'entrada

#include <iostream>
using namespace std;

int main()
{
    const unsigned HORES=24, MINUTS=60, SEGONS=60;
    unsigned hora, minut, segon;
    cout << "Entra hora (0-23) minut (0-59) segon (0-59): ";
    cin>>hora>>minut>>segon;
    segon++;
    if (segon==SEGONS){
        segon=0;
        minut++;
        if (minut==MINUTS){
            minut=0;
            hora++;
            if (hora==HORES)
                hora=0;
        }
    }
    cout<<hora<<":"<<minut<<":"<<segon<<endl;

    return 0;
}
