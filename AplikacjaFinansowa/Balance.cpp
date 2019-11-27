#include "Balance.h"


void Balance::dateSortingIncome(Income income)
{
    sort(incomes.begin(), incomes.end(), sortByDateIncome());
    //cout << "wchodzi do sortowania?" << endl;
    //system("pause");
}

void Balance::viewBalanceFromThisMonth(vector <Income> incomes, vector <Expense> expenses)
{
    float quantityIncomes = 0;
    float sumIncome = 0;
    system("cls");
    //string dataBezZnaku;
    if (!incomes.empty())
    {
        cout << "    >>> PRZYCHODY Z BIEZACEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;

        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {

            //dataBezZnaku = MetodyDaty::resetSign(itr -> pobierzDate());
            //przychod.ustawDate(dataBezZnaku);
            //przychody.push_back(przychod);

            //if (itr -> pobierzIdUzytkownika() == imiePoszukiwanegoAdresata)
            //{
                //incomes=dateSorting(*itr);
                dateSortingIncome(*itr);
                //viewIncomes(*itr);
                //system("pause");
                //wyswietlPrzychod(*itr); //wyswietla wszystko
                quantityIncomes = currentMonthIncome(*itr);
                sumIncome = sumIncome + quantityIncomes;
            //}
        }
        cout << "Suma przychodow: " << sumIncome << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "Nie ma zadnych przychodow." << endl << endl;
    }
    ///////////////
    float quantityExpenses = 0;
    float sumExpense = 0;
    if (!expenses.empty())
    {
        cout << "    >>> WYDATKI Z BIEZACEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            //dataBezZnaku = MetodyDaty::resetSign(itr -> pobierzDate());
            //przychod.ustawDate(dataBezZnaku);
            //przychody.push_back(przychod);

            //if (itr -> pobierzIdUzytkownika() == imiePoszukiwanegoAdresata)
            //{
                dateSortingExpense(*itr);
                quantityExpenses = currentMonthExpense(*itr);
                sumExpense = sumExpense + quantityExpenses;
            //}
        }
        cout << "Suma wydatkow: " << sumExpense << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "Nie ma zadnych wydatkow." << endl << endl;
    }

    float difference = sumIncome - sumExpense;
    cout << "Roznica: " << difference << endl << endl;
    //string numberSt = "1009098.12";
    //cout << "liczba flat:" << HelpingMethods::conversionStringToFloat(numberSt) << endl;
    system("pause");
}

void Balance::dateSortingExpense(Expense expense)
{
    sort(expenses.begin(), expenses.end(), sortByDateExpense());
}

void Balance::viewIncomes(Income income)
{
    cout << "Id przychodu:                        " << income.getIncomeId() << endl;
    cout << "Data przychodu:                      " << income.getDate() << endl;
    cout << "Rodzaj przychodu:                    " << income.getNameOfIncome() << endl;
    cout << "Kwota:                               " << income.getQuantity() << endl;
    cout << endl;
}

void Balance::viewExpenses(Expense expense)
{
    cout << "Id wydatku:                          " << expense.getExpenseId() << endl;
    cout << "Data wydatku:                        " << expense.getDate() << endl;
    cout << "Rodzaj wydatku:                      " << expense.getNameOfExpense() << endl;
    cout << "Kwota:                               " << expense.getQuantity() << endl;
    cout << endl;
}

