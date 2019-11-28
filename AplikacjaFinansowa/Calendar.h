#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <vector>
#include "algorithm"
#include <algorithm>
#include <windows.h>//pobieranie czasu
#include <winbase.h>//pobieranie czasu

#include "HelpingMethods.h"


using namespace std;

class Calendar
{

public:
    string getCurrentDate();
    //bool isDateGood(string differentDate);
    static bool isLeapYear(int year);
    static int numberDaysPerMonth(int month, bool leapYear);
    string trueDateRange();
};

#endif
