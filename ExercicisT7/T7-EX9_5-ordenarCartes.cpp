#include <cmath>
#include <iostream>
#include <string>

using namespace std;

struct Carta {
	string pal;
	unsigned num;
};

const unsigned N_MAX = 48;
typedef Carta Vector_cartes[N_MAX];

struct Pila_cartes {
	Vector_cartes vec;
	unsigned n_cartes;
};

bool es_menor(Carta carta_a, Carta carta_b) {
	//Pre: cert
	//Post: retorna cert si la carta_a és menor (menor pal o en cas d’igual pal menor número) que la carta_b
	bool menor = carta_a.pal<carta_b.pal;
	if (carta_a.pal == carta_b.pal) menor = carta_a.num<carta_b.num;
	return menor;
}

unsigned posicio_insercio(const Pila_cartes& pila, unsigned pos) {
	//Pre: pila.vec[0..pos-1] ordenat i 0<pos<pila.n_cartes 
	//Post: retorna la posició d’insercio de la carta pila.vect[pos] a pila.vect[0..pos]
	int esquerre = 0, dret = pila.n_cartes - 1, mig = 0;
	bool trobat = false;
	Carta carta_nova = pila.vec[pos];
	while (esquerre <= dret and not trobat) {
		mig = (esquerre + dret) / 2;
		if (es_menor(carta_nova, pila.vec[mig])) dret = mig - 1;
		else if (es_menor(pila.vec[mig], carta_nova)) esquerre = mig + 1;
		else trobat = true;
	}
	if (trobat) pos = unsigned(mig);
	else pos = unsigned(esquerre);
	return pos;
}

void insereix_a_pos(Pila_cartes& pila, int pos_carta, int pos_insercio) {
//Pre: pila.vec[0..pos_carta-1] ordenat i 0<pos_carta<pila.n_cartes i 0<=pos_insercio<=pos_carta i pila.vec=VEC
//Post: pila.vec[0..pos_carta] ordenat i amb VEC[pos_carta] inserit a pos_inserció
	Carta carta_a_inserir = pila.vec[pos_carta];
	for (int i = pos_carta - 1; i >= pos_insercio; i--) pila.vec[i + 1] = pila.vec[i];
	pila.vec[pos_insercio] = carta_a_inserir;
}

void ordena(Pila_cartes& pila) {
//Pre: 0<=pila.n_cartes<=N_MAX i pila.vec=VEC
//Post: pila.vec[0..pila.n_cartes-1] conté una permutació ordenada dels valors de VEC[0..pila.n_cartes-1]
	for (int i = 1; i<int(pila.n_cartes) - 1; i++)
		insereix_a_pos(pila, i, posicio_insercio(pila, i));
}


void llegir_cartes(Pila_cartes& cartes) {
	for (int i = 0; i < cartes.n_cartes;i++) {
		cout << "Pal: ";
		cin >> cartes.vec[i].pal;
		cout << "Valor: ";
		cin >> cartes.vec[i].num;
	}
}


void escriure_cartes(Pila_cartes cartes) {
	for (int i = 0; i < cartes.n_cartes; i++) {
		cout << "Pal: "<< cartes.vec[i].pal<< " Valor: "<< cartes.vec[i].num<< endl;
	}
}


int main() {

	Pila_cartes cartes;

	cout << "Introduir número de cartes: ";
	cin >> cartes.n_cartes;
	cout << "Introduir les cartes: " << endl;
	llegir_cartes(cartes);
		
	ordena(cartes);

	escriure_cartes(cartes);

	return 0;
}
