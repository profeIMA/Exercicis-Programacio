/* Determinar si un nombre és parell utilitzant un subprograma */
// Entrada: un natural (n)
// Sortida: indica si n és parell o no

#include<iostream>
using namespace std;

bool es_parell(unsigned n){
//Pre: cert
//Post: cert si n és parell, fals altrament
	return n%2==0;
}

bool te_digit_parell(unsigned n){
//Pre: cert
//Post: cert si n té un dígit parell, fals altrament

    unsigned digit=n%10;
    //FI: n tingui un únic dígit o el dígit analitzat és parell
    while(not es_parell(digit) and n>9){
        cout<<"- "<<digit<<" no parell"<<endl;
        n=n/10;
        digit=n%10;
    }
    return es_parell(digit);
}

int main()
{
	//Entrada
	unsigned n;
	cout<<"Introdueix un natural: ";
	cin>>n;

	//Sortida
	if(te_digit_parell(n)) cout<<"Té un dígit parell"<<endl;
	else cout<<"No té cap dígit parell"<<endl;

	return 0;
}
