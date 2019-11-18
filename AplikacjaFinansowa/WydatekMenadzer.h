#ifndef WYDATEKMENADZER_H // zabezpieczenie przed podwójnym includowaniem PrzychodMenadzer.h
#define WYDATEKMENADZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Wydatek.h"
#include "PlikZWydatkami.h"
#include "MetodyPomocnicze.h"
#include "MetodyDaty.h"

#include "PrzychodMenadzer.h"

using namespace std;

class WydatekMenadzer
{
    struct sortByDate
    {
        inline bool operator() (Wydatek& firstDate, Wydatek& secondDate)
        {
            return (firstDate.pobierzDateInt() < secondDate.pobierzDateInt());
        }
    };
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;//zeby zadna metoda nie zmienila tej danej
    vector <Wydatek> wydatki;
    PlikZWydatkami plikZWydatkami;
    PrzychodMenadzer przychodMenadzer;

    Wydatek podajDaneNowegoWydatku();
    Wydatek podajDaneWydatku(string data);
    void wyswietlWydatek(Wydatek wydatek);

    char wybierzOpcjeDaty();


public:
    WydatekMenadzer(string nazwaPlikuZWydatkami, int idZalogowanegoUzytkownika) //konstruktor: odbieram nazwaPlikuZAdresatami i wysłam do plikuZAdresatami, natepnie odbieram idZalogowanegoUzytkownika którego przypisuje do stalej ID_ZALOGOWANEGO_UZYTKOWNIKA;
        : plikZWydatkami(nazwaPlikuZWydatkami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        wydatki = plikZWydatkami.wczytajWydatekZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        int suma = 0;
    };

    void dodajWydatek();
    void wyswietlWydatkiZBiezacegoMiesiaca();

    void dateSorting(Wydatek wydatek);
    int currentMonth(Wydatek wydatek);
    int pobierzSume();
};

#endif
