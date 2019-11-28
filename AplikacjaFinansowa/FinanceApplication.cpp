#include "FinanceApplication.h"

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
    userManager.userLogin();
    if (userManager.isUserLoggedIn())
    {
        financeManager = new FinanceManager(NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES, userManager.getIdLoggedUser());
    }
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
}

void FinanceApplication::addExpense()
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

void FinanceApplication::balanceFromThisMonth()
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
}

void FinanceApplication::balanceFromLastMonth()
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

void FinanceApplication::balanceFromOtherPeriodOfTime()
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

void FinanceApplication::logOutUser()
{
    userManager.logOutUser();
    delete financeManager;
    financeManager = NULL;
}

void FinanceApplication::changeOfPasswordOfLoggedInUser()
{
    userManager.changeOfPasswordOfLoggedInUser();
}

bool FinanceApplication::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}
