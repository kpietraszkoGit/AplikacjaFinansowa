#ifndef INCOME_H // zabezpieczenie przed podwójnym includowaniem uzytkownik.h
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
//wszystkie one sa prywatne zahermetyzowane
    int incomeId;
    int userId;//idUzytkownika;
    int dateInt;//dataInt
    string date;
    string nameOfIncome;//rodzajPrzychodu;
    string quantity;//ilosc;


public:
    Income(int incomeId = 0, int userId = 0, int dateInt = 0, string date = "", string nameOfIncome = "", string quantity = "")
    {
        this->incomeId = incomeId;//idPrzychodu = idPrzychodu;
        this->userId = userId;
        this->dateInt = dateInt;
        this->date = date;
        this->nameOfIncome = nameOfIncome;
        this->quantity = quantity;
    }
    void setIncomeId(int newIncomeId);//settery aby udostepnic innym klasa, tu publiczenie s¹ metody, które zabezpieczamy w pliku .cpp
    void setUserId(int newUserId);//ustawIdUzytkownika(int noweIdUzytkownika);
    void setDateInt(int newDateInt);
    void setDate(string newDate);
    void setNameOfIncome(string newNameOfIncome);
    void setQuantity(string newQuantity);

    int getIncomeId();//gettery
    int getUserId();
    int getDateInt();
    string getDate();
    string getNameOfIncome();//pobierz typ przychodu
    string getQuantity();//pobierz ilosc

    //income.setNumberOfRecord(fileWithIncomes.getIdLastIncomeFromFile()+1);
    //income.setUserId(ID_LOGGED_USER);

};

#endif
