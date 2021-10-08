
#ifndef INC_5_3_CHARGE_H
#define INC_5_3_CHARGE_H

#include <iostream>
#include <map>
#include <cmath>

enum class Units
{
    C,
    E,
    F
};

std::ostream& operator<<(std::ostream&, const Units&);
std::istream& operator>>(std::istream&, Units&);

static std::map <Units, double> Constants = { {Units::C, 1}, {Units::E, 6.25e18},
                                              {Units::F, 3e9}};

class Charge{
private:
    bool isMemAllocated = false;
    double* m_value;
    Units* m_unit;

public:
    Charge() : m_value(nullptr), m_unit(nullptr) {}
    Charge(double, Units);
    Charge(const Charge& another) : m_value (another.m_value), m_unit (another.m_unit) {}
    ~Charge();

    void convert(Units unit);

    double getValue() { return *m_value; }
    Units getUnit() { return *m_unit; }

    void setValue(double tmp) { *m_value = tmp; }
    void setUnit(Units tmp) { *m_unit = tmp; }

    friend std::ostream& operator<<(std::ostream&, const Charge&);
    friend std::istream& operator>>(std::istream&, Charge&);
};

#endif //INC_5_3_CHARGE_H
