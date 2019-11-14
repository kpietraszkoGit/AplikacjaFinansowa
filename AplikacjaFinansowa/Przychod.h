#ifndef PRZYCHOD_H // zabezpieczenie przed podwójnym includowaniem uzytkownik.h
#define PRZYCHOD_H

#include <iostream>

using namespace std;

class Przychod
{
//wszystkie one sa prywatne zahermetyzowane
    int idPrzychodu;
    int idUzytkownika;
    int dataInt;
    string data;
    string rodzajPrzychodu;
    string ilosc;


public:
    Przychod(int idPrzychodu=0, int idUzytkownika=0, int dataInt=0, string data="", string rodzajPrzychodu="", string ilosc="")
    {
        this->idPrzychodu = idPrzychodu;
        this->idUzytkownika = idUzytkownika;
        this->dataInt = dataInt;
        this->data = data;
        this->rodzajPrzychodu = rodzajPrzychodu;
        this->ilosc = ilosc;
    }
    void ustawIdPrzychodu(int noweIdPrzychodu);//gettery aby udostepnic innym klasa, tu publiczenie s¹ metody, które zabezpieczamy w pliku .cpp
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawDateInt(int nowaDataInt);
    void ustawDate(string nowaData);
    void ustawRodzajPrzychodu(string nowyRodzajPrzychodu);
    void ustawIlosc(string nowaIlosc);

    int pobierzIdPrzychodu();//settery
    int pobierzIdUzytkownika();
    int pobierzDateInt();
    string pobierzDate();
    string pobierzRodzajPrzychodu();
    string pobierzIlosc();
};

#endif
