//
// Created by Артем on 10.11.2021.
//
#include "IncorrectValueException.h"
#include <iostream>
#ifndef INC_8_2_DAY_H
#define INC_8_2_DAY_H


class Day {
private:
    unsigned int day : 5;
    unsigned int month : 4;
    int year;
public:
    Day() = default;
    Day(unsigned int a, unsigned int b, int c){
        if(a<=getDinM(b) && a>0){
            day = a;
        }
        else{
            throw IncorrectValueException();
        }
        if(b<=12&&b>0){
            month = b;
        }
        else{
            throw IncorrectValueException();
        }
        year = c;
    }
    bool operator<(const Day& a);
    bool operator>(const Day& a);
    bool operator<=(const Day& a);
    bool operator>=(const Day& a);
    unsigned int getDinM();
    unsigned int getDinM(const unsigned int a);

    friend std::ostream& operator<<(std::ostream&, const Day&);
    friend std::istream& operator>>(std::istream&, Day&);


};


#endif //INC_8_2_DAY_H
