#ifndef METODYDATY_H
#define METODYDATY_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <windows.h>//pobieranie czasu
#include <winbase.h>//pobieranie czasu
#include <string>

#include "MetodyPomocnicze.h"

using namespace std;

class MetodyDaty
{
public:
    //static string wczytajLinie();
    //static string konwerjsaIntNaString(int liczba);
    //static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    //static int konwersjaStringNaInt(string liczba);
    //static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    //static char wczytajZnak();
    //static int wczytajLiczbeCalkowita();
    static string downloadSystemTime();
    //static string checkDate();
    static bool isLeapYear(int year);
    static int numberDaysPerMonth(int month, bool leapYear);
    static string trueDateRange();
    static string resetSign(string date);

    //vector < Foo > MyVector;
    //vector <Przychod> przychody;
};

#endif
