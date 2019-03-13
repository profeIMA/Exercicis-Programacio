// Entrada: dos enters positius (a i b)
// Sortida: mostra si a és sufix de b

#include <iostream>

using namespace std;

bool es_sufix(unsigned a, unsigned b){
//Pre: cert.
//Post: retorna cert si a és sufix de b, fals en cas contrari.
    if(a==b) return true;
    else if(a%10 != b%10) return false;
    else if(a<10) return true;
    else if(b<10) return false;
    else return es_sufix(a / 10, b / 10);
}

int main() {
    cout << "Introdueix el primer nombre(a): ";
    unsigned a;
    cin >> a;
    cout << "Introdueix el segon nombre(b): ";
    unsigned b;
    cin >> b;
    string text_variable = es_sufix(a, b)? "es":"no es";
    cout << a <<" "<<text_variable << " sufix de " << b << ".";
    return 0;
}

