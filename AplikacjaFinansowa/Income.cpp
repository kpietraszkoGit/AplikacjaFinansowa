#include "Income.h"

void Income::setIncomeId(int newIncomeId)
{
    if (newIncomeId >= 0)
    incomeId = newIncomeId;
}
void Income::setUserId(int newUserId)
{
    if (newUserId >= 0)
    userId = newUserId;
}
void Income::setDateInt(int newDateInt)
{
    if (newDateInt >= 0)
    dateInt = newDateInt;
}
void Income::setDate(string newDate)
{
    date = newDate;
}
void Income::setNameOfIncome(string newNameOfIncome)
{
    nameOfIncome = newNameOfIncome;
}
void Income::setQuantity(string newQuantity)
{
    quantity = newQuantity;
}


int Income::getIncomeId()
{
    return incomeId;
}
int Income::getUserId()
{
    return userId;
}
int Income::getDateInt()
{
    return dateInt;
}
string Income::getDate()
{
    return date;
}
string Income::getNameOfIncome()
{
    return nameOfIncome;
}
string Income::getQuantity()
{
    return quantity;
}
