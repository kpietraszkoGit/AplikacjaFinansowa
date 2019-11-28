#include "HelpingMethods.h"

void HelpingMethods::difference(int sumIncome, int sumExpense)
{
 int disparity = sumIncome - sumExpense;
 cout << "roznica: " << disparity << endl;
}

string HelpingMethods::conversionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string HelpingMethods::loadLine()
{
    string entrance = "";
    getline(cin, entrance);
    return entrance;
}

string HelpingMethods::getNumber(string text, int signPosition)
{
    string number = "";
    while(isdigit(text[signPosition]) == true)
    {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}

int HelpingMethods::conversionStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}

string HelpingMethods::replaceFirstLetterForBigAndOtherForSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char HelpingMethods::loadSign()
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

/*int HelpingMethods::loadIntegerNumber()
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
}*/

string HelpingMethods::conversionCommaToDot(string quantity)
{
    string amount;
    if (quantity.find_first_of(',') != string::npos) quantity[quantity.find_first_of(',')] = '.';
    amount = quantity;
    return amount;
}

string HelpingMethods::removeDashFromDate(string signDelete)
{
    signDelete = signDelete.erase (4,1);
    signDelete = signDelete.erase (6,1);
    return signDelete;
    system("pause");
}

float HelpingMethods::conversionStringToFloat(string number)
{
    float numberFloat=atof(number.c_str());
    return numberFloat;
}


