#include <iostream>

using namespace std;


struct Temps {
	unsigned hores; 
	unsigned minuts;
	unsigned segons;
}; 

unsigned n_segons(Temps t) {
//Pre: cert Post: retorna el nombre d esegons corresponents a t
	return (t.hores*60+t.minuts)*60+t.segons;
}
Temps de_segons_a_temps(unsigned segons) {
//Pre: cert  Post: retorna un temps amb minuts<60 i segons<60 equivalent als segons entrats
	Temps t;
	t.segons=segons%60;
	t.hores=segons/3600;
	t.minuts=segons/60-t.hores*60;
	return t;
}

Temps diferencia(Temps t_inici, Temps t_fi){
//Pre: t_inici anterior a t_fi Post: retorna la diferència entre t_inici i t_fi
	unsigned segons_inici=n_segons(t_inici);
	unsigned segons_fi = n_segons(t_fi);
	if(segons_inici>segons_fi) segons_fi+=24*3600;
	unsigned segons_diferencia=segons_fi-segons_inici;
	return de_segons_a_temps(segons_diferencia);
}

Temps llegir_temps(){
// Pre: cert; Post: retorna el temps llegit de teclat
	Temps t;
	cout<<"Hores: "; cin>>t.hores;
	cout<<"Minuts: "; cin>>t.minuts;
	cout<<"Segons: "; cin>>t.segons;
	return t;
}

void mostrar_temps(Temps t){
// Pre: cert; Post: mostra el temps
	cout<<t.hores<<" hores, "<<t.minuts<<" minuts i "<<t.segons<<" segons."<<endl;
}

int main()
{
	//Entrada
	cout<<"Entrar temps inicial: "<<endl;
	Temps t_inicial = llegir_temps();

	cout<<"Entrar temps final: "<<endl;
	Temps t_final = llegir_temps();

	//Càlcul
	Temps t_dif = diferencia(t_inicial, t_final);
	
	//Sortida
	cout<<"La diferència és de: "; mostrar_temps(t_dif);

	return 0;	
}
