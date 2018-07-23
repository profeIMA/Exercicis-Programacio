// Entrada: llegeix un nombre natural (num)
// Sortida: escriu els números naturals des de 1 fins a num

#include <iostream>
using namespace std;

int main() {
    
    unsigned num;
    cout<<"Fins a quin número natural vols escriure: ";
    cin>>num;
    
    int i=1;
    while ( i<=num) {
        cout<<i<<endl;
        i++;
    }
    
    return 0;
}
