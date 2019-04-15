#ifndef PACIENT_H
#define PACIENT_H

#include <string>

using namespace std;


class Pacient
{
    public:
        Pacient();
        Pacient(const string & dni);
        Pacient(const string & dni, const string & nom, const string & nMetge, int estat, char ingressat);

        // consultores
        bool esMenor(const Pacient & pacient) const;
        bool esMenorPacientMetge(const Pacient & pacient) const;
        bool estaHospitalitzat() const;
        string obtMetge() const;
        void mostrar() const;

        // modificadores
        void canviarEstat(int estat, char ingressat);

    private:
        string a_dni;
        string a_nom;
        string a_nMetge;
        int a_estat;
        char a_ingressat; // bool

};

#endif // PACIENT_H
