
#include "Shape.h"
#include <cmath>
#include <vector>
#include <map>

const double pi = 3.14159265358979323846;

double Ellipse::getPerimeter() const
{
    return pi*(a+b);
}

double Ellipse::getArea() const
{
    return pi*a*b
}

void Ellipse::getInfo() const
{
    using std::cout;
    cout << "Name: Ellipse.\n";
    cout << "Perimeter is " << getPerimeter() << ".\n";
    cout << "Area is " << getArea() << ".\n\n";
}

