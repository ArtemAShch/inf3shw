//
// Created by Артем on 13.10.2021.
//

#include "Fraction.h"
#include <map>
#include <cmath>

int Nok(int a, int b){
    int t=abs(a);
    int f=abs(b);
    while (t*f!=0) {
        if (t < f) f = f % t;
        else t = t % f;
    }
    return t+f;
}

short sig(int a, int b){
    if(a*b<0) return -1;
    else return 1;
}

Fraction::Fraction(int top_v, int bot_v)
{
    if(bot_v==0){
        throw DivisionByZeroFracException();
    }
    int c = Nok(top_v, bot_v);
    top = (sig(top_v, bot_v)*abs(top_v/c));
    bot = (abs(bot_v/c));
//    isMemAllocated = true;
    return;
}

/*Fraction::~Fraction()
{
    if (isMemAllocated)
    {
        delete top;
        top = nullptr;
        delete bot;
        bot = nullptr;
    }
    return;
}*/

/*double Fraction::getValue(){
    double a = top;
    double b = bot;
    double c = a/b;
    return c;
}*/

void Fraction::setTop(int tmp) {
    int c = Nok(tmp, bot);
    top = tmp/c;
    bot /= c;
    return;
}

void Fraction::setBot(int tmp) {
    if(tmp==0){
        throw DivisionByZeroFracException();
    }
    int c = Nok(top, tmp);
    top = top*tmp/abs(tmp)/c;
    bot = abs(tmp)/c;
    return;
}

std::ostream& operator<<(std::ostream& ostr, const Fraction& ch){
    ostr << ch.top << '/' << ch.bot << '\n';
    return ostr;
}

std::istream& operator>>(std::istream& istr, Fraction& ch){
    int top_v, bot_v;
    istr >> top_v >> bot_v;
    if(bot_v==0){
        throw DivisionByZeroFracException();
    }
    int c = Nok(top_v, bot_v);
    ch.top = (sig(top_v, bot_v)*abs(top_v/c));
    ch.bot = (abs(bot_v/c));
//    ch.isMemAllocated = true;
    return istr;
}

Fraction& Fraction::operator-(){
    top*=-1;
}
Fraction Fraction::operator-(const Fraction& b) {
    Fraction a;
    a.setBot(1);
    a.setTop(top*b.getBot()-bot*b.getTop());
    a.setBot(bot*b.getBot());
    return a;
}
Fraction Fraction::operator-(const int a) {
    Fraction b;
    b.setBot(bot);
    b.setTop(top-bot*a);
    return b;
}
Fraction& Fraction::operator-=(const Fraction& b) {
    top = top*b.getBot()-bot*b.getTop();
    bot = bot*b.getBot();
    int c = Nok(top, bot);
    top /= c;
    bot /= c;
}

Fraction& Fraction::operator-=(const int a) {
    top = top-bot*a;
    int c = Nok(top, bot);
    top /= c;
    bot /= c;
}
Fraction Fraction::operator+(const Fraction& b) {
    Fraction a;
    a.setBot(1);
    a.setTop(top*b.getBot()+bot*b.getTop());
    a.setBot(bot*b.getBot());
    return a;
}
Fraction Fraction::operator+(const int a) {
    Fraction b;
    b.setBot(bot);
    b.setTop(top+bot*a);
    return b;
}
Fraction& Fraction::operator*=(const Fraction& b) {
    top*=b.getTop();
    bot*=b.getBot();
    int c = Nok(top, bot);
    top /= c;
    bot /= c;
}
Fraction& Fraction::operator*=(const int a) {
    top*=a;
    int c = Nok(top, bot);
    top /= c;
    bot /= c;
}
Fraction Fraction::operator*(const Fraction& b) {
    Fraction a;
    a.setBot(1);
    a.setTop(top*b.getTop());
    a.setBot(bot*b.getBot());
    return a;
}
Fraction Fraction::operator*(const int a) {
    Fraction b;
    b.setBot(bot);
    b.setTop(a*top);
    return b;
}
Fraction& Fraction::operator+=(const Fraction& b) {
    top = top*b.getBot()+bot*b.getTop();
    bot = bot*b.getBot();
    int c = Nok(top, bot);
    top /= c;
    bot /= c;
}
Fraction& Fraction::operator+=(const int a) {
    top = top+bot*a;
    int c = Nok(top, bot);
    top /= c;
    bot /= c;
}

Fraction& Fraction::operator/=(const Fraction& b) {
    if(b.getTop()==0){
        throw DivisionByZeroFracException();
    }
    top*=b.getBot();
    bot*=b.getTop();
    int c = Nok(top, bot);
    top /= c;
    bot /= c;
}
Fraction& Fraction::operator/=(const int a) {
    if(a==0){
        throw DivisionByZeroFracException();
    }
    bot*=a;
    int c = Nok(top, bot);
    top /= c;
    bot /= c;
}
Fraction Fraction::operator/(const Fraction& b) {
    if(b.getTop()==0){
        throw DivisionByZeroFracException();
    }
    Fraction a;
    a.setBot(1);
    a.setTop(top*b.getBot());
    a.setBot(bot*b.getTop());
    return a;
}
Fraction Fraction::operator/(const int a) {
    if(a==0){
        throw DivisionByZeroFracException();
    }
    Fraction b;
    b.setBot(bot*a);
    b.setTop(top);
    return b;
}

bool Fraction::operator<(const Fraction& b){
    if(top/bot<b.getValue()) return 1;
    else return 0;
}

bool Fraction::operator>(const Fraction& b){
    if(top/bot>b.getValue()) return 1;
    else return 0;
}
