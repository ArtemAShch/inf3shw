
#include "Shape.h"
#include <cmath>
#include <vector>
#include <map>

std::vector <double> Polygon::getSides() const
{
    std::vector <double> p;
    Point buff;
    for(int i = 0;i<numOfAngles-1;i++){
        buff = Angles[i+1]-Angles[i];
        p.push_back(len(buff));
    }
    buff = Angles[0]-Angles[numOfAngles-1];
    p.push_back(len(buff));
    return p;
}

double Polygon::getPerimeter() const
{
    std::vector <double> p;
    Point buff;
    double l = 0;
    for(int i = 0;i<numOfAngles-1;i++){
        buff = Angles[i+1]-Angles[i];
        l+=len(buff);
    }
    buff = Angles[0]-Angles[numOfAngles-1];
    l+=len(buff);
    return l;
}

double Polygon::getArea() const
{
    std::vector <double> p;
    Point buff1;
    Point buff2;
    double area = 0;
    for(int i = 1;i<numOfAngles-1;i++){
        buff1 = Angles[i]-Angles[0];
        buff2 = Angles[i+1]-Angles[0];
        area+=buff1.getX()*buff2.getY()-buff2.getX()*buff1.getY();
    }
    if(area<0) area*=-1;
    return area;
}

void Polygon::getInfo() const
{
    using std::cout;
    cout << "Name: Polygon.\n";
    cout << "Perimeter is " << getPerimeter() << ".\n";
    cout << "Area is " << getArea() << ".\n\n";
}

