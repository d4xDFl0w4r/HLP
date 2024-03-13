#include "./Message.h"

Message::Message(int id, std::string text, std::string sender, std::string date, std::string time) {
    this->text = text;
    this->sender = sender;
    this->date = date;
    this->time = time;
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

std::string Message::getDate() {
    return date;
}

void Message::setDate(std::string date) {
    this->date = date;
}

std::string Message::getTime() {
    return time;
}

void Message::setTime(std::string time) {
    this->time = time;
}

void Message::Print() {
    std::cout << "Message: " << text << std::endl;
    std::cout << "Sender: " << sender << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Time: " << time << std::endl;
}