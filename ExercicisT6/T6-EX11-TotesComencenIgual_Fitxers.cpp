//Entrada: una seqüència de caràcters acabada en '#'
//Sortida: Diu si totes les paraules de la seqüència comencen igual
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
   if(not fitxer.eof()) fitxer.unget();//pot no ser necessari
}


char passar_paraula_obtenint_inici(ifstream& fitxer){
/*Pre: fitxer vàlid i apunt de llegir el 1r carácter d’una paraula
  Post: s’ha llegit tota una paraula i es retorna el nombre de caràcters que la formen*/
   char inici=fitxer.get();
   char lletra=inici;
   while(not fitxer.eof() and not es_separador(lletra)){
      fitxer.get(lletra);
   }
   if(not fitxer.eof()) fitxer.unget(); //pot no ser necessari
   return inici;
}


bool totes_comencen_igual(ifstream& fitxer){
//Pre: fitxer valid
//Post: retorna cert si totes comencen igual, fals atlrament
    passar_separadors(fitxer);
    char inici=' ',inici_paraula=' ';
    if(not fitxer.eof()){
        inici=passar_paraula_obtenint_inici(fitxer);
        inici_paraula=inici;
        passar_separadors(fitxer);
        while(not fitxer.eof() and inici_paraula==inici){
            inici_paraula=passar_paraula_obtenint_inici(fitxer);
            passar_separadors(fitxer);
        }
    }
    return inici_paraula==inici; //si retorno fitxer.eof() la darrera pot començar!=
}

int main(){
    cout<<"Entra el nom del fitxer: ";
    string nom_fitxer;
    cin>>nom_fitxer;
    ifstream fitxer(nom_fitxer.c_str());
    cout<<"Totes les paraules comencen igual? "<<boolalpha<<totes_comencen_igual(fitxer)<<endl;;
    return 0;
}
