/* Entrada: Llegir de teclat les dades de dos rectangles (punt origen, base i altura)
   Sortida: Mostrar la informació (origen, base i altura, vèrtexs) d'un rectangle amb origen al punt mig entre els dos centres dels rectangles inicials i la base i altura del més petit (menys àrea)
 */

#include <iostream>
#include <cmath>
#include"Rectangle.h"
using namespace std;

void mostrar_menu() {
    cout << "a: mostrar area del rectangle mes gran" << endl;
    cout << "p: mostrar perimetre del rectangle mes gran" << endl;
    cout << "i: mostrar rectangle interseccio" << endl;
    cout << "d: mostrar la distancia entre els centres" << endl;
    cout << "f: fi" << endl;
}

Rectangle llegir_rectangle() {
// Retorna un rectangle les dades del qual s'han entrat per teclat
   cout << "Entra components (x,y) del vertex inferior esquerre, separades per un espai: ";
   double x,y;
   cin >> x >> y;
   Punt2D origen(x,y);
   cout << "Entra base i altura, separades per un espai: ";
   double base, altura;
   cin >> base >> altura;
   return Rectangle(origen,base,altura);
}

int main() {
    Rectangle r1= llegir_rectangle();
    Rectangle r2= llegir_rectangle();
    cout << endl;
    r1.mostrar(); r1.mostrar_vertexs();
    cout << endl;
    r2.mostrar(); r2.mostrar_vertexs();
    cout << endl;
    
    char operacio;
    mostrar_menu();
    cout << "Introdueix operacio [a,p,i,d,f]: " << endl;
    cin >> operacio;
    while(operacio != 'f') {
        if (operacio == 'a') {
            cout << "Area mes gran: " << fmax(r1.area(), r2.area()) << endl;
            cout << endl;
        }
        else if (operacio == 'p') {
            cout << "Perimetre mes gran: " << fmax(r1.perimetre(), r2.perimetre()) << endl;
            cout << endl;
        }
        else if (operacio == 'i') {
            Rectangle inter;
            bool hi_ha_inter;
            r1.interseccio(r2, inter, hi_ha_inter);
            if (hi_ha_inter) {
                inter.mostrar();
                inter.mostrar_vertexs();
            }
            else cout << "No hi ha interseccio" << endl;
            cout << endl;
        }
        else if (operacio == 'd') {
            cout << "Distancia entre els centres: " << r1.centre().distancia(r2.centre()) << endl;
            cout << endl;
        }
        mostrar_menu();
        cout << "Introdueix operacio [a,p,i,d,f]: " << endl;
        cin >> operacio;
    }
    
    return 0;
}
