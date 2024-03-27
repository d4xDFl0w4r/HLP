#ifndef MESSAGE_H
#define MESSAGE_H

#include "../../time/Time.h"

#include <iostream>
#include <string>

class Message {
public:
    Message(int id, std::string text, std::string sender);

    int getID();
    void setID(int id);

    std::string getText();
    void setText(std::string text);

    std::string getSender();
    void setSender(std::string sender);

    std::string getTime();
    void setTime();

    void Print() const;

    bool operator>(const Message& other);

    friend std::ostream& operator<<(std::ostream& out, const Message& message);

private:
    int id;
    std::string text;
    std::string sender;
    Time time;
};

#endif //MESSAGE_H
