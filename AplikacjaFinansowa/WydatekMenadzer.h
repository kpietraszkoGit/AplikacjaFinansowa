#ifndef WYDATEKMENADZER_H // zabezpieczenie przed podwójnym includowaniem PrzychodMenadzer.h
#define WYDATEKMENADZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Wydatek.h"
//#include "Adresat.h"
#include "PlikZWydatkami.h"
#include "MetodyPomocnicze.h"
#include "MetodyDaty.h"

using namespace std;

class WydatekMenadzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;//zeby zadna metoda nie zmienila tej danej
    vector <Wydatek> wydatki;
    PlikZWydatkami plikZWydatkami;
    //int idUsuwanegoAdresata, idOstatniegoAdresata, idEdytowanegoAdresata;

    Wydatek podajDaneNowegoWydatku();
    Wydatek podajDaneWydatku(string data);
    //void wyswietlDaneAdresata(Adresat adresat);
    //void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    //int podajIdWybranegoAdresata();
    char wybierzOpcjeDaty();
    //void zaktualizujDaneWybranegoAdresata(Adresat adresat);


public://15:50//19:40
    WydatekMenadzer(string nazwaPlikuZWydatkami, int idZalogowanegoUzytkownika) //konstruktor: odbieram nazwaPlikuZAdresatami i wysłam do plikuZAdresatami, natepnie odbieram idZalogowanegoUzytkownika którego przypisuje do stalej ID_ZALOGOWANEGO_UZYTKOWNIKA;
        : plikZWydatkami(nazwaPlikuZWydatkami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        wydatki = plikZWydatkami.wczytajWydatekZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        //adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajWydatek();
    void wyswietlWydatkiZBiezacegoMiesiaca();
    //void wyswietlWszystkichAdresatow();
    //void wyszukajAdresatowPoImieniu();
    //void wyszukajAdresatowPoNazwisku();
    //int usunAdresata();
    //void edytujAdresata();

};

#endif
