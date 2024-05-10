#ifndef ABSTRACTUSER_H
#define ABSTRACTUSER_H

#include <iostream>
#include <string>

#include "../../Vector/vector.h"
#include "../message/Message.h"

class AbstractUser {
public:
    AbstractUser(std::string name, std::string lastName, int age, std::string login, std::string password, Vector<Message> messageHistory);

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

    Vector<Message> getMessageHistory();
    void setMessage(Vector<Message> messageHistory);

    virtual void Print() const = 0;

protected:
    std::string name;
    std::string lastName;
    int age;
    std::string login;
    std::string password;
    Vector<Message> messageHistory;
};

#endif //ABSTRACTUSER_H