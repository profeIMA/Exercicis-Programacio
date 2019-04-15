#ifndef PACIENTSMETGES_H
#define PACIENTSMETGES_H

#include "Pacient.h"
#include "Metge.h"

class PacientsMetges
{
    public:
        PacientsMetges();

        // consultors
        void hospitalitzats() const;
        void pacientsMetge() const;

        // modificadors
        void llegirFitxer(const char *nomFitxer);
        void ferVisita(const string & dni);
        void ferBaixa(const string & dni);
        void metgesDisponibles();

    private:
        static const int MAX_PACIENTS = 5000;
        static const int MAX_METGES = 50;
        static const char EOS[];
        static const int NO_TROBAT = -1;

        typedef Pacient taulaP[MAX_PACIENTS];
        typedef Metge taulaM[MAX_METGES];

        // atributs
        taulaP tPacients;
        taulaM tMetges;
        int nPacients;
        int nMetges;

        // accions i funciona privades
        int cercarPacient(const string & dni) const;
        int cercarMetge(const string & codi) const;

        void afegirMetge(const string& codi);
        void inserirMetge(const Metge & metge);
        void inserirPacient(const Pacient & pacient);
        void esborrarPacient(int pos);

        // truco per estalviar-me d'ordenar
        static bool esMenorPacient(const Pacient & p1, const Pacient & p2);
        static bool esMenorPacientMetge(const Pacient & p1, const Pacient & p2);

};

#endif // PACIENTSMETGES_H
