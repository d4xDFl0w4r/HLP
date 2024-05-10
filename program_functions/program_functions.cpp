#include "program_functions.h"

std::ostream& operator<<(std::ostream& out, Vector<Message> &vec) {
    for (auto &element : vec) {
        out << element;
    }
    return out;
}

void operator<<(Vector<Message> &vec, const Message &message) {
    vec.push_back(message);
}
void operator<<(Vector<User> &vec, const User &user) {
    vec.push_back(user);
}

void operator-(Vector<Message> &vec, const int &index) {
    vec.erase(index);
}
void operator-(Vector<User> &vec, const int &index) {
    vec.erase(index);
}