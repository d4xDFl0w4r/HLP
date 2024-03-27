#include "menu/Menu.h"
#include "menu/MenuItem.h"
#include "Models/chatbot/Chatbot.h"
#include "Models/user/User.h"
#include "Models/message/Message.h"

#include <ctime>
#include <vector>

using namespace std;

const int MAIN_MENU_ITEMS_NUMBER = 7;
const int USER_MENU_ITEMS_NUMBER = 5;
const int ADMIN_MENU_ITEMS_NUMBER = 4;


Message message (
    1,
    "Test Message",
    "Admin"
);

ChatBot bot (
    "Chat",
    "Bot",
    0,
    "chatbot@bot.api",
    "H@(*hsad8@!hldsidopf&E*rfh23heH*!dsa",
    Message (
        3,
        "Hello, Daniel!",
        "Chat Bot"
    )
);

User user (
    "Daniel",
    "Verdanov",
    18,
    "noreply@mail.com",
    "fjak12fda@e",
    true,
    Message (
        2,
        "Hello, Bot!",
        "Daniel Verdanov"
    )
);

vector<Message> messageHistory {
    message
};
vector<User> userList {
    user, 
    User (
        "Prosto",
        "User",
        21,
        "user123@mail.com",
        "lasdkewf",
        false,
        Message (
            5,
            "Hello, Mir!",
            "Prosto User"
        )
    )
};


ostream& operator<<(ostream& out, vector<Message> &vec) {
    for (auto &element : vec) {
        out << element;
    }
    return out;
}

void operator<<(vector<Message> &vec, const Message &message) {
    vec.push_back(message);
}
void operator<<(vector<User> &vec, const User &user) {
    vec.push_back(user);
}

void operator-(vector<Message> &vec, const int &index) {
    vec.erase(vec.begin() + index);
}
void operator-(vector<User> &vec, const int &index) {
    vec.erase(vec.begin() + index);
}


int SayHelloToUser() {
    cout << "Hello, User!" << endl;
    return 1;
}

int GetRandomNumber() {
    srand(time(nullptr));
    int min{}, max{};
    cout << "Min number: ";
    cin >> min;
    cout << "Max number: ";
    cin >> max;
    cout << min + rand() % (max - min + 1) << endl;
    return 2;
}

int PrintGoose() {
    cout << "                                   ___" << endl;
    cout << "                               ,-\"\"   `." << endl;
    cout << "                             ,'  _   e )`-._" << endl;
    cout << "                            /  ,' `-._<.===-'" << endl;
    cout << "                           /  /" << endl;
    cout << "                          /  ;" << endl;
    cout << "          _              /   ;" << endl;
    cout << " (`._    _.-\"\" \"\"--..__,'    |" << endl;
    cout << " <_  `-\"\"                     \"" << endl;
    cout << "  <`-                          :" << endl;
    cout << "   (__   <__.                  ;" << endl;
    cout << "     `-.   '-.__.      _.'    /" << endl;
    cout << "        \\      `-.__,-'    _,'" << endl;
    cout << "         `._    ,    /__,-'" << endl;
    cout << "            \"\"._\\__,'< <____" << endl;
    cout << "                 | |  `----.`." << endl;
    cout << "                 | |        \\ `." << endl;
    cout << "                 ; |___      \\-``" << endl;
    cout << "                 \\   --<" << endl;
    cout << "                  `.`.<" << endl;
    cout << "                    `-'" << endl;
    return 3;
}

int TestObjects() {
    cout << "Object Message" << endl;
    message.Print();
    cout << "\n\n";

    cout << "Object User" << endl;
    user.Print();
    cout << "\n";

    cout << "Object ChatBot" << endl;
    bot.Print();
    return 4;
}

int UserMenu();
int AdminMenu();

int Exit() {
    return 0;
}

int Exit2() {
    return 0;
}

