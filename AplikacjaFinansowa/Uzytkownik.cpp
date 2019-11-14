#include "Uzytkownik.h"

void Uzytkownik::ustawId(int noweId)//settery aby udostepnic innym klasa to
{
    if(noweId >= 0)
    id = noweId;
}
void Uzytkownik::ustawLogin(string nowyLogin)
{
    login = nowyLogin;
}
void Uzytkownik::ustawHaslo(string noweHaslo)
{
    haslo = noweHaslo;
}
void Uzytkownik::ustawImie(string noweImie)
{
    imie = noweImie;
}
void Uzytkownik::ustawNazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}

int Uzytkownik::pobierzId()
{
    return id;
}
string Uzytkownik::pobierzLogin()
{
    return login;
}
string Uzytkownik::pobierzHaslo()
{
    return haslo;
}
string Uzytkownik::pobierzImie()
{
    return imie;
}
string Uzytkownik::pobierzNazwisko()
{
    return nazwisko;
}
