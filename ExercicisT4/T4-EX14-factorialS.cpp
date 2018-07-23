/* Escriure els factorials dels nombres naturals des de 0 a n (natural). Per exemple, per n=3:
 
 0! = 1
 1! = 1
 2! = 2
 3! = 6
 
 */

// Entrada: llegeix natural n
// Sortida: escriu els factorials des de 0 a n (tal com es mostra en l'enunciat)

#include <iostream>
using namespace std;

int main() {

    // Entrada
    unsigned n;
    cout<<"Entra n: ";
    cin>>n;
    
    // Càlcul i sortida
    for (unsigned num=0; num<=n; num++) {
        unsigned factorial=1;
        for (unsigned i=1; i<=num; i++) factorial*=i;
        cout<<num<<"! = "<<factorial<<endl;
    }
    
    return 0;
}