int AddMessage() {
    string id = "";
    cout << "id: ";
    getline(cin, id);
    string text = "";
    cout << "Message text: ";
    getline(cin, text);
    string sender = "";
    cout << "Sender: ";
    getline(cin, sender);
    messageHistory << Message(
        stoi(id),
        text,
        sender
    );
    return 1;
}

int DeleteMessage() {
    string id = "";
    cout << "Id of message that should be deleted: ";
    getline(cin, id);
    size_t index = 0;
    for (auto& message : messageHistory) {
        if (to_string(message.getID()) == id) {
            messageHistory - index;
            return 1;
        }
        index++;
    }
    return 2;
}

int SortMessages() {
    if (messageHistory.size() < 2) {
        return 3;
    }
    for (size_t i = 0; i < messageHistory.size() - 1; i++) {
        if (messageHistory[i] > messageHistory[i + 1]) {
            Message tmp = messageHistory[i];
            messageHistory[i] = messageHistory[i + 1];
            messageHistory[i + 1] = tmp;
        }
    }
    return 3;
}

int PrintMessages() {
    for (const auto& message : messageHistory) {
        cout << message << endl;
    }
    return 4;
}


int DeleteUser() {
    string login = "";
    cout << "Login of user who should be deleted: ";
    getline(cin, login);
    size_t index = 0;
    for (auto& user : userList) {
        if (user.getLogin() == login) {
            userList - index;
            return 1;
        }
        index++;
    }
    cout << "There are no users with this login: " << login << endl;
    return 1;
}

int SortUsers() {
    if (userList.size() < 2) {
        return 2;
    }
    for (size_t i = 0; i < userList.size() - 1; i++) {
        if (userList[i] > userList[i + 1]) {
            User tmp = userList[i];
            userList[i] = userList[i + 1];
            userList[i + 1] = tmp;
        }
    }
    return 2;
}

int PrintUsers() {
    for (const auto& user : userList) {
        cout << user << endl;
    }
    return 3;
}


MenuItem mainMenuItems[MAIN_MENU_ITEMS_NUMBER] {
    MenuItem("Say hello to user", SayHelloToUser), 
    MenuItem("Get random number", GetRandomNumber), 
    MenuItem("Print Goose", PrintGoose),
    MenuItem("Test objects", TestObjects),
    MenuItem("User menu", UserMenu),
    MenuItem("Admin menu", AdminMenu),
    MenuItem("Exit", Exit)
};
Menu mainMenu("Program menu", mainMenuItems, MAIN_MENU_ITEMS_NUMBER);

MenuItem userMenuItems[USER_MENU_ITEMS_NUMBER] {
    MenuItem("Write message", AddMessage),
    MenuItem("Delete message", DeleteMessage),
    MenuItem("Sort messages history", SortMessages),
    MenuItem("Print messages history", PrintMessages),
    MenuItem("Return to main menu", Exit2)
};
Menu userMenu("User menu", userMenuItems, USER_MENU_ITEMS_NUMBER);

MenuItem adminMenuItems[ADMIN_MENU_ITEMS_NUMBER] {
    MenuItem("Delete user", DeleteUser),
    MenuItem("Sort users", SortUsers),
    MenuItem("Print users", PrintUsers),
    MenuItem("Return to main menu", Exit)
};
Menu adminMenu("Admin menu", adminMenuItems, ADMIN_MENU_ITEMS_NUMBER);

int UserMenu() {
    while(userMenu.runCommand());
    return 5;
}

int AdminMenu() {
    cout << "Login: ";
    string login = "";
    getline(cin, login);
    cout << "Password: ";
    string password = "";
    getline(cin, password);
    if (
        login == "admin@mail.com" &&
        password == "1234"    
    ) {
        while(adminMenu.runCommand());
    } else {
        cout << "This user is not among the administrators" << endl;
    }
    return 6;
}

int main() {
    while(mainMenu.runCommand());

    return 0;
}