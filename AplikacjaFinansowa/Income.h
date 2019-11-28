#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    int dateInt;
    string date;
    string nameOfIncome;
    string quantity;


public:
    Income(int incomeId = 0, int userId = 0, int dateInt = 0, string date = "", string nameOfIncome = "", string quantity = "")
    {
        this->incomeId = incomeId;
        this->userId = userId;
        this->dateInt = dateInt;
        this->date = date;
        this->nameOfIncome = nameOfIncome;
        this->quantity = quantity;
    }
    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDateInt(int newDateInt);
    void setDate(string newDate);
    void setNameOfIncome(string newNameOfIncome);
    void setQuantity(string newQuantity);

    int getIncomeId();//gettery
    int getUserId();
    int getDateInt();
    string getDate();
    string getNameOfIncome();
    string getQuantity();
};

#endif
