#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "FileWithIncomes.h"
#include "Expense.h"
#include "FileWithExpenses.h"
#include "HelpingMethods.h"
#include "Calendar.h"
#include "Balance.h"

#include <windows.h>

using namespace std;

class FinanceManager
{
    const int ID_LOGGED_USER;
    vector <Income> incomes;
    vector <Expense> expenses;
    Calendar calendar;
    Balance balance;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenes;

    Income getInfoAboutNewIncome();
    Expense getInfoAboutNewExpense();
public:
    FinanceManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int idLoggedUser) :
        fileWithIncomes(nameOfFileWithIncomes), fileWithExpenes(nameOfFileWithExpenses), ID_LOGGED_USER(idLoggedUser) {
        incomes = fileWithIncomes.loadIncomesLoggedUserFromFile(ID_LOGGED_USER);
        expenses = fileWithExpenes.loadExpensesLoggedUserFromFile(ID_LOGGED_USER);
        }
    void addIncome();
    void addExpense();
    void viewBalanceFromThisMonth();
    void viewBalanceFromLastMonth();
    void viewBalanceFromOtherPeriodOfTime();
};

#endif
