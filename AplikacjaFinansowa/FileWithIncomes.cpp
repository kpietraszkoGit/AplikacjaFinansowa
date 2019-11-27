#include "FileWithIncomes.h"

bool FileWithIncomes::addIncomeToFile(Income income)
{
    CMarkup xml;
    //bool fileExists = xml.Load( "users.xml" );
    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();//wchodzi do glownego elementu
    xml.IntoElem();//wchodzi do srodka elementu
    xml.AddElem("Income"); //dodanie elementu User
    xml.IntoElem(); //wejœcie do elementu User

    xml.AddElem("IncomeId", HelpingMethods::conversionIntToString(income.getIncomeId())); //MetodyPomocnicze::konwerjsaIntNaString(przychod.pobierzIdPrzychodu()));
    xml.AddElem("UserId",  HelpingMethods::conversionIntToString(income.getUserId())); //MetodyPomocnicze::konwerjsaIntNaString(przychod.pobierzIdUzytkownika()));
    xml.AddElem("DateInt", HelpingMethods::conversionIntToString(income.getDateInt()));
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getNameOfIncome());
    xml.AddElem("Amount", income.getQuantity());

    xml.Save(getFileName());

    idLastIncome++;

cout << "ID dodanego ostatniego adresata: " << idLastIncome << endl;
system("pause");

    return true;
}

vector <Income> FileWithIncomes::loadIncomesLoggedUserFromFile(int idLoggedUser)
{
    //string neOstaniegoPrzychoduWPliku = "";

    CMarkup xml;
    //bool fileExists = xml.Load( "users.xml" );
    bool fileExists = xml.Load(getFileName());
    Income income;
    vector <Income> incomes;

    xml.FindElem(); // root ORDER element
    xml.IntoElem(); // inside ORDER
    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem( "IncomeId" );
        int incomeID = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "UserId" );
        int userID = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "DateInt" );
        int dateInt = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "Date" );
        string date = xml.GetData();
      //int date = atoi( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "Item" );
        string item = xml.GetData();
        xml.FindElem( "Amount" );
        string amount = xml.GetData();
        xml.OutOfElem();

        /*cout << "ID: " << userID << " :)"<< endl;
        cout << "Login : " << login << " :)"<< endl;
        cout << "Haslo : " << password << " :)"<< endl;
        cout << "Imie : " << name << " :)"<< endl;
        cout << "Nazwisko : " << surname << " :)"<< endl;
        cout << "ID przychodu: " << incomeID << " :)"<< endl;
        cout << "ID uzytkownika : " << userID << " :)"<< endl;
        system("pause");*/
        if (idLoggedUser == userID)
        {
            income.setIncomeId(incomeID);//przychod.ustawIdPrzychodu(incomeID);
            income.setUserId(userID);
            income.setDateInt(dateInt);
            income.setDate(date);
            income.setNameOfIncome(item);
            income.setQuantity(amount);
            //uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            incomes.push_back(income);
        }
        if (date == "" && item == "" && amount == "" && incomeID == 0)
        {
            idLastIncome = 0;
        }
        else
        {
            idLastIncome = incomeID;
        }
    }
    return incomes;
}

int FileWithIncomes::getIdLastIncome()
{
    return idLastIncome;
}


