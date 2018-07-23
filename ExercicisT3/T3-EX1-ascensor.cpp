// Entrada: llegeix un nombre natural (pis)
// Sortida: escriu el pis real (pis_real) al qual ha d'anar l'ascensor

#include <iostream>
using namespace std;

int main(){
    unsigned pis;
    cout<<"Pis: ";
    cin>>pis;
    unsigned pis_real;
    if (pis>13)
        pis_real=pis-1;
    else
        pis_real=pis;
    cout<<"L'ascensor pujarà al pis real "<<pis_real<<endl;
    return 0;
}
