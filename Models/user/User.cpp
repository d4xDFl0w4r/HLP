#include "User.h"

User::User() : AbstractUser("No name", "No lastname", 0, "none", "none") {
    setIsAdministrator(false);
}

User::User(std::string name, std::string lastName, int age, std::string login, std::string password, bool isAdministrator) : AbstractUser(name, lastName, age, login, password){
    setIsAdministrator(isAdministrator);
}

bool User::getIsAdministrator() {
    return isAdministrator;
}

void User::setIsAdministrator(bool isAdministrator) {
    this->isAdministrator = isAdministrator;
}

void User::Print() const {
    std::cout << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Login: " << login << std::endl;
    std::cout << "Password: " << password << std::endl;
    std::cout << "Administrator: " << std::boolalpha << isAdministrator << std::endl;
    std::cout << messageHistory;
    std::cout << std::endl;
}

bool User::operator>(const User& other) {
    return login > other.login;
}

std::ostream& operator<<(std::ostream& out, const User& user) {
    user.Print();
    return out;
}

std::istream& operator>>(std::istream& in, User& user) {
    std::string buff;
    std::cout << "Name: ";
    getline(in, buff);
    user.setName(buff);
    std::cout << "Last name: ";
    getline(in, buff);
    user.setLastName(buff);
    std::cout << "Age: ";
    getline(in, buff);
    try {
        user.setAge(stoi(buff));
    } catch (const std::invalid_argument& err) {
        std::cerr << "Error type: " << err.what() << " - string to int conversion error" << std::endl;
        std::cerr << "Input must be a number" << std::endl;
        user.setAge(0);
    }
    std::cout << "Login: ";
    getline(in, buff);
    user.setLogin(buff);
    std::cout << "Password: ";
    getline(in, buff);
    user.setPassword(buff);
    std::cout << "Administrator (y/n): ";
    getline(in, buff);
    if (buff == "y") {
        user.setIsAdministrator(true);
    } else {
        user.setIsAdministrator(false);
    }
    return in;
}