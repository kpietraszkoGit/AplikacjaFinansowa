#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"
#include "HelpingMethods.h"

using namespace std;

class UserManager
{
    int idLoggedUser;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User giveDataNewUser();
    int getIdNewUser();
    bool isLogin(string login);

public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers)
    {
        idLoggedUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void userRegistration();
    void userLogin();
    void changeOfPasswordOfLoggedInUser();
    void logOutUser();
    bool isUserLoggedIn();
    int getIdLoggedUser();
};

#endif
