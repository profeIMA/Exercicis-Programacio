#include<iostream>
using namespace std;

//Entrada: --
//Sortida: escriu el nombre més petit de la sèrie 41, 43, 47, 53, 61, ... que no és  primer

void generar_seguent_terme(unsigned &terme, unsigned &inc) {
//Pre: cert, terme=TERME inc=INC
//Post: terme=TERME+INC i inc=INC+2 (terme s'ha incrementat en inc i inc en 2)
    terme=terme+inc;
    inc=inc+2;
}

bool es_primer(unsigned n) {
//Pre: cert
//Post: retorna cert si n és primer, fals altrament
    bool es_primer=n>1;
    if(n>2){
        unsigned divisor=2;
        while(divisor*divisor<n and n%divisor!=0) divisor++;
        es_primer=n%divisor!=0;
    }
    return es_primer;
}

int main() {
    //Inicialització
    unsigned terme=41;
    unsigned increment=2;
    //Càlcul
    while (es_primer(terme))
        generar_seguent_terme(terme,increment);
    //Sortida
    cout<<"El terme no primer més petit és: "<<terme<<endl;
    return 0;
}

