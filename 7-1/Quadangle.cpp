
#include "Shape.h"
#include <cmath>
#include <vector>
#include <map>


void Quadangle::getInfo() const
{
    using std::cout;
    cout << "Name: Quadangle.\n";
    cout << "Perimeter is " << getPerimeter() << ".\n";
    cout << "Area is " << getArea() << ".\n\n";
}

