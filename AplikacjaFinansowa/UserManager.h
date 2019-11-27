#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"
#include "HelpingMethods.h"

using namespace std;

class UserManager
{
    //int idZalogowanegoUzytkownika;//tutaj NIE inicjalizujemy zmiennych
    int idLoggedUser;
    vector <User> users;
    FileWithUsers fileWithUsers;
    //PlikZUzytkownikami plikZUzytkownikami;

    User giveDataNewUser();//Uzytkownik podajDaneNowegoUzytkownika();
    int getIdNewUser();//int pobierzIdNowegoUzytkownika();
    bool isLogin(string login);//czyIstniejeLogin(string login);

public:
    /*UzytkownikMenadzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };*/
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers)
    {
        idLoggedUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void userRegistration();//rejestracjaUzytkownika();
    void userLogin();//logowanieUzytkownika();
    void changeOfPasswordOfLoggedInUser();//zmianaHaslaZalogowanegoUzytkownika();
    void logOutUser();//wylogowanieUzytkownika();
    bool isUserLoggedIn();//czyUzytkownikJestZalogowany();
    int getIdLoggedUser();//pobierzIdZalogowanegoUzytkownika();
};

#endif
