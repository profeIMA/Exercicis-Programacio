//Entrada: una seqüencia de nombres naturals acabada en -1
//Sortida: la quantiat de nombres parells menors que n
#include<iostream>
using namespace std;

const int EOS=-1;

int main(){
    //inicialització
    unsigned comptador=0;
    int element;
    cin>>element; //llegir el 1r element
    while(element!=EOS){ //mentre no final
        //processar l'element
        if(element%2==0) comptador++;
        cin>>element; //llegir el següent
    }
    //processament final
    cout<<"S'han trobat "<<comptador<<" nombres parells"<<endl;
    return 0;
}

