#ifndef FILEXML_H
#define FILEXML_H

#include <iostream>
#include <fstream>

using namespace std;

class FileXml
{
    const string FILE_NAME;

public:

    FileXml(string fileName) : FILE_NAME(fileName) {};
    string getFileName();
};

#endif
