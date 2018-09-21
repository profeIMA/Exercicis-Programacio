// Entrada: llegeix les dimensions de l'edifici, portes i finestres i el nombre de portes i finestres
// Sortida: mostra la superfície que cal pintar d'acord amb les dades entrades

#ifdef _WIN32
    #include <Windows.h>
#endif

#include <iostream>

using namespace std;
    

int main()
{
    #ifdef _WIN32
	//Perquè el text mostrat es llegeixi correctament cal canviar la codificació de caràcters utilitzada a la consola de Windows
        SetConsoleOutputCP(1252);
        SetConsoleCP(1252);
    #endif
	
    cout<<"Entra totes les mesures en metres"<<endl<<"Amplada, alçada i llargada: "<<endl;
    double amplada, alcada, llargada;
    cin>>amplada>>alcada>>llargada;
    
    cout<<"Nombre de finestres: "<<endl;
    unsigned n_finestres;
    cin>>n_finestres;
    cout<<"Amplada i alçada de les finestres:"<<endl;
    double amplada_f, alcada_f;
    cin>>amplada_f>>alcada_f;

    cout<<"Nombre de portes: "<<endl;
    unsigned n_portes;
    cin>>n_portes;
    cout<<"Amplada i alçada de les portes:"<<endl;
    double amplada_p, alcada_p;
    cin>>amplada_p>>alcada_p;

    double edifici_sup=(amplada*alcada+llargada*alcada)*2;
    double finestres_sup=n_finestres*amplada_f*alcada_f;
    double portes_sup=n_portes*amplada_p*alcada_p;
    double pintar=edifici_sup-finestres_sup-portes_sup;
    cout<<"La superfície a pintar és de "<<pintar<<"m^2."<<endl;
}
