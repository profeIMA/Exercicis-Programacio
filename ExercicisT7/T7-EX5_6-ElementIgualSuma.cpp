// Entrada: llegeix un enter N (nombre d'elements del vector) i el N enters (el vector)
// Sortida: mostra per pantalla si hi ha un element igual a la suma dels ateriors

#include <iostream>

using namespace std;

const unsigned N_MAX=100;
typedef int Vector_enter[N_MAX];


bool hi_ha_element_igual_suma_anteriors(const Vector_enter vec, unsigned n) {
	//Pre: 0<=n<=N_MAX
	//Post: retorna cert si hi ha un vec[i]=vec[0]+...+vec[i-1] amb 0<=i<n (si vec[0]==0 és cert)
	bool trobat=false;
	int suma=0;
	unsigned i=0;
	while (i<n and not trobat) {
		if (suma==vec[i]) trobat=true;
		else {
			suma+=vec[i];
			i++;
		}
	}
	return trobat;
}

void llegir_vector_enter(Vector_enter vec, unsigned n) {
	//Pre: 0<=n<=N_MAX
	//Post: vec[0..n-1] conté successivament els enters entrats
	for (unsigned i=0; i<n; i++) cin>>vec[i];
}


int main() {
	Vector_enter vec; unsigned n;
	cout<<"Nombre d’elements i elements del vector: "<<endl;
	cin>>n;
	llegir_vector_enter(vec,n); 
	cout<<"Hi ha un element igual a la suma dels ateriors ? ";
    cout<<boolalpha<< hi_ha_element_igual_suma_anteriors(vec,n)<<endl;
}