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
    void saveSingleUserToFile(User user);

public:

    FileWithUsers(string fileName) : FileXml(fileName) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();

    void saveAllUsersToFile(vector <User> users);
};

#endif
