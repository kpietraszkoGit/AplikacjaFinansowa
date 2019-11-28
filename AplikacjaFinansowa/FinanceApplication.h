#ifndef FINANCEAPPLICATION_H
#define FINANCEAPPLICATION_H

#include <iostream>

#include "UserManager.h"
#include "FinanceManager.h"
#include "HelpingMethods.h"

using namespace std;

class FinanceApplication
{
    UserManager userManager;
    FinanceManager *financeManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
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
    void addIncome();
    void addExpense();
    void changeOfPasswordOfLoggedInUser();
    void logOutUser();
    void userRegistration();
    void userLogin();

    void balanceFromThisMonth();
    void balanceFromLastMonth();
    void balanceFromOtherPeriodOfTime();

    bool isUserLoggedIn();
    char selectOptionsFromUserMenu();
    char selectOptionsFromMainMenu();
};

#endif
