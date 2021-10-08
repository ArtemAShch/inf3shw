
#include "Charge.h"
#include <map>
#include <string>

Charge::Charge(double value, Units unit)
{
    m_value = new double(value);
    m_unit = new Units(unit);
    isMemAllocated = true;
    return;
}

Charge::~Charge()
{
    if (isMemAllocated)
    {
        delete m_unit;
        m_unit = nullptr;
        delete m_value;
        m_value = nullptr;
    }
    return;
}

void Charge::convert(Units unit)
{
    if (*m_unit == unit) return;
    double a = Constants[unit];
    double b = Constants[*m_unit];
    double tmp = a / b;
    *m_value *= tmp;
    *m_unit = unit;
}

std::ostream& operator<<(std::ostream& ostr, const Units& unit){
    std::string tmp;
    if (unit == Units::C) tmp = "C";
    if (unit == Units::E) tmp = "E";
    if (unit == Units::F) tmp = "F";
    ostr << tmp;
    return ostr;
}

std::istream& operator>>(std::istream& istr, Units& unit){
    std::string tmp;
    istr >> tmp;
    if (tmp == "C") unit = Units::C;
    else if (tmp == "E") unit = Units::E;
    else if (tmp == "F") unit = Units::F;
    return istr;
}

std::ostream& operator<<(std::ostream& ostr, const Charge& ch){
    ostr << *ch.m_value << ' ' << *ch.m_unit << '\n';
    return ostr;
}

std::istream& operator>>(std::istream& istr, Charge& ch){
    double val;
    Units unit;
    istr >> val >> unit;
    ch.m_value = new double(val);
    ch.m_unit = new Units(unit);
    ch.isMemAllocated = true;
    return istr;
}

