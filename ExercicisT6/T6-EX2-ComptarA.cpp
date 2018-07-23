//Entrada: una seqüencia de caràcters acabada en '#'
//Sortida: la quantiat de caràcters 'a' trobats
#include<iostream>
using namespace std;

const char EOS='#';

unsigned comptar_caracters(char lletra){
//Pre:: cert
//Post: compta el nombre d'aparicions de lletra fins a arribar a EOS
    //inicialització
    unsigned comptador=0;
    char element;
    cin>>element; //llegir el 1r element
    while(element!=EOS){ //mentre no final
        //processar l'element
        if(element==lletra) comptador++;
        cin>>element; //llegir el següent
    }
    return comptador;
}

int main(){
    cout<<"Entra una seqüència acabada en '"<<EOS<<"'"<<endl;
    cout<<"S'han trobat "<<comptar_caracters('a')<<" caracters 'a'"<<endl;
    return 0;
}

