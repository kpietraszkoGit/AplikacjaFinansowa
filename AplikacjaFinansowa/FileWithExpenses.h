#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Expense.h"
#include "HelpingMethods.h"
#include "FileXml.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses: public FileXml
{

    int idLastExpense;

public:
    FileWithExpenses(string fileName) : FileXml(fileName)
    {
        idLastExpense = 0;
    };
    bool addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesLoggedUserFromFile(int idLoggedUser);
    int getIdLastExpense();
};

#endif
