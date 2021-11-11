//
// Created by Артем on 11.11.2021.
//
#include <exception>
#ifndef INC_6_1_DIVISIONBYZEROFRACEXCEPTION_H
#define INC_6_1_DIVISIONBYZEROFRACEXCEPTION_H
class DivisionByZeroFracException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: division by zero";
    }
};
#endif //INC_6_1_DIVISIONBYZEROFRACEXCEPTION_H
