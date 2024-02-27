#include "./Menu.h"

Menu::Menu(string title, MenuItem *items, size_t count) : title(title), items(items), count(count) {}

int Menu::getSelect() const {
    return select;
}

bool Menu::isRun() const {
    return running;
}

size_t Menu::getCount() const {
    return count;
}

string Menu::getTitle() {
    return title;
}

MenuItem *Menu::getItems() {
    return items;
}

void Menu::print() {
    for (size_t i{}; i < count; ++i) {
        std::cout << i + 1 << ". ";
        items[i].print();
        std::cout << std::endl;
    }
    std::cout << "0. exit" << std::endl;
}

int Menu::runCommand() {
    print();
    std::cout << "\n   Select >> ";
    std::cin >> select;
    return items[select - 1].run();
}