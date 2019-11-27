#ifndef HELPINGMETHODS_H
#define HELPINGMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class HelpingMethods
{
public:
    static string loadLine();//zaladuj linie
    static string conversionIntToString(int number);//konwerjsaIntNaString(int liczba);
    static string getNumber(string text, int signPosition);//pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int conversionStringToInt(string number);//konwersjaStringNaInt(string liczba);
    static string replaceFirstLetterForBigAndOtherForSmall(string text); // zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static char loadSign();
    static int loadIntegerNumber();//wczytajLiczbeCalkowita();
    static string conversionCommaToDot(string quantity);//zamianaPrzecinkaNaKropke(string ilosc);
    static void difference(int sumIncome, int sumExpense);
    static string removeDashFromDate(string currentDate);
    static float conversionStringToFloat(string number);
};

#endif
