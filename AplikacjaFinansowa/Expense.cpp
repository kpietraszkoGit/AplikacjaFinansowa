#include "Expense.h"

void Expense::setExpenseId(int newExpenseId)
{
    if (newExpenseId >= 0)
    expenseId = newExpenseId;
}
void Expense::setUserId(int newUserId)
{
    if (newUserId >= 0)
    userId = newUserId;
}
void Expense::setDateInt(int newDateInt)
{
    if (newDateInt >= 0)
    dateInt = newDateInt;
}
void Expense::setDate(string newDate)
{
    date = newDate;
}
void Expense::setNameOfExpense(string newNameOfExpense)
{
    nameOfExpense = newNameOfExpense;
}
void Expense::setQuantity(string newQuantity)
{
    quantity = newQuantity;
}


int Expense::getExpenseId()
{
    return expenseId;
}
int Expense::getUserId()
{
    return userId;
}
int Expense::getDateInt()
{
    return dateInt;
}
string Expense::getDate()
{
    return date;
}
string Expense::getNameOfExpense()
{
    return nameOfExpense;
}
string Expense::getQuantity()
{
    return quantity;
}
