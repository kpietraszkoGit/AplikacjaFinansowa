#ifndef HELPINGMETHODS_H
#define HELPINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class HelpingMethods
{
public:
    static string loadLine();
    static string conversionIntToString(int number);
    static string getNumber(string text, int signPosition);
    static int conversionStringToInt(string number);
    static string replaceFirstLetterForBigAndOtherForSmall(string text);
    static char loadSign();
    //static int loadIntegerNumber();
    static string conversionCommaToDot(string quantity);
    static void difference(int sumIncome, int sumExpense);
    static string removeDashFromDate(string currentDate);
    static float conversionStringToFloat(string number);
};

#endif
