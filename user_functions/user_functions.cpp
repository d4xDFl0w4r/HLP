#include "user_functions.h"


// all users functions

void SayHelloToUser(std::string user) {
    std::cout << "Hello, " << user << "!" << std::endl;
}

void menu::UserMenu(Menu& userMenu, Vector<User>& userList, std::string& currentUser) {
    std::cout << "Login: ";
    std::string login = "";
    std::getline(std::cin, login);
    std::cout << "Password: ";
    std::string password = "";
    std::getline(std::cin, password);
    for (User user : userList) {
        if (
            login == user.getLogin() &&
            password == user.getPassword()   
        ) {
            while(userMenu.runCommand());
            return;
        }
    }
    std::cout << "Name: ";
    std::string name = "";
    std::getline(std::cin, name);
    std::cout << "Lastname: ";
    std::string lastname = "";
    std::getline(std::cin, lastname);
    std::cout << "Age: ";
    std::string age = "";
    std::getline(std::cin, age);
    userList.push_back(
            User(
                name,
                lastname,
                0,
                login,
                password,
                false
            )
        );
    try {
        userList[userList.size() - 1].setAge(stoi(age));
    } catch (const std::invalid_argument& err) {
        std::cerr << "Error type: " << err.what() << std::endl;
        std::cerr << "Input must be a number" << std::endl;
    }
    currentUser = name + " " + lastname;
    while(userMenu.runCommand());
}

void menu::AdminMenu(Menu& adminMenu, const Vector<User>& userList) {
    std::cout << "Login: ";
    std::string login = "";
    std::getline(std::cin, login);
    std::cout << "Password: ";
    std::string password = "";
    std::getline(std::cin, password);
    for (User user : userList) {
        if (
            user.getIsAdministrator() &&
            login == user.getLogin() &&
            password == user.getPassword()   
        ) {
            while(adminMenu.runCommand());
            return;
        }
    }
    std::cout << "Incorrect login or password" << std::endl;
}

// common user functions

void usermenu::AddMessage(Vector<Message>& messageHistory, ChatBot& bot, std::string& currentUser) {
    std::string text = "";
    std::cout << "Message text: ";
    std::getline(std::cin, text);
    std::string sender = currentUser;
    messageHistory << Message(
        messageHistory.size(),
        text,
        sender
    );
    if (text.substr(0, 3) == "bot") {
        Message message = bot.Reply(sender, text, messageHistory.size());
        messageHistory << message;
        message.Print();
    }
}

void usermenu::DeleteMessage(Vector<Message>& messageHistory) {
    std::string id = "";
    std::cout << "Id of message that should be deleted: ";
    std::getline(std::cin, id);
    size_t index = 0;
    for (Message message : messageHistory) {
        if (std::to_string(message.getID()) == id) {
            messageHistory - index;
            break;
        }
        index++;
    }
    for (int i = 0; i < messageHistory.size(); i++) {
        messageHistory[i].setID(i);
    }
}

void usermenu::PrintMessages(const Vector<Message>& messageHistory) {
    for (const auto& message : messageHistory) {
        std::cout << message << std::endl;
    }
}


// administrator functions

void adminmenu::DeleteUser(Vector<User>& userList) {
    std::string login = "";
    std::cout << "Login of user who should be deleted: ";
    std::getline(std::cin, login);
    size_t index = 0;
    for (auto& user : userList) {
        if (user.getLogin() == login) {
            userList - index;
            return;
        }
        index++;
    }
    std::cout << "There are no users with this login: " << login << std::endl;
}

void adminmenu::SortUsers(Vector<User>& userList) {
    if (userList.size() < 2) {
        return;
    }
    for (size_t i = 0; i < userList.size() - 1; i++) {
        if (userList[i] > userList[i + 1]) {
            User tmp = userList[i];
            userList[i] = userList[i + 1];
            userList[i + 1] = tmp;
        }
    }
}

void adminmenu::PrintUsers(const Vector<User>& userList) {
    for (const auto& user : userList) {
        std::cout << user << std::endl;
    }
}