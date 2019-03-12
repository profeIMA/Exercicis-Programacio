// Entrada: llegeix un natural k i un real x
// Sortida: escriu el resultat del sumatori 1+x+x^2+x^3+...+x^k

#include <iostream>
#include <cmath>

using namespace std;

double suma_potencies(unsigned k, double x){
//Pre: cert
//Post: retorna el sumatori 1+x+x^2+x^3+...+x^k
    if (k == 0) return 1;
    else return pow(x,k)+suma_potencies(k-1,x);
}

int main() {
    cout << "Introdueix la base (real): ";
    double x;
    cin >> x;
    cout << "Introdueix la potencia maxima: ";
    unsigned k;
    cin >> k;
    cout << "El resultat es: "<< suma_potencies(k,x)<<endl;
    return 0;
}