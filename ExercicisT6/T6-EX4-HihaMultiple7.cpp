//Entrada: una seqüència de naturals acabada en 0
//Sortida: diu si la seqüència té o no un múltiple de 7

#include<iostream>
#include<fstream>
using namespace std;
const unsigned EOS=0;
bool conte_un_multiple(unsigned divisor){
//Pre: divisor>0
//Post: retorna cert si es llegeix un múliple de divisor !=EOS, fals altrament
     unsigned nombre;
     cin>>nombre; //primer element
     while(nombre!=EOS and nombre%divisor!=0) //mentre no fi
        cin>>nombre; //següent
     return nombre!=EOS;
}

int main(){
    cout<<"Entra una seqüència de naturals acabada en "<<EOS<<endl;
    cout<<"Conté un multiple de 7? "<<boolalpha<<conte_un_multiple(7)<<endl;
    return 0;
}
