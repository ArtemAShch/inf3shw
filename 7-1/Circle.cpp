
#include "Shape.h"
#include <cmath>
#include <vector>
#include <map>

const double pi = 3.14159265358979323846;

double Circle::getPerimeter() const
{
    return 2*pi*r;
}

double Circle::getArea() const
{
    return pi*r*r;
}

void Circle::getInfo() const
{
    using std::cout;
    cout << "Name: Circle.\n";
    cout << "Perimeter is " << getPerimeter() << ".\n";
    cout << "Area is " << getArea() << ".\n\n";
}

