//Entrada: una seq. d'entrada d'enters acabada en -1
//Sortida: ens diu si la seq. és o creixent o no

#include<iostream>
#include<fstream>
using namespace std;

const int EOS=-1;

bool es_creixent(){
//Pre: cert
//False: retorna cert si la seq és creixent fins a arribar a EOS, fals altr.
    bool es_creixent=true;
    int element_actual, element_anterior;
    cin>>element_actual;
    element_anterior=element_actual;//perquè entri al while
    while(element_actual!=EOS and element_actual>=element_anterior){
        element_anterior=element_actual;
        cin>>element_actual;
    }
    return element_actual==EOS;
}

bool es_creixent_v2(){
//Pre: cert
//False: retorna cert si la seq és creixent fins a arribar a EOS, fals altr.
    bool es_creixent=true;
    int actual, anterior;
    cin>>anterior;
    if(anterior!=EOS){
        cin>>actual;
        while(actual!=EOS and es_creixent){
            if(actual<anterior) es_creixent=false;
            else{
                anterior=actual;
                cin>>actual;
            }
        }
    }
    return es_creixent;
}

int main(){
    cout<<"Entra una seq. d'enters acabada en "<<EOS<<endl;
    cout<<"És creixent? "<<boolalpha<<es_creixent_v2()<<endl;
    return 0;
}
