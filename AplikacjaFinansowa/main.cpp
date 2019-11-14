#include <iostream>
#include "AplikacjaFinansowa.h"

using namespace std;
//10:52 - zapisac to i przetestowaæ
/*int main()
{//tutaj jest ok
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    //ksiazkaAdresowa.dodajAdresata();
    //ksiazkaAdresowa.wyswietlWszystkichAdresatow();

}*/
int main()
{
    vector <Uzytkownik> uzytkownicy;
    vector <Przychod> przychody;
    vector <Wydatek> wydatki;
    //vector <Adresat> adresaci;

    //AplikacjaFinansowa aplikacjaFinansowa("users.xml", "incomes.xml", "expenses.xml");//incomes-dochody
    AplikacjaFinansowa aplikacjaFinansowa("users.xml", "incomes.xml", "expenses.xml");
    char wybor;

    while (true)
    {
        if (aplikacjaFinansowa.czyUzytkownikJestZalogowany())
        {
            wybor = aplikacjaFinansowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                //idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
                //ksiazkaAdresowa.dodajAdresata();
                aplikacjaFinansowa.dodajPrzychod();
                break;
            case '2':
                //ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
               // wyszukajAdresatowPoImieniu(adresaci);
                aplikacjaFinansowa.dodajWydatek();
                break;
            case '3':
                aplikacjaFinansowa.balanceOfMonth();
                //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //ksiazkaAdresowa.usunAdresata();
                //ksiazkaAdresowa.podajIdOstatniegoAdresataPoUsunieciu();
                //idUsunietegoAdresata = usunAdresata(adresaci);
                //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;//6:58,
            case '6':
                aplikacjaFinansowa.zmianaHaslaZalogowanegoUzytkownika();
                //ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                aplikacjaFinansowa.wylogowanieUzytkownika();
                //idZalogowanegoUzytkownika = 0;
                //adresaci.clear();
                przychody.clear();//vektor
                wydatki.clear();
                break;
            }
        }
        else
        {
            wybor = aplikacjaFinansowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                aplikacjaFinansowa.rejestracjaUzytkownika();
                break;
            case '2':
                aplikacjaFinansowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
/*#include "AdresatMenadzer.h"
int main()
{
  AdresatMenadzer adresatMenadzer("Adresatek.txt", 2);
  adresatMenadzer.wyswietlWszystkichAdresatow();
  adresatMenadzer.dodajAdresata();
  adresatMenadzer.wyswietlWszystkichAdresatow();
}*/
