//Entrada: Dos fitxers de nombres naturals ordenats creixentment
//Sortida: Crea un fitxer ordenat amb els nombres que apareixen en els dos fitxers (sense repeticions)
#include <iostream>
#include<fstream>
using namespace std;

void copiar_fitxer(ifstream& fitxer, ofstream& sortida){
//Pre: fitxer i sortida oberts
//Post: s'ha llegit tot el que quedava per llegir a fitxer i s'ha copiat a sortida
    int numero;
    while(not fitxer.eof()){
        fitxer>>numero;
        sortida<<numero<<" ";
    }
}


int main(){
    ifstream fitxer1("dades1.txt");
    ifstream fitxer2("dades2.txt");
    ofstream sortida("fusio.txt");
    int numero1, numero2;
    cout<<"Els nombres repetits són: "<<endl;
    fitxer1>>numero1;
    fitxer2>>numero2;
    while(not fitxer1.eof() and not fitxer2.eof()){
        if(numero1==numero2){
            sortida<<numero1<<" ";
            fitxer1>>numero1;
            fitxer2>>numero2;
        }
        else if(numero1<numero2){
            sortida<<numero1<<" ";
            fitxer1>>numero1;
        }
        else{
            sortida<<numero2<<" ";
            fitxer2>>numero2;
        }
    }
    if(not fitxer1.eof()){

		copiar_fitxer(fitxer1,sortida);
    copiar_fitxer(fitxer2,sortida);
    return 0;
}

