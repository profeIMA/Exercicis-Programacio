#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

#include "PacientsMetges.h"

const char PacientsMetges::EOS[] = "s";

PacientsMetges::PacientsMetges()
{
    nPacients = nMetges = 0;
}

void PacientsMetges::hospitalitzats() const
{
    cout << "Llistat d'hospitalitzats" << endl;
    for (int i=0; i<nPacients; i++)
        if (tPacients[i].estaHospitalitzat())
            tPacients[i].mostrar();
}

void PacientsMetges::pacientsMetge() const
{
    taulaP tAux;
    for (int i=0; i<nPacients; i++) // es fa un duplicat de la taula
        tAux[i] = tPacients[i];
    sort(tAux, tAux + nPacients, esMenorPacientMetge); //...i s'ordena

    cout << "Llistat pacients" << endl;
    for (int i=0; i<nPacients; i++)
        tAux[i].mostrar();
}

void PacientsMetges::llegirFitxer(const char* nomFitxer)
{
    ifstream f(nomFitxer);
    string dni, nom, nMetge;
    int estat;
    char ingressat;

    if (f.is_open()) {
        f >> dni;
        while (dni != EOS) {
            f  >> nom >> nMetge >> estat >> ingressat;

            Pacient pacient(dni, nom, nMetge, estat, ingressat);
            tPacients[nPacients] = pacient;
            nPacients++;
            afegirMetge(nMetge);

            f >> dni;
        }
        f.close();
        sort(tPacients, tPacients + nPacients, esMenorPacient); // s'ordena després de llegir
    }
    else
        cerr << "No s'ha trobat el fitxer de dades " << endl;
}

void PacientsMetges::ferVisita(const string & dni)
{
    string nom, nMetge;
    int estat;
    char ingressat;

    int pos = cercarPacient(dni);
    if (pos != NO_TROBAT) {
        cout << "Estat:" << endl;
        cin >> estat;
        cout << "Hospitalitzat (s/n):" << endl;
        cin >> ingressat;
        tPacients[pos].canviarEstat(estat, ingressat);
    }
    else {
        cout << "Nom:" << endl;
        cin >> nom;
        cout << "Metge:" << endl;
        cin >> nMetge;
        cout << "Estat:" << endl;
        cin >> estat;
        cout << "Hospitalitzat (s/n):" << endl;
        cin >> ingressat;

        int posMetge = cercarMetge(nMetge);
        while (posMetge!=NO_TROBAT and not tMetges[posMetge].permetPacients()) {
            cout << "Metge no vàlid" << endl;
            cout << "Metge:" << endl;
            cin >> nMetge;
            posMetge = cercarMetge(nMetge);
        }

        Pacient pacient(dni, nom, nMetge, estat, ingressat);
        inserirPacient(pacient);
        afegirMetge(nMetge);
    }
}

void PacientsMetges::ferBaixa(const string & dni)
{
/*    string dni;

    cout << "DNI:" << endl;
    cin >> dni; */

    int pos = cercarPacient(dni);

    if (pos == NO_TROBAT) {
        cout << "No trobat" << endl;
    }
    else {
        esborrarPacient(pos);
    }
}

void PacientsMetges::metgesDisponibles()
{
    int i = 0;
    while (i < nMetges and not tMetges[i].permetPacients())
        i++;
    if (i == nMetges)
        cout << "Tots estan plens" << endl;
    else
        cout << tMetges[i].obtCodi() << " té disponibilitat" << endl;
}


int PacientsMetges::cercarPacient(const string& dni) const
{
    Pacient pacient(dni);
    int mig, esq = 0, dreta = nPacients-1;
    bool trobat = false;
    while (not trobat and esq <= dreta) {
        mig = (esq+dreta)/2;
        if (pacient.esMenor(tPacients[mig])) dreta = mig-1;
        else if (tPacients[mig].esMenor(pacient)) esq = mig+1;
        else trobat = true;
   }

   if (trobat) return mig;
   else return NO_TROBAT;
}

int PacientsMetges::cercarMetge(const string& codi) const
{
    Metge metge(codi);
    int mig, esq = 0, dreta = nMetges-1;
    bool trobat = false;
    while (not trobat and esq <= dreta) {
        mig = (esq+dreta)/2;
        if (metge.esMenor(tMetges[mig])) dreta = mig-1;
        else if (tMetges[mig].esMenor(metge)) esq = mig+1;
        else trobat = true;
   }
   if (trobat) return mig;
   else return NO_TROBAT;

}

void PacientsMetges::afegirMetge(const string& codi)
{
    int pos = cercarMetge(codi);

    if (pos == NO_TROBAT) {
        Metge metge(codi, 1);
        inserirMetge(metge);
    }
    else if (not tMetges[pos].permetPacients())
        cerr << "masses pacient per metge" << endl;
    else
        tMetges[pos].incrementarPacients();

}

void PacientsMetges::inserirMetge(const Metge& metge)
{
    int i = nMetges;
    while (i>0 and metge.esMenor(tMetges[i-1])) {
        tMetges[i] = tMetges[i-1];
        i--;
    }
    tMetges[i] = metge;
    nMetges++;
}


void PacientsMetges::inserirPacient(const Pacient& pacient)
{
    int i = nPacients;
    while (i>0 and pacient.esMenor(tPacients[i-1])) {
        tPacients[i] = tPacients[i-1];
        i--;
    }
    tPacients[i] = pacient;
    nPacients++;
}



void PacientsMetges::esborrarPacient(int pos)
{
    int posMetge = cercarMetge(tPacients[pos].obtMetge());
    if (posMetge == NO_TROBAT) {
        cerr << "No s'ha trobat un metge que hauria d'existir" << endl;
    }
    else {
        tMetges[posMetge].decrementarPacients();
    }

    nPacients--;
    for (int i=pos; i<nPacients; i++)
        tPacients[i] = tPacients[i+1];
}



bool PacientsMetges::esMenorPacient(const Pacient& p1, const Pacient& p2)
{
    return p1.esMenor(p2);
}

bool PacientsMetges::esMenorPacientMetge(const Pacient& p1, const Pacient& p2)
{
    return p1.esMenorPacientMetge(p2);
}



