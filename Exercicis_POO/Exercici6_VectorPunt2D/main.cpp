/* Test de la classe Vector_punt2D
 */

#include <iostream>
#include "Vector_punt2D.h"
using namespace std;

void mostrar_menu() {
    cout << "i: inserir un punt" << endl;
    cout << "m: mostrar vector de punts" << endl;
    cout << "e: esborrar un punt donada la posicio" << endl;
    cout << "n: nombre de punts" << endl;
    cout << "d: distancia mitjana a l'origen" << endl;
    cout << "f: fi" << endl;
    cout << endl;
}

int main() {
    
    Vector_punt2D v;
    Punt2D p;
    int pos;
    
    mostrar_menu();
    char operacio;
    cout << "Introdueix operacio [i,m,e,n,d,f]: ";
    cin >> operacio;
    while(operacio != 'f') {
        if (operacio == 'i') {
            cout << "Entra coordenades (x, y) d'un punt: ";
            p.llegir();
            v.inserir_punt(p);
            // cout << endl;
        }
        else if (operacio == 'm') {
            v.mostrar();
        }
        else if (operacio == 'e') {
            cout << "Posicio a esborrar: ";
            cin >> pos;
            v.esborrar_punt(pos);
            // cout << endl;
        }
        else if (operacio == 'n') {
            cout << "Nombre de punts = " << v.nombre_punts() << endl;
            // cout << endl;
        }
        else if (operacio == 'd') {
            cout << "Distancia mitjana a l'origen = " << v.mitjana_distancies_origen() << endl;
            // cout << endl;
        }
        // mostrar_menu();
        cout << "Introdueix operacio [i,m,e,n,d,f]: ";
        cin >> operacio;
    }
    return 0;
}