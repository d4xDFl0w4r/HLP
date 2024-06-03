#include "menu/Menu.h"
#include "menu/MenuItem.h"

#include "Models/chatbot/Chatbot.h"
#include "Models/user/User.h"
#include "Models/message/Message.h"

#include "Vector/vector.h"

#include "user_functions/user_functions.h"

#include <ctime>

using namespace std;



Message testMessage (
    0,
    "Test Message",
    "System"
);

ChatBot bot (
    "Chat",
    "Bot",
    0,
    "chatbot",
    "H@(*hsad8@!hldsidopf&E*rfh23heH*!dsa"
);

Vector<Message> messageHistory {
    testMessage
};

Vector<User> userList {
    User (
        "Admin",
        "Adminov",
        22,
        "admin",
        "1234",
        true
    )
};

string currentUser = "";

bool Exit() { return false; }


// user functions

bool AddMessage() {
    usermenu::AddMessage(messageHistory, bot, currentUser);
    return true;
}

bool DeleteMessage() {
    usermenu::DeleteMessage(messageHistory);
    return true;
}

bool PrintMessages() {
    usermenu::PrintMessages(messageHistory);
    return true;
}


// administrator functions

bool DeleteUser() {
    adminmenu::DeleteUser(userList);
    return true;
}

bool SortUsers() {
    adminmenu::SortUsers(userList);
    return true;
}

bool PrintUsers() {
    adminmenu::PrintUsers(userList);
    return true;
}


// menu functions prototypes

bool UserMenu();
bool AdminMenu();


// menu objects

Vector<MenuItem> mainMenuItems {
    MenuItem("User menu", UserMenu),
    MenuItem("Admin menu", AdminMenu),
    MenuItem("Exit", Exit)
};
Menu mainMenu("Program menu", mainMenuItems, mainMenuItems.size());

Vector<MenuItem> userMenuItems {
    MenuItem("Write message", AddMessage),
    MenuItem("Delete message", DeleteMessage),
    MenuItem("Print messages history", PrintMessages),
    MenuItem("Return to main menu", Exit)
};
Menu userMenu("User menu", userMenuItems, userMenuItems.size());

Vector<MenuItem> adminMenuItems {
    MenuItem("Delete user", DeleteUser),
    MenuItem("Sort users", SortUsers),
    MenuItem("Print users", PrintUsers),
    MenuItem("Return to main menu", Exit)
};
Menu adminMenu("Admin menu", adminMenuItems, adminMenuItems.size());


// menu functions

bool UserMenu() {
    menu::UserMenu(userMenu, userList, currentUser);
    return true;
}

bool AdminMenu() {
    menu::AdminMenu(adminMenu, userList);
    return true;
}



int main() {
    while(mainMenu.runCommand());

    return 0;
}