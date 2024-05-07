#include "./Message.h"
#include <string>

Message::Message() {
    id = 0;
    text = "";
    sender = "None";
}

Message::Message(int id, std::string text, std::string sender) {
    this->id = id;
    this->text = text;
    this->sender = sender;
}

int Message::getID() {
    return id;
}

void Message::setID(int id) {
    this->id = id;
}

std::string Message::getText() {
    return text;
}

void Message::setText(std::string text) {
    this->text = text;
}

std::string Message::getSender() {
    return sender;
}

void Message::setSender(std::string sender) {
    this->sender = sender;
}

std::string Message::getTime() {
    return time.GetDateAsString();
}

void Message::setTime() {
    this->time = Time();
}

void Message::Print() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Message: " << text << std::endl;
    std::cout << "Sender: " << sender << std::endl;
    std::cout << "Time: " << time.GetDateAsString() << std::endl;
}

bool Message::operator>(const Message& other) {
    return id > other.id;
}

std::ostream& operator<<(std::ostream& out, const Message& message) {
    message.Print();
    return out;
}