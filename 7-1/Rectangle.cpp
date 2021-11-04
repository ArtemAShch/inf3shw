
#include "Shape.h"
#include <cmath>
#include <vector>
#include <map>

double Rectangle::getPerimeter() const
{
    return 2*(a+b);
}

double Rectangle::getArea() const
{
    return a*b
}

void Rectangle::getInfo() const
{
    using std::cout;
    cout << "Name: Rectangle.\n";
    cout << "Perimeter is " << getPerimeter() << ".\n";
    cout << "Area is " << getArea() << ".\n\n";
}