float Balance::currentMonthIncome(Income income)
{
    float incomeFloat = 0;
    int year = 0, month = 0, day = 0, currentDataInt = 0, dateOfBeginInt = 0;
    string dayStringNumber  = "", monthStringNumber = "", dayString = "", beginMonth = "", beginYear = "", dateOfBegin = "", currentData = "";
    string beginDay = "01";

    SYSTEMTIME st;
    GetSystemTime(&st);

    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;

    dayString = HelpingMethods::conversionIntToString(day);
    if (dayString.length() == 1)
    {
        dayStringNumber = "0"+dayString;
    }
    else dayStringNumber = dayString;

    beginMonth = HelpingMethods::conversionIntToString(month);
    if (beginMonth.length() == 1)
    {
        monthStringNumber = "0"+beginMonth;
    }
    else monthStringNumber = beginMonth;

    beginYear = HelpingMethods::conversionIntToString(year);
    dateOfBegin = beginYear+monthStringNumber+beginDay;

    currentData = beginYear+monthStringNumber+dayStringNumber;
    currentDataInt = HelpingMethods::conversionStringToInt(currentData);
    dateOfBeginInt = HelpingMethods::conversionStringToInt(dateOfBegin);
    if (income.getDateInt() >= dateOfBeginInt && income.getDateInt() <= currentDataInt)
    {
        viewIncomes(income);
        //IncomeInt = HelpingMethods::conversionStringToInt(income.getQuantity());//konwersja ze string na float
        incomeFloat = HelpingMethods::conversionStringToFloat(income.getQuantity());
        return incomeFloat;
    }
    else return 0;
}

float Balance::currentMonthExpense(Expense expense)
{
    float expenseFloat = 0;
    int year = 0, month = 0, day = 0, currentDataInt = 0, dateOfBeginInt = 0;
    string dayStringNumber  = "", monthStringNumber = "", dayString = "", beginMonth = "", beginYear = "", dateOfBegin = "", currentData = "";
    string beginDay = "01";

    SYSTEMTIME st;
    GetSystemTime(&st);

    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;

    dayString = HelpingMethods::conversionIntToString(day);
    if (dayString.length() == 1)
    {
        dayStringNumber = "0"+dayString;
    }
    else dayStringNumber = dayString;

    beginMonth = HelpingMethods::conversionIntToString(month);
    if (beginMonth.length() == 1)
    {
        monthStringNumber = "0"+beginMonth;
    }
    else monthStringNumber = beginMonth;

    beginYear = HelpingMethods::conversionIntToString(year);
    dateOfBegin = beginYear+monthStringNumber+beginDay;

    currentData = beginYear+monthStringNumber+dayStringNumber;
    currentDataInt = HelpingMethods::conversionStringToInt(currentData);
    dateOfBeginInt = HelpingMethods::conversionStringToInt(dateOfBegin);
    if (expense.getDateInt() >= dateOfBeginInt && expense.getDateInt() <= currentDataInt)
    {
        viewExpenses(expense);
        expenseFloat = HelpingMethods::conversionStringToFloat(expense.getQuantity());
        //ExpenseInt = HelpingMethods::conversionStringToInt(expense.getQuantity());//ma byc konwersja ze string na float
        return expenseFloat;
    }
    else return 0;
}

void Balance::viewBalanceFromLastMonth(vector <Income> incomes, vector <Expense> expenses)
{
    float quantityIncomes = 0;
    float sumIncome = 0;
    system("cls");
    //string dataBezZnaku;
    if (!incomes.empty())
    {
        cout << "    >>> PRZYCHODY Z POPRZEDNIEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;

        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {

            //dataBezZnaku = MetodyDaty::resetSign(itr -> pobierzDate());
            //przychod.ustawDate(dataBezZnaku);
            //przychody.push_back(przychod);

            //if (itr -> pobierzIdUzytkownika() == imiePoszukiwanegoAdresata)
            //{
                dateSortingIncome(*itr);
                //wyswietlPrzychod(*itr); //wyswietla wszystko
                quantityIncomes = lastMonthIncome(*itr);
                sumIncome = sumIncome + quantityIncomes;
            //}
        }
        cout << "Suma przychodow: " << sumIncome << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "Nie ma zadnych przychodow." << endl << endl;
    }
    ///////////////
    float quantityExpenses = 0;
    float sumExpense = 0;
    if (!expenses.empty())
    {
        cout << "    >>> WYDATKI Z POPRZEDNIEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            //dataBezZnaku = MetodyDaty::resetSign(itr -> pobierzDate());
            //przychod.ustawDate(dataBezZnaku);
            //przychody.push_back(przychod);

            //if (itr -> pobierzIdUzytkownika() == imiePoszukiwanegoAdresata)
            //{
                dateSortingExpense(*itr);
                quantityExpenses = lastMonthExpense(*itr);
                sumExpense = sumExpense + quantityExpenses;
            //}
        }
        cout << "Suma wydatkow: " << sumExpense << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "Nie ma zadnych wydatkow." << endl << endl;
    }

    float difference = sumIncome - sumExpense;
    cout << "Roznica: " << difference << endl << endl;
    system("pause");
}

