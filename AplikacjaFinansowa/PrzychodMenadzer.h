#ifndef PRZYCHODMENADZER_H // zabezpieczenie przed podwójnym includowaniem PrzychodMenadzer.h
#define PRZYCHODMENADZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include <algorithm>
#include <bits/stdc++.h>

#include "Przychod.h"
#include "PlikZPrzychodami.h"
#include "MetodyPomocnicze.h"
#include "MetodyDaty.h"

using namespace std;

class PrzychodMenadzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;//zeby zadna metoda nie zmienila tej danej
    vector <Przychod> przychody;
    PlikZPrzychodami plikZPrzychodami;

    Przychod podajDaneNowegoPrzychodu();
    Przychod podajDanePrzychodu(string data);
    void wyswietlPrzychod(Przychod przychod);
    //void wyswietlDaneAdresata(Adresat adresat);
    //void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    //int podajIdWybranegoAdresata();
    char wybierzOpcjeDaty();
    //void zaktualizujDaneWybranegoAdresata(Adresat adresat);


public://15:50//19:40
    PrzychodMenadzer(string nazwaPlikuZPrzychodami, int idZalogowanegoUzytkownika) //konstruktor: odbieram nazwaPlikuZAdresatami i wysłam do plikuZAdresatami, natepnie odbieram idZalogowanegoUzytkownika którego przypisuje do stalej ID_ZALOGOWANEGO_UZYTKOWNIKA;
        : plikZPrzychodami(nazwaPlikuZPrzychodami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        przychody = plikZPrzychodami.wczytajPrzychodyZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        //adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajPrzychod();
    void wyswietlPrzychodyZBiezacegoMiesiaca();
    //void wyswietlWszystkichAdresatow();
    //void wyszukajAdresatowPoImieniu();
    //void wyszukajAdresatowPoNazwisku();
    //int usunAdresata();
    //void edytujAdresata();
    void dateSorting(Przychod przychod);
    bool sprawdzanie(Przychod PierwszyPrzychod, Przychod DrugiPrzychod);

};

#endif
