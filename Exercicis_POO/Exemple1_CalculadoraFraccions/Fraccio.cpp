#include <iostream>
#include <cstdlib>
#include "Fraccio.h"
using namespace std;

Fraccio::Fraccio() {
    a_num = 0;
    a_den = 1;
}

Fraccio::Fraccio(int numerador, int denominador) {
    a_num = abs(numerador);
    a_den = abs(denominador);
    if (numerador*denominador < 0) {
        a_num*= -1;
    }
    simplificar();
}

Fraccio Fraccio::suma(Fraccio f) const {
    int d = minim_comu_multiple(a_den, f.a_den);
    int num1 = a_num * (d/a_den);
    int num2 = f.a_num * (d/f.a_den);
    int suma_num = num1 + num2;
    Fraccio resultat(suma_num,d); // ja crea la fraccio simplificada
    return resultat;
}

Fraccio Fraccio::resta(Fraccio f) const {
    Fraccio oposada = f;
    oposada.a_num *= -1;
    return suma(oposada);  // restar es sumar l'oposada
}

Fraccio Fraccio::producte(Fraccio f) const {
    Fraccio resultat; // podríem cridar el constructor amb paràmetres
    resultat.a_num = a_num * f.a_num;
    resultat.a_den = a_den * f.a_den;
    resultat.simplificar();
    return resultat;
}

Fraccio Fraccio::divisio(Fraccio f) const {
    // aquí cridem el constructor amb paràmetres
    return Fraccio(a_num * f.a_den,a_den * f.a_num);
}

void Fraccio::mostrar() const {
    if (a_den != 1)
        cout << a_num << '/' << a_den << endl;
    else
        cout << a_num << endl;
}

// ---------------------------------- metodes privats ----------------------------------

void Fraccio::simplificar() {
    if (a_num==0) a_den = 1;
    else {
        int aux = maxim_comu_divisor(abs(a_num), a_den);
        a_num /= aux;
        a_den /= aux;
    }
}

int Fraccio::maxim_comu_divisor(int a, int b) {
    int residu = a % b;
    while (residu != 0) {
        int a = b;
        b = residu;
        residu = a % b;
    }
    return b;
}

int Fraccio::minim_comu_multiple(int a, int b) {
    int mcd = maxim_comu_divisor(a,b);
    return a*b/mcd;
}
