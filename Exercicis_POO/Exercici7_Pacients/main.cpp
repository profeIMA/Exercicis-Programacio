#include <iostream>


#ifdef _WIN32       //no s'havia de posar a l'examen
#include<windows.h> //no s'havia de posar a l'examen
#endif              //no s'havia de posar a l'examen


#include "PacientsMetges.h"

const char NOM_FITXER[] = "pacients.txt";

using namespace std;


char menu() {
    char opcio;
    cout << "Menú" << endl;
    cout << "v: Visita" << endl;
    cout << "b: Baixa del sistema" << endl;
    cout << "d: Metge disponible" << endl;
    cout << "h: Hospitalizats" << endl;
    cout << "m: Pacients per metge" << endl;
    cout << "x: Sortir" << endl;
    cout << "Opcio: " << endl;
    cin >> opcio;

    return opcio;
}


string llegirDni() {
    string dni;
    cout << "DNI:" << endl;
    cin >> dni;

    return dni;
}


void gestionarOpcions(PacientsMetges & pacientsMetges) {
    char opcio = menu();

    while (opcio != 'x') {
        if (opcio == 'v')
            pacientsMetges.ferVisita(llegirDni());
        else if (opcio == 'b')
            pacientsMetges.ferBaixa(llegirDni());
        else if (opcio == 'd')
            pacientsMetges.metgesDisponibles();
        else if (opcio == 'h')
            pacientsMetges.hospitalitzats();
        else if (opcio == 'm')
            pacientsMetges.pacientsMetge();
        else
            cerr << "opcio no valida " << opcio << endl;
        opcio = menu();
    }
}


int main()
{
    #ifdef _WIN32                //no s'havia de posar a l'examen
    SetConsoleOutputCP(1252); //no s'havia de posar a l'examen
    SetConsoleCP(1252);       //no s'havia de posar a l'examen
    #endif                       //no s'havia de posar a l'examen
    PacientsMetges pacientsMetges;

    pacientsMetges.llegirFitxer(NOM_FITXER);
    gestionarOpcions(pacientsMetges);

    return 0;
}


/**
h
v
25153255E
3
n
v
53215425F
Marc
100000581
7
n
d
m
b
52868425r
b
52865425R
v
34234324E
Miquel
1000000001
3
s
x

*/
