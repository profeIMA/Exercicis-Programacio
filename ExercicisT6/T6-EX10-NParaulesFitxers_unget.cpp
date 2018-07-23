//Entrada: un fitxer de caràcters
//Sortida: quantes paraule tè el fitxer
#include<iostream>
#include<fstream>
#include<string>
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
   char lletra;
   fitxer.get(lletra);
   while(not fitxer.eof() and es_separador(lletra))
     fitxer.get(lletra);
  fitxer.unget(); //pot no ser necessari
}


void passar_paraula(ifstream& fitxer){
/*Pre: fitxer vàlid i apunt de llegir el 1r carácter d’una paraula
  Post: s’ha llegit tota una paraula */
   char lletra=fitxer.get(); //lletra=cin.get();
   while(not fitxer.eof() and not es_separador(lletra)){
      fitxer.get(lletra); //lletra=cin.get();
   }
   cout<<endl;
   fitxer.unget(); //pot no ser necessari
}

unsigned nombre_paraules(ifstream& fitxer){
//Pre: fitxer vàlid
//Post: retorna el nombre de paraules de fitxer, eof llegit
    unsigned n_paraules=0;
    passar_separadors(fitxer);
    while(not fitxer.eof()){
        passar_paraula(fitxer);
        n_paraules++;
        passar_separadors(fitxer);
    }
    return n_paraules;
}

int main(){
    cout<<"Entra el nom del fitxer: ";
    string nom_fitxer;
    cin>>nom_fitxer;
    ifstream fentrada(nom_fitxer.c_str());
    cout<<"Conté "<<nombre_paraules(fentrada)<<" paraules."<<endl;;
    return 0;
}
