/* Donades dues fraccions i una operació (+,-,*,/), escriure la fracció simplificada resultant de fer l'operació corresponent en el format (-)numerador/denominador o bé (-)numerador si denominador=1
 */

#include <iostream>
#include "Fraccio.h" 
using namespace std;

void llegir_fraccio(Fraccio & f) {
// Pre: cert
// Post: s'ha creat la fracció f a partir del numerador i denominador llegits de teclat
    int numerador, denominador;
    cout << "Introdueix numerador: " << endl;
    cin >> numerador;
    cout << "Introdueix denominador [!=0]: " << endl;
    cin >> denominador;
    f = Fraccio(numerador, denominador);
}

Fraccio operar(Fraccio f1, Fraccio f2, char operacio) {
// Pre: operacio='+' o '-' o '*' o '/'
// Post: retorna la fracció resultant de l'operació indicada sobre f1 i f2
    Fraccio resultat;
    if (operacio == '+')
        resultat = f1.suma(f2);
    else if (operacio == '-')
        resultat = f1.resta(f2);
    else if (operacio == '*')
        resultat = f1.producte(f2);
    else if (operacio == '/')
        resultat = f1.divisio(f2);
    return resultat;
}

int main() {
    
    Fraccio f1, f2, resultat;
    char operacio;

    cout << "Primera fracció: " << endl;
    llegir_fraccio(f1);
    cout << "Segona fracció: " << endl;
    llegir_fraccio(f2);
    cout << "Introdueix operació [+-*/] o fi [#]: " << endl;
    cin >> operacio;
    while(operacio != '#') {
        resultat = operar(f1, f2, operacio);
        cout << "El resultat de l'operació és: " << endl;
        resultat.mostrar();
        cout << "Introdueix operació [+-*/] o fi [#]: " << endl;
        cin >> operacio;
    }
    return 0;
}
