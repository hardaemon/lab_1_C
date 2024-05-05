#pragma once
#include <iostream>
class Error : public std::exception {
    std::string errorMessage;
public:
    // Конструктор класса исключения
    Error(const std::string& message) : errorMessage(message) {}
    // Переопределение метода what() для возврата описания ошибки
    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};