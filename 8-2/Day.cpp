//
// Created by Артем on 10.11.2021.
//

#include "Day.h"

unsigned int Day::getDinM() {
    unsigned int season = month;
    switch (season) {
        case 1:
            return 31;
        case 2:
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 0;
    }
}

unsigned int Day::getDinM(const unsigned int a) {
    unsigned int season = a;
    switch (season) {
        case 1:
            return 31;
        case 2:
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 0;
    }
}

bool Day::operator<(const Day& a){
    if(day<a.day&&month<=a.month&&year<=a.year){
        return 1;
    }
    else return 0;
}

bool Day::operator>(const Day& a){
    if(day>a.day&&month>=a.month&&year>=a.year){
        return 1;
    }
    else return 0;

}

bool Day::operator<=(const Day& a){
    if(day<=a.day&&month<=a.month&&year<=a.year){
        return 1;
    }
    else return 0;
}

bool Day::operator>=(const Day& a){
    if(day>=a.day&&month>=a.month&&year>=a.year){
        return 1;
    }
    else return 0;

}

std::ostream& operator<<(std::ostream& ostr, const Day& d){
    if(d.day<10){
        ostr<<0<<d.day;
    }
    else ostr<<d.day;
    ostr<<'.';
    if(d.month<10){
        ostr<<0<<d.month;
    }
    else ostr<<d.month;
    ostr<<'.';
    ostr<<d.year;
    return ostr;
}
std::istream& operator>>(std::istream& istr, Day& d){
    unsigned int a, b;
    int c;
    istr >> a >> b>>c;
    if(a<=d.getDinM() && a>0){
        d.day = a;
    }
    else{
        throw IncorrectValueException();
    }
    if(b<=12&&b>0){
        d.month = b;
    }
    else{
        throw IncorrectValueException();
    }
    d.year = c;
    return istr;
}

