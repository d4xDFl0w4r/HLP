#include "Chatbot.h"

ChatBot::ChatBot(std::string name, std::string lastName, int age, std::string login, std::string password, Message message) : AbstractUser(name, lastName, age, login, password, message) {
    setMessage(message);
}

void ChatBot::Print() {
    std::cout << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Login: " << login << std::endl;
    std::cout << "Password: " << password << std::endl;
    message.Print();
    std::cout << std::endl;
}