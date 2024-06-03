#include "./Menu.h"

Menu::Menu(std::string title, const Vector<MenuItem>& items, size_t count) : title(title), items(items), count(count) {}

int Menu::getSelect() const {
    return select;
}

bool Menu::isRun() const {
    return running;
}

size_t Menu::getCount() const {
    return count;
}

std::string Menu::getTitle() const {
    return title;
}

Vector<MenuItem> Menu::getItems() const {
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

bool Menu::runCommand() {
    print();
    for (;;) {
        std::cout << "\n\tSelect >> ";
        std::string buffstring = "";
        getline(std::cin, buffstring);
        std::cout << std::endl;
        try {
            select = stoi(buffstring);
            if (select < 1 || select > count) {
                throw std::out_of_range("out_of_range");
            }
            return items[select - 1].run();
        } catch (const std::out_of_range& err) {
            std::cerr << "Error type: " << err.what() << std::endl;
            std::cerr << "Number must be in range [1;" << count <<"]" << std::endl;
        } catch (const std::invalid_argument& err) {
            std::cerr << "Error type: " << err.what() << " - string to int conversion error" << std::endl;
            std::cerr << "Input must be a number" << std::endl;
        }
    }
}