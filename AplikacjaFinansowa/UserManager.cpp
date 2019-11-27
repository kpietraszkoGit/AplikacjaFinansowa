#include "UserManager.h"

//4:00 - zmienic to

void UserManager::userRegistration()
{
    User user = giveDataNewUser();//podajDaneNowegoUzytkownika();

    users.push_back(user); //uzytkownicy.push_back(uzytkownik);
    fileWithUsers.addUserToFile(user);  //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    Sleep(2000);
    return;
}

User UserManager::giveDataNewUser() //Uzytkownik UzytkownikMenadzer::podajDaneNowegoUzytkownika()//nie musimy miec tutaj vektora uzytkownicy bo jest on juz u nas w klasie
{
    User user;//Uzytkownik uzytkownik;

    user.setId(getIdNewUser()); //uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login, name, surname;
    do
    {
        cout << "Podaj imie: ";
        cin >> name;
        user.setName(name);
        cout << "Podaj nazwisko: ";
        cin >> surname;
        user.setSurname(surname);
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login); //uzytkownik.ustawLogin(login);
    }
    while (isLogin(user.getLogin()) == true); //uzytkownik.pobierzLogin()) == true);//usuwamy tez tutaj wektor uzytkownicy

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password); //uzytkownik.ustawHaslo(haslo);

    return user;
}

int UserManager::getIdNewUser() // UzytkownikMenadzer::pobierzIdNowegoUzytkownika()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLogin(string login) //UzytkownikMenadzer::czyIstniejeLogin(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::userLogin() // UzytkownikMenadzer::logowanieUzytkownika()
{
    string login = "", password = "";
    int i = 0;

    cout << endl << "Podaj login: ";
    login = HelpingMethods::loadLine(); //MetodyPomocnicze::wczytajLinie();

    while (i < users.size())
    {
        if (users[i].getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = HelpingMethods::loadLine();

                if (users[i].getPassword() == password)
                {
                    idLoggedUser = users[i].getId(); //idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    Sleep(2000);
                    //system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        i++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

bool UserManager::isUserLoggedIn() // UzytkownikMenadzer::czyUzytkownikJestZalogowany()
{
    if(idLoggedUser > 0)
        return true;
    else
        return false;
}

int UserManager::getIdLoggedUser()
{
    return idLoggedUser;
}

void UserManager::logOutUser()
{
    idLoggedUser = 0;
}

void UserManager::changeOfPasswordOfLoggedInUser()
{
    if (idLoggedUser > 0)
    {
        string newPassword = "";
        cout << "Podaj nowe haslo: ";
        newPassword = HelpingMethods::loadLine();

        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            if (itr -> getId() == idLoggedUser)
            {
                itr -> setPassword(newPassword);
                cout << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
            }
        }
        fileWithUsers.saveAllUsersToFile(users);  //plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    }
    else
    {
        cout << "Aby zmienic haslo, nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

