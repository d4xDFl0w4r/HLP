#include "menu/Menu.h"
#include "menu/MenuItem.h"

#include <ctime>

using namespace std;

int SayHelloToUser() {
    cout << "Hello, User!" << endl;
    return 1;
}

int GetRandomNumber() {
    srand(time(nullptr));
    int min{}, max{};
    cout << "Min number: ";
    cin >> min;
    cout << "Max number: ";
    cin >> max;
    cout << min + rand() % (max - min + 1) << endl;
    return 2;
}

int PrintGoose() {
    cout << "                                   ___" << endl;
    cout << "                               ,-\"\"   `." << endl;
    cout << "                             ,'  _   e )`-._" << endl;
    cout << "                            /  ,' `-._<.===-'" << endl;
    cout << "                           /  /" << endl;
    cout << "                          /  ;" << endl;
    cout << "          _              /   ;" << endl;
    cout << " (`._    _.-\"\" \"\"--..__,'    |" << endl;
    cout << " <_  `-\"\"                     \"" << endl;
    cout << "  <`-                          :" << endl;
    cout << "   (__   <__.                  ;" << endl;
    cout << "     `-.   '-.__.      _.'    /" << endl;
    cout << "        \\      `-.__,-'    _,'" << endl;
    cout << "         `._    ,    /__,-'" << endl;
    cout << "            \"\"._\\__,'< <____" << endl;
    cout << "                 | |  `----.`." << endl;
    cout << "                 | |        \\ `." << endl;
    cout << "                 ; |___      \\-``" << endl;
    cout << "                 \\   --<" << endl;
    cout << "                  `.`.<" << endl;
    cout << "                    `-'" << endl;
    return 3;
}

const int ITEMS_NUMBER = 3;


int main() {
    MenuItem items[ITEMS_NUMBER] {MenuItem("Say hello to user", SayHelloToUser), MenuItem("Get random number", GetRandomNumber), MenuItem("Print Goose", PrintGoose)};
    Menu menu("My console menu", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};

    return 0;
}