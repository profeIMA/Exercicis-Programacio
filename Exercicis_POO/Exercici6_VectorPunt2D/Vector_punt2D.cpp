#include <iostream>
#include <cmath>
#include "Vector_punt2D.h"
using namespace std;

// Constructors
Vector_punt2D::Vector_punt2D() {
    a_n = 0; 
};

double Vector_punt2D::nombre_punts() const {
    return a_n;
}

double Vector_punt2D::mitjana_distancies_origen() const {
    double dist = 0;
    Punt2D origen(0,0);
    for(unsigned i=0; i<a_n; i++) dist += a_t[i].distancia(origen);
    return dist/a_n;
}

void Vector_punt2D::mostrar() const {
    for(unsigned i=0; i<a_n; i++) {
        cout << i << " -- ";
        a_t[i].mostrar();
    }
    cout << endl;
}

// Modificadors
void Vector_punt2D::inserir_punt(Punt2D punt) {
    if (a_n<MAX) {
        int i = a_n-1;
        bool trobat_lloc = false;
        while (i>=0 and not trobat_lloc) {
            if (es_menor(punt, a_t[i])) {
                a_t[i+1]=a_t[i];
                i--;
            }
            else trobat_lloc=true;
        }
        a_t[i+1]=punt;
        a_n++;
    }
}

void Vector_punt2D::esborrar_punt(int pos) {
    if (a_n>0 and pos<a_n) {
        for (int i=pos+1; i<a_n; i++) a_t[i-1]=a_t[i];
        a_n--;
    }
}

// Mètodes privats
bool Vector_punt2D::es_menor(Punt2D p1, Punt2D p2) {
    Punt2D origen(0,0);
    bool menor = p1.distancia(origen) < p2.distancia(origen);
    if (p1.distancia(origen) == p2.distancia(origen))
        menor = abs(p1.coordenada_x()) < abs(p2.coordenada_x());
    return menor;
}
