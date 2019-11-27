#ifndef USER_H // zabezpieczenie przed podwójnym includowaniem uzytkownik.h
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;//wszystkie one s¹ prywatne zahermetyzowane
    string login;
    string password;
    string name;
    string surname;

public:
    void setId(int newId);//settery aby udostepnic innym klasa, tu publiczenie s¹ metody, które zabezpieczamy w pliku .cpp
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);

    int getId();//gettery
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};

#endif
