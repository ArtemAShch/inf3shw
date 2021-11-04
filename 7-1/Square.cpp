
#include "Shape.h"
#include <cmath>
#include <vector>
#include <map>


double Square::getPerimeter() const
{
    return a*4
}

double Square::getArea() const
{
    return a*a
}

void Square::getInfo() const
{
    using std::cout;
    cout << "Name: Square.\n";
    cout << "Perimeter is " << getPerimeter() << ".\n";
    cout << "Area is " << getArea() << ".\n\n";
}
