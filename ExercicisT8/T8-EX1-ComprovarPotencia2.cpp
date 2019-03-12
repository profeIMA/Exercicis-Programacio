// Entrada: llegeix un nombre natural n
// Sortida: escriu si el nombre és potència de 2 o no.

#include <iostream>

using namespace std;

bool potencia_de_2(unsigned n){
//Pre: cert
//Post: cert si n és potència de 2, fals en cas contrari.
    if(n == 1) return true;
    else if (n%2 != 0 || n < 1) return false;
    else return potencia_de_2(n/2);
}

int main() {
    cout << "Introdueix un nombre: ";
    unsigned n;
    cin >> n;
    string text_variable = potencia_de_2(n)? "es":"no es";
    cout << n << " "<<text_variable << " potencia de 2.";
    return 0;
}