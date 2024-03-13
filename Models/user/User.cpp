#include "User.h"

User::User(std::string name, std::string lastName, int age, std::string login, std::string password, bool isAdministrator, Message message) : AbstractUser(name, lastName, age, login, password, message){
    setIsAdministrator(isAdministrator);
}

bool User::getIsAdministrator() {
    return isAdministrator;
}

void User::setIsAdministrator(bool isAdministrator) {
    this->isAdministrator = isAdministrator;
}

void User::Print() {
    std::cout << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Login: " << login << std::endl;
    std::cout << "Password: " << password << std::endl;
    std::cout << "Administrator: " << std::boolalpha << isAdministrator << std::endl;
    message.Print();
    std::cout << std::endl;
}