#include "PlikZWydatkami.h"

bool PlikZWydatkami::dopiszWydatekDoPliku(Wydatek wydatek)
{
    CMarkup xml;
    //bool fileExists = xml.Load( "users.xml" );
    bool fileExists = xml.Load(pobierzNazwePliku());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();//wchodzi do glownego elementu
    xml.IntoElem();//wchodzi do srodka elementu
    xml.AddElem("Expense"); //dodanie elementu wydatek
    xml.IntoElem(); //wej�cie do elementu User

    xml.AddElem("ExpenseId", MetodyPomocnicze::konwerjsaIntNaString(wydatek.pobierzIdWydatku()));
    xml.AddElem("UserId", MetodyPomocnicze::konwerjsaIntNaString(wydatek.pobierzIdUzytkownika()));
    xml.AddElem("Date", wydatek.pobierzDate());
    xml.AddElem("Item", wydatek.pobierzRodzajWydatku());
    xml.AddElem("Amount", wydatek.pobierzIlosc());

    xml.Save(pobierzNazwePliku());

    idOstatniegoWydatku++;

cout << "ID dodanego ostatniego wydatku: " << idOstatniegoWydatku << endl;
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
vector <Wydatek> PlikZWydatkami::wczytajWydatekZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    //string daneOstaniegoPrzychoduWPliku = "";

    CMarkup xml;
    //bool fileExists = xml.Load( "users.xml" );
    bool fileExists = xml.Load(pobierzNazwePliku());
    Wydatek wydatek;
    vector <Wydatek> wydatki;

    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem( "ExpenseId" );
        int expenseID = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "UserId" );
        int userID = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "Date" );
        string date = xml.GetData();
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
        cout << "ID wydatku: " << expenseID << " :)"<< endl;
        cout << "ID uzytkownika : " << userID << " :)"<< endl;
        system("pause");*/
        if (idZalogowanegoUzytkownika == userID)
        {
            wydatek.ustawIdWydatku(expenseID);
            wydatek.ustawIdUzytkownika(userID);
            wydatek.ustawDate(date);
            wydatek.ustawRodzajWydatku(item);
            wydatek.ustawIlosc(amount);
            //uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            wydatki.push_back(wydatek);
        }
        if (date == "" && item == "" && amount == "" && expenseID == 0)
        {
            idOstatniegoWydatku = 0;
        }
        else
        {
            idOstatniegoWydatku = expenseID;
        }
    }

    return wydatki;
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
int PlikZWydatkami::pobierzIdOstatniegoWydatku()
{
    return idOstatniegoWydatku;
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
        //cout << "Wchodzi w r�wnosc ID???????" << endl;
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

