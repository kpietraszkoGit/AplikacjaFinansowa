#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikXml.h"
#include "Markup.h"

using namespace std;

class PlikZUzytkownikami: public PlikXml
{
        //const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;//stala globalna
        //fstream plikTekstowy;

        //bool czyPlikJestPusty(fstream &plikTekstowy);
    void zapiszPojedynczegoUzytkownikaDoPliku(Uzytkownik uzytkownik);
    //Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    //PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku)
    //PlikZUzytkownikami(string nazwaPlikuZUzytkownikami): NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwaPlikuZUzytkownikami) {};//konstruktor z lista inicjalizujaca {}-cia³o konstruktora
    PlikZUzytkownikami(string nazwaPliku): PlikXml(nazwaPliku) {};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();

    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
};

#endif
