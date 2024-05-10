#include "Chatbot.h"

ChatBot::ChatBot(std::string name, std::string lastName, int age, std::string login, std::string password, Message message) : AbstractUser(name, lastName, age, login, password, message) {
    setMessage(message);
}

void ChatBot::Print() const {
    std::cout << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "ID: " << login << std::endl;
    std::cout << "API token: " << password << std::endl;
    std::cout << messageHistory;
    std::cout << std::endl;
}


std::ostream& operator<<(std::ostream& out, const ChatBot& bot) {
    bot.Print();
    return out;
}

std::istream& operator>>(std::istream& in, ChatBot& bot) {
    std::string buff;
    std::cout << "Name: ";
    getline(in, buff);
    bot.setName(buff);
    std::cout << "Last name: ";
    getline(in, buff);
    bot.setLastName(buff);
    std::cout << "Age: ";
    getline(in, buff);
    bot.setAge(stoi(buff));
    std::cout << "ID: ";
    getline(in, buff);
    bot.setLogin(buff);
    std::cout << "API token: ";
    getline(in, buff);
    bot.setPassword(buff);
    return in;
}