#include <iostream>
#include <vector>
//#include "Shape.h"
#include "Point.h"
#include <utility>

int main() {
    /*Triangle a;
    std::cin>>a;
    std::cout<<a<<std::endl;
    std::cout<<a.area()<<" "<<a.perimeter()<<std::endl;
    std::vector <double> x = a.sides();
    std::cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<std::endl;*/
    std::pair<double , double> V;
    V.first = 1;
    V.second = 2;
    Point b = V;
    Point c;
    c.setX(3);
    c.setY(4);
    c-=b;
    Point x = c-b;
    std::cout<<b.getX()<<" "<<b.getY()<<" "<<c.getX()<<" "<<c.getY()<<" "<<x.getX()<<" "<<x.getY();
    return 0;
}
