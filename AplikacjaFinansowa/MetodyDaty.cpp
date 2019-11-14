#include "MetodyDaty.h"

string MetodyDaty::downloadSystemTime()
{
    int year = 0, month = 0, day = 0;
    string todayDate  = "", monthStringNumber  = "", monthString  = "", dayString  = "", dayStringNumber  = "";

    SYSTEMTIME st;
    GetSystemTime(&st);
    //cout << "Biezacy rok to " << st.wYear << endl;
    //cout << "Biezacy miesiac to " << st.wMonth << endl;
    //cout << "Biezacy dzien  to " << st.wDay << endl;
    //cout << "Data dzisiejszego dnia to: " << st.wYear << "-" << st.wMonth << "-" << st.wDay  << endl;
    year = st.wYear;
    month = st.wMonth;
    monthString = MetodyPomocnicze::konwerjsaIntNaString(month);
    if (monthString.length() == 1)
    {
        monthStringNumber = "0"+monthString;
    }
    else monthStringNumber = monthString;
    //out << "miesiac: " << monthStringNumber << endl;

    day = st.wDay;
    dayString = MetodyPomocnicze::konwerjsaIntNaString(day);
    if (dayString.length() == 1)
    {
        dayStringNumber = "0"+dayString;
    }
    else dayStringNumber = dayString;
    //cout << "dzien: " << dayStringNumber << endl;

    todayDate = MetodyPomocnicze::konwerjsaIntNaString(year)+"-"+monthStringNumber+"-"+dayStringNumber;
    cout << todayDate << endl;

    return todayDate;

    //bool leapYear = isLeapYear(year);
    //cout << leapYear << endl;
    //cout << numberDaysPerMonth(month, leapYear) << endl;
    //dateComparison(year, month, day);

}

/*string MetodyDaty::checkDate()
{

}*/

bool MetodyDaty::isLeapYear(int year)
{
    bool leapYear = (year % 4 == 0 && year% 100 != 0 || year % 400 == 0);
    return leapYear;
}

int MetodyDaty::numberDaysPerMonth(int month, bool leapYear)
{
    int days;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;

    else if (month == 02)
    {
        if (leapYear == 0)
                days = 28;
        else
                days = 29;
    }
    else
    days = 31;
    return days;
}

string MetodyDaty::trueDateRange()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    //cout << endl << "Data dzisiejszego dnia to: " << st.wYear << "-" << st.wMonth << "-" << st.wDay  << endl;

    int giveYear = 0, giveMonthInt = 0, daysInMonth = 0, giveDayInt = 0;
    string giveMonth = "", giveDay = "", writeDate = "";
    bool leapYear;

    ////////////////////////////////////
    cout << "Podaj rok (od 2000 roku): ";
    cin >> giveYear;
    while (giveYear < 2000 || giveYear > st.wYear)
    {
        cout << "Podales rok poza zakresem, podaj rok jeszcze raz: ";
        cin >> giveYear;
    }
    leapYear = isLeapYear(giveYear);
    //cout << "Rok przestepny: " << leapYear << endl;

    cout << "Podaj miesiac: ";
    cin >> giveMonth;
    cout <<giveMonth.length() << endl;
    giveMonthInt = MetodyPomocnicze::konwersjaStringNaInt(giveMonth);
    cout << giveMonthInt << endl;
    while ((giveMonthInt > 12 || giveMonthInt < 1) || giveMonth.length() == 1)
    {
        cout << "Podales miesiac poza zakresem lub w zlym formacie, podaj miesiac jeszcze raz: ";
        cin >> giveMonth;
        giveMonthInt = MetodyPomocnicze::konwersjaStringNaInt(giveMonth);
    }

    daysInMonth = numberDaysPerMonth(giveMonthInt, leapYear);
    cout << "Dni w miesiacu: " <<  daysInMonth << endl;
    cout << "Podaj dzien: ";
    cin >> giveDay;
    cout << giveDay.length() << endl;
    giveDayInt = MetodyPomocnicze::konwersjaStringNaInt(giveDay);
    cout << giveDayInt << endl;
    while ((giveDayInt > daysInMonth || giveDayInt < 1) || giveDay.length() == 1)
    {
        cout << "Podales dzien poza zakresem lub w zlym formacie, podaj dzien jeszcze raz: ";
        giveDay = MetodyPomocnicze::wczytajLinie();
        cin >> giveDay;
    }
    writeDate = MetodyPomocnicze::konwerjsaIntNaString(giveYear)+"-"+giveMonth+"-"+giveDay;
    cout << writeDate << endl;

    return writeDate;
}

string MetodyDaty::resetSign(string signDelete)
{
    //string signDelete = "";
    cout <<"data przed usunieciem: " << signDelete << endl;
    signDelete = signDelete.erase (4,1);
    signDelete = signDelete.erase (6,1);
    cout << "data po usunieciu znaku: " << signDelete << endl;
    return signDelete;
    system("pause");
}


