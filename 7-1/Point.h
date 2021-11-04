
#ifndef INC_7_1_POINT_H
#define INC_7_1_POINT_H
#include <utility>
#include <iostream>
#include <cmath>


class Point {
private:
    double x;
    double y;
public:
    Point()=default;
    Point(std::pair<double, double> tmp){
        x = tmp.first;
        y = tmp.second;
    }
    Point(double tmp1, double tmp2){
        x = tmp1;
        y = tmp2;
    }
    ~Point()=default;
    std::pair<double, double> getPoint() const{
        std::pair<double, double> F;
        F.first = x;
        F.second = y;
        return F;
    };
    double getX() const {
        return x;
    };
    double getY() const {
        return y;
    };
    void setX(double tmp){
        x = tmp;
    };
    void setY(double tmp){
        y = tmp;
    };
    Point operator+(const Point& b) const;
    Point& operator+=(const Point& b);
    Point operator-(const Point& b) const;
    Point& operator-=(const Point& b);
};

double len(Point A){
    return pow(A.getX()*A.getX()+A.getY()*A.getY(), 0.5);
}


#endif //INC_7_1_POINT_H
