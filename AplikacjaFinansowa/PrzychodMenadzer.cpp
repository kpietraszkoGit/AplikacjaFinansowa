#include "PrzychodMenadzer.h"

void PrzychodMenadzer::dodajPrzychod()
//void AdresatMenadzer::dodajAdresata()//17.45
{
    Przychod przychod;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;

    przychod = podajDaneNowegoPrzychodu();

    przychody.push_back(przychod);
    if (plikZPrzychodami.dopiszPrzychodDoPliku(przychod))
        cout << "Nowy przychod zostal dodany" << endl;
    else
        cout << "Blad, nie udalo sie dodac nowego przychodu do pliku." << endl;
    system("pause");
}

//Przychod PrzychodMenadzer::podajDanePrzychodu(int data)
Przychod PrzychodMenadzer::podajDanePrzychodu(string data)
{
    Przychod przychod;
    string rodzajPrzychodu = "";
    string ilosc = "";
    string dataBezZnaku = "";
    int dateWithoutSignInt = 0;

    dataBezZnaku = MetodyDaty::resetSign(data);
    cout << "data bez znaku: " << dataBezZnaku << endl;
    dateWithoutSignInt = MetodyPomocnicze::konwersjaStringNaInt(dataBezZnaku);
    cout << "data bez znaku int: " << dateWithoutSignInt << endl;

    cout << "Podaj rodzaj przychodu: ";
    cin >> rodzajPrzychodu;

    cout << "Podaj kwote przychodu: ";
    cin >> ilosc;
    ilosc = MetodyPomocnicze::zamianaPrzecinkaNaKropke(ilosc);

    przychod.ustawIdPrzychodu((plikZPrzychodami.pobierzIdOstatniegoPrzychodu()+1));
    przychod.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    przychod.ustawDateInt(dateWithoutSignInt);
    przychod.ustawDate(data);
    przychod.ustawRodzajPrzychodu(rodzajPrzychodu);
    przychod.ustawIlosc(ilosc);//zamiana przcinka na kropke napisac funkcje
    return przychod;
}

Przychod PrzychodMenadzer::podajDaneNowegoPrzychodu()
{
    Przychod przychod;

    string data = "";
    //string rodzajPrzychodu = "";
    //string ilosc = "";//float nie int, bo moga byc ulamki
    char wybor;

    //przychod.ustawIdPrzychodu((plikZPrzychodami.pobierzIdOstatniegoPrzychodu()+1));
    //przychod.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    wybor = wybierzOpcjeDaty();

    switch (wybor)
    {
    case '1':
        cout << "Data dzisiejsza: ";
        data = MetodyDaty::downloadSystemTime();
        przychod = podajDanePrzychodu(data);

        /*string dataBezZnaku;
        int dateWithoutSignInt = 0;

        dataBezZnaku = MetodyDaty::resetSign(data);
        cout << "data bez znaku: " << dataBezZnaku << endl;
        dateWithoutSignInt = MetodyPomocnicze::konwersjaStringNaInt(dataBezZnaku);
        cout << "data bez znaku int: " << dateWithoutSignInt << endl;

        przychod = podajDanePrzychodu(dateWithoutSignInt);*/

        /*cout << "Podaj rodzaj przychodu: ";
        rodzajPrzychodu = MetodyPomocnicze::wczytajLinie();

        cout << "Podaj kwote przychodu: ";
        ilosc = MetodyPomocnicze::wczytajLinie();
        ilosc = MetodyPomocnicze::zamianaPrzecinkaNaKropke(ilosc);
        //kwota=(double)atof(ilosc.c_str());
        //kwota += atof (ilosc.c_str());
        cout << ilosc << endl;
        system("pause");
        //cin >> ilosc;//to jest float dlatego bez metodyPomocnieczej, dodac tutaj metodePomocnicza zminay przecinku na kropke
        przychod.ustawIdPrzychodu((plikZPrzychodami.pobierzIdOstatniegoPrzychodu()+1));
        przychod.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        przychod.ustawDate(data);
        przychod.ustawRodzajPrzychodu(rodzajPrzychodu);
        przychod.ustawIlosc(ilosc);//zamiana przcinka na kropke napisac funkcje
        return przychod;*/
        break;
    case '2':
        cout << "Podaj date w formacie rrrr-mm-dd !!!" << endl;
        data = MetodyDaty::trueDateRange();

        przychod = podajDanePrzychodu(data);

       /* cout << "Podaj rodzaj przychodu: ";
        cin >> rodzajPrzychodu;
        //rodzajPrzychodu = MetodyPomocnicze::wczytajLinie();

        cout << "Podaj kwote przychodu: ";
        ilosc = MetodyPomocnicze::wczytajLinie();
        ilosc = MetodyPomocnicze::zamianaPrzecinkaNaKropke(ilosc);

        przychod.ustawIdPrzychodu((plikZPrzychodami.pobierzIdOstatniegoPrzychodu()+1));
        przychod.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        przychod.ustawDate(data);
        przychod.ustawRodzajPrzychodu(rodzajPrzychodu);
        przychod.ustawIlosc(ilosc);//zamiana przcinka na kropke napisac funkcje
        return przychod;*/
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
        break;
    }

    //////////////////////////////////////////////
/*    cout << "Podaj date: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);*/

    return przychod;
}

