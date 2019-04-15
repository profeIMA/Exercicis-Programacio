/* Definint les accions i funcions necessàries en el main, cal omplir un vector de n punts 2D i després
 –	calcular i mostrar la distància mitjana a l'origen de tots els punts
 –	ordenar-lo de menys a més distància a l'origen i mostrar-lo
 –	calcular la distància recorreguda per, començant a l'origen de coordenades, visitar tots els punts (seguint l'ordre donat pel vector ordenat)
 Cal fer un programa que ho solucioni usant la classe Punt2D presentada a classe.

 */

#include <iostream>
#include "Punt2D.h"
using namespace std;

const unsigned MAX = 100;
typedef Punt2D Vec_punt2D[MAX];

void llegir_vector_punt2D(Vec_punt2D vec, unsigned n) {
//Pre: 0<=n<=MAX
//Post: vec[0..n-1] conté successivament els punts 2D entrats
    for(unsigned i=0; i<n; i++) vec[i].llegir();
}

void intercanvi(Punt2D & x, Punt2D & y) {
//Pre: x=X i y=Y
//Post: x=Y i y=X
    Punt2D aux=x;
    x=y;
    y=aux;
}

void ordenacio_intercanvi_directe(Vec_punt2D vec, unsigned n) {
//Pre: 0<n<=MAX i vec=VEC
//Post: vec[0..n-1] conté una permutació ordenada dels valors de VEC[0..n-1]
    Punt2D origen(0,0);
    for(unsigned i=0; i<n-1; i++)
        for(unsigned j=n-1; j>i; j--)
            if (vec[j].distancia(origen) < (vec[j-1]).distancia(origen)) intercanvi(vec[j],vec[j-1]);
}

void escriure_vector_punt2D(const Vec_punt2D vec, unsigned n) {
//Pre: 0<=n<=MAX
//Post: s'han mostrat el n valors de vec[0..n-1]
    for(unsigned i=0; i<n; i++) vec[i].mostrar();
}

double distancia_mitjana_a_origen(Vec_punt2D vec, unsigned n) {
//Pre: 0<n<=MAX
//Post: retorna la distància mitjana a l'origen dels punts contiguts a vec[0..n-1]
    double mitjana = 0;
    double dist = 0;
    Punt2D origen(0,0);
    for(unsigned i=0; i<n; i++) dist += vec[i].distancia(origen);
    mitjana = dist/n;
    return mitjana;
}

double distancia_recorreguda(Vec_punt2D vec, unsigned n) {
//Pre: 0<n<=MAX
//Post: retorna la distància recorreguda (partint de l'origen de coordenades) que resulta de visitar ordenadament tots els punts de vec[0..n-1]
    double dist = 0;
    Punt2D origen(0,0);
    dist = vec[0].distancia(origen);
    for(unsigned i=1; i<n; i++) {
        dist += vec[i].distancia(vec[i-1]);
    }
    return dist;
}

int main() {
    cout << "Entra el nombre de punts per a ser llegits (>0): ";
    unsigned n;
    cin >> n;
    cout << "Entra " << n << " punts (x,y): " << endl;
    Vec_punt2D vec;
    llegir_vector_punt2D(vec, n);

    double dist_mitjana = distancia_mitjana_a_origen(vec, n);
    cout << "Distància mitjana a l'origen: " << dist_mitjana << endl;

    cout << "Vector de punts ordenat: " << endl;
    ordenacio_intercanvi_directe(vec, n);
    escriure_vector_punt2D(vec, n);

    double dist_total = distancia_recorreguda(vec, n);
    cout << "Distància recorreguda des de l'origen: " << dist_total << endl;

    return 0;
}


/*

5
1 1
5 1
5 5
3 6
1 5

*/
