//Entrada: Dos fitxers de nombres naturals ordenats creixentment
//Sortida: Mostra els nobres que apareixen repetits en els dos fitxers
#include <iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fitxer1("dades1.txt");
    ifstream fitxer2("dades2.txt");
    int numero1, numero2;
    cout<<"Els nombres repetits són: "<<endl;
    fitxer1>>numero1;
    fitxer2>>numero2;
    while(not fitxer1.eof() and not fitxer2.eof()){
        if(numero1==numero2){
            cout<<numero1<<" ";
            fitxer1>>numero1;
            fitxer2>>numero2;
        }
        else if(numero1<numero2) fitxer1>>numero1;
        else fitxer2>>numero2;
    }
    cout<<endl;
    return 0;
}