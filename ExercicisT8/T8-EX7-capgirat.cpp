// Entrada: un enter positiu n
// Sortida: mostra n capgirat

#include <iostream>
#include <cmath>

using namespace std;

unsigned capgirat(unsigned n){
//Pre: cert
//Post: retorna n capgirat
    if(n<10) return n;
    else {
        return (n%10)*(unsigned)pow(10,floor(log10(n)))+capgirat(n/10);
    }
}

int main() {
    cout << "Introdueix un enter positiu(n): ";
    unsigned n;
    cin >> n;
    cout << "El capgirat d'aquest nombre es "<< capgirat(n);
    return 0;
}


