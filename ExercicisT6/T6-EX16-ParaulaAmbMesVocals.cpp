//Entrada: un fitxer de caràcters
//Sortida: Diu si hi ha una paraula amb més vocals que consonants
#include<iostream>
#include<fstream>
using namespace std;

bool es_separador(char lletra){
/*Pre: cert
  Post: retorna cert si lletra és un separador, fals altrament */
   bool separador=true;
   if(lletra>='a' and lletra <='z') separador= false;
   else if(lletra>='A' and lletra <='Z') separador= false;
   else if(lletra>='0' and lletra <='9') separador=false;
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

void passar_separadors(ifstream& fitxer){
/*Pre: fitxer vàlid
  Post: s’han llegit tots els separadors */
   char lletra=' ';
   while(not fitxer.eof() and es_separador(lletra))
     fitxer.get(lletra);
   if(not fitxer.eof()) fitxer.unget();
}

bool es_vocal(char lletra){
//Pre: cert
//Post: retorna cert si lletra és una vocal, fals altrament
   bool es_vocal=false;
   switch(lletra){
    case 'a': case 'e': case 'i': case'o': case 'u': case 'A': case 'E': case 'I': case 'U':
    case 'à': case 'è':case 'é':case 'í':case 'ó':case 'ò':case 'ú':case 'ï':case 'ü':
    case 'À': case 'È':case 'É':case 'Í':case 'Ó':case 'Ò':case 'Ú':case 'Ï':case 'Ü': es_vocal=true; break;
   }
   return es_vocal;
}


void passar_paraula_comptant_vocals_consonants(ifstream& fitxer, unsigned& n_vocals, unsigned& n_consonants ){
/*Pre: fitxer vàlid i apunt de llegir el 1r carácter d’una paraula
  Post: s’ha llegit tota una paraula i es n_vocals i n_consonants és el nombre de vocals i de consonants de la paraula llegida*/
   char lletra=fitxer.get();
   n_vocals=0;
   n_consonants=0;
   while(not fitxer.eof() and not es_separador(lletra)){
      if(es_vocal(lletra)) n_vocals++;
      else n_consonants++;
      fitxer.get(lletra);
   }
   if(not fitxer.eof()) fitxer.unget(); //pot no ser necessari
}


bool hi_ha_paraula_amb_mes_vocals(ifstream& fitxer){
//Pre: fitxer valid
//Post: retorna cert si hi ha una paraula amb més vocals que consonants i fals altrament
    unsigned n_vocals=0, n_consonants=1;
    passar_separadors(fitxer);
    while(not fitxer.eof() and n_vocals<=n_consonants){
        passar_paraula_comptant_vocals_consonants(fitxer,n_vocals,n_consonants);
        passar_separadors(fitxer);
    }
    return n_vocals>n_consonants;
}

int main(){
    cout<<"Entra el nom del fitxer: ";
    string nom_fitxer;
    cin>>nom_fitxer;
    ifstream fitxer(nom_fitxer.c_str());
    cout<<"Hi ha paraula amb més vocals? "<<boolalpha<<hi_ha_paraula_amb_mes_vocals(fitxer)<<endl;;
    return 0;
}
