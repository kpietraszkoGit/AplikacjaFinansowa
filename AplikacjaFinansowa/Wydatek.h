#ifndef WYDATEK_H // zabezpieczenie przed podwójnym includowaniem uzytkownik.h
#define WYDATEK_H

#include <iostream>

using namespace std;

class Wydatek
{
//wszystkie one sa prywatne zahermetyzowane
    int idWydatku;
    int idUzytkownika;
    string data;
    string rodzajWydatku;
    string ilosc;


public:
    Wydatek(int idWydatku=0, int idUzytkownika=0, string data="", string rodzajWydatku="", string ilosc="")
    {
        this->idWydatku = idWydatku;
        this->idUzytkownika = idUzytkownika;
        this->data = data;
        this->rodzajWydatku = rodzajWydatku;
        this->ilosc = ilosc;
    }
    void ustawIdWydatku(int noweIdWydatku);//gettery aby udostepnic innym klasa, tu publiczenie s¹ metody, które zabezpieczamy w pliku .cpp
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawDate(string nowaData);
    void ustawRodzajWydatku(string nowyRodzajWydatku);
    void ustawIlosc(string nowaIlosc);

    int pobierzIdWydatku();//settery
    int pobierzIdUzytkownika();
    string pobierzDate();
    string pobierzRodzajWydatku();
    string pobierzIlosc();
};

#endif
