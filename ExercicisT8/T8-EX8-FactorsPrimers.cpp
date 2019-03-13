// Entrada: un enter positiu n
// Sortida: factors primers de n

#include <iostream>
#include <cmath>

using namespace std;

bool es_primer(unsigned n) {
//Pre: n>=2
//Post: retorna certsi n no técapdivisor diferentd'1 i d'ellmateix, falsaltrament
	unsigned divisor=2;
	while(n%divisor!=0 and divisor*divisor<n)
		divisor++;
	// return n%divisor!=0 or n==2;
	bool primer = n%divisor!=0 or n==2;
	return primer;
}

void factors_primers(unsigned n){
//Pre: cert
//Post: mostra per pantalla els factors primers de n
    if(es_primer(n)) cout<< n<< " " ;
    else{
        unsigned factor = (unsigned) sqrt(n);
        while(n%factor!=0) factor++;
        factors_primers(factor);
        factors_primers(n/factor);
    }
}

int main() {
    cout << "Introdueix un nombre(n): ";
    unsigned n;
    cin >> n;
    cout<<"Els factors primers de "<< n << " son: ";
    factors_primers(n);
    return 0;
}


