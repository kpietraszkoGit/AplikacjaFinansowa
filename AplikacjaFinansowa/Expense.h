#ifndef EXPENSE_H // zabezpieczenie przed podwójnym includowaniem uzytkownik.h
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
//wszystkie one sa prywatne zahermetyzowane
    int expenseId;
    int userId;//idUzytkownika;
    int dateInt;//dataInt
    string date;
    string nameOfExpense;//rodzajPrzychodu;
    string quantity;//ilosc;


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
    void setExpenseId(int newExpenseId);//settery aby udostepnic innym klasa, tu publiczenie s¹ metody, które zabezpieczamy w pliku .cpp
    void setUserId(int newUserId);//ustawIdUzytkownika(int noweIdUzytkownika);
    void setDateInt(int newDateInt);
    void setDate(string newDate);
    void setNameOfExpense(string newNameOfExpense);
    void setQuantity(string newQuantity);

    int getExpenseId();//gettery
    int getUserId();
    int getDateInt();
    string getDate();
    string getNameOfExpense();//pobierz typ przychodu
    string getQuantity();//pobierz ilosc
};

#endif
