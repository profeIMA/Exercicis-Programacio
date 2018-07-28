#include<iostream>

using namespace std;

const unsigned N_MAX = 100;

typedef int Vector_enter[N_MAX];

void unio_vectors(const Vector_enter vec1, const Vector_enter vec2, unsigned n1, unsigned n2, Vector_enter vec_unio, unsigned &n) {
//Pre: 0<=n1+n2<=N_MAX i vec1[0..n1-1] i vec2[0..n2-1] sense repetits i ordenats
//Post: 0<=n<=n1+n2 i vec_unio[0..n-1] ordenat i és la unió de vec1[0..n1-1] i vec2[0..n2-1]
	unsigned i1 = 0, i2 = 0;
	n = 0;
	while (i1<n1 and i2<n2) {
		if (vec1[i1]<vec2[i2]) { vec_unio[n] = vec1[i1]; i1++; }
		else if (vec1[i1] == vec2[i2]) { vec_unio[n] = vec1[i1]; i1++; i2++; }
		else { vec_unio[n] = vec2[i2]; i2++; }
		n++;
	}

	while (i1 < n1) {
		vec_unio[n] = vec1[i1]; i1++; n++;
	}
	while (i2 < n2) {
		vec_unio[n] = vec2[i2]; i2++; n++;
	}
}

void llegir_vector_enter(Vector_enter vec_enter, unsigned n) {
//Pre: 0<=n<=N_MAX
//Post: vec_enter[0..n-1] conté successivament els enters entrats
	for (unsigned i = 0; i<n; i++) cin >> vec_enter[i];
}

void escriure_vector_enter(const Vector_enter vec_enter, unsigned n) {
//Pre: 0<=n<=N_MAX
//Post: s'han mostrat el n valors de vec_enter[0..n-1]
	for (unsigned i = 0; i<n; i++) cout << vec_enter[i] << " ";
}

int main() {
	Vector_enter vec1, vec2, vec_unio;  unsigned n1, n2, n;
	cout << "Entra longitud del primer vector: ";
	cin >> n1;
	
	cout << "Entra longitud del segon vector: ";
	cin >> n2;


	cout << "Entrar " << n1 << " enters: ";
	llegir_vector_enter(vec1, n1);
	
	cout << "Entrar " << n2 << " enters: ";
	llegir_vector_enter(vec2, n2);
	unio_vectors(vec1, vec2, n1, n2, vec_unio, n);

	escriure_vector_enter(vec_unio, n);

 	return 0;
}
