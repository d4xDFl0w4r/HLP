#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>

class MenuItem {
public:
    typedef bool (*Function)();
    MenuItem();
    MenuItem(std::string name, Function function);
    std::string getName();
    void print();
    bool run();

private:
    Function function{};
    std::string item_name{};
};
#endif //MENUITEM_H