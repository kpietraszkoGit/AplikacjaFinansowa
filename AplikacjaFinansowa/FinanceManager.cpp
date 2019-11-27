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
    float amount;
    char choice;
    //income.setNumberOfRecord(fileWithIncomes.getIdLastIncomeFromFile()+1);//przychod.ustawIdPrzychodu((plikZPrzychodami.pobierzIdOstatniegoPrzychodu()+1));
    //income.setUserId(ID_LOGGED_USER);

    income.setIncomeId(fileWithIncomes.getIdLastIncome()+1);
    income.setUserId(ID_LOGGED_USER);
    /*przychod.ustawIdPrzychodu((plikZPrzychodami.pobierzIdOstatniegoPrzychodu()+1));
    przychod.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    przychod.ustawDateInt(dateWithoutSignInt);
    przychod.ustawDate(data);
    przychod.ustawRodzajPrzychodu(rodzajPrzychodu);
    przychod.ustawIlosc(ilosc);//zamiana przcinka na kropke napisac funkcje*/

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
        /*do
        {
            differentDate = HelpingMethods::loadLine();
        }
        while (calendar.isDateGood(differentDate) == false);*/
        differentDate = calendar.trueDateRange();
        stringDateWithoutDash = HelpingMethods::removeDashFromDate(differentDate);
        intDateWithoutDash = HelpingMethods::conversionStringToInt(stringDateWithoutDash);

        income.setDate(differentDate);
        income.setDateInt(intDateWithoutDash);
    }
    cout << endl << "Wpisz kategorie, ktorej dotyczyl przychod (np. wynagrodzenie, sprzedaz): ";
    //category = HelpingMethods::loadLine();
    cin >> category;
    income.setNameOfIncome(category);
    cout << endl << "Wpisz kwote przychodu: ";
    //amountForChecking = HelpingMethods::loadLine();
    cin >> amountForChecking;
    amountForChecking = HelpingMethods::conversionCommaToDot(amountForChecking);
    amount = HelpingMethods::conversionStringToFloat(amountForChecking);
//    income.setQuantity(amount);//setQuantity
    income.setQuantity(amountForChecking);

    return income;
}

void FinanceManager::addExpense()
{
    Expense expense;
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
    float amount;
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
        /*do
        {
            differentDate = AdditionalMethods::loadLine();
            if (!calendar.isDateGood(differentDate))
                cout << "Zly format daty. Podaj date jeszcze raz: ";
        }
        while (!calendar.isDateGood(differentDate));*/
        differentDate = calendar.trueDateRange();
        stringDateWithoutDash = HelpingMethods::removeDashFromDate(differentDate);
        intDateWithoutDash = HelpingMethods::conversionStringToInt(stringDateWithoutDash);

        expense.setDate(differentDate);
        expense.setDateInt(intDateWithoutDash);
    }
    cout << endl << "Wpisz kategorie, ktorej dotyczyl wydatek (np. czynsz, jedzenie): ";
    //category = AdditionalMethods::loadLine();
    cin >> category;
    expense.setNameOfExpense(category);
    cout << endl << "Wpisz kwote wydatku: ";
    cin >> amountForChecking;
    amountForChecking = HelpingMethods::conversionCommaToDot(amountForChecking);
    amount = HelpingMethods::conversionStringToFloat(amountForChecking);
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
    //system("pause");
}

void FinanceManager::viewBalanceFromOtherPeriodOfTime()
{
    balance.viewBalanceFromOtherPeriodOfTime(incomes, expenses);
    //system("pause");
}
