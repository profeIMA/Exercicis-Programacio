//Entrada: un fitxer de caràcters
//Sortida: copia el text a pantalla sense els ' ' del principi
#include<iostream> 
#include<fstream> 
#include<string>
using namespace std;

void passar_blancs(ifstream& f_entrada){
//Pre: entrada vàlid (obert i sense haver llegit eof())
//Post: s’han llegit tots els blancs d’entrada, està a punt de llegir el 1r no blanc o s’ha arribat a eof
    char element=f_entrada.get();
    while(not f_entrada.eof() and element==' ') f_entrada.get(element);
    if(not f_entrada.eof()) f_entrada.unget();
}

void mostrar_per_pantalla(ifstream& f_entrada){
//Pre: entrada vàlid (obert i sense haver llegit eof())
//Post: mostra per pantalla tot el contingut del fitxer f_entrada que queda per llegir
     char element=f_entrada.get();//llegim el primer element 
     while(not f_entrada.eof()){ //mentre no fi
        cout<<element; //processo element
        f_entrada.get(element); //següent
     }
}

int main(){
    cout<<"Entra el nom del fitxer: ";
    string nom_fitxer; cin>>nom_fitxer;
    ifstream f_entrada(nom_fitxer.c_str());
    passar_blancs(f_entrada);     
    if(not f_entrada.eof()) mostrar_per_pantalla(f_entrada);
    return 0;
}
