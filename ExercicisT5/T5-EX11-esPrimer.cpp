/* Determinar si un nombre és primer*/
// Entrada: un nombre >=2 (nombre)
// Sortida: diu si és o no un nombre primer

#include<iostream>
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

int main ()
{
	//Entrada
	unsigned nombre;
	cout<<"Introdueix un enter >=2: ";
	cin>>nombre;
	if(es_primer(nombre)) cout<<"És primer"<<endl;
	else cout<<"No és primer"<<endl;
	
	return 0;
}
