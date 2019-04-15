#include <iostream>

#include "Pacient.h"


using namespace std;

Pacient::Pacient()
{
    a_dni = a_nom = a_nMetge = "";
    a_estat = 0;
    a_ingressat = 'n'; // bool
}
Pacient::Pacient(const string& dni)
{
    a_dni = dni;
    a_nom = a_nMetge = "";
    a_estat = 0;
    a_ingressat = 'n'; // bool
}


Pacient::Pacient(const string& dni, const string& nom, const string& nMetge, int estat, char ingressat)
{
    a_dni = dni;
    a_nom = nom;
    a_nMetge = nMetge;
    a_estat = estat;
    a_ingressat = ingressat;
}


bool Pacient::esMenor(const Pacient& pacient) const
{
    return a_dni < pacient.a_dni;
}

bool Pacient::esMenorPacientMetge(const Pacient& pacient) const
{
    return a_nMetge < pacient.a_nMetge or
          (a_nMetge == pacient.a_nMetge and a_estat < pacient.a_estat) or
          (a_nMetge == pacient.a_nMetge and a_estat == pacient.a_estat and a_dni < pacient.a_dni);
}


bool Pacient::estaHospitalitzat() const
{
    return a_ingressat;
}

string Pacient::obtMetge() const
{
    return a_nMetge;
}

void Pacient::mostrar() const
{
   cout << a_dni << ' ' << a_nom << ' ' << a_nMetge << ' '
         << a_estat << ' ' << a_ingressat << endl;
}

void Pacient::canviarEstat(int estat, char ingressat)
{
    a_estat = estat;
    a_ingressat = ingressat;
}
