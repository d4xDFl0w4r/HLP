#ifndef CHATBOT_H
#define CHATBOT_H

#include <iostream>
#include <string>

#include "../abstract_user/AbstractUser.h"

class ChatBot: public AbstractUser
{
public:
    ChatBot(std::string name, std::string lastName, int age, std::string login, std::string password, Message message);

    void Print() override;
};

#endif //CHATBOT_H