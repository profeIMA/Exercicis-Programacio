// Entrada: llegeix dos punts en el pla
// Sortida: escriu la distància entre els dos punts entrats

#include <iostream>
#include <cmath>
using namespace std;

typedef struct {double x; double y;} Punt_2d;

double distancia (Punt_2d punt1, Punt_2d punt2) {
// Pre: cert; Post: retorna distància entre punt1 i punt2
    return sqrt(pow((punt1.x-punt2.x),2)+pow((punt1.y-punt2.y),2));
}

int main() {
    
    // Entrada
    Punt_2d punt1, punt2;
    cout<<"Entra primer punt (coordenada x coordenada y) en el pla: ";
    cin>>punt1.x>>punt1.y;
    cout<<"Entra segon punt (coordenada x coordenada y) en el pla: ";
    cin>>punt2.x>>punt2.y;
    
    // Càlcul i sortida
    cout<<"Distància entre els punts = "<<distancia(punt1,punt2)<<endl;
    
    return 0;
}
