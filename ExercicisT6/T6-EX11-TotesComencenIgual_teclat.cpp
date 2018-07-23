//Entrada: una seqüència de caràcters acabada en '#'
//Sortida: Diu si totes les paraules de la seqüència comencen igual
#include<iostream>
using namespace std;

const char EOS='#';

bool es_separador(char lletra){
/*Pre: cert
  Post: retorna cert si lletra és un separador, fals altrament */
   bool separador=true;
   if(lletra>='a' and lletra <='z') separador= false;
   else if(lletra>='A' and lletra <='Z') separador= false;
   else if(lletra>='0' and lletra <='9') separador=false;
   else if (lletra==EOS) separador=false;
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

void passar_separadors(){
/*Pre: fitxer vàlid
  Post: s’han llegit tots els separadors */
   char lletra=' ';
   while(lletra!=EOS and es_separador(lletra))
     cin.get(lletra);
   cin.unget();
}


bool fi_sequencia(){
/*Pre: EOS no llegida
  Post: retorna cert si es detecta EOS, fals altrament */
   char lletra=cin.get(); //agafem el següent caràcter
   bool final=lletra==EOS; //mirem si indica el final
   if(not final) cin.unget(); //si no és EOS es retorna pq sigui llegit
   return final;
}

char passar_paraula_obtenint_inici(){
/*Pre: fitxer vàlid i apunt de llegir el 1r carácter d’una paraula
  Post: s’ha llegit tota una paraula i es retorna el nombre de caràcters que la formen*/
   char inici=cin.get(); //lletra=cin.get();
   char lletra=inici;
   while(inici!=EOS and not es_separador(lletra)){
      cin.get(lletra); //lletra=cin.get();
   }
   cin.unget(); //pot no ser necessari
   return inici;
}

bool totes_comencen_igual(){
//Pre: cert
//Post: retorna cert si totes les paraules fins a EOS comencen igual, fals atlrament
    char inici=' ', inici_paraula=' ';
    passar_separadors();
    if(not fi_sequencia()){
        inici=passar_paraula_obtenint_inici();
        inici_paraula=inici;
        passar_separadors();
        while(not fi_sequencia() and inici_paraula==inici){
            inici_paraula=passar_paraula_obtenint_inici();
            passar_separadors();
        }
    }
    return inici_paraula==inici; //he de validar que totes, inclosa la darrera comencin igual
}

int main(){
    cout<<"Entra la seqüència acabada en "<<EOS<<endl;
    cout<<"Totes les paraules comencen igual? "<<boolalpha<<totes_comencen_igual()<<endl;;
    return 0;
}
