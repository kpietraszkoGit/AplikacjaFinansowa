#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>
#include <vector>

#include <windows.h>
#include <sstream>

#include "Income.h"
#include "Expense.h"
#include "HelpingMethods.h"
#include "Calendar.h"


using namespace std;

class Balance
{
    struct sortByDateIncome
    {
        inline bool operator() (Income& firstDate, Income& secondDate)
        {
            return (firstDate.getDateInt() < secondDate.getDateInt());
        }
    };

    struct sortByDateExpense
    {
        inline bool operator() (Expense& firstDate, Expense& secondDate)
        {
            return (firstDate.getDateInt() < secondDate.getDateInt());
        }
    };
    vector <Income> incomes;
    vector <Expense> expenses;
    Calendar calendar;
    Income income;

public:

    float currentMonthIncome(Income income);
    float currentMonthExpense(Expense expense);
    void dateSortingIncome(Income income);
    void dateSortingExpense(Expense expense);
    void viewIncomes(Income income);
    void viewExpenses(Expense expense);
    float lastMonthIncome(Income income);
    float lastMonthExpense(Expense expense);
    void viewBalanceFromThisMonth(vector <Income> incomes, vector <Expense> expenses);
    void viewBalanceFromLastMonth(vector <Income> incomes, vector <Expense> expenses);
    void viewBalanceFromOtherPeriodOfTime(vector <Income> incomes, vector <Expense> expenses);
    float selectedPeriodIncome(Income income, int dataFromInt, int dataToInt);
    float selectedPeriodExpense(Expense expense, int dataFromInt, int dataToInt);
};

#endif
