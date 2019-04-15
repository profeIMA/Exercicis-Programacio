#include "Metge.h"

Metge::Metge()
{
    a_codi = "";
    a_nPacients = 0;
}


Metge::Metge(const string& codi)
{
    a_codi = codi;
    a_nPacients = 0;
}

Metge::Metge(const string& codi, int nPacients)
{
    a_codi = codi;
    a_nPacients = nPacients;
}



bool Metge::permetPacients() const
{
    return a_nPacients < MAX_PACIENTS_METGE;
}

string Metge::obtCodi() const
{
    return a_codi;
}


bool Metge::esMenor(const Metge& metge) const
{
    return a_codi < metge.a_codi;
}

void Metge::incrementarPacients()
{
    a_nPacients++;
}

void Metge::decrementarPacients()
{
    a_nPacients--;
}
