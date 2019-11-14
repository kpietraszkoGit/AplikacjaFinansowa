#include "Przychod.h"

void Przychod::ustawIdPrzychodu(int noweIdPrzychodu)//settery aby udostepnic innym klasa to
{
    if (noweIdPrzychodu >= 0)
    idPrzychodu = noweIdPrzychodu;
}
void Przychod::ustawIdUzytkownika(int noweIdUzytkownika)
{
    if (noweIdUzytkownika >= 0)
    idUzytkownika = noweIdUzytkownika;
}
void Przychod::ustawDateInt(int nowaDataInt)
{
    if (nowaDataInt >= 0)
    dataInt = nowaDataInt;
}
void Przychod::ustawDate(string nowaData)
//void Przychod::ustawDate(int nowaData)
{
    data = nowaData;
}
void Przychod::ustawRodzajPrzychodu(string nowyRodzajPrzychodu)
{
    rodzajPrzychodu = nowyRodzajPrzychodu;
}
void Przychod::ustawIlosc(string nowaIlosc)
{
    //if (nowaIlosc >= 0)
    ilosc = nowaIlosc;
}


int Przychod::pobierzIdPrzychodu()
{
    return idPrzychodu;
}
int Przychod::pobierzIdUzytkownika()
{
    return idUzytkownika;
}
int Przychod::pobierzDateInt()
{
    return dataInt;
}
string Przychod::pobierzDate()
{
    return data;
}
string Przychod::pobierzRodzajPrzychodu()
{
    return rodzajPrzychodu;
}
string Przychod::pobierzIlosc()
{
    return ilosc;
}
