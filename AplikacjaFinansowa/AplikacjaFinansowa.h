#ifndef APLIKACJAFINANSOWA_H
#define APLIKACJAFINANSOWA_H

#include <iostream>

#include "UzytkownikMenadzer.h"
#include "PrzychodMenadzer.h"
#include "MetodyPomocnicze.h"
#include "WydatekMenadzer.h"

using namespace std;

class AplikacjaFinansowa
{
    UzytkownikMenadzer uzytkownikMenadzer; //obiekt//12:00
    PrzychodMenadzer *przychodMenadzer;
    WydatekMenadzer *wydatekMenadzer;
    const string NAZWA_PLIKU_Z_PRZYCHODAMI;
    const string NAZWA_PLIKU_Z_WYDATKAMI;
    //AdresatMenadzer *adresatMenadzer;
    //const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    //KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    //    : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    /*AplikacjaFinansowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZPrzychodami)
        : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_PRZYCHODAMI(nazwaPlikuZPrzychodami)*/
    AplikacjaFinansowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZPrzychodami, string nazwaPlikuZWydatkami)
        : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_PRZYCHODAMI(nazwaPlikuZPrzychodami), NAZWA_PLIKU_Z_WYDATKAMI(nazwaPlikuZWydatkami)
    {
        //adresatMenadzer = NULL;// jak sie pracuje na wskaźnikach trzeba przypisać NULL i stworzyć destruktor
        przychodMenadzer = NULL;
        wydatekMenadzer = NULL;
    };
    ~AplikacjaFinansowa()
    {
        delete przychodMenadzer;
        przychodMenadzer = NULL;
        delete wydatekMenadzer;
        wydatekMenadzer = NULL;
    };

    void rejestracjaUzytkownika();// wywolam odpowiednia metode z UzytkownikMenadzer
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    void dodajPrzychod();
    void dodajWydatek();
    void balanceOfMonth();
    //void wyswietlWszystkichAdresatow();
    //void wyszukajAdresatowPoImieniu();
    //void wyszukajAdresatowPoNazwisku();
    //int usunAdresata();
    //void edytujAdresata();
    //void podajIdOstatniegoAdresataPoUsunieciu();

    bool czyUzytkownikJestZalogowany();
    char wybierzOpcjeZMenuUzytkownika();
    char wybierzOpcjeZMenuGlownego();
};

#endif
