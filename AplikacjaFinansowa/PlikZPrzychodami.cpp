#include "PlikZPrzychodami.h"

bool PlikZPrzychodami::dopiszPrzychodDoPliku(Przychod przychod)
{
    CMarkup xml;
    //bool fileExists = xml.Load( "users.xml" );
    bool fileExists = xml.Load(pobierzNazwePliku());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();//wchodzi do glownego elementu
    xml.IntoElem();//wchodzi do srodka elementu
    xml.AddElem("Income"); //dodanie elementu User
    xml.IntoElem(); //wejœcie do elementu User

    xml.AddElem("IncomeId", MetodyPomocnicze::konwerjsaIntNaString(przychod.pobierzIdPrzychodu()));
    xml.AddElem("UserId", MetodyPomocnicze::konwerjsaIntNaString(przychod.pobierzIdUzytkownika()));
    xml.AddElem("DateInt", MetodyPomocnicze::konwerjsaIntNaString(przychod.pobierzDateInt()));
    xml.AddElem("Date", przychod.pobierzDate());
    xml.AddElem("Item", przychod.pobierzRodzajPrzychodu());
    xml.AddElem("Amount", przychod.pobierzIlosc());

    xml.Save(pobierzNazwePliku());

    idOstatniegoPrzychodu++;

cout << "ID dodanego ostatniego adresata: " << idOstatniegoPrzychodu << endl;
system("pause");

    return true;
}
    //PlikZAdresatami plikZAdresatami();//nowe!!!!!!!!!!!!!!!!
/*
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true)
            //czyPlikJestPusty(plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
            plikTekstowy << endl << liniaZDanymiAdresata ;

        idOstatniegoAdresata++;
//cout << "ID dodanego ostatniego adresata: " << idOstatniegoAdresata << endl;
//system("pause");
        plikTekstowy.close();
        return true;
    }
    return false;
}*/

