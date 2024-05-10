#ifndef MENU_H
#define MENU_H

#include <cstddef>
#include <string>
#include "../Vector/vector.h"
#include "./MenuItem.h"

class Menu {
    public:
        Menu(std::string, const Vector<MenuItem>&, size_t);
        int getSelect() const;
        bool isRun() const;
        std::string getTitle() const;
        size_t getCount() const;
        Vector<MenuItem> getItems() const;
        void print();
        int runCommand();

    private:
        int select{-1};
        size_t count{};
        bool running{};
        std::string title{};
        Vector<MenuItem> items;
};
#endif //MENU_H