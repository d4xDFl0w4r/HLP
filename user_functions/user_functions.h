#ifndef USER_FUNCTIONS_H
#define USER_FUNCTIONS_H

#include <iostream>

#include "../menu/Menu.h"

#include "../program_functions/program_functions.h"

void SayHelloToUser(std::string user);

namespace menu {
    void UserMenu(Menu& userMenu);
    void AdminMenu(Menu& adminMenu, const Vector<User>& userList);
} // namespace menu


namespace usermenu {
    void AddMessage(Vector<Message>& messageHistory);
    void DeleteMessage(Vector<Message>& messageHistory);
    void SortMessages(Vector<Message>& messageHistory);
    void PrintMessages(const Vector<Message>& messageHistory);
} // namespace user

namespace adminmenu {
    void DeleteUser(Vector<User>& userList);
    void SortUsers(Vector<User>& userList);
    void PrintUsers(const Vector<User>& userList);
} // namespace admin

#endif // USER_FUNCTIONS_H