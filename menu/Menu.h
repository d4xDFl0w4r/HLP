#ifndef MENU_H
#define MENU_H

#include <cstddef>
#include <string>
#include "./MenuItem.h"

using namespace std;


class Menu {
    public:
        Menu(string, MenuItem *, size_t);
        int getSelect() const;
        bool isRun() const;
        string getTitle();
        size_t getCount() const;
        MenuItem *getItems();
        void print();
        int runCommand();

    private:
        int select{-1};
        size_t count{};
        bool running{};
        string title{};
        MenuItem *items{};
};
#endif //MENU_H