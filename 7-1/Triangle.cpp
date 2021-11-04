
#include "Shape.h"
#include <cmath>
#include <vector>
#include <map>

bool Triangle::check(Point A, Point B, Point C){
    double a, b, c;
    a=len(A-B);
    b=len(B-C);
    c=len(C-A);
    if ((a + b < c) || (a + c < b) || (b + c < a))
        return false;
    return true;
}

void Triangle::getInfo() const
{
    using std::cout;
    cout << "Name: Triangle.\n";
    cout << "Perimeter is " << getPerimeter() << ".\n";
    cout << "Area is " << getArea() << ".\n\n";
}