#ifndef PLIKXML_H
#define PLIKXML_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikXml
{
    const string NAZWA_PLIKU;

public:

    PlikXml(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {};
    string pobierzNazwePliku();
    bool czyPlikJestPusty();
};

/*class PlikZAdresatami : public PlikTekstowy
{

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    void dopisz(string tekst)
    {
        fstream plikTekstowy;
        plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

        if (plikTekstowy.good() == true)
        {
            if (czyPlikJestPusty())
                plikTekstowy << "To jest poczatek pliku" << endl;

             plikTekstowy << tekst << endl;
        }

        plikTekstowy.close();
    }
};*/

/*int main()
{
    PlikZAdresatami plikZAdresatami("AdresaciKTOS.txt");//obiekt klasy o nazwie plikZAdresatami
    //plikZAdresatami.dopisz("tekst do dopisania");

    return 0;
}*/

#endif
