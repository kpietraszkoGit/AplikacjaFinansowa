#ifndef FINANCEAPPLICATION_H
#define FINANCEAPPLICATION_H

#include <iostream>

#include "UserManager.h"
#include "FinanceManager.h"
#include "HelpingMethods.h"

//#include "PrzychodMenadzer.h"
//#include "MetodyPomocnicze.h"
//#include "WydatekMenadzer.h"

using namespace std;

class FinanceApplication
{
    //UzytkownikMenadzer uzytkownikMenadzer; //obiekt//12:00
    UserManager userManager;
    //PrzychodMenadzer *przychodMenadzer;
    //WydatekMenadzer *wydatekMenadzer;
    FinanceManager *financeManager;
    const string NAME_OF_FILE_WITH_INCOMES;//NAZWA_PLIKU_Z_PRZYCHODAMI;
// string nameOfFileWithIncomes,, nameOfFileWithExpenses
    const string NAME_OF_FILE_WITH_EXPENSES;//NAZWA_PLIKU_Z_WYDATKAMI;

public:

    /*AplikacjaFinansowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZPrzychodami, string nazwaPlikuZWydatkami)
        : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_PRZYCHODAMI(nazwaPlikuZPrzychodami), NAZWA_PLIKU_Z_WYDATKAMI(nazwaPlikuZWydatkami)
    {
        //adresatMenadzer = NULL;// jak sie pracuje na wskaźnikach trzeba przypisać NULL i stworzyć destruktor
        przychodMenadzer = NULL;
        wydatekMenadzer = NULL;
    };
    ~AplikacjaFinansowa()
    {
        delete przychodMenadzer;
        przychodMenadzer = NULL;
        delete wydatekMenadzer;
        wydatekMenadzer = NULL;
    };*/
    FinanceApplication(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
        : userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes), NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)
    {
        financeManager = NULL;
    };
    ~FinanceApplication()
    {
        delete financeManager;
        financeManager = NULL;
    };

    //void rejestracjaUzytkownika();// wywolam odpowiednia metode z UzytkownikMenadzer
    //void logowanieUzytkownika();
    //void zmianaHaslaZalogowanegoUzytkownika();
    //void wylogowanieUzytkownika();
    //void dodajPrzychod();
    //void dodajWydatek();
    //void balanceOfMonth();
    //void balanceOfPreviousMonth();
    //void balanceFromSelectedPeriod();

    void addIncome();
    void addExpense();
    void changeOfPasswordOfLoggedInUser();
    void logOutUser();
    void userRegistration();
    void userLogin();

    void balanceFromThisMonth();
    void balanceFromLastMonth();
    void balanceFromOtherPeriodOfTime();


    bool isUserLoggedIn();//czyUzytkownikJestZalogowany();
    char selectOptionsFromUserMenu();//wybierzOpcjeZMenuUzytkownika();
    char selectOptionsFromMainMenu();
};

#endif
