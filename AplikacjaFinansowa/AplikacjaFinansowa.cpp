#include "AplikacjaFinansowa.h"

void AplikacjaFinansowa::rejestracjaUzytkownika()
{
    uzytkownikMenadzer.rejestracjaUzytkownika();
}

char AplikacjaFinansowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char AplikacjaFinansowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void AplikacjaFinansowa::logowanieUzytkownika()
{
    uzytkownikMenadzer.logowanieUzytkownika();
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
        przychodMenadzer = new PrzychodMenadzer(NAZWA_PLIKU_Z_PRZYCHODAMI, uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
        wydatekMenadzer = new WydatekMenadzer(NAZWA_PLIKU_Z_WYDATKAMI, uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
    //adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
        //adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika(), NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWYMI);//wstrzykiwanie zaleznosci miedzy klasami,przesy³anie danych
    }
}

void AplikacjaFinansowa::dodajPrzychod()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        przychodMenadzer->dodajPrzychod(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
    }
    else
    {
        cout << "Aby dodac przychod nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void AplikacjaFinansowa::dodajWydatek()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        wydatekMenadzer->dodajWydatek(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
    }
    else
    {
        cout << "Aby dodac wydatek nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void AplikacjaFinansowa::balanceOfMonth()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        przychodMenadzer->wyswietlPrzychodyZBiezacegoMiesiaca(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
        wydatekMenadzer->wyswietlWydatkiZBiezacegoMiesiaca();
    }
    else
    {
        cout << "Aby wyswietlic wszystkie przychody i wydatki nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}
/*
void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        adresatMenadzer->wyswietlWszystkichAdresatow(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
    }
    else
    {
        cout << "Aby wyswietlic wszystkich adresatow nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        adresatMenadzer->wyszukajAdresatowPoImieniu(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
    }
    else
    {
        cout << "Aby wyszukać adresatow po imieniu nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        adresatMenadzer->wyszukajAdresatowPoNazwisku(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
    }
    else
    {
        cout << "Aby wyszukać adresatow po nazwisku nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

int KsiazkaAdresowa::usunAdresata()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        adresatMenadzer->usunAdresata(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
    }
    else
    {
        cout << "Aby usunac adresatow, nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::edytujAdresata()
{
    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        adresatMenadzer->edytujAdresata(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
    }
    else
    {
        cout << "Aby edytowac adresatow, nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}
/*void KsiazkaAdresowa::podajIdOstatniegoAdresataPoUsunieciu()
{
    adresatMenadzer->podajIdOstatniegoAdresataPoUsunieciu();
}
*/
void AplikacjaFinansowa::wylogowanieUzytkownika()
{
    uzytkownikMenadzer.wylogowanieUzytkownika();
    //delete adresatMenadzer;
    //adresatMenadzer = NULL;
    delete przychodMenadzer;
    przychodMenadzer = NULL;
    delete wydatekMenadzer;
    wydatekMenadzer = NULL;
}

void AplikacjaFinansowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

bool AplikacjaFinansowa::czyUzytkownikJestZalogowany()
{
    return uzytkownikMenadzer.czyUzytkownikJestZalogowany();
}
