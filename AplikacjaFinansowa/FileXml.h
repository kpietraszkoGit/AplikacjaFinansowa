#ifndef FILEXML_H
#define FILEXML_H

#include <iostream>
#include <fstream>

using namespace std;

class FileXml
{
    const string FILE_NAME;//nazwa pliku

public:

    FileXml(string fileName) : FILE_NAME(fileName) {};
    string getFileName();//getFileName
    //bool isFileEmpty();
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