float Balance::lastMonthIncome(Income income)
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    bool leapYear;
    float incomeFloat = 0;
    int year = 0, month = 0, day = 0, earlierMonth = 0, earlierYear = 0, days = 0, dateOfEndInt = 0, dateOfBeginInt = 0;
    string dayStringNumber  = "", monthStringNumber = "", dayString = "", beginMonth = "", beginYear = "", dateOfBegin = "", dateOfEnd = "";
    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;
    string beginDay = "01";

    if (month == 1)
    {
        earlierMonth = 12;
        earlierYear = year - 1;
    }
    else
    {
        earlierMonth = month - 1;
        earlierYear = year;
    }
    //cout << earlierMonth << "-" << earlierYear << endl;
    leapYear = Calendar::isLeapYear(earlierYear);
    days = Calendar::numberDaysPerMonth(earlierMonth, leapYear);
    //cout << days << endl;

    beginMonth = HelpingMethods::conversionIntToString(earlierMonth);
    if (beginMonth.length() == 1)
    {
        monthStringNumber = "0"+beginMonth;
    }
    else monthStringNumber = beginMonth;

    beginYear = HelpingMethods::conversionIntToString(earlierYear);
    dateOfBegin = beginYear+monthStringNumber+beginDay;
    dateOfBeginInt = HelpingMethods::conversionStringToInt(dateOfBegin);

    dayString = HelpingMethods::conversionIntToString(days);

    dateOfEnd = beginYear+beginMonth+dayString;
    dateOfEndInt = HelpingMethods::conversionStringToInt(dateOfEnd);

    if (income.getDateInt() >= dateOfBeginInt && income.getDateInt() <= dateOfEndInt)
    {
        viewIncomes(income);
        incomeFloat = HelpingMethods::conversionStringToFloat(income.getQuantity());//konwersja ze string na float
        return incomeFloat;
    }
    else return 0;
}

float Balance::lastMonthExpense(Expense expense)
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    bool leapYear;
    float expenseFloat = 0;
    int year = 0, month = 0, day = 0, earlierMonth = 0, earlierYear = 0, days = 0, dateOfEndInt = 0, dateOfBeginInt = 0;
    string dayStringNumber  = "", monthStringNumber = "", dayString = "", beginMonth = "", beginYear = "", dateOfBegin = "", dateOfEnd = "";
    year = st.wYear;
    month = st.wMonth;
    day = st.wDay;
    string beginDay = "01";

    if (month == 1)
    {
        earlierMonth = 12;
        earlierYear = year - 1;
    }
    else
    {
        earlierMonth = month - 1;
        earlierYear = year;
    }
    //cout << earlierMonth << "-" << earlierYear << endl;
    leapYear = Calendar::isLeapYear(earlierYear);
    days = Calendar::numberDaysPerMonth(earlierMonth, leapYear);
    //cout << days << endl;

    beginMonth = HelpingMethods::conversionIntToString(earlierMonth);
    if (beginMonth.length() == 1)
    {
        monthStringNumber = "0"+beginMonth;
    }
    else monthStringNumber = beginMonth;

    beginYear = HelpingMethods::conversionIntToString(earlierYear);
    dateOfBegin = beginYear+monthStringNumber+beginDay;
    dateOfBeginInt = HelpingMethods::conversionStringToInt(dateOfBegin);

    dayString = HelpingMethods::conversionIntToString(days);

    dateOfEnd = beginYear+beginMonth+dayString;
    dateOfEndInt = HelpingMethods::conversionStringToInt(dateOfEnd);

    if (expense.getDateInt() >= dateOfBeginInt && expense.getDateInt() <= dateOfEndInt)
    {
        viewExpenses(expense);
        expenseFloat = HelpingMethods::conversionStringToFloat(expense.getQuantity());//ma byc konwersja ze string na float
        return expenseFloat;
    }
    else return 0;
}

