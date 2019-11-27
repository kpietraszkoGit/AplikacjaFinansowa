#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "HelpingMethods.h"
#include "FileXml.h"
#include "Markup.h"

using namespace std;

class FileWithUsers: public FileXml
{
    void saveSingleUserToFile(User user);//zapiszPojedynczegoUzytkownikaDoPliku(Uzytkownik uzytkownik);

public:

    FileWithUsers(string fileName) : FileXml(fileName) {};//PlikZUzytkownikami(string nazwaPliku): PlikXml(nazwaPliku) {};
    void addUserToFile(User user);//dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <User> loadUsersFromFile();//wczytajUzytkownikowZPliku();

    void saveAllUsersToFile(vector <User> users);//zapiszWszystkichUzytkownikowDoPliku(vector <User> users);
};

#endif
