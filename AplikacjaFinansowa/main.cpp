#include <iostream>
#include "FinanceApplication.h"

using namespace std;

int main()
{
    vector<Income> incomes;
    vector<Expense> expenses;

    FinanceApplication financeApplication("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while (true)
    {
        if (financeApplication.isUserLoggedIn())
        {
            choice = financeApplication.selectOptionsFromUserMenu();

            switch (choice)
            {
            case '1':
                financeApplication.addIncome();
                break;
            case '2':
                financeApplication.addExpense();
                break;
            case '3':
                financeApplication.balanceFromThisMonth();
                break;
            case '4':
                financeApplication.balanceFromLastMonth();
                break;
            case '5':
                financeApplication.balanceFromOtherPeriodOfTime();
                break;
            case '6':
                financeApplication.changeOfPasswordOfLoggedInUser();
                break;
            case '7':
                financeApplication.logOutUser();
                incomes.clear();
                expenses.clear();
                break;
            }
        }
        else
        {
            choice = financeApplication.selectOptionsFromMainMenu();

            switch (choice)
            {
            case '1':
                financeApplication.userRegistration();
                break;
            case '2':
                financeApplication.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}

