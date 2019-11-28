#include "FinanceManager.h"

void FinanceManager::addIncome()
{
    Income income;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = getInfoAboutNewIncome();
    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);

    cout << endl << "Dodano nowy przychod!" << endl;
    system("pause");
}

Income FinanceManager::getInfoAboutNewIncome()
{
    Income income;
    string differentDate, category, amountForChecking, stringDateWithoutDash, stringCurrentDateWithoutDash;
    string currentDate;
    int intCurrentDateWithoutDash, intDateWithoutDash;
    char choice;

    income.setIncomeId(fileWithIncomes.getIdLastIncome()+1);
    income.setUserId(ID_LOGGED_USER);


    cout << "Czy chcesz dodac przychod z dzisiejsza data?" << endl;
    cout << "Jesli tak wcisnij 't'. Jesli chcesz wybrac inna date wcisnij 'n': ";
    choice = HelpingMethods::loadSign();
    if(choice == 't')
    {
        currentDate = calendar.getCurrentDate();
        income.setDate(currentDate);
        stringCurrentDateWithoutDash = HelpingMethods::removeDashFromDate(currentDate);
        intCurrentDateWithoutDash = HelpingMethods::conversionStringToInt(stringCurrentDateWithoutDash);
        income.setDateInt(intCurrentDateWithoutDash);
    }
    else
    {
        cout << "Podaj date w postaci rrrr-mm-dd! ";

        differentDate = calendar.trueDateRange();
        stringDateWithoutDash = HelpingMethods::removeDashFromDate(differentDate);
        intDateWithoutDash = HelpingMethods::conversionStringToInt(stringDateWithoutDash);

        income.setDate(differentDate);
        income.setDateInt(intDateWithoutDash);
    }
    cout << endl << "Wpisz kategorie, ktorej dotyczyl przychod (np. wynagrodzenie, sprzedaz): ";
    cin >> category;
    income.setNameOfIncome(category);
    cout << endl << "Wpisz kwote przychodu: ";


            /*float amountForCheckingFloat;
            bool good, bad;
            while(true)
            {
                cin >> amountForCheckingFloat;
                good = cin.good();
                bad = cin.bad();
                cin.clear();
                cin.sync();
                if (( good == 0 ) ||( bad == 1 ))
                {
                    cout << "Wpisana liczba jest niepoprawna, wpisz jeszcze raz: ";
                }
                else
                {
                    std::ostringstream ss;
                    ss << amountForCheckingFloat;
                    std::string s(ss.str());
                    cout << "Liczba float w stringu: " << s << endl;
                    system("pause");
                    break;
                }
            }*/

    cin >> amountForChecking;//dobrze string


    amountForChecking = HelpingMethods::conversionCommaToDot(amountForChecking);
    //amount = HelpingMethods::conversionStringToFloat(amountForChecking);
    income.setQuantity(amountForChecking);//dobrze string

    return income;
}

void FinanceManager::addExpense()
{
    Expense expense;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = getInfoAboutNewExpense();
    expenses.push_back(expense);

    fileWithExpenes.addExpenseToFile(expense);

    cout << endl << "Dodano nowy wydatek!" << endl;
    system("pause");
}

Expense FinanceManager::getInfoAboutNewExpense()
{
    Expense expense;
    string differentDate, category, amountForChecking, stringDateWithoutDash, stringCurrentDateWithoutDash;
    string currentDate;
    int intCurrentDateWithoutDash, intDateWithoutDash;
    char choice;

    expense.setExpenseId(fileWithExpenes.getIdLastExpense()+1);
    expense.setUserId(ID_LOGGED_USER);


    cout << "Czy chcesz dodac wydatek z dzisiejsza data?" << endl;
    cout << "Jesli tak wcisnij 't'. Jesli chcesz wybrac inna date wcisnij 'n': ";
    choice = HelpingMethods::loadSign();
    if(choice == 't')
    {
        currentDate = calendar.getCurrentDate();
        expense.setDate(currentDate);
        stringCurrentDateWithoutDash = HelpingMethods::removeDashFromDate(currentDate);
        intCurrentDateWithoutDash = HelpingMethods::conversionStringToInt(stringCurrentDateWithoutDash);
        expense.setDateInt(intCurrentDateWithoutDash);
    }
    else
    {
        cout << "Podaj date w postaci rrrr-mm-dd! ";

        differentDate = calendar.trueDateRange();
        stringDateWithoutDash = HelpingMethods::removeDashFromDate(differentDate);
        intDateWithoutDash = HelpingMethods::conversionStringToInt(stringDateWithoutDash);

        expense.setDate(differentDate);
        expense.setDateInt(intDateWithoutDash);
    }
    cout << endl << "Wpisz kategorie, ktorej dotyczyl wydatek (np. czynsz, jedzenie): ";
    cin >> category;
    expense.setNameOfExpense(category);
    cout << endl << "Wpisz kwote wydatku: ";
    cin >> amountForChecking;
    amountForChecking = HelpingMethods::conversionCommaToDot(amountForChecking);
    //amount = HelpingMethods::conversionStringToFloat(amountForChecking);
    expense.setQuantity(amountForChecking);

    return expense;
}

void FinanceManager::viewBalanceFromThisMonth()
{
    balance.viewBalanceFromThisMonth(incomes, expenses);
}

void FinanceManager::viewBalanceFromLastMonth()
{
    balance.viewBalanceFromLastMonth(incomes, expenses);
}

void FinanceManager::viewBalanceFromOtherPeriodOfTime()
{
    balance.viewBalanceFromOtherPeriodOfTime(incomes, expenses);
}
