#ifndef METGE_H
#define METGE_H

#include <string>

using namespace std;


class Metge
{
    public:
        Metge();
        Metge(const string & codi);
        Metge(const string & codi, int nPacients);

        bool permetPacients() const;
        string obtCodi() const;

        bool esMenor(const Metge & metge) const;


        void incrementarPacients();
        void decrementarPacients();


    private:
        static const int MAX_PACIENTS_METGE = 300;

        string a_codi;
        int a_nPacients;
};

#endif // METGE_H
