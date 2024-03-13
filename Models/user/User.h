#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

#include "../abstract_user/AbstractUser.h"

class User: public AbstractUser
{
public:
    User(std::string name, std::string lastName, int age, std::string login, std::string password, bool isAdministrator, Message message);

    bool getIsAdministrator();
    void setIsAdministrator(bool isAdministrator);

    void Print() override;

private:
    bool isAdministrator;
};

#endif //USER_H