//Entrada: una seqüència acabada en # entrada per teclat
//Sortida: El nombre de lletres de la primera paraula d'el text.
#include <iostream>
using namespace std;
const char EOS='#';

bool es_separador(char lletra){
/*Pre: cert
  Post: retorna cert si lletra és un separador, fals altrament */
   bool separador=true;
   if(lletra>='a' and lletra <='z') separador= false;
   else if(lletra>='A' and lletra <='Z') separador= false;
   else if(lletra>='0' and lletra <='9') separador=false;
   else if(lletra==EOS) separador=false;
   else{  //considerem els caràcters especials catalans i castellans
      switch(lletra){
         case '·': case 'ç': case 'Ç': case 'ñ': case'Ñ': case 'à': case 'á':
         case 'è': case 'é': case 'í': case'ò': case 'ó': case 'ú': case 'ï':
         case 'ü':
             separador=false; break;
      }
   }
   return separador;
}

char passar_separadors(){
//Pre: caracter és el darrer caracter llegit
//Post: passa tots els separadors i retorna el primer no separador trobat
    char caracter=cin.get();
    while(es_separador(caracter)) caracter=cin.get();
    return caracter;
}

void passar_paraula_comptant(char& caracter, unsigned& llargada){
//Pre: caracter és el darrer caracter llegit, el primer d'una paraula
//Post: llegeix tota una paraula i caracter el darrer caràcter llegit (el 1r que no forma part de la paraula) i la llargada és el nombre de lletres de la paraula
    llargada=0;
    while(caracter!=EOS and not es_separador(caracter)){
      llargada++;
      caracter=cin.get();
    }
}

int main(){
    cout<<"Entra un text acabat en "<<EOS<<endl;
    char caracter=passar_separadors(caracter);
    if(caracter!=EOS){
        unsigned nombre_lletres;
        passar_paraula_comptant(caracter, nombre_lletres);
        cout<<"La primera praula del text té "<<nombre_lletres<<endl;
    }
    else
        cout<<"La sequencia no té cap paraula"<<endl;
}