void Balance::viewBalanceFromOtherPeriodOfTime(vector <Income> incomes, vector <Expense> expenses)
{
    system("cls");
    float quantityIncomes = 0, quantityExpenses = 0;
    float sumIncome = 0, sumExpense = 0;
    int dataFromInt = 0, dataToInt = 0;
    string dataFirst = "", dataSecond = "", dataWithoutSign = "";

    cout << "Podaj date (w formacie rrrr-mm-dd) od kiedy ma byc pokazany przychod i wydatek: " << endl;
    //dataFromInt = MetodyDaty::writeDate();
    dataFirst = calendar.trueDateRange();
    dataWithoutSign = HelpingMethods::removeDashFromDate(dataFirst);
    dataFromInt = HelpingMethods::conversionStringToInt(dataWithoutSign);

    cout << "Podaj date (w formacie rrrr-mm-dd) do kiedy ma byc pokazany przychod i wydatek: " << endl;
    dataSecond = calendar.trueDateRange();
    dataWithoutSign = HelpingMethods::removeDashFromDate(dataSecond);
    dataToInt = HelpingMethods::conversionStringToInt(dataWithoutSign);

    system("cls");
    if (!incomes.empty())
    {
        cout << "   >>> PRZYCHODY Z WYBRANEGO OKRESU <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "WYBRANY OKRES OD " << dataFirst << " DO " << dataSecond << " !!!" << endl;
        cout << endl;
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
                dateSortingIncome(*itr);
                quantityIncomes = selectedPeriodIncome(*itr, dataFromInt, dataToInt);
                sumIncome = sumIncome + quantityIncomes;
        }
        cout << "Suma przychodow: " << sumIncome << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "Nie ma zadnych przychodow." << endl << endl;
    }
    if (!expenses.empty())
    {
        cout << "   >>> WYDATKI Z WYBRANEGO OKRESU <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "WYBRANY OKRES OD " << dataFirst << " DO " << dataSecond << " !!!" << endl;
        cout << endl;
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
                dateSortingExpense(*itr);
                quantityExpenses= selectedPeriodExpense(*itr, dataFromInt, dataToInt);
                sumExpense = sumExpense + quantityExpenses;
        }
        cout << "Suma wydatkow: " << sumExpense << endl;
        cout << endl;
    }
    else
    {
        cout << endl << "Nie ma zadnych wydatkow." << endl << endl;
    }
    float difference = sumIncome - sumExpense;
    cout << "Roznica: " << difference << endl << endl;
    system("pause");
}

float Balance::selectedPeriodIncome(Income income, int dataFromInt, int dataToInt)
{
    float incomeFloat = 0;

    if (income.getDateInt() >= dataFromInt && income.getDateInt() <= dataToInt)
    {
        viewIncomes(income);
        incomeFloat = HelpingMethods::conversionStringToFloat(income.getQuantity());
        return incomeFloat;
    }
    else return 0;
}

float Balance::selectedPeriodExpense(Expense expense, int dataFromInt, int dataToInt)
{
    float expenseFloat = 0;

    if (expense.getDateInt() >= dataFromInt && expense.getDateInt() <= dataToInt)
    {
        viewExpenses(expense);
        expenseFloat = HelpingMethods::conversionStringToFloat(expense.getQuantity());
        return expenseFloat;
    }
    else return 0;
}


