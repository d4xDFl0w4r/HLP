#ifndef ABSTRACTUSER_H
#define ABSTRACTUSER_H

#include <iostream>
#include <string>

#include "../message/Message.h"

class AbstractUser {
public:
    AbstractUser(std::string name, std::string lastName, int age, std::string login, std::string password, Message message);

    std::string getName();
    void setName(std::string name);

    std::string getLastName();
    void setLastName(std::string lastName);

    int getAge();
    void setAge(int age);

    std::string getLogin();
    void setLogin(std::string login);

    std::string getPassword();
    void setPassword(std::string password);

    Message getMessage();
    void setMessage(Message message);

    virtual void Print() = 0;

protected:
    std::string name;
    std::string lastName;
    int age;
    std::string login;
    std::string password;
    Message message;
};

#endif //ABSTRACTUSER_H