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
    std::cout << std::endl << "\t" << title << "\n\n";
    for (size_t i{}; i < count; ++i) {
        std::cout << i + 1 << ". ";
        items[i].print();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int Menu::runCommand() {
    print();
    std::cout << "\tSelect >> ";
    for (;;) {
        std::cin >> select;
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << std::endl;
        if (select < 1 || select > count) {
            cout << "Number must be in range [1;" << count <<"]" << endl;
        } else if (select == 0) {
            return 0;
        } else {
            return items[select - 1].run();
        }
    }
}