/* Entrada: Llegir de teclat les dades de dos rectangles r1 i r2 (punt origen, base i altura)
   Sortida: Mostrar la informació (origen, base i altura, vèrtexs) del rectangle creat r3 amb origen al punt mig entre els dos orígens dels rectangles r1 i r2 i la base i l'altura del més petit d'aquests dos (menys àrea). També es mostrarà successivament el resultat d'escalar r3 en un factor 2 a partir del seu origen, el resultat d'escalar-lo un factor 0.5 a partir del seu centre, el resultat de desplaçar-lo un vector (1,1) i, finalment, el seu perímetre.
 */

#include <iostream>
#include"Rectangle.h"
using namespace std;

Rectangle llegir_rectangle() {
// Retorna un rectangle les dades del qual s'han entrat per teclat
   cout << "Entra components (x,y) del vèrtex inferior esquerre, separades per un espai: ";
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
    Rectangle r3;
    Punt2D punt_mig = r1.origen().punt_mig(r2.origen());
    if (r1.area()<r2.area())
        r3 = Rectangle(punt_mig,r1.base(),r1.altura());
    else
        r3 = Rectangle(punt_mig,r2.base(),r2.altura());
    r3.mostrar(); r3.mostrar_vertexs();
    cout << endl;
    r3.escalar_origen(2);
    r3.mostrar(); r3.mostrar_vertexs();
    cout << endl;
    r3.escalar_centre(0.5);
    r3.mostrar(); r3.mostrar_vertexs();
    cout << endl;
    r3.moure(1,1);
    r3.mostrar(); r3.mostrar_vertexs();
    cout << endl;
    cout << "Perímetre: " << r3.perimetre();
    cout << endl;    
    
    return 0;
}
