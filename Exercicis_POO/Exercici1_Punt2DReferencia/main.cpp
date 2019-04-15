/* Donat un punt 2D de referència entrat per teclat i una seq. de punts (no buida), cal mostrar el punt de la seq. més proper al punt de referència, la distància entre ells i el punt mig
 */
#include <iostream>
#include "Punt2D.h" // s'usa la classe Punt2D
using namespace std;

void actualitzar_proper(Punt2D ref, Punt2D actual, Punt2D & proper, double & dist_min) {
// Pre: dist_min = distancia(ref,proper) i proper=PROPER i dist_min=DIST_MIN
// Post: si actual es més proper a ref que no pas PROPER, proper=actual i dist_min= distancia(ref,actual); en cas contrari proper=PROPER i dist_min=DIST_MIN

   double dist = ref.distancia(actual);
   if (dist<dist_min) { // actual és més proper
      proper = actual; // assignacio entre objectes
      dist_min = dist;
   }
}

int main() {
    cout << "Entra les coordenades x i y del punt de referència: ";
    double x,y;
    cin >> x >> y; // llegim coord. del punt de referència
    Punt2D punt_ref(x,y);  // inicialització amb constructor
    cout << "Entra les coordenades x i y d'un nou punt: ";
    cin >> x >> y;  // llegim coord. d'un nou punt
    Punt2D punt_proper(x,y); // de moment el més proper és el primer
    double distancia_min = punt_ref.distancia(punt_proper);
    cout << "Vols entrar un nou punt?: ";
    char car;
    cin >> car;
    while (car=='s'){
        cout << "Entra les coordenades x i y d'un nou punt: ";
        cin >> x >> y; // llegim coord. d'un nou punt
        Punt2D punt_actual(x,y);
        actualitzar_proper(punt_ref,punt_actual,punt_proper,distancia_min);
        cout << "Vols entrar un nou punt?: ";
        cin >> car;
    }
    cout << "Punt més proper al punt de referència: ";
    punt_proper.mostrar();
    cout << "Distància entre punt de referència i més proper= " << distancia_min << endl;
    Punt2D punt_mig(punt_ref.punt_mig(punt_proper));
    cout << "Punt mig entre el punt de referència i el més proper a ell: ";
    punt_mig.mostrar();
    
    return 0;
}
