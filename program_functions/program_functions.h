#ifndef PROGRAM_FUNCTIONS_H
#define PROGRAM_FUNCTIONS_H

#include <iostream>

#include "../Vector/vector.h"
#include "../Models/message/Message.h"
#include "../Models/user/User.h"
#include "../Models/chatbot/Chatbot.h"


template<typename T>
void sort(Vector<T>& vec, bool isDescending = false) {
    if (vec.size() < 2) {
        return;
    }
    if (!isDescending) {
        for (size_t i = 0; i < vec.size() - 1; i++) {
            if (vec[i] > vec[i + 1]) {
                T buff = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = vec;
            }
        }
    }
    else {
        for (size_t i = 0; i < vec.size() - 1; i++) {
            if (vec[i] < vec[i + 1]) {
                T buff = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = buff;
            }
        }
    }
}

std::ostream& operator<<(std::ostream& out, Vector<Message> &vec);
void operator<<(Vector<Message> &vec, const Message &message);
void operator<<(Vector<User> &vec, const User &user);
void operator-(Vector<Message> &vec, const int &index);
void operator-(Vector<User> &vec, const int &index);

#endif //PROGRAM_FUNCTIONS_H