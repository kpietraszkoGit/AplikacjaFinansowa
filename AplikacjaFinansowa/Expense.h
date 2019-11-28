#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{

    int expenseId;
    int userId;
    int dateInt;
    string date;
    string nameOfExpense;
    string quantity;


public:
    Expense(int expenseId = 0, int userId = 0, int dateInt = 0, string date = "", string nameOfExpense = "", string quantity = "")
    {
        this->expenseId = expenseId;
        this->userId = userId;
        this->dateInt = dateInt;
        this->date = date;
        this->nameOfExpense = nameOfExpense;
        this->quantity = quantity;
    }
    void setExpenseId(int newExpenseId);
    void setUserId(int newUserId);
    void setDateInt(int newDateInt);
    void setDate(string newDate);
    void setNameOfExpense(string newNameOfExpense);
    void setQuantity(string newQuantity);

    int getExpenseId();//gettery
    int getUserId();
    int getDateInt();
    string getDate();
    string getNameOfExpense();
    string getQuantity();
};

#endif
