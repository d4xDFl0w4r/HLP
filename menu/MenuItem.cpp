#include "MenuItem.h"

MenuItem::MenuItem() : item_name("no name"), function(nullptr) {}
MenuItem::MenuItem(std::string _item_name, Function _function) : item_name(_item_name), function(_function) {}

std::string MenuItem::getName() {
    return item_name;
}

void MenuItem::print() {
    std::cout << item_name;
}

bool MenuItem::run() {
    return function();
}