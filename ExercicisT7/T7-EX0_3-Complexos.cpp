//Entrada: dos nombres complexos en forma de dos nombres reals cada un
//Sortida: Els resultats de sumar i multiplicar els dos nombres complexos

#include<iostream>

using namespace std;

struct Complex {
	double r; 
	double i;
}; 

Complex suma (Complex num1, Complex num2) {
// Pre: cert; 
//Post: retorna el complex num1+num2
	Complex resultat;
	resultat.r=num1.r+num2.r;
	resultat.i=num1.i+num2.i;
	return resultat;
}

Complex producte (Complex num1, Complex num2) {
// Pre: cert; 
//Post: retorna el complex num1·num2
	Complex resultat;
	resultat.r=num1.r*num2.r- num1.i*num2.i;
	resultat.i=num1.r*num2.i+ num1.i*num2.r;
	return resultat;
}

Complex llegir_complex () {
// Pre: cert; Post: retorna el complex llegit de teclat
	Complex num;
	cout<<"Part real: "; cin>>num.r;
	cout<<"Part imaginaria: "; cin>>num.i;
	return num;
}

void mostrar_complex (Complex num) {
// Pre: cert; Post: mostra el complex num
	if(num.i>=0) cout<<num.r<<" + "<<num.i<<" i ";
	else cout<<num.r<<" "<<num.i<<" i ";
}


int main() {
	
	// Entrada
	Complex complex1 = llegir_complex();
	Complex complex2 = llegir_complex();
	// Càlcul
	Complex sum = suma(complex1, complex2); 
	Complex prod = producte(complex1, complex2); 
	// Sortida
	cout<<"Suma: ";
	mostrar_complex(complex1);
	cout<<endl<<"Producte: ";
	mostrar_complex(prod);
	return 0;
}
