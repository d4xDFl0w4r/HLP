#include "menu/Menu.h"
#include "menu/MenuItem.h"

#include "Models/chatbot/Chatbot.h"
#include "Models/user/User.h"
#include "Models/message/Message.h"

#include "Vector/vector.h"

#include "user_functions/user_functions.h"

#include <ctime>

using namespace std;



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

Vector<Message> messageHistory {
    message
};
Vector<User> userList {
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



bool Exit() { return false; }


// user functions

bool AddMessage() {
    usermenu::AddMessage(messageHistory);
    return true;
}

bool DeleteMessage() {
    usermenu::DeleteMessage(messageHistory);
    return true;
}

bool SortMessages() {
    usermenu::SortMessages(messageHistory);
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
    MenuItem("Sort messages history", SortMessages),
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
    menu::UserMenu(userMenu);
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