/*
bool PlikZAdresatami::czyPlikJestPusty2(fstream &plikTekstowy)
{
    //fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId())+ '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika())+ '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}
////////////////////////////////*/
vector <Przychod> PlikZPrzychodami::wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    //string neOstaniegoPrzychoduWPliku = "";

    CMarkup xml;
    //bool fileExists = xml.Load( "users.xml" );
    bool fileExists = xml.Load(pobierzNazwePliku());
    Przychod przychod;
    vector <Przychod> przychody;

    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem( "IncomeId" );
        int incomeID = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "UserId" );
        int userID = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "DateInt" );
        int dateInt = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "Date" );
        string date = xml.GetData();
      //int date = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "Item" );
        string item = xml.GetData();
        xml.FindElem( "Amount" );
        string amount = xml.GetData();
        xml.OutOfElem();

        /*cout << "ID: " << userID << " :)"<< endl;
        cout << "Login : " << login << " :)"<< endl;
        cout << "Haslo : " << password << " :)"<< endl;
        cout << "Imie : " << name << " :)"<< endl;
        cout << "Nazwisko : " << surname << " :)"<< endl;
        cout << "ID przychodu: " << incomeID << " :)"<< endl;
        cout << "ID uzytkownika : " << userID << " :)"<< endl;
        system("pause");*/
        if (idZalogowanegoUzytkownika == userID)
        {
            przychod.ustawIdPrzychodu(incomeID);
            przychod.ustawIdUzytkownika(userID);
            przychod.ustawDateInt(dateInt);
            przychod.ustawDate(date);
            przychod.ustawRodzajPrzychodu(item);
            przychod.ustawIlosc(amount);
            //uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            przychody.push_back(przychod);
        }
        if (date == "" && item == "" && amount == "" && incomeID == 0)
        {
            idOstatniegoPrzychodu = 0;
        }
        else
        {
            idOstatniegoPrzychodu = incomeID;
        }
    }

    return przychody;
}
/*
vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    vector <Adresat> adresaci;
    Adresat adresat;
    //int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}
*/
int PlikZPrzychodami::pobierzIdOstatniegoPrzychodu()
{
    return idOstatniegoPrzychodu;
}
/*
int PlikZAdresatami::usunWybranegoAdresataZPliku(int idUsuwanegoAdresata)
{
/*cout << "ID usunietego adresata: " << idUsuwanegoAdresata << endl;
system("pause");
cout << "ID ostatniego adresata: " << idOstatniegoAdresata << endl;
system("pause");

    fstream plikTekstowy, tymczasowyPlikTekstowy;

    int idAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWYMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true && idUsuwanegoAdresata != 0)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
                //cout << "daneJednegoAdresataOddzielonePionowymiKreskami: " << daneJednegoAdresataOddzielonePionowymiKreskami << endl;
                //system("pause");
            idAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami);

                if (idAdresata != idUsuwanegoAdresata)
                {
                    if (czyPlikJestPusty2(tymczasowyPlikTekstowy) == true)
                    //if (czyPlikJestPusty() == false)
                    {
                     //   tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami << endl;
                        tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                    }
                    else
                        tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
                }
                //cout << "idAdresata: " << idAdresata << endl;
                //system("pause");
           /* else if (numerWczytanejLinii != idUsuwanegoAdresata)
            {
                //tymczasowyPlikTekstowy << wczytanaLinia << endl;
            }
            //numerWczytanejLinii++;
        }
        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());
        zmienNazwePliku(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWYMI, pobierzNazwePliku());
    }
    //return true;
    //return idUsuwanegoAdresata;
    podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsuwanegoAdresata, idOstatniegoAdresata);
    return idUsuwanegoAdresata;
}*/
/*
void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}

int PlikZAdresatami::podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata, int idOstatniegoAdresata)
{
        /*cout << "Wchodzi tu???????" << endl;
        system("pause");
        cout << "ID usunietego adresata: " << idUsuwanegoAdresata << endl;
        system("pause");
        cout << "ID ostatniego adresata: " << idOstatniegoAdresata << endl;
        system("pause");
    if (idUsuwanegoAdresata == idOstatniegoAdresata)
    {
        //cout << "Wchodzi w równosc ID???????" << endl;
        //system("pause");
        return pobierzZPlikuIdOstatniegoAdresata();
    }
    else
        return idOstatniegoAdresata;
}
*//*
int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata()
{
    //int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";

    fstream plikTekstowy;
    //plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
            daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    //cout << "!!!daneJednegoAdresataOddzielonePionowymiKreskami: " << daneJednegoAdresataOddzielonePionowymiKreskami << endl;
    //system("pause");
            //plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        //cout << "daneOstaniegoAdresataWPliku2: " << daneOstaniegoAdresataWPliku << endl;
    }
    //cout << "id ostatniego adresata przed wyjsciem z funkcji: " <<idOstatniegoAdresata << endl;
    //system("pause");
    return idOstatniegoAdresata;
}*/
/*
void PlikZAdresatami::edytujAdresataWPliku(Adresat adresat)
{
    fstream plikTekstowy, tymczasowyPlikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string liniaZDanymiAdresata = "";
    int idAdresata = 0;

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWYMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            idAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami);
            liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
//cout << "liniaZDanymiAdresata:  " << liniaZDanymiAdresata << endl;
//system("pause");
            if (idAdresata != adresat.pobierzId())
            {//cout << "rozne ID" << endl;
                    if (czyPlikJestPusty2(tymczasowyPlikTekstowy) == true)
                    //if (czyPlikJestPusty() == false)
                    {
                        tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                    }
                    else
                        tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
            else
            {//cout << "takie same ID: " << adresat.pobierzImie()  << endl;
                    if (czyPlikJestPusty2(tymczasowyPlikTekstowy) == true)
                    //if (czyPlikJestPusty() == false)
                    {
                        tymczasowyPlikTekstowy << liniaZDanymiAdresata;
                    }
                    else
                        tymczasowyPlikTekstowy << endl << liniaZDanymiAdresata;
                    /*if (czyPlikJestPusty() == false)
                    {
                        tymczasowyPlikTekstowy << liniaZDanymiAdresata << endl;
                    }
                }
        }
        plikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(pobierzNazwePliku());//pobierzNazwePliku()
        zmienNazwePliku(NAZWA_PLIKU_Z_ADRESATAMI_TYMCZASOWYMI, pobierzNazwePliku());
    }
}
*/

