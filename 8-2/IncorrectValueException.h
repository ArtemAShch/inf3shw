//
// Created by Артем on 10.11.2021.
//
#include <exception>

#ifndef INC_8_2_INCORRECTVALUEEXCEPTION_H
#define INC_8_2_INCORRECTVALUEEXCEPTION_H
class IncorrectValueException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: incorrect value";
    }
};

#endif //INC_8_2_INCORRECTVALUEEXCEPTION_H
