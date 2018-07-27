#include <iostream>
#include<iomanip>
using namespace std;

const unsigned N_FIL_MAX = 50, N_COL_MAX = 100; \
typedef int Vector_enter[N_FIL_MAX];
typedef Vector_enter Matriu_enter[N_COL_MAX];

void llegir_matriu_enter(Matriu_enter mat_enter, unsigned n, unsigned m) {
	//Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX
	//Post: mat_enter[0..n-1,0..m-1] conté successivament els enters entrats
	for (unsigned i = 0; i<n; i++) {
		cout << "Entra fila " << i + 1 << " : ";
		for (unsigned j = 0; j<m; j++)
			cin >> mat_enter[i][j];
	}
}

void trobat_i_posicio_element(const Vector_enter vec, unsigned n, int x, bool& trobat, unsigned& pos) {
	//Pre: 0<=n<=N_COL_MAX
	//Post: si x existeix a vec[0..n-1], trobat=cert i pos=posició més petita de x, altrament trobat=fals i pos no té significat
	unsigned i = 0;
	trobat = false;
	while (i<n and not trobat) // not (i=n or trobat)
		if (vec[i] == x) trobat = true;
		else i++;
		if (trobat) pos = i;
}

void cerca_matriu(Matriu_enter mat, int n, int m, int x, bool& trobat, unsigned& fila, unsigned& col) {
	//Pre: 0<=n<=N_FIL_MAX, 0<=m<=N_COL_MAX, 
	//Post: si x pertany a mat, trobat=cert i (fila,col) contenen una posició de x; altrament, trobat=fals i (fila,col) no tenen significat
	int i = 0;
	trobat = false;
	while (i<n and not trobat) {
		trobat_i_posicio_element(mat[i], m, x, trobat, col);
		if (trobat) fila = i;
		else i++;
	}
}

int main() {

	Matriu_enter mat;
	unsigned n, m;
	cout << "Nombre files i columnes de la matriu: ";
	cin >> n >> m;

	cout << "Entra " << n << " files de " << m << " enters: " << endl;
	llegir_matriu_enter(mat, n, m);
	cout << endl;

	int valor;
	cout << "Entra el valor a cercar: ";
	cin >> valor;

	unsigned fila, col;
	bool trobat;
	cerca_matriu(mat, n, m, valor, trobat, fila, col);
	if (trobat) cout << "Trobat a (" << fila << "," << col << ")" << endl;
	else cout << "No trobat" << endl;
	return 0;
}
