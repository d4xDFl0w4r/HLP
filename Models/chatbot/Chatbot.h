#ifndef CHATBOT_H
#define CHATBOT_H

#include <iostream>
#include <string>

#include "../abstract_user/AbstractUser.h"

class ChatBot: public AbstractUser
{
public:
    ChatBot(std::string name, std::string lastName, int age, std::string login, std::string password);

    friend std::ostream& operator<<(std::ostream& out, const ChatBot& bot);
    friend std::istream& operator>>(std::istream& in, ChatBot& bot);

    void Print() const override;
    Message Reply(std::string username, std::string request, int id) const;
};

#endif //CHATBOT_H