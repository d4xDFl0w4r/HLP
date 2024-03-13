#include "menu/Menu.h"
#include "menu/MenuItem.h"
#include "Models/chatbot/Chatbot.h"
#include "Models/user/User.h"
#include "Models/message/Message.h"

#include <ctime>

using namespace std;

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
    Message message (
        1,
        "Test Message",
        "Admin",
        "12.03.24",
        "11:11"
    );
    message.Print();
    cout << "\n\n";

    cout << "Object User" << endl;
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
            "Daniel Verdanov",
            "12.03.24",
            "15:12"
        )
    );
    user.Print();
    cout << "\n";

    cout << "Object ChatBot" << endl;
    ChatBot bot (
        "Chat",
        "Bot",
        0,
        "chatbot@bot.api",
        "H@(*hsad8@!hldsidopf&E*rfh23heH*!dsa",
        Message (
            3,
            "Hello, Daniel!",
            "Chat Bot",
            "12.03.24",
            "15:13"
        )
    );
    bot.Print();

    return 4;
}

int Exit() {
    return 0;
}


const int ITEMS_NUMBER = 5;


int main() {
    MenuItem items[ITEMS_NUMBER] {
        MenuItem("Say hello to user", SayHelloToUser), 
        MenuItem("Get random number", GetRandomNumber), 
        MenuItem("Print Goose", PrintGoose),
        MenuItem("Test objects", TestObjects),
        MenuItem("Exit", Exit)
    };
    Menu menu("ChatBot menu", items, ITEMS_NUMBER);
    while (menu.runCommand());

    return 0;
}