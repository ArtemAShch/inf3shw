
#include "Point.h"

Point Point::operator+(const Point& b) const {
    Point F;
    F.setX(x+b.getX());
    F.setY(y+b.getY());
    return F;
}
Point& Point::operator+=(const Point& b){
    x = x+b.getX();
    y = y+b.getY();
}
Point Point::operator-(const Point& b) const{
    Point F;
    F.setX(x-b.getX());
    F.setY(y-b.getY());
    return F;
}
Point& Point::operator-=(const Point& b){
    x = x-b.getX();
    y = y-b.getY();
}
