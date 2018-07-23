// Entrada: llegeix un nombre natural (num)
// Sortida: escriu els números naturals des de 1 fins a num

#include <iostream>
using namespace std;

int main() {
    
    // Entrada
    unsigned num;
    cout<<"Fins a quin número natural vols escriure: ";
    cin>>num;

    // Sortida
    for (int i=1; i<=num; i++) cout<<i<<endl;
    
    return 0;
}

