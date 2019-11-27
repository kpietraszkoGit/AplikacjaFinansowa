#include "FinanceApplication.h"

/*void AplikacjaFinansowa::rejestracjaUzytkownika()
{
    uzytkownikMenadzer.rejestracjaUzytkownika();
}*/
void FinanceApplication::userRegistration()
{
    userManager.userRegistration();
}

char FinanceApplication::selectOptionsFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = HelpingMethods::loadSign();

    return choice;
}

char FinanceApplication::selectOptionsFromUserMenu()
{
    char choice;

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
    choice = HelpingMethods::loadSign();

    return choice;
}

void FinanceApplication::userLogin()
{
    //uzytkownikMenadzer.logowanieUzytkownika();
    userManager.userLogin();
    if (userManager.isUserLoggedIn())
    {
        financeManager = new FinanceManager(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES, userManager.getIdLoggedUser());
    }

    /*if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())
    {
        przychodMenadzer = new PrzychodMenadzer(NAZWA_PLIKU_Z_PRZYCHODAMI, uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
        wydatekMenadzer = new WydatekMenadzer(NAZWA_PLIKU_Z_WYDATKAMI, uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
    //wstrzykiwanie zaleznosci miedzy klasami,przesy³anie danych
    }*/
}

void FinanceApplication::addIncome()
{
    if (userManager.isUserLoggedIn())
    {
        financeManager->addIncome();
    }
    else
    {
        cout << "Aby dodac przychod nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
    /*if (uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        przychodMenadzer->dodajPrzychod(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
    }
    else
    {
        cout << "Aby dodac przychod nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }*/
}

void FinanceApplication::addExpense()//dodaj wydatek
{
    if (userManager.isUserLoggedIn())
    {
        financeManager->addExpense();
    }
    else
    {
        cout << "Aby dodac przychod nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void FinanceApplication::balanceFromThisMonth()//balanceOfMonth()
{
    if (userManager.isUserLoggedIn())
    {
        financeManager->viewBalanceFromThisMonth();
    }
    else
    {
        cout << "Aby wyswietlic przychody i wydatki nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
/*    if(uzytkownikMenadzer.czyUzytkownikJestZalogowany())//kropka do obiektow
    {
        przychodMenadzer->wyswietlPrzychodyZBiezacegoMiesiaca(); // tutaj pracowalismy na wskazniku dlatego uzywamy strzalki
        wydatekMenadzer->wyswietlWydatkiZBiezacegoMiesiaca();
    }
    else
    {
        cout << "Aby wyswietlic przychody i wydatki nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }*/
}

void FinanceApplication::balanceFromLastMonth()//balanceOfPreviousMonth()
{
    if (userManager.isUserLoggedIn())
    {
        financeManager->viewBalanceFromLastMonth();
    }
    else
    {
        cout << "Aby wyswietlic przychody i wydatki nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void FinanceApplication::balanceFromOtherPeriodOfTime()//balanceFromSelectedPeriod()
{
    if (userManager.isUserLoggedIn())
    {
        financeManager->viewBalanceFromOtherPeriodOfTime();
    }
    else
    {
        cout << "Aby wyswietlic przychody i wydatki nalezy najpierw sie zalogowac!" << endl;
        system("pause");
    }
}

void FinanceApplication::logOutUser()//wylogowanieUzytkownika()
{
    userManager.logOutUser();
    //uzytkownikMenadzer.wylogowanieUzytkownika();
    delete financeManager;
    financeManager = NULL;
}

void FinanceApplication::changeOfPasswordOfLoggedInUser()//zmianaHaslaZalogowanegoUzytkownika()
{
    //uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
    userManager.changeOfPasswordOfLoggedInUser();
}

bool FinanceApplication::isUserLoggedIn()
{
    //return uzytkownikMenadzer.czyUzytkownikJestZalogowany();
    return userManager.isUserLoggedIn();
}
