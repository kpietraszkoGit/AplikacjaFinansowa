#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;
    //bool fileExists = xml.Load( "users.xml" );
    bool fileExists = xml.Load(getFileName());//(pobierzNazwePliku());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();//wchodzi do glownego elementu
    xml.IntoElem();//wchodzi do srodka elementu
    xml.AddElem("User"); //dodanie elementu User
    xml.IntoElem(); //wejœcie do elementu User

    xml.AddElem("UserId", HelpingMethods::conversionIntToString(user.getId()));
    xml.AddElem("Login", user.getLogin());//uzytkownik.pobierzLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());

    xml.Save(getFileName());
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    CMarkup xml;
    //bool fileExists = xml.Load( "users.xml" );
    bool fileExists = xml.Load(getFileName());
    User user;
    vector <User> users;

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
    user.setId(userID); //uzytkownik.ustawId(userID);
    user.setLogin(login);
    user.setPassword(password);
    user.setName(name);
    user.setSurname(surname);
    //uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
    users.push_back(user); //uzytkownicy.push_back(uzytkownik);
    }
    return users;
}

void FileWithUsers::saveSingleUserToFile(User user)
{
/*    cout << uzytkownik.pobierzId() << endl;
    cout << uzytkownik.pobierzLogin() << endl;
    cout << uzytkownik.pobierzHaslo() << endl;
    cout << uzytkownik.pobierzImie() << endl;
    cout << uzytkownik.pobierzNazwisko() << endl;
system("pause");*/

    CMarkup xml;
    bool fileExists = xml.Load(getFileName());
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

    xml.AddElem("UserId", HelpingMethods::conversionIntToString(user.getId()));
    xml.AddElem("Login", user.getLogin());//uzytkownik.pobierzLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.Save(getFileName());
}

void FileWithUsers::saveAllUsersToFile(vector <User> users)
{
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        saveSingleUserToFile(*itr);
    }
}

