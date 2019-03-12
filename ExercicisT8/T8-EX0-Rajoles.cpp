// Entrada: llegeix un nombre natural n (nombre de rajoles)
// Sortida: escriu el nombre de camins diferents que ens permeten recórrer les n rajoles combinant salts d'una i dues rajoles

#include <iostream>

using namespace std;

unsigned salt_rajoles(unsigned n){
//Pre: cert
//Post: nombre de camins diferents possibles per recórrer n rajoles amb salts de 1 i 2
    if (n<3) return n;
    else return salt_rajoles(n-1) + salt_rajoles(n-2);
}


int main() {
    cout << salt_rajoles(4) << endl;
    return 0;
}