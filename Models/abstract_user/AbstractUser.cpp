#include "AbstractUser.h"

AbstractUser::AbstractUser(
        std::string name,
        std::string lastName,
        int age,
        std::string login,
        std::string password
    ) {
        this->name = name;
        this->lastName = lastName;
        this->age = age;
        this->login = login;
        this->password = password;
}



std::string AbstractUser::getName() {
    return name;
}

void AbstractUser::setName(std::string name) {
    this->name = name;
}

std::string AbstractUser::getLastName() {
    return lastName;
}

void AbstractUser::setLastName(std::string lastName) {
    this->lastName = name;
}

int AbstractUser::getAge() {
    return age;
}

void AbstractUser::setAge(int age) {
    this->age = age;
}

std::string AbstractUser::getLogin() {
    return login;
}

void AbstractUser::setLogin(std::string login) {
    this->login = login;
}

std::string AbstractUser::getPassword() {
    return password;
}

void AbstractUser::setPassword(std::string password) {
    this->password = password;
}

Vector<Message> AbstractUser::getMessageHistory() {
    return messageHistory;
}

void AbstractUser::setMessage(Vector<Message> messageHistory) {
    this->messageHistory = messageHistory;
}
