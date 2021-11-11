//
// Created by Артем on 13.10.2021.
//

#ifndef INC_6_1_FRACTION_H
#define INC_6_1_FRACTION_H

#include <iostream>
#include <map>
#include <cmath>
#include "DivisionByZeroFracException.h"

class Fraction{
private:
    int top;
    int bot;
//    bool isMemAllocated = false;

public:
    Fraction() = default;
    Fraction(int , int );
    Fraction(const Fraction& another) : top (another.top), bot (another.bot) {}
//    ~Fraction();

    int getTop() const { return top; }
    int getBot() const { return bot; }
    double getValue() const{ return top/bot;}

    void setTop(int tmp);
    void setBot(int tmp);

    Fraction& operator-();
    Fraction operator-(const Fraction& b);
    Fraction operator-(const int a);
    Fraction& operator-=(const Fraction& b);
    Fraction& operator-=(const int a);
    Fraction operator+(const Fraction& b);
    Fraction operator+(const int a);
    Fraction& operator*=(const Fraction& b);
    Fraction& operator*=(const int a);
    Fraction operator*(const Fraction& b);
    Fraction operator*(const int a);
    Fraction& operator+=(const Fraction& b);
    Fraction& operator+=(const int a);
    Fraction operator/(const Fraction& b);
    Fraction operator/(const int a);
    Fraction& operator/=(const Fraction& b);
    Fraction& operator/=(const int a);
    bool operator<(const Fraction& b);
    bool operator>(const Fraction& b);
    operator double() const { return double(top)/double(bot);}

    friend std::ostream& operator<<(std::ostream&, const Fraction&);
    friend std::istream& operator>>(std::istream&, Fraction&);
};

#endif //INC_6_1_FRACTION_H
