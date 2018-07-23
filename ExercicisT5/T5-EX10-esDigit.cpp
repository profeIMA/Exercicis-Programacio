/* Determinar ordenar dos nombres */
// Entrada: un caràcter (caracter)
// Sortida: diu si és o no un dígit

#include<iostream>
using namespace std;

bool es_digit(char caracter) {
//Pre: cert
//Post: cert si caracter és un digit ('0' a '9')
    return caracter>='0' and caracter<='9';
}

int main()
{
	//Entrada
	char caracter;
	cout<<"Introdueix un caràcter: ";
	cin>>caracter;
	//Càlcul i Sortida
	if(es_digit(caracter)) cout<<"És un dígit"<<endl;
	else cout<<"No es un dígit"<<endl;

	return 0;
}
