#include "Chatbot.h"

ChatBot::ChatBot(std::string name, std::string lastName, int age, std::string login, std::string password) : AbstractUser(name, lastName, age, login, password) {}

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
    try {
        bot.setAge(stoi(buff));
    } catch (const std::invalid_argument& err) {
        std::cerr << "Error type: " << err.what() << " - string to int conversion error" << std::endl;
        std::cerr << "Input must be a number" << std::endl;
        bot.setAge(0);
    }
    std::cout << "ID: ";
    getline(in, buff);
    bot.setLogin(buff);
    std::cout << "API token: ";
    getline(in, buff);
    bot.setPassword(buff);
    return in;
}

Message ChatBot::Reply(std::string username, std::string request, int id) const {
    request.erase(0, 4);
    if (request == "commands") {
        return Message(id, "commands: hello, bye, who are you, calc (first num, + or - or * or /, second num:   5 + 1)" + username, name);
    } else if (request == "hello") {
        return Message(id, "hello, " + username, name);
    } else if (request == "bye") {
        return Message(id, "bye, " + username, name);
    } else if (request == "who are you") {
        return Message(id, "I am " + name + " " + lastName, name);
    } else if (request.length() > 4 && request.substr(0, 4) == "calc") {
        request.erase(0, 5);
        std::string result = "";
        try {
            size_t pos;
            pos = request.find(" ");
            double firstNum = std::stod(request.substr(0, pos));
            request.erase(0, pos + 1);
            pos = request.find(" ");
            std::string operation = request.substr(0, pos);
            request.erase(0, pos + 1);
            pos = request.find(" ");
            double secondNum = std::stod(request.substr(0, pos));
            double resnum = 0;
            if (operation == "+") {
                resnum = firstNum + secondNum;
                result = std::to_string(firstNum) + " " + operation + " " + std::to_string(secondNum) + " = " + std::to_string(resnum);
            } else if (operation == "-") {
                resnum = firstNum - secondNum;
                result = std::to_string(firstNum) + " " + operation + " " + std::to_string(secondNum) + " = " + std::to_string(resnum);
            } else if (operation == "*") {
                resnum = firstNum * secondNum;
                result = std::to_string(firstNum) + " " + operation + " " + std::to_string(secondNum) + " = " + std::to_string(resnum);
            } else if (operation == "/") {
                try {
                    if (secondNum == 0) { throw std::logic_error("Divide by 0"); }
                    resnum = firstNum / secondNum;
                    result = std::to_string(firstNum) + " " + operation + " " + std::to_string(secondNum) + " = " + std::to_string(resnum);
                } catch (const std::exception& err) {
                    std::cerr << "Error type: " << err.what() << std::endl;
                    result = "an error received";
                }
            } else {
                result = "Unknown operation: " + operation;
            }
        } catch (const std::exception& err) {
            std::cerr << "Error type: " << err.what() << std::endl;
            result = "an error received";
        }
        return Message(id, result, name + " " + lastName);
    } else {
        return Message(id, "sorry, " + username + ", i don`t know this command, write \"bot commands\" if you want to see all my commands", name);
    }
}