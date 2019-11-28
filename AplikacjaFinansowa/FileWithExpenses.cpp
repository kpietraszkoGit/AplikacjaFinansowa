#include "FileWithExpenses.h"

bool FileWithExpenses::addExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();//wchodzi do glownego elementu
    xml.IntoElem();//wchodzi do srodka elementu
    xml.AddElem("Expense"); //dodanie elementu wydatek
    xml.IntoElem(); //wejœcie do elementu User

    xml.AddElem("ExpenseId", HelpingMethods::conversionIntToString(expense.getExpenseId()));
    xml.AddElem("UserId",  HelpingMethods::conversionIntToString(expense.getUserId()));
    //xml.AddElem("DateInt", HelpingMethods::conversionIntToString(expense.getDateInt()));
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getNameOfExpense());
    xml.AddElem("Amount", expense.getQuantity());

    xml.Save(getFileName());

    idLastExpense++;

    return true;
}

vector <Expense> FileWithExpenses::loadExpensesLoggedUserFromFile(int idLoggedUser)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());
    Expense expense;
    vector <Expense> expenses;

    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem( "ExpenseId" );
        int expenseID = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "UserId" );
        int userID = atoi( MCD_2PCSZ(xml.GetData()) );
       // xml.FindElem( "DateInt" );
        //int dateInt = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "Date" );
        string date = xml.GetData();
        xml.FindElem( "Item" );
        string item = xml.GetData();
        xml.FindElem( "Amount" );
        string amount = xml.GetData();
        xml.OutOfElem();

        string dateWithoutDash = HelpingMethods::removeDashFromDate(date);
        int dateInt = HelpingMethods::conversionStringToInt(dateWithoutDash);

        if (idLoggedUser == userID)
        {
            expense.setExpenseId(expenseID);
            expense.setUserId(userID);
            expense.setDateInt(dateInt);
            expense.setDate(date);
            expense.setNameOfExpense(item);
            expense.setQuantity(amount);
            expenses.push_back(expense);
        }
        if (date == "" && item == "" && amount == "" && expenseID == 0)
        {
            idLastExpense = 0;
        }
        else
        {
            idLastExpense = expenseID;
        }
    }

    return expenses;
}

int FileWithExpenses::getIdLastExpense()
{
    return idLastExpense;
}


