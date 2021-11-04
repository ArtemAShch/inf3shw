
#ifndef INC_7_1_SHAPE_H
#define INC_7_1_SHAPE_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "Point.h"

class Shape
{
public:
    Shape() {
        std::cout << "Constructing Shape.\n";
    }
    virtual ~Shape() {
        std::cout << "Destructing Shape.\n";
    }
    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;
    virtual void getInfo() const = 0;
};

//////////////////////////////////////////////////////////////////

class Ellipse : public Shape
{
private:
    double a, b;
    Point C;

public:
    Ellipse() = default;
    Ellipse(Point Ctmp, double tmp1 = 0, double tmp2 = 0) : a(tmp1), b(tmp2), C(Ctmp)
    {
        std::cout << "Constructing Ellipse.\n";
    }
    virtual ~Ellipse()
    {
        std::cout << "Destructing Ellipse.\n";
    }
    virtual double getPerimeter() const override;
    virtual double getArea() const override;
    virtual void getInfo() const override;

public:
    double getA() const { return a; }
    double getB() const { return b; }
    Point getCentre() const {return C; }
    void setA(double tmp) { a = tmp; }
    void setB(double tmp) { b = tmp; }
    void setCentre(Point tmp) { C = tmp; }
};

//////////////////////////////////////////////////////////////////

class Circle : public Ellipse
{
private:
    double r;
    Point CC;
public:
    Circle(Point center, double tmp = 0) : r(tmp), CC(center)
    {
        std::cout << "Constructing Circle.\n";
    }
    virtual ~Circle()
    {
        std::cout << "Destructing Circle.\n";
    }
    virtual double getPerimeter() const override final;
    virtual double getArea() const override final;
    virtual void getInfo() const override final;

public:
    double getRadius() const { return r; }
    Point getCenter() const { return CC; }
    void setRadius(double tmp) { r = tmp; }
    void setCenter(Point tmp) { CC = tmp; }

    double getA() const = delete;
    double getB() const = delete;
    void setA(double tmp) = delete;
    void setB(double tmp) = delete;
};

///////////////////////////////////////////////////////////////////////////

class Polygon : public Shape
{
private:
    int numOfAngles;
    std::vector<Point> Angles;
protected:

    Polygon(int tmp = 3) : numOfAngles(tmp)
    {
        Angles.resize(numOfAngles);
        std::cout << "Constructing Polygon.\n";
    }
public:
    Polygon(int tmp, const std::vector<Point>& tmp1) : numOfAngles(tmp)
    {
        if (tmp < 3)
        {
            std::cout << "Error: unable to create polygon.\n";
            return;
        }
        for (auto i = 0; i < numOfAngles; i++)
            Angles.push_back(tmp1[i]);
        std::cout << "Constructing Polygon.\n";
    }
    virtual ~Polygon()
    {
        Angles.clear();
        std::cout << "Destructing Polygon.\n";
    }
    virtual double getPerimeter() const override;
    virtual double getArea() const override;
    virtual void getInfo() const override;
    virtual std::vector <double> getSides() const;

    double getNumOfAngles() const { return numOfAngles; }
    void setNumOfAngles(int tmp) { numOfAngles = tmp; }

    const std::vector<Point>& getAngles() const { return Angles; }
    void setAngles(std::vector<Point>& inputAngles)
    {
        if (inputAngles.size() != numOfAngles)
        {
            std::cout << "Error: unable to set polygon lines.\n";
            return;
        }

        for (int i = 0; i < numOfAngles; i++) Angles[i] = inputAngles[i];
    }
};

//////////////////////////////////////////////////////////////////////////

class Triangle : public Polygon
{
private:
    bool check(Point a, Point b, Point c);
public:
    Triangle() = delete;
    Triangle(const std::vector<Point>& tmp) : Polygon(3, tmp)
    {
        if (!check(tmp[0], tmp[1], tmp[2]))
        {
            std::cout << "Error: unable to construct triangle.\n";
            return;
        }
        std::cout << "Constructing Triangle.\n";
    }
    Triangle(Point a, Point b, Point c) : Polygon(3)
    {
        if (!check(a, b, c))
        {
            std::cout << "Error: unable to construct triangle.\n";
            return;
        }
        std::vector<Point> tmp{ a, b, c };
        setAngles(tmp);
        std::cout << "Constructing Triangle.\n";
    }
    virtual ~Triangle()
    {
        std::cout << "Destructing Triangle.\n";
    }

    virtual double getPerimeter() const = 0;
    virtual std::vector <double> getSides() const;
    virtual double getArea() const = 0;
    virtual void getInfo() const override;

    double getNumOfAngles() const = delete;
    void setNumOfAngles(int tmp) = delete;
};

////////////////////////////////////////////////////////////////////////

class Quadangle : public Polygon
{
protected:
    Quadangle() : Polygon(4)
    {
        std::cout << "Constructing Quadangle.\n";
    }

public:
    Quadangle(const std::vector<Point>& tmp) : Polygon(4, tmp)
    {
        std::cout << "Constructing Quadangle.\n";
    }
    virtual ~Quadangle()
    {
        std::cout << "Destructing Quadangle.\n";
    }

    virtual double getPerimeter() const = 0;
    virtual double getArea() const = 0;
    virtual void getInfo() const override;

    double getNumOfAngles() const = delete;
    void setNumOfAngles(int tmp) = delete;
};

/////////////////////////////////////////////////////////////////

class Rectangle : public Quadangle
{
private:
    double a, b;

public:
    Rectangle() = delete;
    Rectangle(double tmp1, double tmp2 = 0) : a(tmp1), b(tmp2)
    {
        std::cout << "Constructing Rectangle.\n";
    }
    virtual ~Rectangle()
    {
        std::cout << "Destructing Rectangle.\n";
    }

    virtual double getPerimeter() const override;
    virtual double getArea() const override;
    virtual void getInfo() const override;
};

//////////////////////////////////////////////////////////////////////

class Square : public Rectangle
{
private:
    double a;

public:
    Square(double tmp) : a(tmp), Rectangle(tmp)
    {
        std::cout << "Constructing Square.\n";
    }
    virtual ~Square()
    {
        std::cout << "Destructing Square.\n";
    }

    virtual double getPerimeter() const override final;
    virtual double getArea() const override final;
    virtual void getInfo() const override final;
};
#endif //INC_7_1_SHAPE_H
