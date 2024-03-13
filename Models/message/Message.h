#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>

class Message {
public:
    Message(int id, std::string text, std::string sender, std::string date, std::string time);

    int getID();
    void setID(int id);

    std::string getText();
    void setText(std::string text);

    std::string getSender();
    void setSender(std::string sender);

    std::string getDate();
    void setDate(std::string date);

    std::string getTime();
    void setTime(std::string time);

    void Print();

private:
    int id;
    std::string text;
    std::string sender;
    std::string date;
    std::string time;
};

#endif //MESSAGE_H
