#include <cmath>
#include <iostream>

using namespace std;

struct Punt {
	double x;
	double y;
};

const unsigned N_MAX = 100;

typedef Punt Vector_punts[N_MAX];

struct Taula_punts {
	Vector_punts vect;
	unsigned n;
};

double dist(Punt p, Punt q) {
	//Pre: cert
	//Post: retorna la distància Euclidea entre els punts p i q
	double dif_x = p.x - q.x, dif_y = p.y - q.y;
	return sqrt(dif_x*dif_x + dif_y * dif_y);
}

Punt mes_proper_a_origen(Taula_punts punts) {
//Pre: 0<=punts.n<=N_MAX
//Post: retorna el punt de punts.vect[0..punts.n-1] més proper a p
	Punt p;
	p.x = 0; p.y = 0;
	Punt mes_proper=punts.vect[0];
	double menor_dist = dist(mes_proper, p);
	int darrer = int(punts.n) - 1;
	for (unsigned i = 1; i<darrer; i++) {
		double distancia = dist(punts.vect[i], p);
		if (distancia<menor_dist) { menor_dist = distancia; mes_proper = punts.vect[i]; }
	}
	return mes_proper;
}

void llegir_vector_punts(Taula_punts & punts) {
//Pre: 0<=punts.n<=N_MAX
//Post: punts.vect[0..punts.n-1] conté successivament els Punts entrats
	for(unsigned i = 0; i<punts.n; i++)
		cin >> punts.vect[i].x >> punts.vect[i].y;
}

void escriure_taula_punts(Taula_punts punts) {
	for (int i = 0; i < punts.n; i++) {
		cout << "(" << punts.vect[i].x << ", " << punts.vect[i].y<< "), ";
	}
}

int main() {
	Taula_punts punts;
	cout << "Nombre de punts: "; cin >> punts.n;
	llegir_vector_punts(punts);
	Punt proper_origen = mes_proper_a_origen(punts);
	escriure_taula_punts(punts);
	cout << "El punt més proper a l'origen de coordenades és: ("<< proper_origen.x<<", "<<proper_origen.y<<")";
	return 0;
}
