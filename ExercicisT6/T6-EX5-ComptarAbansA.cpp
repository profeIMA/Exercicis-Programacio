//Entrada: una seqüència de caràcters acabada en #
//Sortida: si hi ha un a 'a' diu el nombre de caràcters d'abans de la primera 'a', sinó diu que no n'hi ha cap

#include<iostream>
#include<fstream>
using namespace std;

const char EOS='#';

int comptar_abans_aparicio(char lletra){
//Pre: lletra != ws
//Post:  retorna el nombre de caràcters d'abans de llegir lletra o -1 si no es llegeix.
     unsigned comptador=0; //inicialització
     char element;
     cin>>element; //primer element
     while(element!=EOS and element!=lletra){ //mentre no fi
        comptador++; //processar element
        cin>>element; //següent
     }
     if(element==EOS) comptador=-1;
     return comptador;
}

int main(){
    cout<<"Entra una seqüència acabada en "<<EOS<<endl;
    int comptador=comptar_abans_aparicio('a');
    if(comptador==-1) cout<<"No s'ha trobat cap 'a'"<<endl;
    else cout<<"S'han llegit "<<comptador<<" caràcters abans de la primera 'a'"<<endl;
    return 0;
}
