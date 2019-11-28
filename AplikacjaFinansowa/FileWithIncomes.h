#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Income.h"
#include "HelpingMethods.h"
#include "FileXml.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes: public FileXml
{
    int idLastIncome;

public:
    FileWithIncomes(string fileName) : FileXml(fileName)
    {
        idLastIncome = 0;
    };
    bool addIncomeToFile(Income income);
    vector <Income> loadIncomesLoggedUserFromFile(int idLoggedUser);
    int getIdLastIncome();
};

#endif
