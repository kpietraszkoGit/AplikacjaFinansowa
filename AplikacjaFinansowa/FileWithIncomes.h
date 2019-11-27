#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Income.h"
#include "HelpingMethods.h"
#include "FileXml.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes: public FileXml
{
    //const string NAZWA_PLIKU_Z_ADRESATAMI;//stala globalna
    //string NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWYMI;
    int idLastIncome;//idOstatniegoPrzychodu;
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
    FileWithIncomes(string fileName) : FileXml(fileName)
    {
        idLastIncome = 0;//idOstatniegoPrzychodu = 0;
    };
    bool addIncomeToFile(Income income);//dopiszPrzychodDoPliku(Przychod przychod);
    vector <Income> loadIncomesLoggedUserFromFile(int idLoggedUser);//vector <Przychod> wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int getIdLastIncome(); //lub//getIdLastIncomeFromFile//pobierzIdOstatniegoPrzychodu();
};

#endif
