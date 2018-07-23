//Entrada: el nom d'un fitxer de caràcters existent
//Sortida: copia el text a pantalla sense els ' ' del principi

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const char EOS='#';

char passar_blancs(ifstream& f_entrada){
    char element;
    f_entrada.get(element);
    while(not f_entrada.eof() and element==' ') f_entrada.get(element);
    return element;
}

void mostrar_per_pantalla(ifstream& f_entrada, char element){
//Pre: entrada vàlid (obert i sense haver llegit eof())
//Post: mostra per pantalla lletra seguida de tot el contingut del fitxer entrada
     //el primer element ja el tinc llegit, és element
     while(not f_entrada.eof()){ //mentre no fi
        cout<<element;
        f_entrada.get(element); //següent
     }
}

int main(){
    cout<<"Entra el nom del fitxer: ";
    string nom_fitxer;
    cin>>nom_fitxer;
    ifstream f_entrada(nom_fitxer.c_str());
    if(f_entrada.is_open()){
        char element=passar_blancs(f_entrada);
        cout<<"Contingut del fitxer: "<<endl;
        mostrar_per_pantalla(f_entrada,element);
    }
    else cout<<"Mo s'ha pogut obrir el fitxer"<<endl;
    return 0;
}
