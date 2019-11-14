#include "PlikZUzytkownikami.h"

void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
    CMarkup xml;
    //bool fileExists = xml.Load( "users.xml" );
    bool fileExists = xml.Load(pobierzNazwePliku());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();//wchodzi do glownego elementu
    xml.IntoElem();//wchodzi do srodka elementu
    xml.AddElem("User"); //dodanie elementu User
    xml.IntoElem(); //wejœcie do elementu User

    xml.AddElem("UserId", MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId()));
    xml.AddElem("Login", uzytkownik.pobierzLogin());
    xml.AddElem("Password", uzytkownik.pobierzHaslo());
    xml.AddElem("Name", uzytkownik.pobierzImie());
    xml.AddElem("Surname", uzytkownik.pobierzNazwisko());

    xml.Save(pobierzNazwePliku());
}


/*    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    //plikTekstowy.open(NAZWA_PLIKU_Z_UZYTKOWNIKAMI.c_str(), ios::app);pobierzNazwePliku()
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);
    if (plikTekstowy.good() == true)
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiUzytkownika;
            //plikTekstowy << liniaZDanymiUzytkownika << endl;//jest OK
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << pobierzNazwePliku() << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}

/*bool PlikZUzytkownikami::czyPlikJestPusty(fstream &plikTekstowy)
{
    //fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}*/

/*string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik)
{
    string liniaZDanymiUzytkownika = "";
    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId());//metoda statyczna
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin();
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo();

    return liniaZDanymiUzytkownika;
}*/

vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    CMarkup xml;
    //bool fileExists = xml.Load( "users.xml" );
    bool fileExists = xml.Load(pobierzNazwePliku());
    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;

    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        int userID = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "Login" );
        string login = xml.GetData();
        xml.FindElem( "Password" );
        string password = xml.GetData();
        xml.FindElem( "Name" );
        string name = xml.GetData();
        xml.FindElem( "Surname" );
        string surname= xml.GetData();
        xml.OutOfElem();

    /*cout << "ID: " << userID << " :)"<< endl;
    cout << "Login : " << login << " :)"<< endl;
    cout << "Haslo : " << password << " :)"<< endl;
    cout << "Imie : " << name << " :)"<< endl;
    cout << "Nazwisko : " << surname << " :)"<< endl;*/
    uzytkownik.ustawId(userID);
    uzytkownik.ustawLogin(login);
    uzytkownik.ustawHaslo(password);
    uzytkownik.ustawImie(name);
    uzytkownik.ustawNazwisko(surname);
    //uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    uzytkownicy.push_back(uzytkownik);
    }
    return uzytkownicy;
}
/*
Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    Uzytkownik uzytkownik;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                uzytkownik.ustawId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                uzytkownik.ustawLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                uzytkownik.ustawHaslo(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return uzytkownik;
}
*/
void PlikZUzytkownikami::zapiszPojedynczegoUzytkownikaDoPliku(Uzytkownik uzytkownik)
{
/*    cout << uzytkownik.pobierzId() << endl;
    cout << uzytkownik.pobierzLogin() << endl;
    cout << uzytkownik.pobierzHaslo() << endl;
    cout << uzytkownik.pobierzImie() << endl;
    cout << uzytkownik.pobierzNazwisko() << endl;
system("pause");*/

    CMarkup xml;
    bool fileExists = xml.Load(pobierzNazwePliku());
    xml.FindChildElem("User");
    xml.RemoveChildElem();

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();//wchodzi do glownego elementu
    xml.IntoElem();//wchodzi do srodka elementu
    xml.AddElem("User"); //dodanie elementu User
    xml.IntoElem(); //wejœcie do elementu User

    xml.AddElem("UserId", MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId()));
    xml.AddElem("Login", uzytkownik.pobierzLogin());
    xml.AddElem("Password", uzytkownik.pobierzHaslo());
    xml.AddElem("Name", uzytkownik.pobierzImie());
    xml.AddElem("Surname", uzytkownik.pobierzNazwisko());
    xml.Save(pobierzNazwePliku());
}

void PlikZUzytkownikami::zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy)
{
    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        zapiszPojedynczegoUzytkownikaDoPliku(*itr);
    }
}

