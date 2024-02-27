#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>

using namespace std;


 class MenuItem {
public:
    typedef int(*Func)();
    MenuItem(string, Func);
    string getName();
    void print();
    int run();

private:
    Func func{};
    string item_name{};
};
#endif //MENUITEM_H