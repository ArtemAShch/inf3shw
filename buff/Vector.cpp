#include "Vector.h"
#include <algorithm>
#include <iostream>

const std::vector<double>& Vector::get_components() const {
    return components;
}

unsigned Vector::get_dimension() const {
    return dimension;
}


void Vector::set_dimension(unsigned dimension) {
    this->dimension = dimension;
    components.resize(dimension);
}

void Vector::set_components(const std::vector<double>& components) {
    this->components = components;
    dimension = components.size();
}
void Vector::set_comp(const double g, const int i){
    components[i]=g;
}

std::ostream& operator<<(std::ostream& ostr, const Vector& vec){
    ostr << "Dimension: " << vec.get_dimension() << std::endl;
    ostr << "Components: ";
    for(int i=0;i<vec.get_components().size();i++){
        ostr<<vec.get_components()[i]<<' ';
    }
    ostr<<std::endl;
    return ostr;
}

std::istream& operator>>(std::istream& istr, Vector& v){
    double a;
    int dim;
    std::vector <double> buff;
    std::cout << "Enter the dimension:";
    istr >> dim;
    v.set_dimension(dim);
    std::cout << "Enter the components:";
    for(int i=0;i<v.get_dimension();i++){
        istr >> a;
        buff.push_back(a);
    }
    v.set_components(buff);
    std::cout << std::endl;
    return istr;
}

Vector& Vector::operator*=(const double& num){
    for(int i=0;i<dimension;i++){
        components[i]*=num;
    }
}

Vector Vector::operator*(const double& num){
    Vector buff;
    buff.set_dimension(dimension);
    for (int i=0;i<dimension;i++){
        buff.set_comp(num*components[i], i);
    }
    return buff;
}

Vector& Vector::operator+=(const Vector& b)
{
    if (dimension!=b.get_dimension())
    {
        std::cout << "Dimension error"<<std::endl;
    }
    for (int i=0;i<dimension;i++){
        components[i]+=b.get_components()[i];
    }
}

Vector Vector::operator+(const Vector& b)
{
    if (dimension!=b.get_dimension())
    {
        std::cout << "Dimension error"<<std::endl;
        Vector empty;
        return empty;
    }
    Vector buff;
    buff.set_dimension(dimension);
    for (int i=0;i<dimension;i++){
        buff.set_comp(components[i]+b.get_components()[i], i);
    }
    return buff;
}

Vector& Vector::operator-=(const Vector& b)
{
    if (dimension!=b.get_dimension())
    {
        std::cout << "Dimension error"<<std::endl;
    }
    for (int i=0;i<dimension;i++){
        components[i]-=b.get_components()[i];
    }
}

Vector Vector::operator-( const Vector& b)
{
    if (dimension!=b.get_dimension())
    {
        std::cout << "Dimension error"<<std::endl;
        Vector empty;
        return empty;
    }
    Vector buff;
    buff.set_dimension(dimension);
    for (int i=0;i<dimension;i++){
        buff.set_comp(components[i]-b.get_components()[i], i);
    }
    return buff;
}

Vector& Vector::operator-()
{
    for (int i=0;i<dimension;i++){
       components[i]*=-1;
    }
}

double Vector::scalar(const Vector& b)
{
    if (dimension!=b.get_dimension())
    {
        std::cout << "Dimension error"<<std::endl;
        return 0;
    }
    double res=0;
    for (int i=0;i<dimension;i++){
        res+=components[i]*b.get_components()[i];
    }
    return res;
}

double Vector::vector_abs()
{
    double a=0;
    for (int i=0;i<dimension;i++){
        a+=pow(components[i], 2);
    }

    a=pow(a, 0.5);
    return a;
}