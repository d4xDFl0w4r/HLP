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

    void Print() const override;

    bool operator>(const User& other);

    friend std::ostream& operator<<(std::ostream& out, const User& user);
    friend std::istream& operator>>(std::istream& in, User& user);

private:
    bool isAdministrator;
};

#endif //USER_H