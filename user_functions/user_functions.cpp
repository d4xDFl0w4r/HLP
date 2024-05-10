#include "user_functions.h"


// all users functions

void SayHelloToUser(std::string user) {
    std::cout << "Hello, " << user << "!" << std::endl;
}

void menu::UserMenu(Menu& userMenu) {
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

void usermenu::AddMessage(Vector<Message>& messageHistory) {
    std::string id = "";
    std::cout << "id: ";
    std::getline(std::cin, id);
    std::string text = "";
    std::cout << "Message text: ";
    std::getline(std::cin, text);
    std::string sender = "";
    std::cout << "Sender: ";
    std::getline(std::cin, sender);
    messageHistory << Message(
        stoi(id),
        text,
        sender
    );
}

void usermenu::DeleteMessage(Vector<Message>& messageHistory) {
    std::string id = "";
    std::cout << "Id of message that should be deleted: ";
    std::getline(std::cin, id);
    size_t index = 0;
    for (Message message : messageHistory) {
        if (std::to_string(message.getID()) == id) {
            messageHistory - index;
            return;
        }
        index++;
    }
}

void usermenu::SortMessages(Vector<Message>& messageHistory) {
    if (messageHistory.size() < 2) {
        return;
    }
    for (size_t i = 0; i < messageHistory.size() - 1; i++) {
        if (messageHistory[i] > messageHistory[i + 1]) {
            Message tmp = messageHistory[i];
            messageHistory[i] = messageHistory[i + 1];
            messageHistory[i + 1] = tmp;
        }
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