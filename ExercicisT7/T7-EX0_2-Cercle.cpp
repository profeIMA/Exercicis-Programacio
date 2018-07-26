/* Donat un punt en el pla, que representa el centre d'un cercle, i un radi, construir una funció booleana que ens digui si un altre punt donat està dins del cercle. */
 
// Entrada: llegeix el centre del cercle, el seu radi i un altre punt
// Sortida: escriu si el segon punt entrat pertany o no al cercle entrat

#include <iostream>
#include <cmath>
using namespace std;

struct Punt_2d {double x; double y;};

double distancia (Punt_2d punt1, Punt_2d punt2) {
    // Pre: cert; Post: retorna distància entre punt1 i punt2
    return sqrt(pow((punt1.x-punt2.x),2)+pow((punt1.y-punt2.y),2));
}

bool pertany (Punt_2d centre, double radi, Punt_2d punt) {
    // Pre: radi>0; Post: retorna cert si punt pertany al cercle definit per (centre,radi), fals en cas contrari
    return distancia(centre,punt)<=radi;
}

Punt_2d llegir_punt() {
    Punt_2d punt;
    cin>>punt.x>>punt.y;
    return punt;
}

int main() {
    
    // Entrada
    Punt_2d centre, punt;
    double radi;
    cout<<"Entra centre del cercle (coordenada x coordenada y) en el pla: ";
    centre=llegir_punt();
    cout<<"Entra radi cercle: ";
    cin>>radi;
    cout<<"Entra punt (coordenada x coordenada y) en el pla: ";
    punt=llegir_punt();
    
    // Càlcul i sortida
    if(pertany(centre,radi,punt) ) cout<<"El punt està dins del cercle"<<endl;
    else cout<<"El punt està fora del cercle"<<endl;
    
    return 0;
}