char PrzychodMenadzer::wybierzOpcjeDaty()
{
    char wybor;

    cout << "Z jakiej daty jest przychod? " << endl;
    cout << "1 - Dzisiejsza data" << endl;
    cout << "2 - Inna data" << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

int PrzychodMenadzer::wyswietlPrzychodyZBiezacegoMiesiaca()
{
    int quantity = 0;
    int sumIncome = 0;
    system("cls");
    //string dataBezZnaku;
    if (!przychody.empty())
    {
        cout << "    >>> PRZYCHODY Z BIEZACEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Przychod> :: iterator itr = przychody.begin(); itr != przychody.end(); itr++)
        {

            //dataBezZnaku = MetodyDaty::resetSign(itr -> pobierzDate());
            //przychod.ustawDate(dataBezZnaku);
            //przychody.push_back(przychod);

            //if (itr -> pobierzIdUzytkownika() == imiePoszukiwanegoAdresata)
            //{
                dateSorting(*itr);
                //wyswietlPrzychod(*itr); //wyswietla wszystko
                quantity = currentMonth(*itr);
                sumIncome = sumIncome + quantity;
            //}
        }
        cout << "Suma przychodow: " << sumIncome << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "Nie ma zadnych przychodow." << endl << endl;
    }
    return sumIncome;
   // system("pause");
}

int PrzychodMenadzer::pokazSume()
{
    int pobierzSume = wyswietlPrzychodyZBiezacegoMiesiaca();
    return pobierzSume;
}

void PrzychodMenadzer::wyswietlPrzychod(Przychod przychod)
{
    cout << "Id przychodu:                        " << przychod.pobierzIdPrzychodu() << endl;
    cout << "Data przychodu:                      " << przychod.pobierzDate() << endl;
    cout << "Rodzaj przychodu:                    " << przychod.pobierzRodzajPrzychodu() << endl;
    cout << "Kwota:                               " << przychod.pobierzIlosc() << endl;
    cout << endl;
}

void PrzychodMenadzer::dateSorting(Przychod przychod)
{
    sort(przychody.begin(), przychody.end(), sortByDate());
}

int PrzychodMenadzer::currentMonth(Przychod przychod)
{
    int IncomeInt = 0;
    int year = 0, month = 0, day = 0, currentDataInt = 0, dateOfBeginInt = 0;
    string dayStringNumber  = "", monthStringNumber = "", dayString = "", beginMonth = "", beginYear = "", dateOfBegin = "", currentData = "";
    string beginDay = "01";

    SYSTEMTIME st;
    GetSystemTime(&st);

    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;

    dayString = MetodyPomocnicze::konwerjsaIntNaString(day);
    if (dayString.length() == 1)
    {
        dayStringNumber = "0"+dayString;
    }
    else dayStringNumber = dayString;

    beginMonth = MetodyPomocnicze::konwerjsaIntNaString(month);
    if (beginMonth.length() == 1)
    {
        monthStringNumber = "0"+beginMonth;
    }
    else monthStringNumber = beginMonth;

    beginYear = MetodyPomocnicze::konwerjsaIntNaString(year);
    dateOfBegin = beginYear+monthStringNumber+beginDay;

    currentData = beginYear+monthStringNumber+dayStringNumber;
    currentDataInt = MetodyPomocnicze::konwersjaStringNaInt(currentData);
    dateOfBeginInt = MetodyPomocnicze::konwersjaStringNaInt(dateOfBegin);
    if (przychod.pobierzDateInt() >= dateOfBeginInt && przychod.pobierzDateInt() <= currentDataInt)
    {
        wyswietlPrzychod(przychod);
        IncomeInt = MetodyPomocnicze::konwersjaStringNaInt(przychod.pobierzIlosc());
        return IncomeInt;
    }
    else return 0;
}


/*
void AdresatMenadzer::wyswietlWszystkichAdresatow()
{
    system("cls");

    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenadzer::wyszukajAdresatowPoImieniu()//poprawic ta funkcje
//void wyszukajAdresatowPoImieniu(vector <Adresat> &adresaci)
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenadzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenadzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow)
{
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc wyszukanych adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}

void AdresatMenadzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

int AdresatMenadzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    //int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                //numerLiniiUsuwanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata);
                //usunWybranaLinieWPliku(numerLiniiUsuwanegoAdresata);

                //idUsuwanegoAdresata = PlikZAdresatami::usunWybranegoAdresataZPliku(idUsuwanegoAdresata);
                plikZAdresatami.usunWybranegoAdresataZPliku(idUsuwanegoAdresata);

                adresaci.erase(itr);
                cout << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
//cout << "ID usunietego adresata: " << idUsuwanegoAdresata << endl;
                system("pause");
                return idUsuwanegoAdresata;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return 0;
}
*/
/*void AdresatMenadzer::podajIdOstatniegoAdresataPoUsunieciu()
{
    plikZAdresatami.podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsuwanegoAdresata, idOstatniegoAdresata);
}*/
/*
int AdresatMenadzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatMenadzer::edytujAdresata()
{
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    string imie, nazwisko, numerTelefonu, email, adres;

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();
//cout << "idEdytowanegoAdresata:jest OK:: " << idEdytowanegoAdresata << endl;
//system("pause");

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                imie = MetodyPomocnicze::wczytajLinie();
                imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
                adresaci[i].ustawImie(imie);
                //cout << adresaci[i].pobierzId() << "|" << adresaci[i].pobierzIdUzytkownika() << "|" << adresaci[i].pobierzImie() << "|" << endl;
                //system("pause");
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                nazwisko = MetodyPomocnicze::wczytajLinie();
                nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
                adresaci[i].ustawNazwisko(nazwisko);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                numerTelefonu = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawNumerTelefonu(numerTelefonu);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                email = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawEmail(email);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adres = MetodyPomocnicze::wczytajLinie();
                adresaci[i].ustawAdres(adres);
                zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatMenadzer::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void AdresatMenadzer::zaktualizujDaneWybranegoAdresata(Adresat adresat)
{
    plikZAdresatami.edytujAdresataWPliku(adresat);
    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

*/



