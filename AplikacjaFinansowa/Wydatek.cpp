#include "Wydatek.h"

void Wydatek::ustawIdWydatku(int noweIdWydatku)//settery aby udostepnic innym klasa to
{
    if (noweIdWydatku >= 0)
    idWydatku = noweIdWydatku;
}
void Wydatek::ustawIdUzytkownika(int noweIdUzytkownika)
{
    if (noweIdUzytkownika >= 0)
    idUzytkownika = noweIdUzytkownika;
}
void Wydatek::ustawDate(string nowaData)
{
    data = nowaData;
}
void Wydatek::ustawRodzajWydatku(string nowyRodzajWydatku)
{
    rodzajWydatku = nowyRodzajWydatku;
}
void Wydatek::ustawIlosc(string nowaIlosc)
{
    //if (nowaIlosc >= 0)
    ilosc = nowaIlosc;
}


int Wydatek::pobierzIdWydatku()
{
    return idWydatku;
}
int Wydatek::pobierzIdUzytkownika()
{
    return idUzytkownika;
}
string Wydatek::pobierzDate()
{
    return data;
}
string Wydatek::pobierzRodzajWydatku()
{
    return rodzajWydatku;
}
string Wydatek::pobierzIlosc()
{
    return ilosc;
}
