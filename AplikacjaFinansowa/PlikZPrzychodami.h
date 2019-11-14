#ifndef PLIKZPRZYCHODAMI_H
#define PLIKZPRZYCHODAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Przychod.h"
#include "MetodyPomocnicze.h"
#include "PlikXml.h"
#include "Markup.h"

using namespace std;

class PlikZPrzychodami: public PlikXml
{
    //const string NAZWA_PLIKU_Z_ADRESATAMI;//stala globalna
    //string NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWYMI;
    int idOstatniegoPrzychodu;
    //int idUsuwanegoAdresata;
    //fstream plikTekstowy;

    //bool czyPlikJestPusty2(fstream &plikTekstowy);
    //string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    //string pobierzLiczbe(string tekst, int pozycjaZnaku);
   //Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    //int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    //int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    //void usunPlik(string nazwaPlikuZRozszerzeniem);
    //void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public://18:07
    //PlikZAdresatami(string nazwaPlikuZAdresatami): NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    PlikZPrzychodami(string nazwaPliku) : PlikXml(nazwaPliku)
    {
        //NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWYMI = "AdresaciTymczasowi.txt";
        idOstatniegoPrzychodu = 0;
        //idUsuwanegoAdresata = 0;
    };//konstruktor z lista inicjalizujaca {}-cialo konstruktora
    bool dopiszPrzychodDoPliku(Przychod przychod);
    vector <Przychod> wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoPrzychodu();
    //int usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
    //int podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata);//wstawic to gdzies
    //int pobierzZPlikuIdOstatniegoAdresata();//to trzeba uaktywic
    //void edytujAdresataWPliku(Adresat adresat);
};

#endif
