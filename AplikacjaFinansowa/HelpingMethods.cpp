#include "HelpingMethods.h"

void HelpingMethods::difference(int sumIncome, int sumExpense)
{
 int disparity = sumIncome - sumExpense;
 cout << "roznica: " << disparity << endl;
}

string HelpingMethods::conversionIntToString(int number)//konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string HelpingMethods::loadLine() //wczytajLinie()
{
    string entrance = "";
    getline(cin, entrance);
    return entrance;
}

string HelpingMethods::getNumber(string text, int signPosition) //MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string number = "";
    while(isdigit(text[signPosition]) == true)
    {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}

int HelpingMethods::conversionStringToInt(string number)//konwersjaStringNaInt(string liczba)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}

string HelpingMethods::replaceFirstLetterForBigAndOtherForSmall(string text)//zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char HelpingMethods::loadSign() //wczytajZnak()
{
    string entrance = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, entrance);

        if (entrance.length() == 1)
        {
            sign = entrance[0];
            break;
        }
        else if (entrance.length() >= 2)
        {
            cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
        }
    }
    return sign;
}

int HelpingMethods::loadIntegerNumber() //wczytajLiczbeCalkowita()
{
    string entrance = "";
    int number = 0;

    while (true)
    {
        getline(cin, entrance);

        stringstream myStream(entrance);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

string HelpingMethods::conversionCommaToDot(string quantity)//zamianaPrzecinkaNaKropke(string ilosc)
{//poprawic bo nam zmienia liczbe jak sa wieksze, zwracanie stringa kwota lub ilosc
    string amount;//kwota;
    if (quantity.find_first_of(',') != string::npos) quantity[quantity.find_first_of(',')] = '.';
    amount = quantity;
    //kwota += atof (ilosc.c_str());
    return amount;
}

string HelpingMethods::removeDashFromDate(string signDelete)
{
    //cout <<"data przed usunieciem: " << signDelete << endl;
    signDelete = signDelete.erase (4,1);
    signDelete = signDelete.erase (6,1);
    //cout << "data po usunieciu znaku: " << signDelete << endl;
    return signDelete;
    system("pause");
}

float HelpingMethods::conversionStringToFloat(string number)
{
    float numberFloat=atof(number.c_str());
    return numberFloat;
}


