#include "./MenuItem.h"


MenuItem::MenuItem(std::string name, Func func) : item_name(name), func(func) {}

string MenuItem::getName() {
    return item_name;
}

void MenuItem::print() {
    std::cout << item_name;
}

int MenuItem::run() {
    return func();
}