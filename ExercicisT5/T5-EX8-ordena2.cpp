/* Determinar ordenar dos nombres */
// Entrada: dos enters
// Sortida: els enters ordenats

#include<iostream>
using namespace std;

void ordena2(int& a, int& b){
//Pre: a=A, b=B
//Post: a<=b i contenen una permutació d'A i B
    if(a<b){
        //cout<<"- intercanvi -";
        int c=a;
        a=b;
        b=c;
    }
}

int main()
{
	//Entrada
	int n1, n2;
	cout<<"Introdueix dos enters: ";
	cin>>n1>>n2;
	//Càlcul
	ordena2(n1,n2);
	//Sortida
	cout<<"De gran a petit: "<<n1<<" "<<n2<<endl;
	

	return 0;
}
