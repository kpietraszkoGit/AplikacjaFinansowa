#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Expense.h"
#include "HelpingMethods.h"
#include "FileXml.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses: public FileXml
{
    //const string NAZWA_PLIKU_Z_ADRESATAMI;//stala globalna
    //string NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWYMI;
    int idLastExpense;
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
    FileWithExpenses(string fileName) : FileXml(fileName)
    {
        idLastExpense = 0;
    };
    bool addExpenseToFile(Expense expense);//dopiszPrzychodDoPliku(Przychod przychod);
    vector <Expense> loadExpensesLoggedUserFromFile(int idLoggedUser);//vector <Przychod> wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int getIdLastExpense();

};

#endif
