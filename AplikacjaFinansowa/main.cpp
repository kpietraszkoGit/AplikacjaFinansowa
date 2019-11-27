#include <iostream>
#include "FinanceApplication.h"

using namespace std;

int main()
{
    //vector <Uzytkownik> uzytkownicy;
    //vector <Przychod> przychody;
    //vector <Wydatek> wydatki;
    vector<Income> incomes;
    vector<Expense> expenses;

    FinanceApplication financeApplication("users.xml", "incomes.xml", "expenses.xml");
    //AplikacjaFinansowa aplikacjaFinansowa("users.xml", "incomes.xml", "expenses.xml");
    //char wybor;
    char choice;

    while (true)
    {
        //if (aplikacjaFinansowa.czyUzytkownikJestZalogowany())
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
                break;//6:58,
            case '6':
                financeApplication.changeOfPasswordOfLoggedInUser();
                //ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                financeApplication.logOutUser();
                incomes.clear();//przychody
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
/*#include "AdresatMenadzer.h"
int main()
{
  AdresatMenadzer adresatMenadzer("Adresatek.txt", 2);
  adresatMenadzer.wyswietlWszystkichAdresatow();
  adresatMenadzer.dodajAdresata();
  adresatMenadzer.wyswietlWszystkichAdresatow();
}*/
