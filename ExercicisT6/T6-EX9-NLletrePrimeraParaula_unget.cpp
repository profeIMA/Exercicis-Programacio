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
         case 'è': case 'é': case 'í': case'ò': case 'ó': case 'ú': case 'ï': case 'ü':
            separador=false; break;
      }
   }
   return separador;
}



void passar_separadors(){
//Pre: EOS no llegida
//Post: EOS no llegida i s'han passat tots els separadors
    char caracter=cin.get();
    while(es_separador(caracter)) caracter=cin.get();
    cin.unget();
}

unsigned passar_paraula_comptant(){
//Pre: EOS no llegida i apunt de començar una paraula
//Post: EOS no llegida i s'ha passat tota la paraula, es retorna la llargada de la paraula.
    char caracter=cin.get();
    unsigned compt=0;
    while(caracter!=EOS and not es_separador(caracter)){
      compt++;
      caracter=cin.get();
    }
    cin.unget();
    return compt;
}

bool fi_sequencia(){
//Pre EOS no llegida
//Post retorna cert si s'ha llegit eos, altrament no s'ha fet res.
    char caracter;
    cin.get(caracter);
    if(caracter!=EOS) cin.unget();
    return  caracter==EOS;
}

int main(){
    cout<<"Entra un text acabat en "<<EOS<<endl;
    passar_separadors();
    if(not fi_sequencia())
        cout<<"La primera praula del text té "<<passar_paraula_comptant()<<endl;
    else
        cout<<"La sequencia no té cap paraula"<<endl;

}
